#include "global.h"
#include "dungeon_ai.h"

#include "constants/ability.h"
#include "constants/dungeon_action.h"
#include "constants/direction.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_movement.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "dungeon_visibility.h"
#include "map.h"
#include "pokemon.h"
#include "status_checks.h"
#include "targeting.h"
#include "tile_types.h"

extern char gAvailablePokemonNames[];
extern char *gPtrCouldntBeUsedMessage;
extern char *gPtrItsaMonsterHouseMessage;

extern void SetMessageArgument(char[], struct Entity*, u32);
extern u8 sub_8044B28(void);
extern void sub_807AB38(struct Entity *, u32);
extern void sub_8041888(u32);
extern u8 sub_803F428(s16 *);
extern void sub_803E708(u32, u32);

u32 sub_8075818(struct Entity *entity)
{
    struct Tile *tile;
    struct EntityInfo *entityInfo;
    struct Entity *subEntity;
    struct Item *item;
    u8 *trapData; // TODO: turn into struct when more research is done..
    u8 r1;

    entityInfo = entity->info;
    if(EntityExists(entity))
    {
        tile = GetTileAtEntitySafe(entity);
        if(IQSkillIsEnabled(entity, IQ_SUPER_MOBILE))
            if(!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
                return 1;
        subEntity = tile->object;
        if(subEntity != NULL)
        {
            switch(GetEntityType(subEntity))
            {
                case ENTITY_NOTHING:
                case ENTITY_MONSTER:
                case ENTITY_UNK_4:
                case ENTITY_UNK_5:
                    break;
                case ENTITY_TRAP:
                    trapData = (u8*) GetTrapData(subEntity);
                    r1 = 0;
                    if(trapData[1] == 0)
                    {
                        if(!subEntity->isVisible || entityInfo->isNotTeamMember)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData[1] == 1)
                    {
                        if(!entityInfo->isNotTeamMember)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData[1] == 2)
                    {
                        if(!entityInfo->isNotTeamMember)
                            r1 = 1;
                    }
flag_check:
                    if(r1 == 0)
                        break;
                    else
                        goto error;
                case ENTITY_ITEM:
                    if(!entityInfo->isTeamLeader)
                    {
                        if(!(entityInfo->heldItem.flags & ITEM_FLAG_EXISTS))
                        {
                            if(!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
                            {
                                if(entityInfo->isNotTeamMember)
                                    break;
                                else
                                {
                                    item = GetItemData(subEntity);
                                    if(!(item->flags & ITEM_FLAG_IN_SHOP))
                                    {
                                        return 1;
                                    }
                                }
                            }
                            else
                            {
                                item = GetItemData(subEntity);
                                if(!(item->flags & ITEM_FLAG_IN_SHOP))
                                {
error:
                                    return 1;
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}

void sub_8075900(struct Entity *pokemon, u8 r1)
{
    if(EntityExists(pokemon))
    {
        if(!pokemon->info->isNotTeamMember)
        {
            if(!sub_8044B28())
            {
                if(!gDungeon->monsterHouseTriggered)
                {
                    if((GetTileAtEntitySafe(pokemon)->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE))
                    {
                        // It's a monster house!
                        SendMessage(GetLeader(), gPtrItsaMonsterHouseMessage);
                        gDungeon->unk672 = 1;
                        sub_807AB38(pokemon, r1);
                        sub_8041888(0);
                        if(sub_803F428(&pokemon->pos.x) != 0)
                            sub_803E708(0x78, 0x39);
                    }
                }
            }
        }
    }
}

void RunMonsterAI(struct Entity *pokemon, u32 unused)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    if (pokemonInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)
    {
        if (pokemonInfo->immobilizeStatus == STATUS_PETRIFIED)
        {
            SendImmobilizeEndMessage(pokemon, pokemon);
        }
    }
    else
    {
        pokemonInfo->targetingDecoy = TARGETING_DECOY_NONE;
        if (pokemonInfo->clientType == CLIENT_TYPE_NONE || IsMovingClient(pokemon))
        {
            if (pokemonInfo->clientType != CLIENT_TYPE_CLIENT && pokemonInfo->useHeldItem)
            {
                if (CannotUseItems(pokemon))
                {
                    pokemonInfo->useHeldItem = FALSE;
                    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
                    SendMessage(pokemon, gPtrCouldntBeUsedMessage);
                    return;
                }
                DecideUseItem(pokemon);
                if (pokemonInfo->action.action != ACTION_NOTHING)
                {
                    return;
                }
            }
            if (!HasStatusAffectingActions(pokemon))
            {
                if (gDungeon->decoyActive)
                {
                    s32 i;
                    struct Entity *target;
                    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
                    {
                        target = gDungeon->allPokemon[i];
                        if (EntityExists(target) &&
                            target->info->waitingStatus == STATUS_DECOY &&
                            CanSeeTarget(pokemon, target))
                        {
                            bool8 enemyDecoy = target->info->enemyDecoy;
                            u8 targetingDecoy = TARGETING_DECOY_TEAM;
                            if (enemyDecoy)
                            {
                                targetingDecoy = TARGETING_DECOY_WILD;
                            }
                            pokemonInfo->targetingDecoy = targetingDecoy;
                            break;
                        }
                    }
                }
                ClearMonsterActionFields(&pokemonInfo->action);
                if (pokemonInfo->clientType == CLIENT_TYPE_CLIENT)
                {
                    SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                    pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
                    pokemonInfo->targetPos.x = pokemon->pos.x;
                    pokemonInfo->targetPos.y = pokemon->pos.y - 1;
                }
                else
                {
                    DecideUseItem(pokemon);
                    if (pokemonInfo->action.action == ACTION_NOTHING)
                    {
                        if (!IQSkillIsEnabled(pokemon, IQ_DEDICATED_TRAVELER))
                        {
                            DecideAttack(pokemon);
                            if (pokemonInfo->action.action != ACTION_NOTHING)
                            {
                                return;
                            }
                            if (pokemonInfo->volatileStatus == STATUS_CONFUSED)
                            {
                                SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                            }
                            else
                            {
                                if (!CanMove(pokemonInfo->id))
                                {
                                    return;
                                }
                                MoveIfPossible(pokemon, TRUE);
                            }
                        }
                        else
                        {
                            if (pokemonInfo->volatileStatus == STATUS_CONFUSED)
                            {
                                SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                            }
                            else
                            {
                                if (CanMove(pokemonInfo->id))
                                {
                                    MoveIfPossible(pokemon, TRUE);
                                }
                                if (pokemonInfo->action.action > ACTION_PASS_TURN)
                                {
                                    return;
                                }
                                DecideAttack(pokemon);
                                if (pokemonInfo->action.action <= ACTION_PASS_TURN)
                                {
                                    return;
                                }
                                pokemonInfo->aiNotNextToTarget = FALSE;
                                pokemonInfo->aiNextToTarget = FALSE;
                                pokemonInfo->waiting = FALSE;
                            }
                        }
                    }
                }
            }
        }
    }
}

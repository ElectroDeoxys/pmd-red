#include "global.h"
#include "dungeon_ai_item_weight.h"

#include "code_80521D0.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_ai_1.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "moves.h"
#include "number_util.h"
#include "status_checks_1.h"

extern void sub_803E708(u32, u32);
extern void sub_80421C0(struct DungeonEntity *r0, u16 r1);
extern void sub_8078B5C(struct DungeonEntity *, u32, u32, u32, u32);
extern void sub_80763F8(struct DungeonEntity *, u32, u32);
extern void sub_80769CC(struct DungeonEntity *, u32);
extern void sub_8076210(struct DungeonEntity *, u32, u32, u32);
extern void sub_8077780(struct DungeonEntity *, u32, u32);
extern void sub_8076E20(struct DungeonEntity *, u32, u32, u32, u32, u32);

extern u8 *gPtrMusicBoxPlayedCrumbledMessage[];
extern u8 *gPtrWishStoneCrumbledMessage[];
extern u8 *gPtrIcePartCrumbledMessage[];
extern u8 *gPtrRockPartCrumbledMessage[];
extern u8 *gPtrSteelPartCrumbledMessage[];
extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4FAC;
extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8051E7C(struct DungeonEntity *pokemon);

void sub_8048DB8(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u8 r2)
{
    u8 temp;
    if(r2 != 0)
        sub_806F370(pokemon, r1, gUnknown_80F4FAC, 1, &temp, 0, 0x217, 0, 0, 0);
    else
        sub_8051E7C(pokemon);
}

void sub_8048E04(struct DungeonEntity *pokemon, u32 r1)
{
    sub_8078B5C(pokemon, r1, 0x1E, 0, 1);
    switch(DungeonRandomCapped(5))
    {
        case 0:
            sub_80763F8(pokemon, r1, 1);
            break;
        case 1:
            sub_80769CC(pokemon, r1);
            break;
        case 2:
            sub_8076210(pokemon, r1, 1, 1);
            break;
        case 3:
            sub_8077780(pokemon, r1, 1);
            break;
        case 4:
            sub_8076E20(pokemon, r1, gUnknown_8106A4C, 3, 1, 1);
            sub_8076E20(pokemon, r1, gUnknown_8106A50, 3, 1, 1);
            break;
    } 
}

void sub_8048EB0(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrIcePartCrumbledMessage);
}

void sub_8048EC4(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrRockPartCrumbledMessage);
}

void sub_8048ED8(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrSteelPartCrumbledMessage);
}

void sub_8048EEC(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrWishStoneCrumbledMessage);
}

void sub_8048F00(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0xD6);
    SendMessage(pokemon, *gPtrMusicBoxPlayedCrumbledMessage);
    sub_803E708(0x3C, 0x46);
}

u32 EvaluateItem(struct DungeonEntity *targetPokemon, struct ItemSlot *item, u32 itemTargetFlags)
{
    struct DungeonEntityData *pokemonData = targetPokemon->entityData;
    s32 itemWeight = 0;
    bool8 targetOther = itemTargetFlags & 1;
    u16 targetAlly = (itemTargetFlags >> 1) & 1;
    s32 i;
    struct PokemonMove *move;
    struct PokemonMove *move2;
    switch (item->itemIndex)
    {
        case ITEM_ID_STICK:
        case ITEM_ID_IRON_THORN:
        case ITEM_ID_SILVER_SPIKE:
        case ITEM_ID_GOLD_FANG:
        case ITEM_ID_CACNEA_SPIKE:
        case ITEM_ID_CORSOLA_TWIG:
        case ITEM_ID_GRAVELEROCK:
        case ITEM_ID_GEO_PEBBLE:
            if (targetOther)
            {
                itemWeight = 70;
            }
            break;
        case ITEM_ID_DIET_RIBBON:
            if (targetOther && RoundUpFixedPoint(pokemonData->belly) > 0)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_WHIFF_SPECS:
        case ITEM_ID_NO_AIM_SCOPE:
            if (targetOther)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_ORAN_BERRY:
        case ITEM_ID_SITRUS_BERRY:
            if (pokemonData->HP < pokemonData->maxHP && pokemonData->HP <= pokemonData->maxHP / 4)
            {
                if (!targetOther)
                {
                    if (CanTargetAdjacentPokemon(targetPokemon))
                    {
                        itemWeight = 100;
                    }
                    else
                    {
                        itemWeight = 50;
                    }
                }
                else
                {
                    itemWeight = 50;
                }
            }
            break;
        case ITEM_ID_MAX_ELIXIR:
            itemWeight = 0;
            move = pokemonData->moves;
            move2 = move;
            for (i = 0; i < MAX_MON_MOVES; move++, move2++, i++)
            {
                if (move->moveFlags & MOVE_FLAG_EXISTS)
                {
                    if (move->PP == 0)
                    {
                        itemWeight += 30;
                    }
                    if (move->PP != GetMoveMaxPP(move2))
                    {
                        itemWeight += 6;
                    }
                }
            }
            if (itemWeight >= 99)
            {
                itemWeight = 99;
            }
            break;
        case ITEM_ID_HEAL_SEED:
            if (HasNegativeStatus(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_PROTEIN:
            if (pokemonData->attack > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_CALCIUM:
            if (pokemonData->specialAttack > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_IRON:
            if (pokemonData->defense > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_ZINC:
            if (pokemonData->specialDefense > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_LIFE_SEED:
            if (!targetOther)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 10;
                }
                else
                {
                    itemWeight = 100;
                }
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_EYEDROP_SEED:
            if (!CanSeeInvisible(targetPokemon))
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_QUICK_SEED:
            if (targetPokemon->entityData->movementSpeed <= 3)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_ALLURE_SEED:
            if (pokemonData->eyesightStatus != EYESIGHT_STATUS_CROSS_EYED)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_CHERI_BERRY:
            if (pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_PARALYZED)
            {
                return 0;
            }
            else if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 30;
            }
            break;
        case ITEM_ID_TOTTER_SEED:
            if (pokemonData->volatileStatus != VOLATILE_STATUS_CONFUSED)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 15;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_PECHA_BERRY:
            if (pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_POISONED &&
                pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                return 0;
            }
            else if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 100;
            }
            else
            {
                itemWeight = 50;
            }
            break;
        case ITEM_ID_BLINKER_SEED:
            if (pokemonData->eyesightStatus != EYESIGHT_STATUS_BLINKER)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_WARP_SEED:
            if (!targetAlly)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 40;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else if (pokemonData->HP < pokemonData->maxHP && pokemonData->HP < 20)
            {
                if (!targetOther)
                {
                    if (CanTargetAdjacentPokemon(targetPokemon))
                    {
                        itemWeight = 100;
                    }
                    else
                    {
                        itemWeight = 50;
                    }
                }
                else
                {
                    itemWeight = 50;
                }
            }
            break;
        case ITEM_ID_PATSY_BAND:
            itemWeight = 40;
            break;
        case ITEM_ID_SLEEP_SEED:
            if (pokemonData->sleepStatus != SLEEP_STATUS_SLEEP &&
                pokemonData->sleepStatus != SLEEP_STATUS_NAPPING &&
                pokemonData->sleepStatus != SLEEP_STATUS_NIGHTMARE)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_CHESTO_BERRY:
            if (pokemonData->sleepStatus != SLEEP_STATUS_SLEEPLESS)
            {
                itemWeight = 5;
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_JOY_SEED:
            if (pokemonData->level < 99)
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_GINSENG:
            itemWeight = 80;
            break;
        case ITEM_ID_RAWST_BERRY:
            if (pokemonData->nonVolatileStatus == NON_VOLATILE_STATUS_BURNED)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_HUNGER_SEED:
            if (RoundUpFixedPoint(pokemonData->belly) > 0)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_DOOM_SEED:
            if (pokemonData->level > 1)
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_STUN_SEED:
            if (pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED)
            {
                return 0;
            }
            else if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 5;
            }
            break;
        case ITEM_ID_BLAST_SEED:
            if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 30;
            }
            break;
        case ITEM_ID_APPLE:
        case ITEM_ID_BIG_APPLE:
        case ITEM_ID_HUGE_APPLE:
            if (RoundUpFixedPoint(pokemonData->belly) < 10)
            {
                return 100;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_GRIMY_FOOD:
            itemWeight = 30;
            break;
        case ITEM_ID_ROLLCALL_ORB:
            move = pokemonData->moves; // Fixes a regswap.
            if (targetOther)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 20;
            }
            break;
        default:
            itemWeight = 0;
    }
    return itemWeight;
}

bool8 CanTargetAdjacentPokemon(struct DungeonEntity *pokemon)
{
    s32 facingDir;
    for (facingDir = 0; facingDir < NUM_DIRECTIONS; facingDir++)
    {
        struct MapTile *mapTile = GetMapTileAtPosition(pokemon->posWorld.x + gAdjacentTileOffsets[facingDir].x, pokemon->posWorld.y + gAdjacentTileOffsets[facingDir].y);
        struct DungeonEntity *adjacentPokemon = mapTile->pokemon;
        if (adjacentPokemon != NULL && GetEntityType(adjacentPokemon) != ENTITY_NONE &&
            CanTarget(pokemon, adjacentPokemon, FALSE, TRUE) == TARGET_CAPABILITY_CAN_TARGET)
        {
            return TRUE;
        }
    }
    return FALSE;
}

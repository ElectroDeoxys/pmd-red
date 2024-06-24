#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "iq_skill_list_menu.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

extern u8 gUnknown_202DEA8[];

static EWRAM_DATA_2 struct unkStruct_203B23C *sUnknown_203B23C = {0};

#include "data/iq_skill_list_menu.h"

static void sub_801C440(void);

bool8 CreateIQSkillListMenu(s16 species, u32 index, u32 a2)
{
#ifndef NONMATCHING
    register s32 species_s32 asm("r4");
#else
    s32 species_s32;
#endif

    species_s32 = species;

    if (HasNoAvailIQSkills(species))
        return FALSE;

    if (sUnknown_203B23C == NULL)
        sUnknown_203B23C = MemoryAlloc(sizeof(struct unkStruct_203B23C), 8);

    sUnknown_203B23C->species = species_s32;
    sUnknown_203B23C->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    sUnknown_203B23C->numIQSkills = GetNumAvailableIQSkills(sUnknown_203B23C->iqSkills, sUnknown_203B23C->pokeStruct->IQ);
    sUnknown_203B23C->s24.s0.unk34 = index;
    sUnknown_203B23C->s24.s0.unk38 = &sUnknown_203B23C->s24.s0.unk3C[index];
    sub_8006518(sUnknown_203B23C->s24.s0.unk3C);
    sUnknown_203B23C->s24.s0.unk3C[sUnknown_203B23C->s24.s0.unk34] = sUnknown_80DBDF0;
    sUnknown_203B23C->s24.s0.unk38->unk14 = sUnknown_203B23C->s24.unk9C;
    sub_8012D08(sUnknown_203B23C->s24.s0.unk38, a2);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B23C->s24.s0.unk3C, TRUE, TRUE);
    sub_8013818(&sUnknown_203B23C->s24.s0.input, sUnknown_203B23C->numIQSkills, a2, index);
    sub_801C440();
    BuildIQSkillList();
    return TRUE;
}

u32 HandleIQSkillListMenuInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B23C->s24.s0.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B23C->s24.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&sUnknown_203B23C->s24.s0.input, 1) != 0) {
                sub_801C440();
                BuildIQSkillList();
                return 1;
            }
            return 0;
    }
}

s32 GetIQSkillSelection(void)
{
    return (sUnknown_203B23C->s24.s0.input.unk1E * sUnknown_203B23C->s24.s0.input.unk1C) + sUnknown_203B23C->s24.s0.input.menuIndex;
}

void RedrawIQSkillListMenu(bool8 addCursor)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B23C->s24.s0.unk3C, FALSE, FALSE);
    sUnknown_203B23C->s24.s0.input.unk22 = sUnknown_203B23C->numIQSkills;
    sub_8013984(&sUnknown_203B23C->s24.s0.input);
    sub_801C440();
    BuildIQSkillList();

    if (addCursor)
       AddMenuCursorSprite(&sUnknown_203B23C->s24.s0.input);
}

void CleanIQSkillListMenu(void)
{
    if (sUnknown_203B23C != NULL) {
        sUnknown_203B23C->s24.s0.unk3C[sUnknown_203B23C->s24.s0.unk34] = sUnknown_80DBDD8;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B23C->s24.s0.unk3C, TRUE, TRUE);
        MemoryFree(sUnknown_203B23C);
        sUnknown_203B23C = NULL;
    }
}

static void sub_801C440(void)
{
    sUnknown_203B23C->s24.unk9C[0] = sUnknown_203B23C->s24.s0.input.unk20;
    sUnknown_203B23C->s24.unk9C[1] = sUnknown_203B23C->s24.s0.input.unk1E;
    sUnknown_203B23C->s24.unk9C[2] = 10;
    sUnknown_203B23C->s24.unk9C[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B23C->s24.s0.unk3C, TRUE, TRUE);

    SUB_80095E4_CALL_2(sUnknown_203B23C->s24.s0);
}

void BuildIQSkillList(void)
{
    u32 y;
    s32 x;
    s32 x2;
    u32 skillIndex;
    s32 counter;

    sub_8008C54(sUnknown_203B23C->s24.s0.unk34);
    sub_80073B8(sUnknown_203B23C->s24.s0.unk34);
    x = sUnknown_203B23C->s24.s0.input.unk1E * 8;
    x2 = x;
    x2 += 10;
    xxx_call_draw_string(x2, 0, sIQSkills, sUnknown_203B23C->s24.s0.unk34, 0);

    x += 4;
    x2 = x + sUnknown_203B23C->s24.unk9C[2] * 8;
    sub_8012BC4(x2, 0, sUnknown_203B23C->s24.s0.input.unk1E + 1, 1, 7, sUnknown_203B23C->s24.s0.unk34);

    for (counter = 0; counter < sUnknown_203B23C->s24.s0.input.unk1A; counter++) {
        skillIndex = sUnknown_203B23C->iqSkills[(sUnknown_203B23C->s24.s0.input.unk1E * sUnknown_203B23C->s24.s0.input.unk1C) + counter];

        y = sub_8013800(&sUnknown_203B23C->s24.s0.input, counter);
        strncpy(gUnknown_202DEA8, GetIQSkillName(skillIndex), 80);

        if (IsIQSkillSet((u8 *)&sUnknown_203B23C->pokeStruct->IQSkills, 1 << skillIndex))
            strcpy(gUnknown_202DEA8 - 80, sStarBullet);
        else
            strcpy(gUnknown_202DEA8 - 80, sUnknown_80DBE18);

        xxx_format_and_draw(12, y, sFmt01, sUnknown_203B23C->s24.s0.unk34, 0);
    }

    sub_80073E0(sUnknown_203B23C->s24.s0.unk34);
}

bool8 HasNoAvailIQSkills(s16 species)
{
    s32 species_s32;
    u8 iqSkillBuffer[NUM_IQ_SKILLS];
    PokemonStruct1 *pokeStruct;

    species_s32 = species;
    pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];

    if (GetNumAvailableIQSkills(iqSkillBuffer, pokeStruct->IQ) == 0)
        return TRUE;

    return FALSE;
}

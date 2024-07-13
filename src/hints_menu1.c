#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "common_strings.h"
#include "hints_menu1.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"
#include "structs/struct_sub80095e4.h"

static EWRAM_DATA_2 struct_Sub80095E4 *sUnknown_203B264 = {0};

#include "data/hints_menu1.h"

static void DrawHintSelectionMenu(void);

static void sub_801E594(void);

bool8 sub_801E3F0(u32 a0)
{
    if (sUnknown_203B264 == NULL)
        sUnknown_203B264 = MemoryAlloc(sizeof(*sUnknown_203B264), 8);

    sUnknown_203B264->unk34 = a0;
    sUnknown_203B264->unk38 = &sUnknown_203B264->unk3C[a0];
    sub_8006518(sUnknown_203B264->unk3C);
    sUnknown_203B264->unk3C[sUnknown_203B264->unk34] = sUnknown_80DC0BC;
    sub_8012D08(sUnknown_203B264->unk38, 10);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B264->unk3C, TRUE, TRUE);
    sub_8013818(&sUnknown_203B264->input, 5, 10, a0);
    sub_801E594();
    DrawHintSelectionMenu();
    return TRUE;
}

u32 sub_801E474(bool8 a0)
{
    if (a0 == 0) {
        sub_8013660(&sUnknown_203B264->input);
        return 0;
    }

    switch(GetKeyPress(&sUnknown_203B264->input))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        case 4:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if(sub_80138B8(&sUnknown_203B264->input, 1))
            {
                sub_801E594();
                DrawHintSelectionMenu();
                return 1;
            }
            else
                return 0;
    }
}

s32 GetChosenHintIndex(void)
{
    return (sUnknown_203B264->input.unk1E * sUnknown_203B264->input.unk1C) + sUnknown_203B264->input.menuIndex;
}

void CreateHintSelectionScreen(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B264->unk3C, FALSE, FALSE);
    sub_8013984(&sUnknown_203B264->input);
    sub_801E594();
    DrawHintSelectionMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B264->input);
}

void sub_801E54C(void)
{
    if (sUnknown_203B264 != NULL) {
        sUnknown_203B264->unk3C[sUnknown_203B264->unk34] = sUnknown_80DC0A0;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B264->unk3C, TRUE, TRUE);
        MemoryFree(sUnknown_203B264);
        sUnknown_203B264 = NULL;
    }
}

static void sub_801E594(void)
{
    SUB_80095E4_CALL(*sUnknown_203B264);
}

static void DrawHintSelectionMenu(void)
{
    s32 hintIndex;
    s32 y;

    sub_8008C54(sUnknown_203B264->unk34);
    sub_80073B8(sUnknown_203B264->unk34);
    xxx_call_draw_string(16, 0, sHints, sUnknown_203B264->unk34, 0);

    for (hintIndex = 0; hintIndex < NUM_HINTS; hintIndex++) {
        y = sub_8013800(&sUnknown_203B264->input, hintIndex);
        xxx_call_draw_string(10, y, gCommonHints[hintIndex].heading, sUnknown_203B264->unk34, 0);
    }

    sub_80073E0(sUnknown_203B264->unk34);
}

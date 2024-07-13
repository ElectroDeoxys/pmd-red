#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "constants/input.h"
#include "event_flag.h"
#include "friend_area.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"
#include "wigglytuff_shop1.h"

static EWRAM_DATA_2 WigglytuffShop1Work *sWigglytuffShop1Work = {0};
static EWRAM_DATA_2 u32 sUnknown_203B284 = {0};
static EWRAM_DATA_2 u16 sUnknown_203B288 = {0};
static EWRAM_DATA_2 u16 sUnknown_203B28A = {0};

#include "data/wigglytuff_shop1.h"

static void sub_8021410(void);
static s32 sub_8021664(void);

bool8 sub_80211AC(u32 mode, u32 a1)
{
    if (sub_8021700(mode))
        return FALSE;

    sWigglytuffShop1Work = MemoryAlloc(sizeof(WigglytuffShop1Work), 8);
    sWigglytuffShop1Work->mode = mode;
    sWigglytuffShop1Work->s40.s0.unk34 = a1;
    sWigglytuffShop1Work->s40.s0.unk38 = &sWigglytuffShop1Work->s40.s0.unk3C[sWigglytuffShop1Work->s40.s0.unk34];
    sub_8006518(sWigglytuffShop1Work->s40.s0.unk3C);
    sWigglytuffShop1Work->s40.s0.unk3C[sWigglytuffShop1Work->s40.s0.unk34] = sUnknown_80DC47C;
    sWigglytuffShop1Work->s40.s0.unk38->unk14 = sWigglytuffShop1Work->s40.unk9C;
    ResetUnusedInputStruct();
    sub_800641C(sWigglytuffShop1Work->s40.s0.unk3C, TRUE, TRUE);
    sub_8013818(&sWigglytuffShop1Work->s40.s0.input, sub_8021664(), 10, a1);

    if (sUnknown_203B284 == sWigglytuffShop1Work->mode) {
        sWigglytuffShop1Work->s40.s0.input.menuIndex = sUnknown_203B288;
        sWigglytuffShop1Work->s40.s0.input.unk1E = sUnknown_203B28A;
        sub_8013984(&sWigglytuffShop1Work->s40.s0.input);
    }

    sub_8021410();
    sub_8021494();
    return TRUE;
}

u32 sub_8021274(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sWigglytuffShop1Work->s40.s0.input);
        return 0;
    }

    switch (GetKeyPress(&sWigglytuffShop1Work->s40.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            if (sWigglytuffShop1Work->mode == 2 && GetFriendAreaPrice(sub_802132C()) > gTeamInventoryRef->teamMoney)
                PlayMenuSoundEffect(2);
            else
                PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&sWigglytuffShop1Work->s40.s0.input, 1) != 0) {
                sub_8021410();
                sub_8021494();
                return 1;
            }
            return 0;
    }
}

u8 sub_802132C(void)
{
    return sWigglytuffShop1Work->friendAreas[(sWigglytuffShop1Work->s40.s0.input.unk1E * sWigglytuffShop1Work->s40.s0.input.unk1C) + sWigglytuffShop1Work->s40.s0.input.menuIndex];
}

void sub_8021354(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(sWigglytuffShop1Work->s40.s0.unk3C, FALSE, FALSE);
    sWigglytuffShop1Work->s40.s0.input.unk22 = sub_8021664();
    sub_8013984(&sWigglytuffShop1Work->s40.s0.input);
    sub_8021410();
    sub_8021494();

    if (cursorSprite)
        AddMenuCursorSprite(&sWigglytuffShop1Work->s40.s0.input);
}

void sub_80213A0(void)
{
    if (sWigglytuffShop1Work) {
        sUnknown_203B284 = sWigglytuffShop1Work->mode;
        sUnknown_203B288 = sWigglytuffShop1Work->s40.s0.input.menuIndex;
        sUnknown_203B28A = sWigglytuffShop1Work->s40.s0.input.unk1E;
        sWigglytuffShop1Work->s40.s0.unk3C[sWigglytuffShop1Work->s40.s0.unk34] = sUnknown_80DC464;
        ResetUnusedInputStruct();
        sub_800641C(sWigglytuffShop1Work->s40.s0.unk3C, TRUE, TRUE);
        MemoryFree(sWigglytuffShop1Work);
        sWigglytuffShop1Work = NULL;
    }
}

static void sub_8021410(void)
{
    sWigglytuffShop1Work->s40.unk9C[0] = 1;
    sWigglytuffShop1Work->s40.unk9C[1] = 0;
    sWigglytuffShop1Work->s40.unk9C[2] = 12;
    sWigglytuffShop1Work->s40.unk9C[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(sWigglytuffShop1Work->s40.s0.unk3C, TRUE, TRUE);

    SUB_80095E4_CALL(sWigglytuffShop1Work->s40.s0);
}

void sub_8021494(void)
{
    u8 friendAreaIndex;
    s32 i;
    u8 buffer1[80];
    u8 buffer2[80];

    sub_8008C54(sWigglytuffShop1Work->s40.s0.unk34);
    sub_80073B8(sWigglytuffShop1Work->s40.s0.unk34);
    xxx_call_draw_string(10, 0, sFriendAreas, sWigglytuffShop1Work->s40.s0.unk34, 0);

    sub_8012BC4((sWigglytuffShop1Work->s40.unk9C[2] * 8) + 4, 0, sWigglytuffShop1Work->s40.s0.input.unk1E + 1, 1, 7, sWigglytuffShop1Work->s40.s0.unk34);

    for (i = 0; i < sWigglytuffShop1Work->s40.s0.input.unk1A; i++) {
        friendAreaIndex = sWigglytuffShop1Work->friendAreas[(sWigglytuffShop1Work->s40.s0.input.unk1E * sWigglytuffShop1Work->s40.s0.input.unk1C) + i];

        if (sWigglytuffShop1Work->mode == 2) {
            sub_8092578(buffer1, friendAreaIndex, TRUE);

            if (GetFriendAreaPrice(friendAreaIndex) <= gTeamInventoryRef->teamMoney)
                xxx_call_draw_string(8,sub_8013800(&sWigglytuffShop1Work->s40.s0.input, i), buffer1, sWigglytuffShop1Work->s40.s0.unk34, 0);
            else {
                sprintfStatic(buffer2, sFmtRedString, buffer1);
                xxx_call_draw_string(8, sub_8013800(&sWigglytuffShop1Work->s40.s0.input, i), buffer2, sWigglytuffShop1Work->s40.s0.unk34, 0);
            }
        }
        else if (sWigglytuffShop1Work->mode == 0) {
            if (gFriendAreas[friendAreaIndex] == TRUE)
                xxx_call_draw_string(8, sub_8013800(&sWigglytuffShop1Work->s40.s0.input, i), GetFriendAreaName(friendAreaIndex), sWigglytuffShop1Work->s40.s0.unk34, 0);
            else {
                sprintfStatic(buffer2, sFmtGreenString, GetFriendAreaName(friendAreaIndex));
                xxx_call_draw_string(8, sub_8013800(&sWigglytuffShop1Work->s40.s0.input, i), buffer2, sWigglytuffShop1Work->s40.s0.unk34, 0);
            }
        }
        else
            xxx_call_draw_string(8, sub_8013800(&sWigglytuffShop1Work->s40.s0.input, i), GetFriendAreaName(friendAreaIndex), sWigglytuffShop1Work->s40.s0.unk34, 0);
    }

    sub_80073E0(sWigglytuffShop1Work->s40.s0.unk34);
}

static s32 sub_8021664(void)
{
    s32 i;
    s32 counter;

    counter = 0;

    switch (sWigglytuffShop1Work->mode) {
        case 0:
            for (i = BOUNTIFUL_SEA; i < NUM_FRIEND_AREAS; i++) {
                sWigglytuffShop1Work->friendAreas[counter] = i;
                counter++;
            }
            break;
        case 1:
            for (i = BOUNTIFUL_SEA; i < NUM_FRIEND_AREAS; i++) {
                if (gFriendAreas[i]) {
                    sWigglytuffShop1Work->friendAreas[counter] = i;
                    counter++;
                }
            }
            break;
        case 2:
            for (i = BOUNTIFUL_SEA; i < NUM_FRIEND_AREAS; i++) {
                if (gFriendAreas[i])
                    continue;

                switch (GetFriendAreaUnlockCondition(i)) {
                    case UNLOCK_SHOP_STORY:
                        sWigglytuffShop1Work->friendAreas[counter] = i;
                        counter++;
                        break;
                    case UNLOCK_SHOP_POST_GAME:
                        if (sub_80023E4(6)) {
                            sWigglytuffShop1Work->friendAreas[counter] = i;
                            counter++;
                        }
                        break;
                }
            }
            break;
    }

    return counter;
}

bool8 sub_8021700(u32 kind)
{
    s32 i;

    switch (kind) {
        case 0:
            return FALSE;
        case 1:
            for (i = BOUNTIFUL_SEA; i < NUM_FRIEND_AREAS; i++) {
                if (gFriendAreas[i])
                    return FALSE;
            }
            break;
        case 2:
            for (i = BOUNTIFUL_SEA; i < NUM_FRIEND_AREAS; i++) {
                if (gFriendAreas[i])
                    continue;

                switch (GetFriendAreaUnlockCondition(i)) {
                    case UNLOCK_SHOP_STORY:
                        return FALSE;
                    case UNLOCK_SHOP_POST_GAME:
                        if (sub_80023E4(6))
                            return FALSE;
                        break;
                }
            }
            break;
    }

    return TRUE;
}

#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_80958E8.h"
#include "constants/input.h"
#include "input.h"
#include "pokemon_mail.h"
#include "pokemon_news1.h"
#include "pokemon_news2.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B2CC *sUnknown_203B2CC = {0};
static EWRAM_DATA_2 u16 sUnknown_203B2D0 = {0};
static EWRAM_DATA_2 u16 sUnknown_203B2D2 = {0};

#include "data/pokemon_news1.h"

static void CreatePKMNNewsMenu(void);
static s32 GetNumPKMNNews(void);

static void sub_802B880(void);

bool8 sub_802B640(u32 a0, UnkTextStruct2_sub *a1, u32 a2)
{
    if (HasNoPKMNNews())
        return FALSE;

    if (sUnknown_203B2CC == NULL)
        sUnknown_203B2CC = MemoryAlloc(sizeof(struct unkStruct_203B2CC), 8);

    sUnknown_203B2CC->s38.unk34 = a0;
    sUnknown_203B2CC->s38.unk38 = &sUnknown_203B2CC->s38.unk3C[a0];

    sub_8006518(sUnknown_203B2CC->s38.unk3C);

    sUnknown_203B2CC->s38.unk3C[sUnknown_203B2CC->s38.unk34] = sUnknown_80DFBEC;

    if (a1 != NULL)
        sUnknown_203B2CC->s38.unk3C[sUnknown_203B2CC->s38.unk34].unk8 = *a1;

    sub_8012D08(sUnknown_203B2CC->s38.unk38, a2);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2CC->s38.unk3C, TRUE, TRUE);

    sub_8013818(&sUnknown_203B2CC->s38.input, GetNumPKMNNews(), a2, a0);

    sUnknown_203B2CC->s38.input.menuIndex = sUnknown_203B2D0;
    sUnknown_203B2CC->s38.input.unk1E = sUnknown_203B2D2;

    sub_8013984(&sUnknown_203B2CC->s38.input);
    sub_802B880();
    CreatePKMNNewsMenu();

    return TRUE;
}

u32 sub_802B720(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2CC->s38.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2CC->s38.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
    }

    if (sub_80138B8(&sUnknown_203B2CC->s38.input, 1)) {
        sub_802B880();
        CreatePKMNNewsMenu();
        return 1;
    }
    return 0;
}

u8 GetPokemonNewsIndex(void)
{
    return sUnknown_203B2CC->receivedNewsletters[(sUnknown_203B2CC->s38.input.unk1E * sUnknown_203B2CC->s38.input.unk1C) + sUnknown_203B2CC->s38.input.menuIndex];
}

void sub_802B7D0(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2CC->s38.unk3C, FALSE, FALSE);

    sUnknown_203B2CC->s38.input.unk22 = GetNumPKMNNews();
    sub_8013984(&sUnknown_203B2CC->s38.input);
    sub_802B880();
    CreatePKMNNewsMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2CC->s38.input);
}

void sub_802B81C(void)
{
    if (sUnknown_203B2CC != NULL) {
        sUnknown_203B2D0 = sUnknown_203B2CC->s38.input.menuIndex;

        sUnknown_203B2D2 = sUnknown_203B2CC->s38.input.unk1E;

        sUnknown_203B2CC->s38.unk3C[sUnknown_203B2CC->s38.unk34] = sUnknown_80DFBD0;

        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B2CC->s38.unk3C, TRUE, TRUE);

        MemoryFree(sUnknown_203B2CC);
        sUnknown_203B2CC = NULL;
    }
}

static void sub_802B880(void)
{
    SUB_80095E4_CALL(sUnknown_203B2CC->s38);
}

static void CreatePKMNNewsMenu(void)
{
    s32 index;
    s32 y;
    s32 new_index;
    u8 mailIndex;

    sub_8008C54(sUnknown_203B2CC->s38.unk34);
    sub_80073B8(sUnknown_203B2CC->s38.unk34);
    xxx_call_draw_string(10, 0, sNewsList, sUnknown_203B2CC->s38.unk34, 0);

    sub_8012BC4((sUnknown_80DFBE8.f2 * 8) + 4, 0, sUnknown_203B2CC->s38.input.unk1E + 1, 2, 7, sUnknown_203B2CC->s38.unk34);

    for (index = 0; index < sUnknown_203B2CC->s38.input.unk1A; index++) {
        y = sub_8013800(&sUnknown_203B2CC->s38.input, index);
        new_index = (sUnknown_203B2CC->s38.input.unk1E * sUnknown_203B2CC->s38.input.unk1C) + index;
        mailIndex = sUnknown_203B2CC->receivedNewsletters[new_index];
        sub_803B6B0(10, y, 6, sUnknown_203B2CC->s38.unk34);
        sub_802BC7C();
        xxx_format_and_draw(21, y, GetPokemonMailHeadline(mailIndex), sUnknown_203B2CC->s38.unk34, 0);
    }

    sub_80073E0(sUnknown_203B2CC->s38.unk34);
}

static s32 GetNumPKMNNews(void)
{
    s32 i;
    s32 newsCount;

    newsCount = 0;

    for (i = 0; i < NUM_POKEMON_NEWS; i++) {
        if (CheckPKMNNewsSlot(i)) {
            sUnknown_203B2CC->receivedNewsletters[newsCount] = i;
            newsCount++;
        }
    }

    return newsCount;
}

bool8 HasNoPKMNNews(void)
{
    s32 i;

    for (i = 0; i < NUM_POKEMON_NEWS; i++) {
        if (CheckPKMNNewsSlot(i))
            return FALSE;
    }

    return TRUE;
}

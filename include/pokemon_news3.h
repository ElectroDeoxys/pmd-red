#ifndef GUARD_POKEMON_NEWS3_H
#define GUARD_POKEMON_NEWS3_H

#include "structs/menu.h"
#include "structs/struct_sub80095e4.h"

// size: 0xA4
struct unkStruct_203B2D8
{
    u8 unk0[4];
    /* 0x4 */ struct_Sub80095E4_2 unk4;
};

void CreateMailMenu(void);
bool8 HasNoMailinMailbox(void);

bool8 sub_802BD14(s32, UnkTextStruct2_sub *, u32);
u32 sub_802BDEC(bool8);
u8 sub_802BE74(void);
void sub_802BE94(bool8 cursorSprite);
void sub_802BEDC(void);

#endif // GUARD_POKEMON_NEWS3_H

#ifndef GUARD_CODE_801D014_H
#define GUARD_CODE_801D014_H

#include "menu.h"
#include "pokemon.h"
#include "structs/str_text.h"

// size: 0x118
struct unk_203B250
{
    /* 0x0 */ PokemonStruct1 *pokeStruct;
    /* 0x4 */ s16 index;
    /* 0x6 */ u8 currFriendAreaLocation; // 0 when not in a friend area
    u8 unk7;
    u8 unk8;
    u8 unk9;
    PokemonStruct1 *unkC;
    /* 0x10 */ u32 state;
    /* 0x14 */ u32 menuAction;
    MenuStruct unk18;
    MenuItem unk68[8];
    u16 unkA8[8];
    UnkTextStruct2 unkB8[4];
};

// size: 0x8
struct TeamBadgeData
{
    /* 0x0 */ u8 *pics; // probably a pointer to an arrays of pixels?
    /* 0x4 */ u8 *pallete; // Pics share common pallete
};

bool8 sub_801D014(PokemonStruct1 *);
u32 sub_801D0DC(void);
u32 sub_801D178(void);
u8 sub_801D1D4(void);
void sub_801D1E0(void);

#endif // GUARD_CODE_801D014_H
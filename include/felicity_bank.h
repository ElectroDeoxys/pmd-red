#ifndef GUARD_FELICITY_BANK_H
#define GUARD_FELICITY_BANK_H

#include "file_system.h"
#include "text.h"
#include "menu.h"

// size: 0x108
struct FelicityBankWork
{
    u32 isAsleep;
    s32 currState;
    u32 fallbackState;
    u32 chosenAmount;
    u32 menuAction;
    struct MenuItem unk14[8];
    u16 unk54[8];
    u32 unk64;
    u8 fill68[0x78 - 0x68];
    u32 unk78;
    u8 fill7C[0x94 - 0x7C];
    /* 0x94 */ struct OpenedFile *faceFile;
    /* 0x98 */ u8 *faceData;
    u16 unk9C;
    u16 unk9E;
    u8 unkA0;
    u8 unkA1;
    u8 unkA2;
    u8 unkA3;
    struct OpenedFile **unkA4;
    struct UnkTextStruct2 unkA8[4];
};

#endif

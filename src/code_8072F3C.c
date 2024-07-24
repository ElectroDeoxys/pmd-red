#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "code_80118A4.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"
#include "structs/struct_sub80095e4.h"


struct unkStruct_203B314
{
    // size: 0x15C
    s16 unk0[2];
    u8 fill4[0x5C - 0x4];
    u8 unk5C[2];
    u8 fill5E[0x8A - 0x5E];
    u8 unk8A[2];
    u8 unk8C[0xB8 - 0x8C];
    u8 unkB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    struct struct_Sub80095E4_2 sBC;
};

EWRAM_DATA_2 struct unkStruct_203B314 *gUnknown_203B314 = {0};

const UnkTextStruct2 gUnknown_80E06FC = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80E0714 = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x0E, 0x0E,
    0x0E, 0x00,
    NULL
};
const UnkTextStruct2 gUnknown_80E072C = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x10, 0x10,
    0x10, 0x00,
    NULL
};

ALIGNED(4) const u8 gUnknown_80E0744[] = "Dungeons";
ALIGNED(4) const u8 gUnknown_80E0750[] =  {0x83, 0xC2};
ALIGNED(4) const u8 gUnknown_80E0754[] = {0x83, 0xC0};

void sub_802F9C0(void);
void sub_802FA50(void);
const u8 *sub_80974A0(s16 index);
extern bool8 sub_802FCF0(u32);
extern s32 sub_802FBF4(void);

u32 sub_802F73C(u32 r0, UnkTextStruct2_sub *r1, u32 r2, u8 r3)
{
    if (sub_802FCF0(r0))
        return 0;

    if (gUnknown_203B314 == NULL)
        gUnknown_203B314 = MemoryAlloc(sizeof(struct unkStruct_203B314), 8);

    gUnknown_203B314->unkB8 = r3;
    gUnknown_203B314->sBC.s0.unk34 = r0;
    gUnknown_203B314->sBC.s0.unk38 = &gUnknown_203B314->sBC.s0.unk3C[gUnknown_203B314->sBC.s0.unk34];
    sub_8006518(gUnknown_203B314->sBC.s0.unk3C);

    if (r3 != 0)
        gUnknown_203B314->sBC.s0.unk3C[gUnknown_203B314->sBC.s0.unk34] = gUnknown_80E072C;
    else
        gUnknown_203B314->sBC.s0.unk3C[gUnknown_203B314->sBC.s0.unk34] = gUnknown_80E0714;

    gUnknown_203B314->sBC.s0.unk38->unk14 = &gUnknown_203B314->sBC.unk9C;

    if (r1 != 0)
        gUnknown_203B314->sBC.s0.unk3C[gUnknown_203B314->sBC.s0.unk34].unk8 = *r1;

    sub_8012D08(gUnknown_203B314->sBC.s0.unk38, r2);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B314->sBC.s0.unk3C, TRUE, TRUE);
    sub_8013818(&gUnknown_203B314->sBC.s0.input, sub_802FBF4(), r2, r0);
    sub_802F9C0();
    sub_802FA50();
    return 1;
}

u32 sub_802F848(s16 param_1)
{
    int index;
    s32 param_1_32;

    param_1_32 = param_1; // cast needed

    for( index = 0; index < gUnknown_203B314->sBC.s0.input.unk22; index++ ) {
        if (gUnknown_203B314->unk0[index] == param_1_32) {
            sub_8013878(&gUnknown_203B314->sBC.s0.input,index);
            sub_802F9C0();
            sub_802FA50();
            return 1;
        }
    }
    sub_8013878(&gUnknown_203B314->sBC.s0.input,0);
    return 0;
}

u32 sub_802F8A0(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B314->sBC.s0.input);
        return 0;
    }
    else
    {
        switch(GetKeyPress(&gUnknown_203B314->sBC.s0.input))
        {
            case INPUT_B_BUTTON:
                PlayMenuSoundEffect(1);
                return 2;
            case INPUT_A_BUTTON:
                PlayMenuSoundEffect(0);
                return 3;
            default:
                if(sub_80138B8(&gUnknown_203B314->sBC.s0.input, 1) != 0)
                {
                    sub_802F9C0();
                    sub_802FA50();
                    return 1;
                }
                else
                {
                    return 0;
                }
        }
    }
}

s16 sub_802F90C(void)
{
    return gUnknown_203B314->unk0[(gUnknown_203B314->sBC.s0.input.unk1E * gUnknown_203B314->sBC.s0.input.unk1C) + gUnknown_203B314->sBC.s0.input.menuIndex];
}

void sub_802F938(u8 r0)
{
    gUnknown_203B314->sBC.s0.input.unk22 = sub_802FBF4();
    sub_8013984(&gUnknown_203B314->sBC.s0.input);
    sub_802F9C0();
    sub_802FA50();

    if(r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B314->sBC.s0.input);
}

void sub_802F974(void)
{
    if(gUnknown_203B314 != NULL)
    {
        gUnknown_203B314->sBC.s0.unk3C[gUnknown_203B314->sBC.s0.unk34] = gUnknown_80E06FC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B314->sBC.s0.unk3C, TRUE, TRUE);
        MemoryFree(gUnknown_203B314);
        gUnknown_203B314 = NULL;
    }
}

void sub_802F9C0(void)
{
    gUnknown_203B314->sBC.unk9C.f0 = 1;
    gUnknown_203B314->sBC.unk9C.f1 = 0;
    gUnknown_203B314->sBC.unk9C.f2 = 8;
    gUnknown_203B314->sBC.unk9C.f3 = 0;

    SUB_80095E4_CALL(gUnknown_203B314->sBC.s0);
}

void sub_802FA50(void)
{
  s32 sVar1;
  const u8 *text;
  u32 y;
  u32 y2;
  int index;
  int counter;

  sub_8008C54(gUnknown_203B314->sBC.s0.unk34);
  sub_80073B8(gUnknown_203B314->sBC.s0.unk34);
  xxx_call_draw_string(10,0,gUnknown_80E0744,gUnknown_203B314->sBC.s0.unk34,0);
  sub_8012BC4(gUnknown_203B314->sBC.unk9C.f2 * 8 + 4,0,gUnknown_203B314->sBC.s0.input.unk1E + 1,2,7,gUnknown_203B314->sBC.s0.unk34);
  if (gUnknown_203B314->unkB8 != 0) {
    for(counter = 0; counter < gUnknown_203B314->sBC.s0.input.unk1A; counter++)
    {
        y = sub_8013800(&gUnknown_203B314->sBC.s0.input,counter);
        index = gUnknown_203B314->sBC.s0.input.unk1E * gUnknown_203B314->sBC.s0.input.unk1C + counter;
        sVar1 = gUnknown_203B314->unk0[index];
        if (gUnknown_203B314->unk5C[index] != 0) {
            xxx_call_draw_string(10,y,gUnknown_80E0750,gUnknown_203B314->sBC.s0.unk34,0);
        }
        else if (gUnknown_203B314->unk8A[index] != 0) {
            xxx_call_draw_string(10,y,gUnknown_80E0754,gUnknown_203B314->sBC.s0.unk34,0);
        }
        xxx_call_draw_string(0x18,y,sub_80974A0(sVar1),gUnknown_203B314->sBC.s0.unk34,0);
    }
  }
  else {
    for(counter = 0; counter < gUnknown_203B314->sBC.s0.input.unk1A; counter++)
    {
        y2 = sub_8013800(&gUnknown_203B314->sBC.s0.input,counter);
        text = sub_80974A0(gUnknown_203B314->unk0[gUnknown_203B314->sBC.s0.input.unk1E * gUnknown_203B314->sBC.s0.input.unk1C + counter]);
        xxx_call_draw_string(8,y2,text,gUnknown_203B314->sBC.s0.unk34,0);
    }
  }
  sub_80073E0(gUnknown_203B314->sBC.s0.unk34);
}

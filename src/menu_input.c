#include "global.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "text1.h"
#include "text2.h"
#include "util.h"
#include "code_800D090.h"
#include "menu_input.h"
#include "code_80130A8.h"
#include "sprite.h"

extern u8 gUnknown_80D4828[];

extern void PlayMenuSoundEffect(u32);
extern s32 sub_8008ED0(const u8 *);
void sub_8012EBC(struct MenuStruct *param_1);
extern void sub_8013134(struct MenuInputStruct *, u32, u32);
extern s16 sub_8009614(u32, u32);
extern u32 ReturnIntFromChar2(u8);
extern void nullsub_7(u16 *);
void sub_8013470(struct MenuInputStruct *);
void sub_801332C(s16 *);

const u32 gDefaultMenuTextColors[] = { COLOR_WHITE_2, COLOR_RED, COLOR_RED };

u32 sub_8012A64(struct MenuInputStructSub *r0, s32 r1)
{
    if(r0 == NULL)
    {
        return sub_8012AE8();
    }
    if(r1 != -1)
    {
        nullsub_34(r0);
    }
    if(r0->a_button != 0)
    {
        r0->a_button = 0;
        return INPUT_A_BUTTON;
    }
    else if(r0->b_button == 0)
    {
        return sub_8012AE8();
    }
    else
    {
        r0->b_button = 0;
        return INPUT_B_BUTTON;
    }
}

s32 GetKeyPress(struct MenuInputStruct *r0)
{
    if(r0 != NULL)
    {
        if(r0->unk28.a_button != 0)
        {
            return INPUT_A_BUTTON;
        }
        if(r0->unk28.b_button != 0)
        {
            return INPUT_B_BUTTON;
        }
        if(r0->unk28.dpad_left != 0)
        {
            return INPUT_DPAD_LEFT;
        }
        if(r0->unk28.dpad_right != 0)
        {
            return INPUT_DPAD_RIGHT;
        }
    }
    return sub_8012AE8();
}

s32 sub_8012AE8(void)
{
  if ((gRealInputs.held & R_BUTTON) != 0) {
    if ((gRealInputs.pressed & A_BUTTON) != 0) {
        return INPUT_R_A_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_UP) != 0) {
        return INPUT_R_DPAD_UP_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_DOWN) != 0) {
        return INPUT_R_DPAD_DOWN_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_LEFT) != 0) {
        return INPUT_R_DPAD_LEFT_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_RIGHT) != 0) {
        return INPUT_R_DPAD_RIGHT_BUTTONS;
    }
    if ((gRealInputs.repeated & R_BUTTON) != 0) {
        return INPUT_R_BUTTON;
    }
  }
  else
  {
    if ((gRealInputs.pressed & A_BUTTON) != 0) {
        return INPUT_A_BUTTON;
    }
    if ((gRealInputs.pressed & B_BUTTON) != 0) {
        return INPUT_B_BUTTON;
    }
    if ((gRealInputs.pressed & SELECT_BUTTON) != 0) {
        return INPUT_SELECT_BUTTON;
    }
    if ((gRealInputs.pressed & START_BUTTON) != 0) {
        return INPUT_START_BUTTON;
    }
    if ((gRealInputs.repeated & DPAD_UP) != 0) {
        return INPUT_DPAD_UP;
    }
    if ((gRealInputs.repeated & DPAD_DOWN) != 0) {
        return INPUT_DPAD_DOWN;
    }
    if ((gRealInputs.repeated & DPAD_LEFT) != 0) {
        return INPUT_DPAD_LEFT;
    }
    if ((gRealInputs.repeated & DPAD_RIGHT) != 0) {
        return INPUT_DPAD_RIGHT;
    }
    if ((gRealInputs.repeated & L_BUTTON) != 0) {
        return INPUT_L_BUTTON;
    }
  }
  return INPUT_NONE;
}

void sub_8012BC4(u32 x, u32 y, s32 n, s32 len, u32 color, u32 param_6)
{
  s32 iVar1;
  u32 uVar2;
  struct unkChar *iVar3;
  s32 counter;
  s32 *piVar3;
  s32 *piVar4;
  s32 total_x;
  s32 decimal [8];
  
  total_x = 0;
  ConvertToDecimal(decimal,n,len);
  counter = len - 1;
  if (0 < counter) {
    piVar3 = &decimal[counter];
    if(*piVar3 == 0)
    {
        do  {
          *piVar3 = 0xff;
          piVar3--;
          counter--;
          if (counter <= 0) break;
        } while(*piVar3 == 0);
    }
  }
    
  counter = 0;
  if ((counter < len) && (decimal[0] != 0xFF)) {
    piVar4 = &decimal[0];
    do {
      iVar1 = *piVar4;
      piVar4++;
      uVar2 = ReturnIntFromChar2(iVar1 + 0x30);
      iVar3 = GetCharacter(uVar2);
      total_x += iVar3->unk6;
      xxx_call_draw_char(x - total_x,y,uVar2,color,param_6);
      counter++;
      if (counter >= len) {
        break;
      }
    } while (*piVar4 != 0xff);
  }
}

void sub_8012C60(u32 x,u32 y,u32 param_3,u32 color,u32 param_5)
{
  u32 add_x;
  struct unkChar *iVar3;
  u32 uVar2;
  
  uVar2 = ReturnIntFromChar2(param_3);
  iVar3 = GetCharacter(uVar2);
  if (iVar3->unk6 < 0xc) {
    add_x = ((0xc - iVar3->unk6) / 2);
  }
  else {
    add_x = 0;
  }
  xxx_call_draw_char(x + add_x,y,uVar2,color,param_5);
}

void sub_8012CAC(struct UnkTextStruct2 *param_1, const struct MenuItem *param_2)
{
  s16 length;
  int r5;
  int r6;
  int r7;
  s32 iVar4;
#ifndef NONMATCHING
  register s32 r0 asm("r0");
#else
  s32 r0;
#endif
  
  r7 = 0;
  r6 = 0;
  if (param_2->text != NULL) {
    r5 = 0x10000;
    r0 = r5;
    do {
      r0 = r5;
      r5 = r5 + 0x10000;
      r7 = r0 >> 0x10;
      length = sub_8008ED0(param_2->text);
      if (length > r6) {
        r6 = length;
      }
      param_2++;
    } while (param_2->text != NULL);
  }
  if (r6 < 0)
    iVar4 = r6 + 7;
  else
    iVar4 = r6;
  param_1->unkC = (iVar4 >> 3) + 2;
  sub_8012D08(param_1, r7);
}

NAKED
void sub_8012D08(struct UnkTextStruct2 *param_1, s32 param_2)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tadds r0, r1, 0\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tldr r0, [r4, 0x4]\n"
	"\tcmp r0, 0x6\n"
	"\tbne _08012D24\n"
	"\tadds r0, r1, 0x2\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
"_08012D24:\n"
	"\tlsls r0, r1, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r4, 0xE]\n"
	"\tstrh r0, [r4, 0x10]\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}

// https://decomp.me/scratch/QadfW  (200 - 90% matched)  - Seth
NAKED
void sub_8012D34(struct UnkTextStruct2 *param_1, s32 param_2)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tadds r0, r1, 0\n"
	"\tmovs r1, 0x18\n"
	"\tbl sub_8009614\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tldr r0, [r4, 0x4]\n"
	"\tcmp r0, 0x6\n"
	"\tbne _08012D50\n"
	"\tadds r0, r1, 0x2\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
"_08012D50:\n"
	"\tlsls r0, r1, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r4, 0xE]\n"
	"\tstrh r0, [r4, 0x10]\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}

void sub_8012D60(struct MenuStruct *param_1,const struct MenuItem *menuItems,u32 *colorArray,u16 *param_4,s32 menuAction,
                s32 index)
{
  const u8 *textPtr;
  s32 counter;
  s32 menuIndex;
  s32 iVar1;
  
  counter = 0;
  menuIndex = -1;
  iVar1 = 0;
  param_1->index = index;
  param_1->menuItems = menuItems;
  param_1->menuTextColorArray = colorArray;
  if (colorArray == NULL) {
    param_1->menuTextColorArray = gDefaultMenuTextColors;
  }
  param_1->unkC = param_4;
  textPtr = menuItems->text;
  if(textPtr)
  {
      while (textPtr != 0) {
        if ((0 <= menuAction) && (menuAction == menuItems->menuAction)) {
          menuIndex = counter;
        }
        if (*menuItems->text == '*') {
          iVar1 = counter;
        }
        menuItems++;
        counter++;
        textPtr = menuItems->text;
      }
  }
  if (menuIndex < 0) {
    menuIndex = iVar1;
  }
  sub_8013134(&param_1->input,counter,index);
  param_1->input.menuIndex = menuIndex;
  sub_80137B0(&param_1->input,0);
  param_1->unk4C = TRUE;
  param_1->unk4D = TRUE;
  param_1->unk4E = TRUE;
  param_1->menuAction = -1;
}

void sub_8012E04(struct MenuStruct *param_1,const struct MenuItem *menuItems,u32 *colorArray,u16 *param_4,s32 menuAction,
                s32 index)
{
  const u8 *textPtr;
  s32 counter;
  const struct MenuItem *menuItemPtr;
  s32 iVar1;
  s32 menuIndex;
  
  counter = 0;
  menuIndex = -1;
  iVar1 = 0;
  textPtr = menuItems->text;
  if (textPtr) {
    menuItemPtr = menuItems;
    while (textPtr != NULL) {
      if ((0 <= menuAction) && (menuAction == menuItemPtr->menuAction)) {
        menuIndex = counter;
      }
      if (*menuItemPtr->text == '*') {
        iVar1 = counter;
      }
      menuItemPtr++;
      counter++;
      textPtr = menuItemPtr->text;
    }
  }
    
  if (menuIndex < 0) {
    menuIndex = iVar1;
  }
  sub_8013134(&param_1->input,counter,index);
  param_1->input.menuIndex = menuIndex;
  sub_80137B0(&param_1->input,0);
  param_1->index = index;
  param_1->menuTextColorArray = colorArray;
  if (colorArray == NULL) {
    param_1->menuTextColorArray = gDefaultMenuTextColors;
  }
  param_1->unkC = param_4;
  param_1->menuItems = menuItems;
  param_1->unk4E = FALSE;
  param_1->unk4C = TRUE;
  param_1->unk4D = TRUE;
  param_1->menuAction = -1;
}

void sub_8012EA4(struct MenuStruct *param_1, bool8 r1)
{
    param_1->unk4C = r1;
    param_1->unk4D = TRUE;
    sub_8012EBC(param_1);
}

void sub_8012EBC(struct MenuStruct *param_1)
{
  s32 x;
  s32 y;
  u32 color;
  const u8 *textPtr;
  const struct MenuItem *menuItemsPtr;
  u16 *_puVar2;
  const u32 *colorArray;
  s32 counter;
  s32 index;
  struct UnkTextStruct2 textStack[4];
  u8 buffer [256];
  struct UnkTextStruct1 *ptr_text;
  struct UnkTextStruct2 *ptr_text2;
  
  if (param_1->unk4D) {
    sub_80073B8(param_1->index);
    index = param_1->index;
    ptr_text = &gUnknown_2027370[index];
    if ((ptr_text->unkC) == 6) {
      ptr_text2 = &textStack[index];
      sub_8006518(textStack);
      x = sub_8008ED0(param_1->unk0);
      xxx_format_and_draw((((ptr_text2->unk14[2]) * 8 - x) /2) + 8,
          0,param_1->unk0, param_1->index, 0);
    }
    colorArray = param_1->menuTextColorArray;
    menuItemsPtr = param_1->menuItems;
    _puVar2 = param_1->unkC;
    counter = 0;
    if (menuItemsPtr->text != NULL) {
      do {
        textPtr = menuItemsPtr->text;
        if (*textPtr == '*') {
          textPtr++;
        }
        if (_puVar2 != NULL) {
            color = colorArray[*_puVar2];
            _puVar2++;
        }
        else if (menuItemsPtr->menuAction < 0) {
            // Color the action red
            color = colorArray[1];
        }
        else {
            // Use the default white
            color = colorArray[0];
        }
        sprintfStatic(buffer,gUnknown_80D4828,color,textPtr);
        y = sub_8013800(&param_1->input,counter);
        xxx_format_and_draw(8,y,buffer,param_1->index,0);
        menuItemsPtr++;
        counter++;
      } while (menuItemsPtr->text != NULL);
    }
    sub_80073E0(param_1->index);
    param_1->unk4D = FALSE;
  }
  if (param_1->unk4E) {
    if (param_1->unk4C) {
      AddMenuCursorSprite(&param_1->input);
    }
    else {
      sub_8013660(&param_1->input);
    }
  }
}

bool8 sub_8012FD8(struct MenuStruct *param_1)
{
  u32 prevMenuIndex;
  s32 index;
  const struct MenuItem *item;
  
  prevMenuIndex = param_1->input.menuIndex;
  if (param_1->unk4C) {
    switch(GetKeyPress(&param_1->input))
    {
        case INPUT_DPAD_DOWN:
            MoveMenuCursorDown(&param_1->input);
            if (prevMenuIndex != param_1->input.menuIndex) {
                PlayMenuSoundEffect(3);
            }
            break;
        case INPUT_DPAD_UP:
            MoveMenuCursorUp(&param_1->input);
            if (prevMenuIndex != param_1->input.menuIndex) {
                PlayMenuSoundEffect(3);
            }
            break;
        case INPUT_A_BUTTON:
            index = sub_80137A8(&param_1->input);
            item = &param_1->menuItems[index];
            if ((-1 < item->menuAction) &&
               ((param_1->unkC == NULL || (param_1->unkC[index] != 1)))) {
              param_1->menuAction = item->menuAction;
              ++param_1; --param_1;
              param_1->unk4C = FALSE;
              param_1->input.unk24 = 0;
            }
            else
            {
                PlayMenuSoundEffect(2);
                break;
            }
            if ((param_1->unkC != NULL) && (param_1->unkC[index] == 2)) {
                PlayMenuSoundEffect(2);
            }
            else
                PlayMenuSoundEffect(0);
            break;
        case INPUT_B_BUTTON:
            if (-1 < param_1->menuItems[param_1->input.unk1A].menuAction) {
                param_1->menuAction = param_1->menuItems[param_1->input.unk1A].menuAction;
                param_1->unk4C = FALSE;
                PlayMenuSoundEffect(1);
            }
            break;
    }
  }
  sub_8012EBC(param_1);
  return param_1->unk4C;
}

bool8 sub_80130A8(struct MenuStruct *param_1)
{
  s32 index;
  s32 menuAction;
  const struct MenuItem *menuItem;
  
  if (param_1->unk4C) {

    switch(GetKeyPress(&param_1->input))
    {
        case INPUT_A_BUTTON:
            index = sub_80137A8(&param_1->input);
            menuItem = &param_1->menuItems[index];
            param_1->menuAction = menuItem->menuAction;
            param_1->unk4C = FALSE;
            param_1->input.unk24 = 0;
            PlayMenuSoundEffect(0);
            break;
        case INPUT_B_BUTTON:
            if(menuAction = param_1->menuItems[param_1->input.unk1A].menuAction, -1 < menuAction) {
              param_1->menuAction = menuAction;
              param_1->unk4C = FALSE;
              PlayMenuSoundEffect(0);
            }
            break;
    }
  }
  sub_8012EBC(param_1);
  return param_1->unk4C;
}

bool8 sub_8013114(struct MenuStruct *param_1, s32 *menuAction)
{
    if(param_1->unk4C){
        return TRUE;
    }
    if (menuAction != NULL){
        *menuAction = param_1->menuAction;
    }
    return FALSE;
}

void sub_8013134(struct MenuInputStruct *param_1, u32 menuItemCounter, u32 index) {

    struct UnkTextStruct1 *temp;

    temp = &gUnknown_2027370[index];
    
    param_1->unk0 = index;
    param_1->menuIndex = 0;
    param_1->unk1A = menuItemCounter;
    param_1->unk1C = menuItemCounter;
    param_1->unk1E = 0;
    param_1->unk4 = 0;

    if(temp->unkC == 6)
    {
        param_1->unk6 = 0x10;
    }
    else
    {
        param_1->unk6 = 0x2;
    }


    param_1->unkC = 0;
    param_1->unkE = 0;
    param_1->unk14 = 0;
    param_1->unk24 = 0;
    sub_801317C(&param_1->unk28);
}

void sub_801317C(struct MenuInputStructSub *param_1)
{
    param_1->unk0 = 0;
    param_1->a_button = 0;
    param_1->b_button = 0;
    param_1->dpad_left = 0;
    param_1->dpad_right = 0;
    param_1->unk8 = -1;
    param_1->unkA = -1;
    nullsub_7(&param_1->unk8);
    ResetUnusedInputStruct();
}

void AddMenuCursorSprite(struct MenuInputStruct *param_1)
{
    AddMenuCursorSprite_(param_1, 0);
}

void AddMenuCursorSprite_(struct MenuInputStruct *a0, u32 a1)
{
    struct SpriteOAM sp = {};
    struct SpriteOAM* ptr;
    s32 value;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r5;

    if (a0->unk1A > 0) {
        UpdateMenuCursorSpriteCoords(a0);

        if (!(a0->unk24 & 8)) {
            register u32 tmp asm("r0"), tmp2 asm("r1"), r4;

            tmp = sp.atrib1;
            sp.atrib1 = tmp & ~SPRITEOAM_MASK_AFFINEMODE1;
            sp.atrib1 = sp.atrib1;

            tmp2 = sp.atrib1;
            sp.atrib1 = tmp2 & ~SPRITEOAM_MASK_AFFINEMODE2;
            sp.atrib1 = sp.atrib1;

            tmp2 = sp.atrib1;
            tmp = r4 = (u16)~SPRITEOAM_MASK_OBJMODE;
            sp.atrib1 = tmp & tmp2;
            sp.atrib1 = sp.atrib1;

            tmp2 = sp.atrib1;
            sp.atrib1 = tmp2 & ~SPRITEOAM_MASK_MOSAIC;
            sp.atrib1 = sp.atrib1;

            tmp2 = sp.atrib1;
            sp.atrib1 = tmp2 & ~SPRITEOAM_MASK_BPP;
            sp.atrib1 = sp.atrib1;

            tmp2 = sp.atrib1;
            sp.atrib1 = tmp2 & ~SPRITEOAM_MASK_SHAPE;
            sp.atrib1 = sp.atrib1;

            ptr = &sp;

            r2 = 0x3F4 << SPRITEOAM_SHIFT_TILENUM;
            ptr->atrib3 &= ~SPRITEOAM_MASK_TILENUM;
            ptr->atrib3 |= r2;

            ptr->atrib3 &= r4; // ~SPRITEOAM_MASK_PRIORITY

            r5 = (u16)~SPRITEOAM_MASK_UNK6_4;

            r1 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
            ptr->atrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
            ptr->atrib3 |= r1;

            ptr->unk6 &= ~SPRITEOAM_MASK_UNK6_0;
            ptr->unk6 &= ~SPRITEOAM_MASK_UNK6_1;

            r0 = a0->unk8;
            r0 &= SPRITEOAM_MAX_X;
            ptr->atrib2 = r0;

            value = ((a0->unkA + 1) & SPRITEOAM_MAX_UNK6_4) << SPRITEOAM_SHIFT_UNK6_4;
            ptr->unk6 &= r5;
            ptr->unk6 |= value;

            AddSprite(&sp, 0xFF, 0, 0);
        }
    }

    sub_8013470(a0);
    if (a0->unk14 != 0)
        sub_801332C(&a0->unk14);

    a0->unk24++;
}

void nullsub_34(struct MenuInputStructSub *a0)
{
}
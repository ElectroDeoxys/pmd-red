#include "global.h"
#include "debug.h"
#include "ground_link.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "ground_map.h"
#include "dungeon.h"
#include "other_random.h"
#include "rescue_team_info.h"
#include "code_80118A4.h"

#ifndef NONMATCHING
#define GROUND_SCRIPT_INCOMPLETE_DECLARATIONS
#endif

#include "ground_main.h"
#include "code_80A26CC.h"

typedef struct {
    u8 xTiles;
    u8 xFlags;
    u8 yTiles;
    u8 yFlags;
} PosInfo;
typedef struct GroundObjectData {
    u8 kind;
    u8 unk1;
    u8 widthTiles;
    u8 heightTiles;
    PosInfo pos;
    ScriptCommand *scripts[4]; // 2 - dialogue script
} GroundObjectData;
typedef struct GroundEffectData {
    u8 kind;
    u8 unk1;
    u8 widthTiles; //???
    u8 heightTiles;
    PosInfo pos;
    ScriptCommand *script;
} GroundEffectData;

void GroundMap_Select(s16);
void GroundMap_SelectDungeon(s16, DungeonLocation*, u8);
void GroundMap_ExecuteEnter(s16);
void GroundMap_ExecuteEvent(s16, bool8);
void GroundMap_GetStationScript(ScriptInfoSmall *out, s16, s32, s32);
void GroundMap_ExecuteStation(s32, s32, s32, bool8);
void GroundLives_ExecuteScript(s32, s16 *, ScriptInfoSmall *);
void GroundObject_ExecuteScript(s32, s16 *, ScriptInfoSmall *);
void GroundEffect_ExecuteScript(s32, s16 *, ScriptInfoSmall *);
void GroundLives_Select(s16, s32 group, s32 sector);
void GroundObject_Select(s16, s32 group, s32 sector);
void GroundEffect_Select(s16, s32 group, s32 sector);
void GroundEvent_Select(s16, s32 group, s32 sector);
void GroundLives_Cancel(s32 group, s32 sector);
void GroundObject_Cancel(s32 group, s32 sector);
void GroundEffect_Cancel(s32 group, s32 sector);
void GroundEvent_Cancel(s32 group, s32 sector);
void GroundLives_CancelBlank_1(void);
void GroundObject_CancelBlank(void);
void GroundEffect_CancelBlank(void);
void GroundWeather_Select(s16);
u32 GroundLives_ExecutePlayerScriptActionLives();
s16 GroundObject_Add(s16 id, GroundObjectData*, s16 group, s8 sector);
s16 GroundEffect_Add(s16 id, GroundEffectData*, s16 group, s8 sector);
void FatalError(void* loc, char* fmt, ...) __attribute__((noreturn));

// Beware of the declarations without specified arguments, returning u32 or s32, these were quickly hacked in to get the code to compile and link
// The return values are almost certainly NOT correct and will need to be rechecked when moving to header files
u32 FlagCalc();
u32 FlagJudge();
s32 sub_8001658(ScriptUnion832*, s32);
void sub_8001570(u8*, s16);
void sub_80015C0(u8*, s16);
u32 sub_8001784(ScriptUnion832*, s16, u16);
void sub_80018D8(s32, s32, s32);
void sub_800199C(u8*, s16, u32, s32);
u32 sub_8001AB0();
void sub_8001B88(s16, s32*, s32*);
u32 ScenarioCalc(s16, s32, s32);
u32 sub_8001CC4();
u32 sub_8001D08();
u32 sub_8001D44();
void sub_800226C(u8*, s16, s32, u8);
void sub_80022A0(u8*, s16, s32, u8);
u32 sub_80022F8();
u32 sub_8002318();
u32 sub_80023E4();
u32 sub_80026CC();
void sub_80026E8(s16, bool8);
char sub_8002984(s32, u8);
u32 sub_8002C60();
u32 sub_8002D54();
u8 sub_8002DF0(Position32*, Position32*, Position32*, Position32*);
s32 sub_8009FB8();

// TODO: move to code_80118A4.h
u32 StopAllMusic_1();
u32 xxx_call_start_new_bgm();
u32 xxx_call_queue_bgm();
u32 xxx_call_play_fanfare_se();
u32 xxx_call_fade_out_fanfare_se();

bool8 sub_8021700(s32);
bool8 sub_802FCF0(void);


s32 FindItemInInventory();
u32 ShiftItemsDownFrom();
void sub_809733C(s16, bool8);
void sub_80973A8(s16, bool8);
void sub_8097418(s16, bool8);
void sub_80975A8(s16, bool8);
void sub_80976F8(u8);
u32 sub_8098100();
void sub_8098D1C(s32, u32, s32);
void sub_8098D80(s32);
void sub_8098E18(s32, s32);
u32 sub_80999E8();
u32 sub_80999FC();
u32 sub_8099A10();
u32 sub_8099A34();
u32 sub_8099A48();
u32 sub_8099A5C();
u32 sub_8099AFC();
u32 sub_809A6E4();
u32 sub_809A6F8();
u32 sub_809A738();
u32 sub_809A768();
bool8 ScriptPrintNullTextbox(void);
bool8 ScriptPrintEmptyTextbox(void);
u32 sub_809A83C();
u32 sub_809AC7C();
u32 sub_809ADD8();
bool8 ScriptPrintText(s32, s16, char*);
bool8 sub_809AEEC(char*);
bool8 sub_809AF2C(char*);
bool8 sub_809AF6C(s16, char*);
void sub_809AFC8(bool8, s32, s32, char*);
u32 sub_809B028();
bool8 sub_809B1C0(s32, s32, char[12]);
void sub_809B1D4(u8, s32, s32, char*);
void sub_809C770(s16, s16);
s32 sub_809CBA4(u8);
u32 sub_809CC90();
void sub_809D0BC(void);
void sub_809D124(s32, s32, s32);
void sub_809D158(s32, Position32*);
void sub_809D170(s32, s32);
void sub_809D190(s32, Position32*, s32);
void sub_809D1A8(s32, s32, s32);
void sub_809D1CC(s32, Position32*, s32);
void sub_809D1E4(s32, s32, s32);
void sub_809D208(s32, Position32*, s32);
void sub_809D220(s32, s32, s32);
u32 sub_809D52C();
u32 InitScriptData();
void sub_809D710(Action*, ScriptInfoSmall*, s16);
u8 sub_809D8EC(Action*, s16);
bool8 sub_809D940(void);
void sub_809D9B8(s16);
bool8 sub_809DA08(Action*, s16, u8);
s16 sub_80A4D7C(s32);
s16 sub_80A7AE8(s16);
void sub_80A87AC(s32, s32);
void sub_80A8BD8(s16, s32*);
u32 sub_80A8C2C();
u32 sub_80A8C98();
char *sub_80A8D54(s16);
s16 sub_80A8FD8(s32, Position32*);
s16 sub_80A8F9C(s32, Position32*);
u32 sub_80A9050();
u32 sub_80A9090();
s16 sub_80AC448(s16, Position32*);
s32 sub_80AC49C(s16, Position32*);
s16 sub_80AD360(s16, Position32*);
s16 sub_80AD3B4(s16, Position32*);
u32 sub_80AD8B4();
u32 sub_80AD914();
void DeleteBlankGroundEvents(void);
void DeleteBlankGroundLives(void);
void DeleteBlankGroundObjects(void);
void DeleteBlankGroundEffects(void);

extern int gFormatData_202DE30[10];

extern s16 gCurrentMap;
extern s16 gUnknown_2039A32;
extern s16 gUnknown_2039A34;

extern struct { char *unk0; s32 unk4; } gUnknown_2039D50[9];
extern char gUnknown_2039D98[12];
extern int gUnknown_203B4AC;

extern FunctionScript gFunctionScriptTable[];

extern Position32 gUnknown_81164DC;
extern char gUnknown_81165D4[];
extern char gUnknown_81165F4[];
extern char gUnknown_811660C[];
extern char gUnknown_8116628[];
extern char gUnknown_8116644[];
extern char gUnknown_8116664[];
extern char gUnknown_8116684[];
extern char gUnknown_81166C0[];
extern char gUnknown_81166D8[];


extern DebugLocation gUnknown_81166B4;

// Return values:
// This function returns what's likely an enum, which controls the state of the script engine state machine, and possibly provides information to code calling the engine.
// The enum is shared at least with HandleAction.
// This value is saved into the state field of the Action when returned from this function.
// - Value 0 indicates a RET on script engine level, HandleAction copies action->scriptData2 onto action->scriptData, and reinitializes scriptData2.
//     If there is no active scriptData2 it clears and reinits scriptData.
//     Ultimately returns code 3 to the script engine caller.
//     Caveat: If the scripting engine is in state 0, HandleAction will immediately return 0 without performing any work.
// - Value 1 is a terminal state (script success? error?), no further scripting progress will happen. This code is always returned to the caller from now on.
// - Value 2 gives control back to the HandleAction function (entry point into the scripting engine state machine)
//     This is the only return value that does not return to the script engine caller
// - Value 3 returns to the caller, but will give control back to ExecuteScriptCommand when reentering the script ("script not finished")
// - Value 4 is some kind of fatal error state, no further scripting progress will happen. This code is always returned to the caller from now on.
s32 ExecuteScriptCommand(Action *action) {
    ScriptCommand curCmd;
    ScriptData *scriptData = &action->scriptData;

    while (1) {
        scriptData->curPtr = scriptData->script.ptr;
        curCmd = *scriptData->script.ptr++;
        switch (scriptData->curScriptOp = curCmd.op) {
            case 0x01: {
                u32 arg = (s16)curCmd.arg1;
                u32 argCopy = arg;
                u32 byte = (u8)curCmd.argByte;
                if (ScriptLoggingEnabled(TRUE)) {
                    // "    ground select %3d[%s] %3d"
                    Log(1, gUnknown_81165D4, arg, gGroundConversion_811BAF4[arg].text, byte);
                }
                GroundMainGroundRequest(argCopy, byte, curCmd.argShort);
                break;
            }
            case 0x02: {
                s32 arg = (s16)curCmd.arg1;
                if (arg == -1) arg = (s16)sub_8001658(0, 19);
                if (ScriptLoggingEnabled(TRUE)) {
                    // "    dungeon select %3d"
                    Log(1, gUnknown_81165F4, arg);
                }
                if (arg != -1) {
                    GroundMainRescueRequest(arg, curCmd.argShort);
                    action->scriptData.script.ptr = sub_80A2460(action, 1);
                } else {
                    action->scriptData.script.ptr = sub_80A2460(action, 0);
                }
                break;
            }
            case 0x03: {
                if ((s8)sub_8021700(curCmd.arg1)) {
                    action->scriptData.script.ptr = sub_80A2460(action, -1);
                } else {
                    sub_8098D80(curCmd.argShort);
                    action->scriptData.script.ptr = sub_80A2460(action, 0);
                }
                break;
            }
            case 0x04: {
                if (curCmd.arg1 == -1) {
                    if (!(u8)sub_802FCF0() && (u8)sub_809B1C0(12,0,0)) {
                        sub_80A87AC(0, 11);
                        action->scriptData.branchDiscriminant = 0;
                    } else {
                        action->scriptData.branchDiscriminant = -1;
                    }
                    return 2; // do action
                } else {
                    sub_80018D8(0, 18, sub_80A26B8((s16)curCmd.arg1));
                    action->scriptData.branchDiscriminant = 1;
                    return 2; // do action
                }
                break;
            }
            case 0x06: {
                if (curCmd.arg1 == -1) {
                    if ((s8)sub_809B1C0(36, 0, 0)) {
                        sub_80A87AC(0, 11);
                        action->scriptData.branchDiscriminant = 0;
                        return 2;
                    } else {
                        action->scriptData.branchDiscriminant = -1;
                        return 2;
                    }
                } else {
                    sub_80018D8(0, 19, curCmd.arg1);
                    action->scriptData.branchDiscriminant = 1;
                    return 2;
                }
            }
            case 0x05: {
                action->scriptData.branchDiscriminant = 1;
                return 2;
            }
            case 0x07: {
                s32 tmp = (s16)curCmd.arg1;
                if (tmp == -1) {
                    tmp = (s16)sub_8001658(0, 19);
                } else {
                    sub_80018D8(0, 19, tmp);
                }
                if (ScriptLoggingEnabled(TRUE)) {
                    Log(1, gUnknown_811660C, tmp);
                }
                if (tmp != -1) {
                    action->scriptData.branchDiscriminant = 1;
                    return 2;
                } else {
                    action->scriptData.branchDiscriminant = -1;
                    return 2;
                }
            }
            case 0x08: case 0x09: {
                if (curCmd.op == 0x08) {
                    gCurrentMap = curCmd.arg1;
                    gUnknown_2039A32 = sub_80A4D7C((s16)curCmd.arg1);
                    gUnknown_2039A34 = gUnknown_2039A32;
                    if (ScriptLoggingEnabled(TRUE)) {
                        // "    map select %3d %3d[%s]"
                        Log(1,gUnknown_8116628,gCurrentMap,gUnknown_2039A32,
                            gGroundConversion_811BAF4[gCurrentMap].text);
                    }
                } else {
                    gUnknown_2039A32 = gCurrentMap = curCmd.arg1;
                    gUnknown_2039A34 = curCmd.arg1;
                    if (ScriptLoggingEnabled(TRUE)) {
                        // "    ground select %3d %3d[%s]"
                        Log(1,gUnknown_8116644,gCurrentMap,gUnknown_2039A32,
                            gGroundConversion_811BAF4[gCurrentMap].text);
                    }
                }
                sub_80018D8(0,0x10,gCurrentMap);
                sub_80018D8(0,0x11,gGroundConversion_811BAF4[gCurrentMap].unk2);
                GroundSprite_Reset(gUnknown_2039A32);
                sub_809D0BC();
                DeleteBlankGroundEvents();
                DeleteBlankGroundLives();
                DeleteBlankGroundObjects();
                DeleteBlankGroundEffects();
                sub_809C770(gCurrentMap, gGroundConversion_811BAF4[gCurrentMap].unk2);
                GroundMap_Select(gUnknown_2039A32);
                GroundLink_Select(gUnknown_2039A32);
                GroundLives_Select(gUnknown_2039A32,0,0);
                GroundObject_Select(gUnknown_2039A32,0,0);
                break;
            }
            case 0x0a: {
                const DungeonInfo *tmp;
                DungeonLocation loc;
                tmp = sub_80A2608((s16)curCmd.arg1);
                gUnknown_2039A34 = gUnknown_2039A32 = gCurrentMap = (s16)curCmd.arg2;
                if (ScriptLoggingEnabled(TRUE)) {
                    // "    dungeon select %3d %3d[%s]"
                    Log(1, gUnknown_8116664, gCurrentMap,gUnknown_2039A32,
                        gGroundConversion_811BAF4[gCurrentMap].text);
                }
                GroundSprite_Reset(gUnknown_2039A32);
                sub_809D0BC();
                DeleteBlankGroundEvents();
                DeleteBlankGroundLives();
                DeleteBlankGroundObjects();
                DeleteBlankGroundEffects();
                loc.id = tmp->dungeonIndex;
                loc.floor = curCmd.argShort;
                GroundMap_SelectDungeon(gUnknown_2039A32, &loc, curCmd.argByte);
                GroundLink_Select(gUnknown_2039A32);
                GroundLives_Select(gUnknown_2039A32,0,0);
                GroundObject_Select(gUnknown_2039A32,0,0);
                break;
            }
            case 0x0b: {
                GroundWeather_Select((s16)curCmd.arg1);
                break;
            }
            case 0x0c ... 0x15: {
                s32 group;
                s32 sector;
                {
                    s32 tmp = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    group = tmp;
                }
                {
                    s32 tmp = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    sector = tmp;
                }
                switch (curCmd.op) {
                    case 0x0c: {
                        GroundLives_Select(gUnknown_2039A32, group, sector);
                        GroundObject_Select(gUnknown_2039A32, group, sector);
                        GroundEffect_Select(gUnknown_2039A32, group, sector);
                        GroundEvent_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x0d: {
                        GroundLives_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x0e: {
                        GroundObject_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x0f: {
                        GroundEffect_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x10: {
                        GroundEvent_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x11: {
                        GroundLives_Cancel(group, sector);
                        GroundObject_Cancel(group, sector);
                        GroundEffect_Cancel(group, sector);
                        GroundEvent_Cancel(group, sector);
                        break;
                    }
                    case 0x12: {
                        GroundLives_Cancel(group, sector);
                        break;
                    }
                    case 0x13: {
                        GroundObject_Cancel(group, sector);
                        break;
                    }
                    case 0x14: {
                        GroundEffect_Cancel(group, sector);
                        break;
                    }
                    case 0x15: {
                        GroundEvent_Cancel(group, sector);
                        break;
                    }
                }
                break;
            }
            case 0x16: {
                GroundLives_CancelBlank_1();
                break;
            }
            case 0x17: {
                GroundObject_CancelBlank();
                break;
            }
            case 0x18: {
                GroundEffect_CancelBlank();
                break;
            }
            case 0x19: {
                s8 unk[4];
                GroundObjectData *obj;
                Position32 pos;
                s16 res;
                s32 group;
                s32 sector;
                action->callbacks->func14(action->parentObject, unk);
                obj = ({ GroundObjectData obj = {
                    .unk1 = *unk,
                    .widthTiles = 1,
                    .heightTiles = 1,
                    .pos = {},
                    .kind = curCmd.arg2,
                    .scripts = { [3] = gFunctionScriptTable[curCmd.arg1].script },
                    };
                    group = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    sector = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    &obj;
                });
                res = GroundObject_Add(-1, obj, group, sector);
                if (res >= 0) {
                    action->callbacks->func0C(action->parentObject, &pos);
                    sub_80AC49C(res, &pos);
                }
                break;
            }
            case 0x1a: {
                s8 unk;
                GroundEffectData *eff;
                Position32 pos;
                s16 res;
                s32 group;
                s32 sector;
                action->callbacks->func14(action->parentObject, &unk);
                eff = ({ GroundEffectData eff = {
                    .unk1 = unk,
                    .widthTiles = 1,
                    .heightTiles = 1,
                    .pos = {},
                    .kind = curCmd.arg2,
                    .script = gFunctionScriptTable[curCmd.arg1].script,
                    };
                    group = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    sector = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    &eff;
                });
                res = GroundEffect_Add(-1, eff, group, sector);
                if (res >= 0) {
                    action->callbacks->func0C(action->parentObject, &pos);
                    sub_80AD3B4(res, &pos);
                }
                break;
            }
            case 0x1c: {
                GroundMap_ExecuteEvent(curCmd.argShort, 1);
                break;
            }
            case 0x1b: {
                GroundMap_ExecuteEvent(curCmd.argShort, 0);
                break;
            }
            case 0x1d: case 0x1e: {
                s32 map;
                s32 group, sector;
                bool8 res;
                {
                    s32 tmp = curCmd.arg1 != -1 ? (s16)curCmd.arg1 : gCurrentMap;
                    map = tmp;
                }
                {
                    s32 tmp = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    group = tmp;
                }
                {
                    s32 tmp = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    sector = tmp;
                }
                map = sub_80A4D7C(map);
                res = curCmd.op == 0x1e;
                GroundMap_ExecuteStation(map, group, sector, res);
                if (gUnknown_2039A34 != map) {
                    gUnknown_2039A34 = map;
                    sub_809D940();
                    if (action->unk8[0] != 0)
                        return 4; // Fatal?
                }
                break;
            }
            case 0x1f: {
                s32 a = (s16)sub_8001658(0, 19);
                const DungeonInfo *ret1 = sub_80A2608(a);
                s32 thing = sub_8001784(0, 48, a) == 0 ? ret1->unk6 : ret1->unk8;
                // fakematch: this is almost certainly a range check of the form 0x37 <= a && a < 0x48
                // but that loses the s32 -> u16 cast. Inlines, macros, or other schenanigans are likely involved
                if (!((u16)(a - 0x37) < 0x11) && (s16)sub_80A2750(a) == 1) {
                    if (thing == -1) {
                        if (ScriptLoggingEnabled(TRUE)) {
                            // "    dungeon rescue select %3d"
                            Log(1, gUnknown_8116684, a);
                        }
                        GroundMainRescueRequest(a, -1);
                    } else {
                        GroundMap_ExecuteEvent(thing, 0);
                        break;
                    }
                } else {
                    GroundMainRescueRequest(a, -1);
                }
                break;
            }
            case 0x20: {
                switch (action->unkC.arr[0]) {
                    case 0:
                        GroundMap_ExecuteEvent(curCmd.argShort, 0);
                        break;
                    case 1: {
                        ScriptInfoSmall info1;
                        sub_809D710(action, &info1, curCmd.argShort);
                        GroundLives_ExecuteScript(action->unkC.arr[1], action->unk8, &info1);
                        break;
                    }
                    case 2: {
                        ScriptInfoSmall info2;
                        sub_809D710(action, &info2, curCmd.argShort);
                        GroundObject_ExecuteScript(action->unkC.arr[1], action->unk8, &info2);
                        break;
                    }
                    case 3: {
                        ScriptInfoSmall info3;
                        sub_809D710(action, &info3, curCmd.argShort);
                        GroundEffect_ExecuteScript(action->unkC.arr[1], action->unk8, &info3);
                        break;
                    }
                }
                break;
            }
            case 0x21: {
                s32 ret;
                s32 unk;
                Position32 pos1;
                Position32 pos2;
                Position32 pos3;
                Position32 pos4;
                s32 tmp;
                ret = (s16)sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    sub_80A8BD8(ret, &unk);
                    if (unk & 0x200) {
                        action->callbacks->func0C(action->parentObject, &pos1);
                        action->callbacks->func08(action->parentObject, &pos2);
                        sub_80A8FD8(ret, &pos3);
                        sub_80A8F9C(ret, &pos4);
                        if ((tmp = (s8)sub_8002DF0(&pos3, &pos4, &pos1, &pos2)) != -1 ||
                            (tmp = (s8)sub_8002D54(&pos1, &gUnknown_81164DC, &pos3, &gUnknown_81164DC)) != -1) {
                            sub_80A9090(ret, tmp);
                        }
                    }
                    GroundLives_ExecutePlayerScriptActionLives(action->unk8[1], ret);
                    return 3;
                }
                break;
            }
            case 0x22: {
                sub_80999E8(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x23: {
                sub_80999FC(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x24: {
                sub_8099A10(curCmd.argShort, (u16)curCmd.arg1, (u16)curCmd.arg2);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x25: {
                sub_8099A34(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x26: {
                sub_8099A48(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x27: case 0x28: {
                // THANK YOU pidgey, only an array *inside* a struct works
                // TODO: Define this struct globally, so it can be passed to sub_8099A5C and sub_8099AFC
                // This kind of hackiness is used at all callsites (or they load from a global)
                s32 color = ({
                    struct color { u8 arr[4]; } color = {{
                        curCmd.arg2 >> 16,
                        curCmd.arg2 >> 8,
                        curCmd.arg2,
                        0,
                    }};
                    *(s32*)&color;
                });
                switch (curCmd.op) {
                    case 0x27:
                        sub_8099A5C(curCmd.argShort, curCmd.arg1, color);
                        break;
                    case 0x28:
                        sub_8099AFC(curCmd.argShort, curCmd.arg1, color);
                        break;
                }
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x29: {
                sub_809A6E4((u16)curCmd.argShort);
                break;
            }
            case 0x2a: {
                sub_809A6F8((u16)curCmd.argShort);
                break;
            }
            case 0x2b: {
                sub_809A738(curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0x2c: {
                if (!(s8)sub_809A768()) break;
                sub_80A87AC(0, 10);
                if ((s8)sub_809D8EC(action, 0)) return 2;
                break;
            }
            case 0x30: {
                ScriptPrintNullTextbox();
                break;
            }
            case 0x31: {
                ScriptPrintEmptyTextbox();
                break;
            }
            case 0x2d: {
                switch ((u8)curCmd.argByte) {
                    case 0: {
                        sub_809A83C(curCmd.argShort);
                        break;
                    }
                    case 1: {
                        sub_80A2500(curCmd.argShort, action->unk8);
                        break;
                    }
                    case 2: {
                        sub_80A2500(curCmd.argShort, action->unkC.arr);
                        break;
                    }
                    case 3: {
                        struct {s16 unk0; s16 unk2;} unk;
                        unk.unk2 = sub_80A7AE8((s16)curCmd.arg1);
                        unk.unk0 = 1;
                        sub_80A2500(curCmd.argShort, (void*)&unk);
                        break;
                    }
                    case 4: {
                        sub_80A252C(curCmd.argShort, action->unk8);
                        break;
                    }
                    case 5: {
                        sub_80A252C(curCmd.argShort, action->unkC.arr);
                        break;
                    }
                    case 6: {
                        struct {s16 unk0; s16 unk2;} unk;
                        s16 res = sub_80A7AE8((s16)curCmd.arg1);
                        unk.unk2 = res;
                        if (unk.unk2 >= 0) {
                            unk.unk0 = 1;
                            sub_80A252C(curCmd.argShort, (void*)&unk);
                        } else {
                            sub_80A2584(curCmd.argShort, (s16)curCmd.arg1);
                        }
                        break;
                    }
                    case 7: {
                        sub_80A2558(curCmd.argShort, action->unk8);
                        break;
                    }
                    case 8: {
                        sub_80A2558(curCmd.argShort, action->unkC.arr);
                        break;
                    }
                    case 9: {
                        struct {s16 unk0; s16 unk2;} unk;
                        s16 res = sub_80A7AE8((s16)curCmd.arg1);
                        unk.unk2 = res;
                        if (unk.unk2 >= 0) {
                            unk.unk0 = 1;
                            sub_80A2558(curCmd.argShort, (void*)&unk);
                        } else {
                            sub_80A2598(curCmd.argShort, (s16)curCmd.arg1);
                        }
                        break;
                    }
                    case 10: {
                        u8 a = sub_80A2740((s16)curCmd.arg1);
                        s32 o = 0;
                        switch ((s16)curCmd.arg1) {
                            case 0: o = 1; break;
                            case 2: o = -1; break;
                        }
                        gFormatData_202DE30[curCmd.argShort] = GetDungeonFloorCount(a) + o;
                        break;
                    }
                }
                break;
            }
            case 0x2e: {
                sub_809AC7C(curCmd.argShort, (s8)curCmd.arg1, (u8)curCmd.argByte);
                break;
            }
            case 0x2f: {
                s32 unk[2];
                unk[0] = curCmd.arg1;
                unk[1] = curCmd.arg2;
                sub_809ADD8(curCmd.argShort, unk);
                break;
            }
            case 0x32 ... 0x38: {
                s8 ret = 0;
                switch (scriptData->curScriptOp) {
                    case 0x32: ret = ScriptPrintText(0, curCmd.argShort, curCmd.argPtr); break;
                    case 0x33: ret = ScriptPrintText(1, curCmd.argShort, curCmd.argPtr); break;
                    case 0x34: ret = ScriptPrintText(2, curCmd.argShort, curCmd.argPtr); break;
                    case 0x35: ret = ScriptPrintText(3, curCmd.argShort, curCmd.argPtr); break;
                    case 0x36: ret = ScriptPrintText(4, curCmd.argShort, curCmd.argPtr); break;
                    case 0x37: ret = sub_809AEEC(curCmd.argPtr); break;
                    case 0x38: ret = sub_809AF2C(curCmd.argPtr); break;
                }
                if (ret) {
                    sub_80A87AC(0, 10);
                    if ((s8)sub_809D8EC(action, 0)) return 2;
                }
                break;
            }
            case 0x39: {
                if ((s8)sub_809AF6C(curCmd.argShort, curCmd.argPtr) && curCmd.argShort >= 0) {
                    sub_80A87AC(0, 10);
                    if ((s8)sub_809D8EC(action, 0)) return 2;
                }
                break;
            }
            case 0x3a: {
                sub_809AFC8((u8)curCmd.argByte > 0, curCmd.arg1, (s16)curCmd.arg2, curCmd.argPtr);
                if ((s8)sub_809D8EC(action, 1)) {
                    sub_80A87AC(0, 11);
                    return 2;
                }
                break;
            }
            case 0x3c: {
                sub_809B1D4(curCmd.argByte, curCmd.arg1, curCmd.arg2, curCmd.argPtr);
                sub_80A87AC(0, 11);
                return 2;
            }
            case 0x3b: {
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x3d: {
                struct { u8 pad[0x4c]; u8 unk4C[10]; } *unk; // unknown struct
                int i;
                if ((s16)curCmd.arg1 != -1) {
                    unk = (void*)sub_80A8D54(curCmd.arg1);
                    if (unk) {
                        for (i = 0; i < 10; i++) {
                            gUnknown_2039D98[i] = unk->unk4C[i];
                        }
                        gUnknown_2039D98[10] = 0;
                        sub_809B1C0(4, 0, gUnknown_2039D98);
                        sub_80A87AC(0, 11);
                        return 2;
                    }
                    break;
                } else {
                    sub_809B1C0(4, 1, gUnknown_2039D98);
                    sub_80A87AC(0, 11);
                    return 2;
                }
            }
            case 0x3e: {
                sub_80920B8(gUnknown_2039D98);
                gUnknown_2039D98[10] = 0;
                sub_809B1C0(5, 0, gUnknown_2039D98);
                sub_80A87AC(0, 11);
                return 2;
            }
            case 0x3f: {
                int i;
                for (i = 0; i < 12; i++) {
                    gUnknown_2039D98[i] = 0;
                }
                sub_809B1C0(6, (u8)curCmd.argByte, gUnknown_2039D98);
                sub_80A87AC(0, 11);
                return 2;
            }
            case 0x42: {
                StopAllMusic_1();
                break;
            }
            case 0x43: {
                FadeOutAllMusic(curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case 0x44: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999) {
                    xxx_call_start_new_bgm((u16)id);
                } else {
                    xxx_call_stop_bgm();
                }
                break;
            }
            case 0x45: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999) {
                    xxx_call_fade_in_new_bgm((u16)id, (u16)curCmd.argShort); //sub_8011900
                } else {
                    xxx_call_stop_bgm();
                }
                break;
            }
            case 0x46: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999) {
                    xxx_call_queue_bgm((u16)id);
                }
                break;
            }
            case 0x47: {
                xxx_call_stop_bgm();
                break;
            }
            case 0x48: {
                xxx_call_fade_out_bgm(curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case 0x49: case 0x4c: {
                xxx_call_play_fanfare_se((u16)curCmd.arg1, 256);
                break;
            }
            case 0x4a: case 0x4d: {
                xxx_call_stop_fanfare_se((u16)curCmd.arg1);
                break;
            }
            case 0x4b: case 0x4e: {
                xxx_call_fade_out_fanfare_se((u16)curCmd.arg1, curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case 0x4f: {
                if (action->scriptData2.state == 1) {
                    InitScriptData(&action->scriptData2);
                }
                action->callbacks->func1C(action->parentObject, 0);
                break;
            }
            case 0x50: {
                Action *ptr;
                Position32 pos;
                s8 c;
                {
                    Action *tmp = (Action*)sub_809D52C(action->unkC.arr);
                    ptr = tmp;
                }
                if (ptr) {
                    ptr->callbacks->func0C(action->parentObject, &pos);
                    ptr->callbacks->func14(action->parentObject, &c);
                    action->callbacks->func24(action->parentObject, &pos);
                    action->scriptData.unk26 = c;
                    action->callbacks->func2C(action->parentObject, c);
                }
                break;
            }
            case 0x51: {
                Position32 posIn;
                Position32 posOut1;
                Position32 posOut2;
                action->callbacks->func0C(action->parentObject, &posIn);
                sub_80AD914(curCmd.argShort, &posOut1, &posOut2, &posIn);
                action->callbacks->func20(action->parentObject, &posOut1, &posOut2);
                break;
            }
            case 0x52: {
                action->callbacks->func3C(action->parentObject, curCmd.arg1);
                break;
            }
            case 0x53: {
                if (curCmd.arg1 & 0x400 && action->scriptData2.state == 1) {
                    InitScriptData(&action->scriptData2);
                }
                action->callbacks->func40(action->parentObject, curCmd.arg1);
                break;
            }
            case 0x54: {
                action->callbacks->func14(action->parentObject, &action->scriptData.unk26);
                if (curCmd.argShort) {
                    action->scriptData.unk24 = curCmd.argShort;
                }
                action->callbacks->func30(action->parentObject, (u16)curCmd.argShort);
                break;
            }
            case 0x55: {
                action->callbacks->func34(action->parentObject, (u16)curCmd.argShort);
                break;
            }
            case 0x56: {
                action->callbacks->func38(action->parentObject, (s16)curCmd.arg1, curCmd.argShort);
                break;
            }
            case 0x57: {
                action->callbacks->func44(action->parentObject, curCmd.argShort);
                break;
            }
            case 0x58: {
                u32 unk[2];
                unk[0] = curCmd.arg1 << 8;
                unk[1] = curCmd.arg2 << 8;
                action->callbacks->func24(action->parentObject, unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x59: {
                u32 unk[2];
                unk[0] = curCmd.argShort << 8;
                unk[1] = curCmd.arg1 << 8;
                action->callbacks->func48(action->parentObject, unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5a: {
                u32 unk[2];
                unk[0] = OtherRandInt(curCmd.argShort) << 8;
                unk[1] = OtherRandInt(curCmd.arg1) << 8;
                action->callbacks->func48(action->parentObject, unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5b: {
                Position32 unk;
                action->callbacks->func0C(action->parentObject, &unk);
                sub_80AD8B4((s16)curCmd.arg1, &unk);
                action->callbacks->func24(action->parentObject, &unk); // landing end of unwanted tailmerge
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5c: {
                Position32 pos, pos1, pos2;
                action->callbacks->func0C(action->parentObject, &pos);
                sub_80AD914((s16)curCmd.arg1, &pos1, &pos2, &pos);
                pos.x = pos1.x + OtherRandInt(pos2.x - pos1.x);
                pos.y = pos1.y + OtherRandInt(pos2.y - pos1.y);
                action->callbacks->func24(action->parentObject, &pos);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5d: {
                Position32 unk;
                s16 res = sub_80A7AE8((s16)curCmd.arg1);
                if (res >= 0) {
                    sub_80A8FD8(res, &unk);
                    action->callbacks->func24(action->parentObject, &unk);
                    scriptData->unk2A = (u8)curCmd.argByte;
                    return 2;
                }
                break;
            }
            case 0x5e: {
                Position32 pos;
                s32 height;
                s32 dir;
                pos.x = sub_8001784(0, 0x32, (u16)curCmd.arg1); // POSITION_X
                pos.y = sub_8001784(0, 0x33, (u16)curCmd.arg1); // POSITION_Y
                height = sub_8001784(0, 0x34, (u16)curCmd.arg1); // POSITION_HEIGHT
                dir = (s8)sub_8001784(0, 0x35, (u16)curCmd.arg1); // POSITION_DIRECTION
                action->callbacks->func24(action->parentObject, &pos);
                action->callbacks->func28(action->parentObject, height);
                action->scriptData.unk26 = dir;
                action->callbacks->func2C(action->parentObject, dir);
                // NONMATCHING: unwanted tailmerge
#ifndef NONNMATCHING
                asm("");
#endif
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5f: {
                Position32 pos;
                u32 height;
                u32 wat;
                s8 dir;
                action->callbacks->func0C(action->parentObject, &pos);
                action->callbacks->func10(action->parentObject, &height, &wat);
                action->callbacks->func14(action->parentObject, &dir);
                sub_800199C(0, 0x32, (u16)curCmd.arg1, pos.x);
                sub_800199C(0, 0x33, (u16)curCmd.arg1, pos.y);
                sub_800199C(0, 0x34, (u16)curCmd.arg1, height);
                sub_800199C(0, 0x35, (u16)curCmd.arg1, dir);
                break;
            }
            case 0x60: {
                action->callbacks->func28(action->parentObject, curCmd.arg1 << 8);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x61: case 0x69: {
                scriptData->pos2.x = curCmd.arg1 << 8;
                scriptData->pos2.y = curCmd.arg2 << 8;
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x62: case 0x6a: {
                u32 pos[2];
                action->callbacks->func0C(action->parentObject, pos);
                scriptData->pos2.x = pos[0] + (curCmd.arg1 << 8);
                scriptData->pos2.y = pos[1] + (curCmd.arg2 << 8);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x63: case 0x6b: {
                action->callbacks->func0C(action->parentObject, &scriptData->pos2);
                sub_80AD8B4((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x64: case 0x6c: {
                action->callbacks->func0C(action->parentObject, &scriptData->pos2);
                sub_80AD8B4((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x65: case 0x6d: {
                action->callbacks->func0C(action->parentObject, &scriptData->pos2);
                sub_80AD8B4((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = OtherRandInt((u8)curCmd.argByte);
                return 2;
            }
            case 0x66: case 0x67: case 0x6e: case 0x6f: {
                s16 ret = sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    sub_80A8FD8(ret, &scriptData->pos2);
                    scriptData->unk30 = curCmd.argShort;
                    scriptData->unk2A = (u8)curCmd.argByte;
                    return 2;
                }
                break;
            }
            case 0x71: case 0x77: case 0x7d: case 0x83: {
                action->callbacks->func0C(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = curCmd.arg1 << 8;
                scriptData->pos2.y = curCmd.arg2 << 8;
                if (curCmd.op == 0x7d || curCmd.op == 0x83) {
                    scriptData->unk2A = sub_8009FB8(scriptData->pos2.x - scriptData->pos1.x, scriptData->pos2.y - scriptData->pos1.y) / curCmd.argShort;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x72: case 0x78: case 0x7e: case 0x84: {
                action->callbacks->func0C(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = scriptData->pos1.x + (curCmd.arg1 << 8);
                scriptData->pos2.y = scriptData->pos1.y + (curCmd.arg2 << 8);
                if (curCmd.op == 0x7e || curCmd.op == 0x84) {
                    scriptData->unk2A = sub_8009FB8(scriptData->pos2.x - scriptData->pos1.x, scriptData->pos2.y - scriptData->pos1.y) / curCmd.argShort;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x73: case 0x79: case 0x7f: case 0x85: {
                s32 cap1 = curCmd.arg1 * 2 - 1;
                s32 cap2 = curCmd.arg2 * 2 - 1;
                action->callbacks->func0C(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = scriptData->pos1.x + ((OtherRandInt(cap1) - curCmd.argShort) << 8);
                scriptData->pos2.y = scriptData->pos1.y + ((OtherRandInt(cap2) - curCmd.arg1) << 8);
                if (curCmd.op == 0x7f || curCmd.op == 0x85) {
                    scriptData->unk2A = sub_8009FB8(scriptData->pos2.x - scriptData->pos1.x, scriptData->pos2.y - scriptData->pos1.y) / curCmd.argShort;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x74: case 0x7a: case 0x80: case 0x86: {
                action->callbacks->func0C(action->parentObject, &scriptData->pos1);
                scriptData->pos2 = scriptData->pos1;
                sub_80AD8B4((s16)curCmd.arg1, &scriptData->pos2);
                if (curCmd.op == 0x80 || curCmd.op == 0x86) {
                    scriptData->unk2A = sub_8009FB8(scriptData->pos2.x - scriptData->pos1.x, scriptData->pos2.y - scriptData->pos1.y) / curCmd.argShort;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x75: case 0x7b: case 0x81: case 0x87: {
                s32 cap = curCmd.arg1 * 2 - 1;
                action->callbacks->func0C(action->parentObject, &scriptData->pos2);
                sub_80AD8B4((s16)curCmd.arg2, &scriptData->pos2);
                scriptData->pos2.x = scriptData->pos2.x + ((OtherRandInt(cap) - curCmd.argShort) << 8);
                scriptData->pos2.y = scriptData->pos2.y + ((OtherRandInt(cap) - curCmd.argShort) << 8);
                if (curCmd.op == 0x81 || curCmd.op == 0x87) {
                    scriptData->unk2A = sub_8009FB8(scriptData->pos2.x - scriptData->pos1.x, scriptData->pos2.y - scriptData->pos1.y) / curCmd.argShort;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x76: case 0x7c: case 0x82: case 0x88: {
                s16 ret = sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    action->callbacks->func0C(action->parentObject, &scriptData->pos1);
                    sub_80A8FD8(ret, &scriptData->pos2);
                    if (curCmd.op == 0x82 || curCmd.op == 0x88) {
                        scriptData->unk2A = sub_8009FB8(scriptData->pos2.x - scriptData->pos1.x, scriptData->pos2.y - scriptData->pos1.y) / curCmd.argShort;
                        if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                    } else {
                        scriptData->unk2A = curCmd.argShort;
                    }
                    return 2;
                }
                break;
            }
            case 0x68: case 0x70: {
                scriptData->unk48 = curCmd.arg1 << 8;
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x89: {
                action->scriptData.unk26 = curCmd.arg1;
                action->callbacks->func2C(action->parentObject, (s8) curCmd.arg1);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8a: {
                s8 dir;
                action->callbacks->func14(action->parentObject, &dir);
                action->scriptData.unk26 = sub_8002984(dir, (s8)curCmd.arg1);
                action->callbacks->func2C(action->parentObject, action->scriptData.unk26);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8b: {
                action->scriptData.unk26 = curCmd.argShort;
                action->callbacks->func2C(action->parentObject, action->scriptData.unk26);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8c: {
                int ret = (s16)sub_80A7AE8((s16)curCmd.arg1);
                s8 dir;
                if (ret >= 0) {
                    sub_80A9050(ret, &dir);
                    action->scriptData.unk26 = sub_8002984(dir, curCmd.argShort);
                    action->callbacks->func2C(action->parentObject, action->scriptData.unk26);
                }
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8d: {
                s8 dir;
                action->callbacks->func14(action->parentObject, &dir);
                action->scriptData.unk26 = sub_8002984(dir, curCmd.argShort);
                action->callbacks->func2C(action->parentObject, action->scriptData.unk26);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8e: case 0x8f: case 0x90: {
                bool8 flag = FALSE;
                s8 dir;
                Position32 pos1, pos2, pos3, pos4;
                switch (curCmd.op) {
                    case 0x8e: {
                        s32 val = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (val >= 0) {
                            flag = TRUE;
                            sub_80A8FD8(val, &pos1);
                            sub_80A8F9C(val, &pos2);
                        }
                        break;
                    }
                    case 0x8f: {
                        s32 val = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (val >= 0) {
                            flag = TRUE;
                            sub_80A8FD8(val, &pos1);
                            pos2 = gUnknown_81164DC;
                        }
                        break;
                    }
                    case 0x90: {
                        flag = TRUE;
                        action->callbacks->func0C(action->parentObject, &pos1);
                        action->callbacks->func08(action->parentObject, &pos2);
                        sub_80AD8B4((s16)curCmd.arg1, &pos1);
                        break;
                    }
                }
                if (flag) {
                    s8 ret;
                    int tmp;
                    action->callbacks->func0C(action->parentObject, &pos3);
                    action->callbacks->func08(action->parentObject, &pos4);
                    ret = sub_8002DF0(&pos3, &pos4, &pos1, &pos2); // wtf
                    *&dir = ret;

                    tmp = -1;
                    if (dir == tmp) {
                        dir = sub_8002D54(&pos3, &gUnknown_81164DC, &pos1, &gUnknown_81164DC);
                    }
                    if (dir == tmp) {
                        action->callbacks->func14(action->parentObject, &dir);
                    }
                    action->scriptData.unk26 = sub_8002984(dir, (s8)curCmd.argShort);
                    action->callbacks->func2C(action->parentObject, action->scriptData.unk26);
                }
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x93: case 0x94: case 0x95: {
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x91: {
                action->scriptData.unk4D = (s8)curCmd.arg1;
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x92: {
                s8 unk;
                action->callbacks->func14(action->parentObject, &unk);
                action->scriptData.unk4D = sub_8002984(unk, (s8)curCmd.arg1);
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x97: {
                sub_809D124(curCmd.argShort, curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0x98: {
                s32 id = action->callbacks->func04(action->parentObject);
                switch(action->unk8[0]) {
                    case 1:
                        sub_809D170(1, id);
                        break;
                    case 2:
                        sub_809D170(2, id);
                        break;
                    case 3:
                        sub_809D170(3, id);
                        break;
                }
                break;
            }
            case 0x99: {
                s32 id = action->callbacks->func04(action->parentObject);
                Position32 unk;
                switch(action->unk8[0]) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D158(0, &unk);
                        break;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D158(0, &unk);
                        break;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D158(0, &unk);
                        break;
                }
                break;
            }
            case 0x9a: {
                sub_809D170(1, 0);
                break;
            }
            case 0x9b: {
                s32 id = action->callbacks->func04(action->parentObject);
                if (id < 0) break;
                switch(action->unk8[0]) {
                    case 1:
                        sub_809D1A8(1, id, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_809D1A8(2, id, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_809D1A8(3, id, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case 0x9c: {
                s32 id = action->callbacks->func04(action->parentObject);
                Position32 unk;
                switch(action->unk8[0]) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D190(0, &unk, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D190(0, &unk, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D190(0, &unk, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case 0x9d: {
                sub_809D1A8(1, 0, curCmd.argShort);
                return 2;
            }
            case 0x9e: {
                s32 id = action->callbacks->func04(action->parentObject);
                if (id < 0) break;
                switch(action->unk8[0]) {
                    case 1:
                        sub_809D1E4(1, id, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_809D1E4(2, id, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_809D1E4(3, id, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case 0x9f: {
                s32 id = action->callbacks->func04(action->parentObject);
                Position32 unk;
                switch(action->unk8[0]) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D1CC(0, &unk, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D1CC(0, &unk, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D1CC(0, &unk, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case 0xa0: {
                sub_809D1E4(1, 0, curCmd.argShort);
                return 2;
            }
            case 0xa1: {
                s32 id = action->callbacks->func04(action->parentObject);
                if (id < 0) break;
                switch(action->unk8[0]) {
                    case 1:
                        sub_809D220(1, id, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_809D220(2, id, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_809D220(3, id, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case 0xa2: {
                s32 id = action->callbacks->func04(action->parentObject);
                Position32 unk;
                switch(action->unk8[0]) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D208(0, &unk, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D208(0, &unk, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D208(0, &unk, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case 0xa3: {
                sub_809D220(1, 0, curCmd.argShort);
                return 2;
            }
            case 0xa4: {
                sub_8001570(scriptData->unk50[0].arr, curCmd.argShort);
                break;
            }
            case 0xa5: {
                sub_80015C0(scriptData->unk50[0].arr, curCmd.argShort);
                break;
            }
            case 0xa6: {
                sub_800226C(scriptData->unk50[0].arr, curCmd.argShort, curCmd.arg1, curCmd.argByte);
                break;
            }
            case 0xa7: {
                sub_80022A0(scriptData->unk50[0].arr, curCmd.argShort, (s16)curCmd.arg1, curCmd.argByte);
                break;
            }
            case 0xa8: {
                sub_800199C(scriptData->unk50[0].arr, curCmd.argShort, (u16)curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0xa9: {
                ScenarioCalc(curCmd.argShort, curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0xaa: {
                s32 a, b;
                sub_8001B88(curCmd.argShort, &a, &b);
                ScenarioCalc(curCmd.argShort, a, b+1);
                break;
            }
            case 0xab: {
                sub_80018D8(0, 19, curCmd.arg1);
                sub_80018D8(0, 22, curCmd.argShort);
                break;
            }
            case 0xac: {
                sub_80018D8(0, 28, curCmd.argShort);
                break;
            }
            case 0xad: {
                sub_80026E8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xae: {
                sub_809733C(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xaf: {
                sub_80973A8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xb0: {
                sub_8097418(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xb1: {
                sub_80975A8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xb2: {
                sub_80976F8(curCmd.argShort);
                break;
            }
            case 0xb3: {
                if ((u8)sub_80022F8(0, curCmd.argShort, curCmd.arg1, 2)) {
                    scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xb4: {
                if ((s8)sub_80022F8(scriptData->unk50, (s16)curCmd.arg1, curCmd.arg2, (u8)curCmd.argByte)) {
                    scriptData->script.ptr = sub_80A242C(action, curCmd.argShort);
                }
                break;
            }
            case 0xb5: {
                if ((s8)sub_8002318(scriptData->unk50, (s16)curCmd.arg1, (s16)curCmd.arg2, (u8)curCmd.argByte)) {
                    scriptData->script.ptr = sub_80A242C(action, curCmd.argShort);
                }
                break;
            }
            case 0xb6: {
                if (sub_8001784(scriptData->unk50, (s16)curCmd.arg1, (u16)curCmd.arg2)) {
                    scriptData->script.ptr = sub_80A242C(action, curCmd.argShort);
                }
                break;
            }
            case 0xb7: {
                if ((s8)FlagJudge(sub_8001AB0(scriptData->unk50, (s16)curCmd.arg1), curCmd.arg2, (u8)curCmd.argByte)) {
                    scriptData->script.ptr = sub_80A242C(action, curCmd.argShort);
                }
                break;
            }
            case 0xb8: {
                if ((s8)sub_8001CC4(curCmd.argShort, curCmd.arg1, curCmd.arg2)) {
                    scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xb9: {
                if ((s8)sub_8001D08(curCmd.argShort, curCmd.arg1, curCmd.arg2)) {
                    scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xba: {
                if ((s8)sub_8001D44(curCmd.argShort, curCmd.arg1, curCmd.arg2)) {
                    scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbb: {
                if ((s8)sub_80023E4(curCmd.argShort)) {
                    scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbc: {
                if ((s8)sub_8098100((u8)curCmd.argShort)) {
                    scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbd: {
                if ((s8)sub_80026CC((s16)curCmd.arg1)) {
                        scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbf: {
                if (sub_809CBA4(curCmd.argShort) > 0) {
                        scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbe: {
                if (action->unk8[0] == 1) {
                    if ((s8)sub_80A8C98(action->unk8[1])) {
                        scriptData->script.ptr = sub_80A242C(action, (u8)curCmd.argByte);
                    }
                }
                break;
            }
            case 0x41: {
                if (FindItemInInventory((u8)curCmd.argShort) >= 0) ShiftItemsDownFrom();
                break;
            }
            case 0xc0 ... 0xcb: {
                s32 val;
                Position32 pos, pos2, pos3;
                switch (curCmd.op) {
                    case 0xc0: {
                        val = sub_8001658(scriptData->unk50, curCmd.argShort);
                        break;
                    }
                    case 0xc1: {
                        val = FlagCalc(
                            sub_8001658(scriptData->unk50, curCmd.argShort),
                            curCmd.arg1,
                            (u8)curCmd.argByte);
                        break;
                    }
                    case 0xc2: {
                        val = FlagCalc(
                            sub_8001658(scriptData->unk50, curCmd.argShort),
                            sub_8001658(scriptData->unk50, (s16)curCmd.arg1),
                            (u8)curCmd.argByte);
                        break;
                    }
                    case 0xc3: {
                        val = OtherRandInt(curCmd.argShort);
                        break;
                    }
                    case 0xc4: {
                        val = sub_8001784(0, curCmd.argShort, 0);
                        break;
                    }
                    case 0xc5: {
                        val = sub_8001784(0, curCmd.argShort, 1);
                        break;
                    }
                    case 0xc6: {
                        val = (s16)sub_80A8C2C((s16)curCmd.arg1);
                        break;
                    }
                    case 0xc7: {
                        s8 dir;
                        action->callbacks->func14(action->parentObject, &dir);
                        val = dir;
                        break;
                    }
                    case 0xca: {
                        action->callbacks->func0C(action->parentObject, &pos);
                        pos2 = pos;
                        sub_80AD8B4((s16)curCmd.arg1, &pos2);
                        pos3.x = pos2.x - pos.x;
                        pos3.y = pos2.y - pos.y;
                        val = (s8)sub_8002C60(&pos3);
                        break;
                    }
                    case 0xc8: {
                        s16 tmp = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (tmp >= 0) {
                            Position32 pos1, pos2, pos3, pos4;
                            action->callbacks->func0C(action->parentObject, &pos1);
                            action->callbacks->func08(action->parentObject, &pos2);
                            sub_80A8FD8(tmp, &pos3);
                            sub_80A8F9C(tmp, &pos4);
                            val = (s8)sub_8002DF0(&pos1, &pos2, &pos3, &pos4);
                            if (val == -1) {
                                val = (s8)sub_8002D54(&pos1, &gUnknown_81164DC, &pos3, &gUnknown_81164DC);
                            }
                        } else {
                            val = -1;
                        }
                        break;
                    }
                    case 0xc9: {
                        s16 tmp = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (tmp >= 0) {
                            Position32 pos1, pos2, pos3;
                            action->callbacks->func0C(action->parentObject, &pos1);
                            action->callbacks->func08(action->parentObject, &pos2);
                            sub_80A8FD8(tmp, &pos3);
                            val = (s8)sub_8002DF0(&pos1, &pos2, &pos3, &gUnknown_81164DC);
                            if (val == -1) {
                                val = (s8)sub_8002D54(&pos1, &gUnknown_81164DC, &pos3, &gUnknown_81164DC);
                            }
                        } else {
                            val = -1;
                        }
                        break;
                    }
                    case 0xcb: {
                        val = sub_809CC90(curCmd.argShort);
                        break;
                    }
                    default: {
                        // The locdata says this is part of an inlined function... :/
                        // "switch type error %d"
                        FatalError(&gUnknown_81166B4, gUnknown_81166C0, curCmd.op);
                    }
                }
                scriptData->script.ptr = sub_80A2460(action, val);
                break;
            }
            case 0xcf: {
                scriptData->branchDiscriminant = sub_8001658(scriptData->unk50, curCmd.argShort);
                while (scriptData->script.ptr->op == 0xd0) {
                    if (scriptData->script.ptr->argShort == scriptData->branchDiscriminant)
                        return 2;
                    scriptData->script.ptr++;
                }
                if (scriptData->script.ptr->op == 0xd1) {
                    scriptData->branchDiscriminant = -1;
                    return 2;
                }
                break;
            }
            case 0xd2 ... 0xd8: {
                char *out = curCmd.argPtr;
                gUnknown_203B4AC = 0;
                scriptData->branchDiscriminant = 0;
                switch(curCmd.op) {
                    case 0xd6: case 0xd7: case 0xd8: {
                        s32 disc = sub_8001658(scriptData->unk50, (s16)curCmd.arg2);
                        for (; scriptData->script.ptr->op == 0xd0; scriptData->script.ptr++, scriptData->branchDiscriminant++) {
                            if (scriptData->script.ptr->argShort == disc)
                                out = scriptData->script.ptr->argPtr;
                        }
                        for (; scriptData->script.ptr->op == 0xd1; scriptData->script.ptr++, scriptData->branchDiscriminant++) {
                            if (!out) out = scriptData->script.ptr->argPtr;
                        }
                    }
                }
                if (!out) out = gUnknown_81166D8; // ""
                for (; scriptData->script.ptr->op == 0xd9; scriptData->script.ptr++) {
                    gUnknown_2039D50[gUnknown_203B4AC].unk0 = scriptData->script.ptr->argPtr;
                    gUnknown_2039D50[gUnknown_203B4AC].unk4 = gUnknown_203B4AC + 1;
                    gUnknown_203B4AC++;
                }
                if (gUnknown_203B4AC <= 0) break;
                gUnknown_2039D50[gUnknown_203B4AC].unk0 = NULL;
                gUnknown_2039D50[gUnknown_203B4AC].unk4 = curCmd.argShort;
                switch (curCmd.op) {
                    case 0xd2: case 0xd3: case 0xd6: {
                        sub_809B028(gUnknown_2039D50, (u8)curCmd.argByte > 0, -1, 0, (s16)curCmd.arg1, out);
                        break;
                    }
                    case 0xd4: case 0xd7: {
                        sub_809B028(gUnknown_2039D50, (u8)curCmd.argByte > 0, -1, 1, (s16)curCmd.arg1, out);
                        break;
                    }
                    case 0xd5: case 0xd8: {
                        sub_809B028(gUnknown_2039D50, (u8)curCmd.argByte > 0, -1, 2, (s16)curCmd.arg1, out);
                        break;
                    }
                }
                if ((s8)sub_809D8EC(action, 1)) {
                    sub_80A87AC(0, 11);
                    return 2;
                }
                break;
            }
            case 0xda: {
                if (sub_809D8EC(action, 1)) {
                    return 2;
                }
                break;
            }
            case 0xdb: {
                scriptData->unk2A = curCmd.argShort;
                return 2;
            }
            case 0xdc: {
                scriptData->unk2A = curCmd.argShort + OtherRandInt(curCmd.arg1 - curCmd.argShort);
                return 2;
            }
            case 0xdd ... 0xe2: {
                return 2; // do action
            }
            case 0xe3: {
                scriptData->branchDiscriminant = curCmd.argShort;
                if (sub_809D8EC(action, curCmd.argShort)) {
                    return 2;
                }
                break;
            }
            case 0xe4: {
                sub_809D9B8(curCmd.argShort);
                break;
            }
            case 0xe5: {
                scriptData->branchDiscriminant = curCmd.argShort;
                if ((s8)sub_809DA08(action, curCmd.argShort, curCmd.argByte)) {
                    return 2;
                }
                break;
            }
            case 0xe6: {
                scriptData->savedScript = scriptData->script;
            } //fallthrough
            case 0xe7: { // ???
                scriptData->script.ptr = sub_80A242C(action, curCmd.argShort);
                break;
            }
            case 0xe8: { // SAVE_AND_TRIGGER
                scriptData->savedScript = scriptData->script;
            } // fallthrough
            case 0xe9: { // TRIGGER
                scriptData->script.ptr2 = scriptData->script.ptr = gFunctionScriptTable[curCmd.argShort].script;
                break;
            }
            case 0xea: { // SAVE_AND_RUN_STATION
                scriptData->savedScript = scriptData->script;
            } // fallthrough
            case 0xeb: { // RUN_STATION
                ScriptInfoSmall info;
                u32 group, sector;
                u32 tmp = gUnknown_2039A34;
                {
                    s32 tmp = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    group = tmp;
                }
                {
                    s32 tmp = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    sector = tmp;
                }
                GroundMap_GetStationScript(&info, tmp, group, sector);
                scriptData->script.ptr = info.ptr;
                scriptData->script.ptr2 = info.ptr;
                scriptData->script.group = group;
                scriptData->script.sector = sector;
                break;
            }
            case 0xec: {
                gUnknown_2039A34 = sub_80A4D7C((s16)sub_8001658(scriptData->unk50, curCmd.argShort));
                sub_809D940();
                GroundMap_ExecuteEnter(gUnknown_2039A34);
                break;
            }
            case 0xed: { // DELETE_SAVED
                scriptData->savedScript.ptr = NULL;
                scriptData->savedScript.ptr2 = NULL;
                break;
            }
            case 0xee: { // RESTORE_SAVED
                if (scriptData->savedScript.ptr == NULL) {
                    return 0;
                }
                scriptData->script = scriptData->savedScript;
                scriptData->savedScript.ptr = NULL;
                scriptData->savedScript.ptr2 = NULL;
                break;
            }
            case 0xef:
                return 0;
            case 0xf0:
                return 1;
            case 0xf1:
                return 4; // fatal error?
            case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: {
                // Debug, not in release ROM
                break;
            }
        }
    }
}

u32 sub_80A14E8(u32, u8, u32, u32);

UNUSED u32 sub_80A1440(u32 r0, u32 r1, u32 r2)
{
   return sub_80A14E8(0, r0, r1, r2); 
}

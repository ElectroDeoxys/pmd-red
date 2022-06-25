#include "global.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "music.h"

extern u8 sub_80023E4(u32);
extern void FadeOutAllMusic(u16);
extern void sub_809C730();

extern bool8 DisableInterrupts();
extern bool8 EnableInterrupts();

extern void Random();
extern void sub_800BA5C();
extern void xxx_update_bg_sound_input();

// 0 - Only seen it initialized
// 1 - Playing
// 2 - 
// 3 - Fade Out?
// 4 - Stopped
extern u16 gBGMusicPlayerState;

extern u16 gCurrentBGSong;
extern u16 gUnknown_202D690;
extern u8 gRestartBGM;
extern u32 gUnknown_203B0B8;
extern u16 gRawKeyInput;

void StopBGMusicVSync(void)
{
    bool8 interrupt_flag;
    u16 temp;

    FadeOutFanfareSE(0x3e5, 0x10);
    FadeOutFanfareSE(0x3e6, 0x10);

    interrupt_flag = DisableInterrupts();
    if(gUnknown_202D690 == 0)
    {
        if(gCurrentBGSong != 999)
        {
            temp = gBGMusicPlayerState - 1;
            if(temp <= 1)
            {
                if(gBGMusicPlayerState == 2)
                {
                    gRestartBGM = FALSE;
                }
                else if(gBGMusicPlayerState == BG_PLAYER_STATE_PLAYING)
                {
                    gRestartBGM = TRUE;
                }
                gBGMusicPlayerState = BG_PLAYER_STATE_STOPPED;
            }
        }
    }
    m4aMPlayStop(&gMPlayInfo_BGM);
    m4aSoundVSyncOff();
    if(interrupt_flag)
    {
        EnableInterrupts();
    }
}

void StartBGMusicVSync(void)
{
    bool8 interrupt_flag = DisableInterrupts();
    m4aSoundVSyncOn();
    if(gUnknown_202D690 == 0)
    {
        if(gCurrentBGSong != 999)
        {
            if(gBGMusicPlayerState == BG_PLAYER_STATE_STOPPED)
            {
                gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
                if(gRestartBGM)
                {
                    m4aSongNumStart(gCurrentBGSong);
                }
                else
                {
                    m4aMPlayContinue(&gMPlayInfo_BGM);
                }
            }
        }
    }
    if(interrupt_flag)
    {
        EnableInterrupts();
    }

}

void nullsub_179(void)
{
}

// Unused
bool8 IsValidSong(u32 songIndex)
{
    if(IsBGSong(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) == INDEX_BGM)
        {
            return TRUE;
        }
    }
    if(IsFanfare(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) == INDEX_FANFARE)
        {
            return TRUE;
        }
    }
    else if(IsSoundEffect(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) >= INDEX_SE1)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void nullsub_19(void)
{
}

bool8 IsBGSong(u32 songIndex)
{
    if(songIndex <= NUM_BG_SONGS)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsSoundEffect(u32 songIndex)
{
    if(songIndex - 300 <= 639)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsFanfare(u32 songIndex)
{
    if(songIndex - 200 <= 19)
    {
        return TRUE;
    }
    return FALSE;
}

u16 GetMusicPlayerIndex(u16 songIndex)
{
    return gSongTable[songIndex].ms;
}

bool8 IsMusicPlayerPlaying(u16 playerIndex)
{
    // Had to cast this.. m4a_internal header has this as u32
    if((u16)gMPlayTable[playerIndex].info->status == 0)
    {
        return FALSE;
    }
    return TRUE;
}

void nullsub_20(u16 songIndex)
{
}

void nullsub_21(u16 songIndex)
{
}

void sub_800CB20(void)
{
    sub_800BA5C();
    gUnknown_203B0B8++;
    if((gRawKeyInput & (A_BUTTON | SELECT_BUTTON)) != 0)
    {
        Random();
    }
    Random();
}

// Unused
u32 sub_800CB50(void)
{
    return gUnknown_203B0B8;
}

void nullsub_180(void)
{
}

void xxx_call_update_bg_sound_input(void)
{
    xxx_update_bg_sound_input();
}

void nullsub_181(void)
{
}

u32 sub_800CB70(void)
{
    return 0;
}


#ifndef GUARD_COMMON_STRINGS_KANGASKHAN_STORAGE_H
#define GUARD_COMMON_STRINGS_KANGASKHAN_STORAGE_H

enum KangaskhanStorageMode
{
    KANG_MODE_AWAKE,
    KANG_MODE_ASLEEP,
    KANG_MODE_COUNT
};
enum KangaskhanStorageDialogue
{
    KANG_DLG_WELCOME,
    KANG_DLG_ANYTHING_ELSE,
    KANG_DLG_BYE,
    KANG_DLG_STORE_WHAT,
    KANG_DLG_STORE_MORE,
    KANG_DLG_DEPOSIT_ONE_PROMPT,
    KANG_DLG_DEPOSIT_MANY_PROMPT,
    KANG_DLG_DEPOSIT_CONFIRMATION,
    KANG_DLG_TAKE_WHAT,
    KANG_DLG_TAKE_MORE,
    KANG_DLG_WITHDRAW_ONE_PROMPT,
    KANG_DLG_WITHDRAW_MANY_PROMPT,
    KANG_DLG_WITHDRAW_CONFIRMATION,
    KANG_DLG_YOU_HAVE_NOTHING,
    KANG_DLG_YOU_ARE_FULL,
    KANG_DLG_STORAGE_HAS_NOTHING,
    KANG_DLG_DEPOSIT__INVALID_ITEM,
    KANG_DLG_DEPOSIT__TOO_MANY_OF_ITEM,
    KANG_DLG_STORAGE_FULL,
    KANG_DLG_HOW_IT_WORKS,
    KANG_DLG_MAX
};

#endif // GUARD_COMMON_STRINGS_KANGASKHAN_STORAGE_H
#ifndef GUARD_CONSTANTS_WONDER_MAIL_H
#define GUARD_CONSTANTS_WONDER_MAIL_H 

enum RewardType
{
    MONEY,
    MONEY_EXTRA,
    ITEM,
    ITEM_EXTRA,
    BLANK_4,
    MONEY1,
    MONEY1_EXTRA,
    ITEM1,
    ITEM1_EXTRA,
    FRIEND_AREA,
    END_REWARDS
};

enum WonderMailMode {
    WONDER_MAIL_MODE_SEND = 1,
    WONDER_MAIL_MODE_RECEIVE = 2,
};

enum WonderMailMethod {
    WONDER_MAIL_GAME_LINK = 3,
    WONDER_MAIL_PASSWORD = 5, 
};

enum WonderMailTypes {
    WONDER_MAIL_TYPE_NONE = 0,
    WONDER_MAIL_TYPE_SOS = 1,
    //WONDER_MAIL_TYPE_SOS = 2, // SOS MAIL is 1 and 2?
    WONDER_MAIL_TYPE_AOK = 4,
    WONDER_MAIL_TYPE_THANK_YOU = 5,
    WONDER_MAIL_TYPE_WONDER = 5,
    WONDER_MAIL_TYPE_COMPLETED = 6,
    WONDER_MAIL_TYPE_OKD = 7,
};

// Used in CreateRescueTitle and CreateRescueDescription
enum MailStatuses {
    MAIL_STATUS_SUSPENDED,
    MAIL_STATUS_TAKE_JOB,
    MAIL_STATUS_DONE
};

// Used in CreateRescueTitle and CreateRescueDescription
enum MissionTypes {
    MISSION_TYPE_FRIEND_RESCUE,
    MISSION_TYPE_FIND_ITEM,
    MISSION_TYPE_DELIVER_ITEM,
    MISSION_TYPE_RESCUE_CLIENT,
    MISSION_TYPE_RESCUE_TARGET,
    MISSION_TYPE_ESCORT_CLIENT,
    MISSION_TYPE_SPECIAL_MISSION
};

enum WonderMailMissionTypes
{
    WONDER_MAIL_MISSION_TYPE_RESCUE_CLIENT = 0,
    WONDER_MAIL_MISSION_TYPE_RESCUE_TARGET = 1,
    WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT = 2,
    WONDER_MAIL_MISSION_TYPE_FIND_ITEM = 3,
    WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM = 4,
    WONDER_MAIL_MISSION_TYPE_UNK6 = 6,
};

enum MissionTypes 
{
    MISSION_TYPE_FRIEND_RESCUE,
    MISSION_TYPE_FIND_ITEM,
    MISSION_TYPE_DELIVER_ITEM,
    MISSION_TYPE_RESCUE_CLIENT,
    MISSION_TYPE_RESCUE_TARGET,
    MISSION_TYPE_ESCORT_CLIENT,
    MISSION_TYPE_SPECIAL_MISSION
};

#define MAIL_STATUS_SUSPENDED 0


#define NUM_POKEMON_NEWS 56 // 50 normal + 6 special issues
#define PASSWORD_BUFFER_SIZE 54
#define MAX_ITEM_REWARDS 3


#endif //GUARD_CONSTANTS_WONDER_MAIL_H

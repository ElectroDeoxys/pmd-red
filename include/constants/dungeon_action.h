#ifndef GUARD_CONSTANTS_DUNGEON_ACTION_H
#define GUARD_CONSTANTS_DUNGEON_ACTION_H

enum DungeonAction
{
    DUNGEON_ACTION_WAIT = 0x1,
    DUNGEON_ACTION_WALK = 0x2,
    // Switching between Pokémon in the moves menu.
    DUNGEON_ACTION_NEXT_POKEMON_MOVES = 0x6,
    DUNGEON_ACTION_PREVIOUS_POKEMON_MOVES = 0x7,
    DUNGEON_ACTION_PLACE_ITEM = 0x8,
    // Some actions are different between the leader and AI-controlled Pokémon.
    DUNGEON_ACTION_TAKE_ITEM_LEADER = 0x9, // Picking up an item underfoot.
    DUNGEON_ACTION_THROW_ITEM_LEADER = 0xB,
    DUNGEON_ACTION_CONSUME_ITEM_LEADER = 0xD,
    DUNGEON_ACTION_USE_ITEM_LEADER = 0x12,
    DUNGEON_ACTION_TALK_FIELD = 0x13, // Talking to another Pokémon by facing them and interacting.
    DUNGEON_ACTION_USE_MOVE_LEADER = 0x14,
    DUNGEON_ACTION_USE_MOVE_AI = 0x15,
    DUNGEON_ACTION_STRUGGLE = 0x17, // Using the Struggle move.
    DUNGEON_ACTION_CHECK_MOVES = 0x19,
    DUNGEON_ACTION_CHANGE_TACTICS = 0x1A,
    DUNGEON_ACTION_CHECK_POKEMON_SUMMARY = 0x1B,
    DUNGEON_ACTION_TALK_MENU = 0x1C, // Talking to another Pokémon via the menu.
    DUNGEON_ACTION_SET_MOVE = 0x1E, // Registering a move.
    DUNGEON_ACTION_CONSUME_ITEM_AI = 0x23,
    DUNGEON_ACTION_THROW_ITEM_AI = 0x24,
    DUNGEON_ACTION_THROW_STRAIGHT_THROWN_ITEM_LEADER = 0x27,
    DUNGEON_ACTION_USE_LINK_BOX = 0x2C,
    DUNGEON_ACTION_GIVE_UP = 0x2E,
    DUNGEON_ACTION_CHANGE_IQ_SKILLS = 0x30,
    DUNGEON_ACTION_USE_ORB = 0x31,
    DUNGEON_ACTION_REGULAR_ATTACK = 0x32,
    DUNGEON_ACTION_UNSET_MOVE = 0x33,
    DUNGEON_ACTION_GIVE_HELD_ITEM = 0x36,
    DUNGEON_ACTION_TAKE_HELD_ITEM = 0x37,
    DUNGEON_ACTION_HAVE_SECOND_THOUGHTS = 0x39, // Happens with invalid actions, like attempting to eat a non-consumable item.
    DUNGEON_ACTION_SET_ITEM = 0x3C,
    DUNGEON_ACTION_UNSET_ITEM = 0x3D,
    DUNGEON_ACTION_TAKE_ITEM_AI = 0x3F,
    DUNGEON_ACTION_THROW_ARC_THROWN_ITEM_LEADER = 0x41, // Throwing Gravelerocks and Geo Pebbles.
};

#endif

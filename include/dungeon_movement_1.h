#ifndef GUARD_DUNGEON_MOVEMENT_1_H
#define GUARD_DUNGEON_MOVEMENT_1_H

#include "dungeon_entity.h"

bool8 CanCrossWalls(struct Entity *pokemon);
s32 CalcSpeedStage(struct Entity *pokemon);

#endif

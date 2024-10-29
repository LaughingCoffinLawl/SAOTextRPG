#include "Random.h"
#include "Room.h"
#include "EmptyRoom.h"
#include "StartRoom.h"
#include "NormalRoom.h"
#include "TreasureRoom.h"
#include "BossRoom.h"
#include "Dungeon.h"

#include <map>

#ifndef DUNGEONS_PREFAB_H
#define DUNGEON_PREFAB_H

namespace DungeonsPrefab {
    Dungeon createPrefabs();
}

#endif // DUNGEONS_PREFAB_H


#include "Random.h"
#include "Room.h"
#include "EmptyRoom.h"
#include "StartRoom.h"
#include "TreasureRoom.h"

#ifndef DUNGEONS_PREFAB_H
#define DUNGEON_PREFAB_H

namespace DungeonsPrefab {
    Dungeon createPrefabs();    // Picks a random dungeon between the prefabs
}

#endif // DUNGEONS_PREFAB_H


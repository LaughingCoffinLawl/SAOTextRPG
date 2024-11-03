#include "DungeonsPrefab.h"

// Creates two fixed dungeons
// Pick one with a dice roll
// Returns an empty dungeons if something goes wrong

Dungeon DungeonsPrefab::createPrefabs() {
    std::array<std::unique_ptr<Room>, 36> exampleDungeon1{
        // Initialize with the layout of Example Dungeon 1
        // # # # # # #
        // # S N N N #
        // # # # # N #
        // # # # T N #
        // # # # # N #
        // # # # # B #
    };
    // Creates an empty dungeon
    for (auto& room : exampleDungeon1)
        room = std::make_unique<EmptyRoom>();

    // Specify which room is where
    exampleDungeon1[7] = std::make_unique<StartRoom>();
    exampleDungeon1[8] = std::make_unique<NormalRoom>();
    exampleDungeon1[9] = std::make_unique<NormalRoom>();
    exampleDungeon1[10] = std::make_unique<NormalRoom>();
    exampleDungeon1[16] = std::make_unique<NormalRoom>();
    exampleDungeon1[21] = std::make_unique<TreasureRoom>();
    exampleDungeon1[22] = std::make_unique<NormalRoom>();
    exampleDungeon1[28] = std::make_unique<NormalRoom>();
    exampleDungeon1[34] = std::make_unique<BossRoom>();

    std::array<std::unique_ptr<Room>, 36> exampleDungeon2{
        // Initialize with the layout of Example Dungeon 2
        // # # # # # #
        // S N N # # #
        // # # N # # #
        // # # N T # #
        // # # N # # #
        // # # N B # #
    };
    for (auto& room : exampleDungeon2)
        room = std::make_unique<EmptyRoom>();

    exampleDungeon2[6] = std::make_unique<StartRoom>();
    exampleDungeon2[7] = std::make_unique<NormalRoom>();
    exampleDungeon2[8] = std::make_unique<NormalRoom>();
    exampleDungeon2[14] = std::make_unique<NormalRoom>();
    exampleDungeon2[20] = std::make_unique<NormalRoom>();
    exampleDungeon2[21] = std::make_unique<TreasureRoom>();
    exampleDungeon2[26] = std::make_unique<NormalRoom>();
    exampleDungeon2[32] = std::make_unique<NormalRoom>();
    exampleDungeon2[33] = std::make_unique<BossRoom>();

    std::array<std::unique_ptr<Room>, 36> emptyDungeon{};

    for (auto& room : emptyDungeon)
        room = std::make_unique<EmptyRoom>();

    // Gets a random dungeon between the two or empty if something goes wrong.
    const int randomDungeon{ Random::RollD20() % 2 };
    switch (randomDungeon) {
    case 0:     return Dungeon{ exampleDungeon1 };
    case 1:     return Dungeon{ exampleDungeon2 };
    default:    return Dungeon{ emptyDungeon };
    }
}
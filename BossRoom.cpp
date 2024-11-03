#include "BossRoom.h"
#include "MonsterFactory.h"

// When the players enters the room, the boss is spawned.
RoomResult BossRoom::onEnter() const {
	return MonsterFactory::spawnBoss();
}

// Letter on the map
std::string_view BossRoom::textToDisplay() const {
	return "B";
}

// Returns true or false if the room is empty
bool BossRoom::isEmpty() const {
	return false;
}
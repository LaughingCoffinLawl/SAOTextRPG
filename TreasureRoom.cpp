#include "TreasureRoom.h"

// When the player enters the room, a random weapon is created
RoomResult TreasureRoom::onEnter() const {
	return MonsterFactory::createRandomWeapon();
}

// Letter on the map
std::string_view TreasureRoom::textToDisplay() const {
	return "T";
}

// Returns true or false if the room is empty
bool TreasureRoom::isEmpty() const {
	return false;
}
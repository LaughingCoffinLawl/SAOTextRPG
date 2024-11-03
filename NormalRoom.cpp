#include "NormalRoom.h"

// When the player enters a random monster is spawned.
RoomResult NormalRoom::onEnter() const {
	return MonsterFactory::createRandomMonster();
}

// Letter on the map
std::string_view NormalRoom::textToDisplay() const {
	return "N";
}

// Returns true or false if the room is empty
bool NormalRoom::isEmpty() const {
	return false;
}
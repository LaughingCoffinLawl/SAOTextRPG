#include "TreasureRoom.h"

RoomResult TreasureRoom::onEnter() const {
	return MonsterFactory::createRandomWeapon();
}

std::string_view TreasureRoom::textToDisplay() const {
	return "T";
}

bool TreasureRoom::isEmpty() const {
	return false;
}
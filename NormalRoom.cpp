#include "NormalRoom.h"

RoomResult NormalRoom::onEnter() const {
	return MonsterFactory::createRandomMonster();
}

std::string_view NormalRoom::textToDisplay() const {
	return "N";
}

bool NormalRoom::isEmpty() const {
	return false;
}
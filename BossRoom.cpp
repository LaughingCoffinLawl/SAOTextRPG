#include "BossRoom.h"
#include "MonsterFactory.h"

RoomResult BossRoom::onEnter() const {
	return MonsterFactory::spawnBoss();
}

std::string_view BossRoom::textToDisplay() const {
	return "B";
}

bool BossRoom::isEmpty() const {
	return false;
}
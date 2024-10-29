#include "Room.h"

#ifndef BOSS_ROOM_H
#define BOSS_ROOM_H

class BossRoom : public Room {
public:
	RoomResult onEnter() const override;
	std::string_view textToDisplay() const override;
	bool isEmpty() const override;
};

#endif // !BOSS_ROOM_H


#include "Room.h"

#ifndef TREASURE_ROOM_H
#define TREASURE_ROOM_H

class TreasureRoom : public Room {
public:
	RoomResult onEnter() const override;
	std::string_view textToDisplay() const override;
	bool isEmpty() const override;
};

#endif // !TREASURE_ROOM_H


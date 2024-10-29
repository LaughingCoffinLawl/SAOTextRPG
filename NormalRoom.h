#include "Room.h"

#ifndef NORMAL_ROOM_H
#define NORMAL_ROOM_H

class NormalRoom : public Room {
public:
	RoomResult onEnter() const override;
	std::string_view textToDisplay() const override;
	bool isEmpty() const override;
};

#endif // !NORMAL_ROOM_H


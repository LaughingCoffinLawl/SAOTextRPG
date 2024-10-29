#include "Room.h"

#ifndef EMPTY_ROOM_H
#define EMPTY_ROOM_H

class EmptyRoom : public Room {
public:
	RoomResult onEnter() const override;
	std::string_view textToDisplay() const override;
	bool isEmpty() const override;
};

#endif // 


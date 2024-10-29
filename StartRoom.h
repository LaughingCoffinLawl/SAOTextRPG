#include "Room.h"

#ifndef START_ROOM_H
#define START_ROOM_H

class StartRoom : public Room {
public:
	RoomResult onEnter() const override;
	std::string_view textToDisplay() const override;
	bool isEmpty() const override;
};

#endif // !START_ROOM_H


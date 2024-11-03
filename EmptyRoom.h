#include "Room.h"

#ifndef EMPTY_ROOM_H
#define EMPTY_ROOM_H

// Empty room class

class EmptyRoom : public Room {
public:
	RoomResult onEnter() const override;				// What happens when the player enters the room
	std::string_view textToDisplay() const override;	// Text to display on the map to recognize the room type
	bool isEmpty() const override;						// True or false if the room is empty
};

#endif // 


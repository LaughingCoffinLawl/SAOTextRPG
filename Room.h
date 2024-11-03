#include "Monster.h"
#include "Weapon.h"
#include "Boss.h"
#include "MonsterFactory.h"

#include <iostream>
#include <variant>

#ifndef ROOM_H
#define ROOM_H

// Virtual class for the rooms

// OnEnter can returns three different types
using RoomResult = std::variant<std::monostate, std::unique_ptr<Monster>, std::unique_ptr<Weapon>, std::unique_ptr<Boss>>;

class Room {
public:
	Room() = default;										// Defacult constructor
	virtual ~Room() = default;								// Virtual destructor
	virtual std::string_view textToDisplay() const = 0;		// Text to display based on the room
	virtual RoomResult onEnter() const = 0;					// What happens the the player enters the room
	virtual bool isEmpty() const = 0;						// True or false if the room is empty
};	

#endif // !ROOM_H


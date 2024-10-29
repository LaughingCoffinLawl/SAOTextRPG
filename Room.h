#include "Monster.h"
#include "Weapon.h"
#include "Boss.h"
#include "MonsterFactory.h"

#include <iostream>
#include <variant>

#ifndef ROOM_H
#define ROOM_H

using RoomResult = std::variant<std::monostate, std::unique_ptr<Monster>, std::unique_ptr<Weapon>, std::unique_ptr<Boss>>;

class Room {
public:
	Room() = default;
	virtual ~Room() = default;
	virtual std::string_view textToDisplay() const = 0;
	virtual RoomResult onEnter() const = 0;
	virtual bool isEmpty() const = 0;
};

#endif // !ROOM_H


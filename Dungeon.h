#include "Room.h"
#include "StartRoom.h"

#include <array>
#include <cassert>

#ifndef DUNGEON_H
#define DUNGEON_H

class Dungeon {
public:
	explicit Dungeon(std::array<std::unique_ptr<Room>, 36>& dungeon);
	Room& operator()(std::size_t row, std::size_t column);
	Room& operator[](std::size_t index);
	void display();
	std::size_t getPlayerPosition() const;
	RoomResult movePlayer(char direction);
	void resetPlayerPosition();
private:
	std::array<std::unique_ptr<Room>, 36> m_dungeon;
	const std::size_t m_rows{ 6 };
	const std::size_t m_columns{ 6 };
	std::size_t m_playerPosition{};
};

#endif // !DUNGEON_H


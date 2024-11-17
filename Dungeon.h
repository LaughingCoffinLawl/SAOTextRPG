#include <array>
#include <cassert>
#include "Room.h"
#include "StartRoom.h"

#ifndef DUNGEON_H
#define DUNGEON_H

// Dungeon class

class Dungeon {
   public:
	explicit Dungeon(std::array<std::unique_ptr<Room>, 36>& dungeon);	// Constructor
	Room& operator()(std::size_t row, std::size_t column);				// Overload of the operator ()
	Room& operator[](std::size_t index);								// Overload of the operator []
	void display();														// Prints the dungeon
	std::size_t getPlayerPosition() const;								// Returns player position
	RoomResult movePlayer(char direction);								// Moves the player with a direction;
	void resetPlayerPosition();											// Resets player position to the start room
   private:
	std::array<std::unique_ptr<Room>, 36> m_dungeon;   // Dungeon is a 1D array
	const std::size_t m_rows{6};					   // Max rows
	const std::size_t m_columns{6};					   // Max columns
	std::size_t m_playerPosition{};					   // Player position
};

#endif	 // !DUNGEON_H

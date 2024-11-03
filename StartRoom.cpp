#include "StartRoom.h"

// When the player enters nothing happens
RoomResult StartRoom::onEnter() const {
	return std::monostate{};
}

// Letter on the map
std::string_view StartRoom::textToDisplay() const {
	return "S";
}

// Returns true or false if the room is empty
bool StartRoom::isEmpty() const {
	return false;
}
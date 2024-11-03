#include "EmptyRoom.h"

// When the player enters nothing happens
RoomResult EmptyRoom::onEnter() const {
	return std::monostate{};
}

// Symbol on the map
std::string_view EmptyRoom::textToDisplay() const {
	return "#";
}

// Return true as the room is always empty
bool EmptyRoom::isEmpty() const {
	return true;
}
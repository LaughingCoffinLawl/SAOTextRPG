#include "EmptyRoom.h"

RoomResult EmptyRoom::onEnter() const {
	return std::monostate{};
}

std::string_view EmptyRoom::textToDisplay() const {
	return "#";
}

bool EmptyRoom::isEmpty() const {
	return true;
}
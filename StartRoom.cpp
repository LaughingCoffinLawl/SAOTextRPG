#include "StartRoom.h"

RoomResult StartRoom::onEnter() const {
	return std::monostate{};
}

std::string_view StartRoom::textToDisplay() const {
	return "S";
}

bool StartRoom::isEmpty() const {
	return false;
}
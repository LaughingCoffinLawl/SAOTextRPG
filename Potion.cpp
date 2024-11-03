#include "Potion.h"

// Returns how many HP the potion restores
int Potion::effect() const {
	return m_hpRestored;
}

// Returns the name of the item
std::string_view Potion::getName() const {
	return "potion";
}
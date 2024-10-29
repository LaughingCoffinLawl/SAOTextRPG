#include "Potion.h"

int Potion::effect() const {
	return m_hpRestored;
}

std::string_view Potion::getName() const {
	return "potion";
}
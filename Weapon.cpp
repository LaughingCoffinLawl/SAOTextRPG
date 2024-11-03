#include "Weapon.h"

// Constructor to inizialize the weapon with the damage
Weapon::Weapon(int damage)
	:m_damage{ damage }
{
}

// Retuns the weapon damage
int Weapon::getDamage() const {
	return m_damage;
}

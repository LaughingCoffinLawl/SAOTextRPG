#include "Boar.h"

// Creates a Boar with "Boar" as name, 5 as attack and 35 as health
Boar::Boar()
	: Monster("Boar", 5, 35)
{
	std::cout << "A boar has appeared!" << '\n';
}

// Boars can be printed std::cout << boar -> Boar | Damage: 5 | Health: 35
std::ostream& Boar::print(std::ostream& out) const {
	out << Monster::getName() << " | Damage: " << Monster::getDamage() << " | Health: " << Monster::getHealth();
	return out;
}

// Returns the damage as an int
int Boar::attack() const {
	std::cout << Monster::getName() << " attacks! | Dealing: " << Monster::getDamage() << " damage" << '\n';
	return Monster::getDamage();
}

// Returns the skill damage as an int
int Boar::useSkill() const {
	std::cout << Monster::getName() << " uses running attack! | Dealing: " << m_skill << " damage" << '\n';
	return m_skill;
}
#include "Goblin.h"

// Creates a Goblin with "Goblin" as name, 12 as attack and 60 as health
Goblin::Goblin()
	: Monster("Goblin", 12, 60)
{
	std::cout << "A globin has appeared!" << '\n';
}

// Goblins can be printed std::cout << goblin -> Goblin | Damage: 12 | Health: 60
std::ostream& Goblin::print(std::ostream& out) const {
	out << Monster::getName() << " | Damage: " << Monster::getDamage() << " | Health: " << Monster::getHealth();
	return out;
}

// Returns the damage as an int
int Goblin::attack() const {
	std::cout << Monster::getName() << " attacks! | Dealing: " << Monster::getDamage() << " damage" << '\n';
	return Monster::getDamage();
}

// Returns the skill damage as an int
int Goblin::useSkill() const {
	std::cout << Monster::getName() << " bonks you! | Dealing: " << m_skill << " damage" << '\n';
	return m_skill;
}
#include "Goblin.h"

Goblin::Goblin()
	: Monster("Goblin", 12, 60)
{
	std::cout << "A globin has appeared!" << '\n';
}

std::ostream& Goblin::print(std::ostream& out) const {
	out << Monster::getName() << " | Damage: " << Monster::getDamage() << " | Health: " << Monster::getHealth();
	return out;
}

int Goblin::attack() const {
	std::cout << Monster::getName() << " attacks! | Dealing: " << Monster::getDamage() << " damage" << '\n';
	return Monster::getDamage();
}

int Goblin::useSkill() const {
	std::cout << Monster::getName() << " bonks you! | Dealing: " << m_skill << " damage" << '\n';
	return m_skill;
}
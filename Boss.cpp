#include "Boss.h"

Boss::Boss()
	: Monster("Boss", 25, 250)
{
	std::cout << "The BOSS has appeared!" << '\n';
}

std::ostream& Boss::print(std::ostream& out) const {
	out << Monster::getName() << " | Damage: " << Monster::getDamage() << " | Health: " << Monster::getHealth();
	return out;
}

int Boss::attack() const {
	std::cout << Monster::getName() << " attacks! | Dealing: " << Monster::getDamage() << " damage" << '\n';
	return Monster::getDamage();
}

int Boss::useSkill() const {
	std::cout << Monster::getName() << " bonks you! | Dealing: " << m_skill << " damage" << '\n';
	return m_skill;
}
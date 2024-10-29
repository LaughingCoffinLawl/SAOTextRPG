#include "Boar.h"

Boar::Boar()
	: Monster("Boar", 5, 35)
{
	std::cout << "A boar has appeared!" << '\n';
}

std::ostream& Boar::print(std::ostream& out) const {
	out << Monster::getName() << " | Damage: " << Monster::getDamage() << " | Health: " << Monster::getHealth();
	return out;
}

int Boar::attack() const {
	std::cout << Monster::getName() << " attacks! | Dealing: " << Monster::getDamage() << " damage" << '\n';
	return Monster::getDamage();
}

int Boar::useSkill() const {
	std::cout << Monster::getName() << " uses running attack! | Dealing: " << m_skill << " damage" << '\n';
	return m_skill;
}
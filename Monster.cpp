#include "Monster.h"
#include "Potion.h"

Monster::Monster(std::string_view name, int damage, int health)
	: m_name{ name }
	, m_damage{ damage }
	, m_health{ health }
{
}

std::string_view Monster::getName() const {
	return m_name;
}

int Monster::getDamage() const {
	return m_damage;
}

int Monster::getHealth() const {
	return m_health;
}

void Monster::takeHit(int damageRecieved) {
	m_health -= damageRecieved;
}

bool Monster::isDead() const {
	return m_health <= 0;
}

std::unique_ptr<Item> Monster::drop() {
	auto item{ std::make_unique<Potion>() };
	return item;
}
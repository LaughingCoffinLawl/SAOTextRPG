#include "Monster.h"
#include "Potion.h"

// Monster constructor
Monster::Monster(std::string_view name, int damage, int health)
	: m_name{ name }
	, m_damage{ damage }
	, m_health{ health }
{
}

// Reuturns monster name
std::string_view Monster::getName() const {
	return m_name;
}

// Returns monster damage
int Monster::getDamage() const {
	return m_damage;
}

// Returns monster health
int Monster::getHealth() const {
	return m_health;
}

// Change monster health when the player attacks
void Monster::takeHit(int damageRecieved) {
	m_health -= damageRecieved;
}

// Returns true or false if the monster is dead
bool Monster::isDead() const {
	return m_health <= 0;
}

// Creates an item if drop
std::unique_ptr<Item> Monster::drop() {
	auto item{ std::make_unique<Potion>() };
	return item;
}
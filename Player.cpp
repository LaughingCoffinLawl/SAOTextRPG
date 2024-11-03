#include "Player.h"

// Construct a player with a name
Player::Player(std::string_view name)
	: m_name{ name }
{
	m_maxHealth = m_vitality * 10;
	m_health = m_vitality * 10;
	m_damage = m_strength;
}

// Return player vitality stat
int Player::getVit() const {
	return m_vitality;
}

// Return player health
int Player::getHealth() const {
	return m_health;
}

// Return player strength stat
int Player::getStr() const {
	return m_strength;
}

// Return player name 
std::string_view Player::getName() const {
	return m_name;
}

// Return player damage
int Player::getDagame() const {
	return m_damage;
}

// Return true or false if the player has a weapon
bool Player::isWeapon() const {
	if (m_weapon)
		return true;
	return false;
}

// Heals the player full 
void Player::healToFull() {
	m_health = m_maxHealth;
}

// Returns the weapon's damage if equipped
int Player::getWeaponDagame() const {
	return m_weapon->getDamage();
}

// Attacks the monster
int Player::attack() const {
	return m_damage;
}

// Level up (damage+5, health+50 as test)
void Player::levelUp() {
	m_damage += 5;
	m_health += 50;
}

// Players gets hit by monsters
void Player::takeHit(int damageRecieved) {
	m_health -= damageRecieved;
}

// Equips weapon if no weapon is already equipped
void Player::equipWeapon(std::unique_ptr<Weapon> weapon) {
	m_weapon = std::move(weapon);
	if (m_weapon)
		m_damage += m_weapon->getDamage();
}

// Adds items dropped by monsters to the inventory
void Player::addToInventory(std::unique_ptr<Item> item) {
	std::cout << "Item added to your inventory!" << '\n';
	m_inventory.push_back(std::move(item));
}

// Use items from the inventory
void Player::useItem(int index) {
	if ((m_maxHealth - m_health) < m_inventory[index].get()->effect()) {
		m_health += m_inventory[index].get()->effect();
		m_inventory.erase(m_inventory.begin() + index);
	} else {
		m_health = m_maxHealth;
	}
}

// Returns the whole inventory as text
void Player::getInventory() const {
	if (!m_inventory.empty()) {
		int index{ 0 };
		for (const auto& items : m_inventory) {
			std::cout << index << ": " << items->getName() << '\n';
			++index;
		}
		std::cout << "5: Exit\n";
	}
	else {
		std::cout << "Your inventory is empty!" << '\n';
	}
}

// Returns true or false if the player is dead
bool Player::isDead() const {
	return m_health <= 0;
}
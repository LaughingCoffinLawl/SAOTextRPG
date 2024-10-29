#include "Player.h"

Player::Player(std::string_view name)
	: m_name{ name }
{
	m_maxHealth = m_vitality * 10;
	m_health = m_vitality * 10;
	m_damage = m_strength;
}

int Player::getVit() const {
	return m_vitality;
}

int Player::getHealth() const {
	return m_health;
}

int Player::getStr() const {
	return m_strength;
}

std::string_view Player::getName() const {
	return m_name;
}

int Player::getDagame() const {
	return m_damage;
}

bool Player::isWeapon() const {
	if (m_weapon)
		return true;
	return false;
}

void Player::healToFull() {
	m_health = m_maxHealth;
}

int Player::getWeaponDagame() const {
	return m_weapon->getDamage();
}

int Player::attack() const {
	return m_damage;
}

void Player::levelUp() {
	m_damage += 5;
	m_health += 50;
}

void Player::takeHit(int damageRecieved) {
	m_health -= damageRecieved;
}

void Player::equipWeapon(std::unique_ptr<Weapon> weapon) {
	m_weapon = std::move(weapon);
	if (m_weapon)
		m_damage += m_weapon->getDamage();
}

void Player::addToInventory(std::unique_ptr<Item> item) {
	std::cout << "Item added to your inventory!" << '\n';
	m_inventory.push_back(std::move(item));
}

void Player::useItem(int index) {
	if ((m_maxHealth - m_health) < m_inventory[index].get()->effect())
		m_health += m_inventory[index].get()->effect();
	else {
		m_health = m_maxHealth;
	}
}

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

bool Player::isDead() const {
	return m_health <= 0;
}
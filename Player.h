#include "Weapon.h"
#include "Item.h"

#include <string>
#include <iostream>
#include <vector>	

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	explicit Player(std::string_view name = "Player");
	~Player() = default;
	int getVit() const;
	int getStr() const;
	int getDagame() const;
	int getHealth() const;
	bool isWeapon() const;
	int getWeaponDagame() const;
	void healToFull();
	int attack() const;
	void levelUp();
	std::string_view getName() const;
	void equipWeapon(std::unique_ptr<Weapon> weapon);
	void addToInventory(std::unique_ptr<Item> item);
	void useItem(int index);
	void getInventory() const;
	void takeHit(int damageReceived);
	bool isDead() const;
	friend std::ostream& operator<<(std::ostream& out, const Player& player) {
		std::cout << "Health: " << player.m_health << '\n';
		std::cout << "Dagame: " << player.m_damage << '\n';
		std::cout << "Strength: " << player.m_strength << '\n';
		std::cout << "Intelligence: " << player.m_intelligence << '\n';
		std::cout << "Dexterity: " << player.m_dexterity << '\n';
		if (player.m_weapon)
			std::cout << "Weapon equipped: " << player.m_weapon.get()->getDamage() << '\n';
		else
			std::cout << "No weapon equipped" << '\n';
		return out;
	}
private:
	std::string m_name{};
	int m_maxHealth{};
	int m_health{};
	int m_damage{};
	int m_vitality{ 10 };
	int m_strength{ 10 };
	int m_intelligence{ 10 };
	int m_dexterity{ 10 };
	std::unique_ptr<Weapon> m_weapon{};
	std::vector<std::unique_ptr<Item>> m_inventory{};
};

#endif // !PLAYER_H


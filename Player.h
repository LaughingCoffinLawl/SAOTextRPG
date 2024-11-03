#include "Weapon.h"
#include "Item.h"

#include <string>
#include <iostream>
#include <vector>	

#ifndef PLAYER_H
#define PLAYER_H

// Player class

class Player {
public:
	explicit Player(std::string_view name = "Player");										// Constructor
	~Player() = default;																	// Destructor
	int getVit() const;																		// Returns m_vitality
	int getStr() const;																		// Returns m_strength
	int getDagame() const;																	// Returns m_damage
	int getHealth() const;																	// Returns m_health
	bool isWeapon() const;																	// Returns true or false
	int getWeaponDagame() const;															// Returns equipped weapon dmg
	void healToFull();																		// Heals the player to full	
	int attack() const;																		// Attacks monster 
	void levelUp();																			// Level up event
	std::string_view getName() const;														// Returns m_name
	void equipWeapon(std::unique_ptr<Weapon> weapon);										// Equips the new weapon
	void addToInventory(std::unique_ptr<Item> item);										// Add to inventory
	void useItem(int index);																// Use item from inventory
	void getInventory() const;																// Return m_inventory
	void takeHit(int damageReceived);														// Gets hit from monster
	bool isDead() const;																	// True or false if dead
	friend std::ostream& operator<<(std::ostream& out, const Player& player) {
		std::cout << "Health: " << player.m_health << '\n';
		std::cout << "Dagame: " << player.m_damage << '\n';
		std::cout << "Strength: " << player.m_strength << '\n';								// Prints the object
		std::cout << "Intelligence: " << player.m_intelligence << '\n';
		std::cout << "Dexterity: " << player.m_dexterity << '\n';
		if (player.m_weapon)
			std::cout << "Weapon equipped: " << player.m_weapon.get()->getDamage() << '\n';
		else
			std::cout << "No weapon equipped" << '\n';
		return out;
	}
private:
	std::string m_name{};									// Player name
	int m_maxHealth{};										// Player max health
	int m_health{};											// Player health
	int m_damage{};											// Player damage
	int m_vitality{ 10 };									// Vitality stat
	int m_strength{ 10 };									// Strength stat
	int m_intelligence{ 10 };								// Intelligence stat
	int m_dexterity{ 10 };									// Dexterity stat
	std::unique_ptr<Weapon> m_weapon{};						// Weapon pointer
	std::vector<std::unique_ptr<Item>> m_inventory{};		// Inventory (max 5 slots)
};

#endif // !PLAYER_H


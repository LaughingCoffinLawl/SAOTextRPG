#include "Item.h"

#include <iostream>

#ifndef MONSTER_H
#define MONSTER_H

// Base monster class

class Monster {
public:
	Monster(std::string_view name, int damage, int health);							// Constructor with name, damage and health of the monster
	virtual ~Monster() = default;													// Destructor
	virtual std::ostream& print(std::ostream& out) const = 0;						// Object can be printed
	std::string_view getName() const;												// Returns name
	int getDamage() const;															// Returns damage
	int getHealth() const;															// Returns health
	void takeHit(int damageRecieved);												// Monster take hit
	bool isDead() const;															// True or false 
	virtual int attack() const = 0;													// Attacks the player
	virtual int useSkill() const = 0;												// Attacks the player
	virtual std::unique_ptr<Item> drop();											// Drop event

	friend std::ostream& operator<<(std::ostream& out, const Monster& monster) {	// std::cout << monster;
		monster.print(out);
		return out;
	}
private:
	std::string m_name{};															// Monster name
	int m_damage{};																	// Monster damage
	int m_health{};																	// Monster health
}; 
#endif // !MONSTER_H


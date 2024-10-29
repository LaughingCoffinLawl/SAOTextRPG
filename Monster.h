#include "Item.h"

#include <iostream>

#ifndef MONSTER_H
#define MONSTER_H

class Monster {
public:
	Monster(std::string_view name, int damage, int health);
	virtual ~Monster() = default;
	virtual std::ostream& print(std::ostream& out) const = 0;
	std::string_view getName() const;
	int getDamage() const;
	int getHealth() const;
	void takeHit(int damageRecieved);
	bool isDead() const;
	virtual int attack() const = 0;
	virtual int useSkill() const = 0;
	virtual std::unique_ptr<Item> drop();

	friend std::ostream& operator<<(std::ostream& out, const Monster& monster) {
		monster.print(out);
		return out;
	}
private:
	std::string m_name{};
	int m_damage{};
	int m_health{};
}; 
#endif // !MONSTER_H


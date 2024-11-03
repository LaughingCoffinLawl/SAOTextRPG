#include "Random.h"
#include "Monster.h"
#include "Weapon.h"
#include "Boar.h"
#include "Goblin.h"
#include "Boss.h"

#ifndef MONSTER_FACTORY_H
#define MONSTER_FACTORY_H

// Monster factory class

namespace MonsterFactory {

	std::unique_ptr<Monster> createRandomMonster();		// Creates a random monster

	std::unique_ptr<Weapon> createRandomWeapon();		// Creates a random weapon

	std::unique_ptr<Boss> spawnBoss();					// Creates a boss
}

#endif // !MONSTER_FACTORY_H


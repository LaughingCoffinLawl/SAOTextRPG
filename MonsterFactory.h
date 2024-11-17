#include "Boar.h"
#include "Boss.h"
#include "Goblin.h"
#include "Monster.h"
#include "Random.h"
#include "Weapon.h"

#ifndef MONSTER_FACTORY_H
#define MONSTER_FACTORY_H

// Monster factory class

namespace MonsterFactory {

	std::unique_ptr<Monster> createRandomMonster();	  // Creates a random monster

	std::unique_ptr<Weapon> createRandomWeapon();	// Creates a random weapon

	std::unique_ptr<Boss> spawnBoss();	 // Creates a boss
}	// namespace MonsterFactory

#endif	 // !MONSTER_FACTORY_H

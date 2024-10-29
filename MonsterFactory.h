#include "Random.h"
#include "Monster.h"
#include "Weapon.h"
#include "Boar.h"
#include "Goblin.h"
#include "Boss.h"

#ifndef MONSTER_FACTORY_H
#define MONSTER_FACTORY_H

namespace MonsterFactory {

	std::unique_ptr<Monster> createRandomMonster();

	std::unique_ptr<Weapon> createRandomWeapon();

	std::unique_ptr<Boss> spawnBoss();
}

#endif // !MONSTER_FACTORY_H


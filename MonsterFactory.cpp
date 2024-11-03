#include "MonsterFactory.h"

// Creates a random monster
std::unique_ptr<Monster> MonsterFactory::createRandomMonster() {
	int monsterToSpawn{ Random::RollD20() % 2 };
	switch (monsterToSpawn) {
	case 0:		return std::make_unique<Boar>();
	case 1:		return std::make_unique<Goblin>();
	default:	return nullptr;
	}
}

// Creates a random weapon with random damage
// Legendary if the dice rolls 20
std::unique_ptr<Weapon> MonsterFactory::createRandomWeapon() {
	int weaponToCreate{ Random::RollD20() };
	if (weaponToCreate == 20) {
		std::cout << "You found a LEGENDARY weapon!" << '\n';
		return std::make_unique<Weapon>(Random::get(10, 20));
	}
	else {
		std::cout << "You found a normal weapon!" << '\n';
		return std::make_unique<Weapon>(Random::get(1, 10));
	}
}
// Spawns the boss
std::unique_ptr<Boss> MonsterFactory::spawnBoss() {
	return std::make_unique<Boss>();
}

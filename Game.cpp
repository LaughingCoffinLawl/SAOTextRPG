#include "Game.h"

Game::Game()
	: m_player{ std::make_unique<Player>(playerName()) }
	, m_dungeon{ std::make_unique<Dungeon>(DungeonsPrefab::createPrefabs()) }
{
	init();
	update();
}

bool Game::getPlaying() const{
	return m_playing;
}

void Game::setPlaying() {
	m_playing = !m_playing;
}

bool Game::isBossDead(const Boss& boss) const {
	return boss.isDead();
}

void Game::init() const {
	std::cout << "Welcome to SAO RPG: " << m_player->getName() << '\n';
	std::cout << "These are you stats: \n" << *m_player << '\n';
	std::cout << "Dungeon has been created!" << '\n';
}

std::string Game::playerName() const {
	while (getPlaying()) {
		std::cout << "Enter your name: ";
		std::string name;
		std::cin >> name;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		return name;
	}
	return "Hero";
}

char Game::getPlayerDirection() const {
	while (true) {
		std::cout << "Enter the direction of the room you want to go next: (WASD)";
		char direction;
		std::cin >> direction;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (direction) {
		case 'W':
		case 'w':
		case 'A':
		case 'a':
		case 'S':
		case 's':
		case 'D':
		case 'd':
			return direction;
		default:
			continue;
		}
	}
}

int Game::getInventorySelection() const {
	while (true) {
		std::cout << "Select the item you want to use (5 to exit): ";
		int item;
		std::cin >> item;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (item) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return item;
		case 5:
			break;
		default:
			continue;
		}

		return item;
	}
}

int Game::getBattleSelection() const {
	while (true) {
		std::cout << "Select your next action: \n";
		std::cout << "0. Attack\n";
		std::cout << "1. Items\n";
		std::cout << "2. Shop\n";
		std::cout << "3. Flee\n";

		int action;
		std::cin >> action;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (action) {
		case 0:
		case 1:
		case 2:
		case 3:
			return action;
		default:
			continue;
		}
	}
}

bool Game::battle(Monster& monster) {
	while (!m_player->isDead() && !monster.isDead()) {

		switch (int action{ getBattleSelection() }) {
		case 0:
			monster.takeHit(m_player->attack());
			std::cout << "You dealt " << m_player->getDagame() << '\n';
			break;
		case 1:
			m_player->getInventory();
			if (getInventorySelection() != 5) 
				m_player->useItem(getInventorySelection());
			break;
		case 2:
			std::cout << "Shop in under construction!" << '\n';
			break;
		case 3:
			std::cout << "You fled the battle!" << '\n';
			return false;
		default:
			std::cout << "Something went wrong!\n";
			break;
		}

		if (!monster.isDead()) {
			m_player->takeHit(monster.attack());
			std::cout << "Your current health: " << m_player->getHealth() << '\n';
		}
	}
	return !m_player->isDead();
}

bool Game::bossBattle(Boss& boss) {
	while (!m_player->isDead() && !boss.isDead()) {

		switch (int action{ getBattleSelection() }) {
		case 0:
			boss.takeHit(m_player->attack());
			std::cout << "You dealt " << m_player->getDagame() << '\n';
			break;
		case 1:
			m_player->getInventory();
			if (getInventorySelection() != 5)
				m_player->useItem(getInventorySelection());
			break;
		case 2:
			std::cout << "Shop in under construction!" << '\n';
			break;
		case 3:
			std::cout << "You cannot flee during a boss!" << '\n';
			break;
		default:
			std::cout << "Something went wrong!\n";
			break;
		}

		if (!boss.isDead()) {
			m_player->takeHit(boss.attack());
			std::cout << "Your current health: " << m_player->getHealth() << '\n';
		}

		if (isBossDead(boss)) {
			createNewDungeon();
		}
	}
	return !m_player->isDead();
}

void Game::update() {
	while (getPlaying()) {
		m_dungeon->display();
		auto event{ m_dungeon->movePlayer(getPlayerDirection()) };

		if (std::holds_alternative<std::unique_ptr<Monster>>(event)) {
			handleMonsterEvent(event);
		}

		if (std::holds_alternative<std::unique_ptr<Weapon>>(event)) {
			handleWeaponEvent(event);
		}

		if (std::holds_alternative<std::unique_ptr<Boss>>(event)) {
			handleBossEvent(event);
		}
	}
}

void Game::handleMonsterEvent(const RoomResult& event) {
	std::cout << "A monster appeared: ";
	const auto& monsterPtr{ std::get<std::unique_ptr<Monster>>(event) };
	std::cout << *monsterPtr << "\n The battle starts!\n";

	if (battle(*monsterPtr)) {
		std::cout << "You won!\n";
		std::cout << "Your current health: " << m_player->getHealth() << '\n';
		handleLevelup();
		handleMonsterDrop(*monsterPtr);
	}
	else if (m_player->isDead()) {
		std::cout << "Game over!\n";
		setPlaying();
	} else {
			std::cout << "You fled the battle and returned to the previous room.\n";
	}
}

void Game::handleBossEvent(const RoomResult& event) {
	std::cout << "A monster appeared: ";
	const auto& bossPtr{ std::get<std::unique_ptr<Boss>>(event) };
	std::cout << *bossPtr << "\n The battle starts!\n";

	if (bossBattle(*bossPtr)) {
		std::cout << "You won!\n";
		std::cout << "Your current health: " << m_player->getHealth() << '\n';
		handleLevelup();
		handleMonsterDrop(*bossPtr);
	}
	else if (m_player->isDead()) {
		std::cout << "Game over!\n";
		setPlaying();
	}
	else {
		std::cout << "You fled the battle and returned to the previous room.\n";
	}
}

void Game::handleMonsterDrop(Monster& monsterPtr) const {
	if (Random::RollD20() % 2 == 0) {
		std::cout << "The monster dropped an item!\n";
		auto drop{ monsterPtr.drop() };
		std::cout << "You found a " << drop->getName();
		m_player->addToInventory(std::move(drop));
		std::cout << " added to you inventory!";
	}
}

void Game::handleWeaponEvent(RoomResult& event) const {
	auto& weaponPtr{ std::get<std::unique_ptr<Weapon>>(event) };
	std::cout << "Weapon Damage: " << weaponPtr->getDamage() << '\n';
	if (m_player->isWeapon()) {

	} else {
		m_player->equipWeapon(std::move(weaponPtr));
	}
	
	std::cout << "Weapon has been equipped!\n";
}

void Game::handleLevelup() const {
	std::cout << "Level up! Damage and Health increased from: D: " << m_player->getDagame() << " H: " << m_player->getHealth();
	m_player->levelUp();
	std::cout << " | To: D: " << m_player->getDagame() << " H: " << m_player->getHealth() << '\n';
}

void Game::handleSwitchWeapon(std::unique_ptr<Weapon> weapon) const {
	if (m_player->isWeapon()) {
		std::cout << " | Current weapon damage: " << m_player->getWeaponDagame() << " :";
	}
	std::cout << " | New weapon damage: " << weapon->getDamage() << " :";

	if (getSwitchWeaponInput()) {
		m_player->equipWeapon(std::move(weapon));
		std::cout << "Weapon has been equipped!\n";
	}
	else {
		std::cout << "You left the weapon there.\n";
	}
}

bool Game::getSwitchWeaponInput() const {
	while (true) {
		std::cout << "Do you want to switch weapons? (y/n): ";
		char choice;
		std::cin >> choice;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (choice) {
		case 'y':
		case 'Y':
			return true;
		case 'n':
		case 'N':
			return false;
		default:
			continue;
		}
	}
}

void Game::createNewDungeon() {
	std::cout << "\033[32mCongratulations! You defeated the boss! A new dungeons has been created!\033[0m\n";
	m_dungeon = std::make_unique<Dungeon>(DungeonsPrefab::createPrefabs());
	m_player->healToFull();
	m_dungeon->resetPlayerPosition();
}

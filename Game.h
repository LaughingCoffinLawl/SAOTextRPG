#include "Player.h"
#include "Dungeon.h"
#include "DungeonsPrefab.h"
#include "Potion.h"

#ifndef GAME_H
#define GAME_H

// Game class

class Game {
public:
	[[noreturn]] explicit Game();										// Constructor
	bool getPlaying() const;											// Returns m_playing state
	void setPlaying();													// Change m_playing state
	void init() const;													// Inizialize the game
	void update();														// Main loop
	bool battle (Monster& monster);										// Handle the battle loop
	bool bossBattle(Boss& boss);										// Handle the boss battle loop
	bool isBossDead(const Boss& boss) const;							// Return true or false if the boss is dead
	std::string playerName() const;										// Ask the player to enter a name
	int getBattleSelection() const;										// Handle battle selection (attack, flee, shop...)
	char getPlayerDirection() const;									// Gets the player direction
	int getInventorySelection() const;									// Gets which item the player wants to use
	bool getSwitchWeaponInput() const;									// If the player wants to switch equipped weapon
	void handleMonsterEvent(const RoomResult& event);					// Spawns a monster in a Normal Room
	void handleBossEvent(const RoomResult& event);						// Spawns a boss in a Boss Room
	void handleMonsterDrop(Monster& monsterPtr) const;					// Handle monsters' drop
	void handleWeaponEvent(RoomResult& event) const;					// Spawns a weapon in a Treasure Room
	void handleLevelup() const;											// Handle player level up
	void handleSwitchWeapon(std::unique_ptr<Weapon> weapon) const;		// Handle if the player wants to switch weapon
	void createNewDungeon();											// Creates a new dungeon
private:
	bool m_playing{ true };												// Game state (true or false)
	std::unique_ptr<Player> m_player;									// Player pointer
	std::unique_ptr<Dungeon> m_dungeon;									// Dungeon pointer
};

#endif // !GAME_J

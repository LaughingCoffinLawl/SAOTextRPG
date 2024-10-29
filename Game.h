#include "Player.h"
#include "Dungeon.h"
#include "DungeonsPrefab.h"
#include "Potion.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
	explicit Game();
	bool getPlaying() const;
	void setPlaying();
	void init() const;
	void update [[noreturn]]();
	bool battle (Monster& monster);
	bool bossBattle(Boss& boss);
	bool isBossDead(const Boss& boss) const;
	std::string playerName() const;
	int getBattleSelection() const;
	char getPlayerDirection() const;
	int getInventorySelection() const;
	bool getSwitchWeaponInput() const;
	void handleMonsterEvent(const RoomResult& event);
	void handleBossEvent(const RoomResult& event);
	void handleMonsterDrop(Monster& monsterPtr) const;
	void handleWeaponEvent(RoomResult& event) const;
	void handleLevelup() const;
	void handleSwitchWeapon(std::unique_ptr<Weapon> weapon) const;
	void createNewDungeon();
private:
	bool m_playing{ true };
	std::unique_ptr<Player> m_player;
	std::unique_ptr<Dungeon> m_dungeon;
};

#endif // !GAME_J

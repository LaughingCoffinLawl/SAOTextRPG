#include "Monster.h"

#ifndef GOBLIN_H
#define GOBLIN_H

// Goblin class

class Goblin : public Monster {
public:	
	explicit Goblin();											// Constructor
	int attack() const override;								// Returns damage
	int useSkill() const override;								// Returns skill damage
	std::ostream& print(std::ostream& out) const override;		// Object can be printed
private:
	int m_skill{ 20 };											// Skill damage
};

#endif // !GOBLIN_H


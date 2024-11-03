#include "Monster.h"

#ifndef BOAR_H
#define BOAR_H

class Boar : public Monster {
public:
	explicit Boar();										// Constructor
	int attack() const override;							// Returns attack as an int
	int useSkill() const override;							// Returns skill attack as an int
	std::ostream& print(std::ostream& out) const override;	// Object can be printed
private:
	int m_skill{ 9 };										// Skill damage
};

#endif // !BOAR_H


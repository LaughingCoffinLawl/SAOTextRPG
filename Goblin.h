#include "Monster.h"

#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin : public Monster {
public:
	explicit Goblin();
	int attack() const override;
	int useSkill() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	int m_skill{ 20 };
};

#endif // !GOBLIN_H


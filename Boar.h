#include "Monster.h"

#ifndef BOAR_H
#define BOAR_H

class Boar : public Monster {
public:
	explicit Boar();
	int attack() const override;
	int useSkill() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	int m_skill{ 9 };
};

#endif // !BOAR_H


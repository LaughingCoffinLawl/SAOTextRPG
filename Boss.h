#ifndef BOSS_H
#define BOSS_H

#include "Monster.h"

class Boss : public Monster {
public:
    explicit Boss();
    int attack() const override;
    int useSkill() const override;
    std::ostream& print(std::ostream& out) const override;
private:
    int m_skill{ 40 };
};

#endif // !BOSS_H


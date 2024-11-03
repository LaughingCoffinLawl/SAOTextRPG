#ifndef BOSS_H
#define BOSS_H

#include "Monster.h"

// Boss class

class Boss : public Monster {
public:
    explicit Boss();                                        // Constructor
    int attack() const override;                            // Returns an int as the attack
    int useSkill() const override;
    std::ostream& print(std::ostream& out) const override;  // Can be printed with std::cout << boss;
private:
    int m_skill{ 40 };                                      // Skill damage
};

#endif // !BOSS_H


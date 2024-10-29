#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
	explicit Weapon(int damage);
	~Weapon() = default;
	int getDamage() const;
private:
	int m_damage{ 0 };
};

#endif // !WEAPON_H


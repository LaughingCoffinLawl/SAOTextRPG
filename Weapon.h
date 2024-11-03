#ifndef WEAPON_H
#define WEAPON_H

// Weapon class
class Weapon {
public:
	explicit Weapon(int damage);	// Constructor
	~Weapon() = default;			// Destructor
	int getDamage() const;			// Returns the damage of the weapon
private:
	int m_damage{ 0 };				// Damage (inizialized as 0)
};

#endif // !WEAPON_H


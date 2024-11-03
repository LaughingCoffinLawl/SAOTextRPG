#include "Item.h"

#ifndef POTION_H
#define POTION_H

// Potion class

class Potion : public Item {
public:
	Potion() = default;							// Default constructor
	int effect() const override;				// Returns the effect of the item (e.g. potion heals)
	std::string_view getName() const override;	// Returns the name of the item
private:
	int m_hpRestored{ 100 };
};

#endif // !POTION_H


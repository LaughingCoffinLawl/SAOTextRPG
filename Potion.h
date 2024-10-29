#include "Item.h"

#ifndef POTION_H
#define POTION_H

class Potion : public Item {
public:
	Potion() = default;
	int effect() const override;
	std::string_view getName() const override;
private:
	int m_hpRestored{ 100 };
};

#endif // !POTION_H


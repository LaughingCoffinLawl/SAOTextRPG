#include <string>

#ifndef ITEM_H
#define ITEM_H

// Virtual item class (cannot be instantiated)

class Item {
public:
	Item() = default;
	virtual ~Item() = default;
	virtual int effect() const = 0;
	virtual std::string_view getName() const = 0;
};

#endif // !ITEM_H


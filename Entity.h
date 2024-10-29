#include <string>

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
	Entity(std::string_view name = "Entity", int vit = 10, int str = 10, int intl = 10, int dex = 10);
	virtual ~Entity() = default;
	std::string_view getName() const;
	int getVit() const;
	int getStr() const;
	virtual std::ostream& print(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const Entity& entity) {
		entity.print(out);
		return out;
	}

private:
	std::string m_name{};
};

#endif // !ENTITY_H


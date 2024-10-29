#include "Entity.h"

#include <iostream>

Entity::Entity(std::string_view name, int vit = 10, int str = 10, int intl = 10, int dex = 10) 
	: m_name{ name }
	, m_vitality{ vit }
	, m_strength{ str }
	, m_intelligence{ intl }
	, m_dexterity{ dex }
{
}

std::ostream& Entity::print(std::ostream& out) const {
	out << "You're in entity";
	return out;
}

std::string_view Entity::getName() const { return m_name; }
int Entity::getVit() const { return m_vitality; }
int Entity::getStr() const { return m_strength; }
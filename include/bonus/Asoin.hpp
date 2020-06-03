#ifndef ASOIN_HPP
#define ASOIN_HPP

#include "Unite.hpp"


class Asoin : public Unite
{
public:
	Asoin(sf::Color c,int aHp, int aDmg, int aPrix, int aPortee) : Unite(c,aHp, aDmg, aPrix, aPortee) {}
	virtual *Action agit() = 0;
};

#endif

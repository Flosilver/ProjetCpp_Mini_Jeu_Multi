#ifndef INFIRMIER_HPP
#define INFIRMIER_HPP

#include "Asoin.hpp"

class Infirmier : public Asoin
{
public:
	Infirmier(sf::Color c) : Asoin(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

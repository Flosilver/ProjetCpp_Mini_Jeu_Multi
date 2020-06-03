#ifndef CHEVALIER_HPP
#define CHEVALIER_HPP

class Chevalier : public ATank
{
public:
	Chevalier(sf::Color c) : ATank(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

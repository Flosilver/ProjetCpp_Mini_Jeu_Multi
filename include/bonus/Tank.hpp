#ifndef TANK_HPP
#define TANK_HPP

class Tank : public ATank
{
public:
	Tank(sf::Color c) : ATank(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

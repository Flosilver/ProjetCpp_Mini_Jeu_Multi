#ifndef ARCHER_HPP
#define ARCHER_HPP

class Archer : public ADistance
{
public:
	Archer(sf::Color c) : ADistance(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

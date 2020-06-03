#ifndef ADISTANCE_HPP
#define ADISTANCE_HPP

class ADistance : public Unite
{
public:
	ADistance(sf::Color c,int aHp, int aDmg, int aPrix, int aPortee) : Unite(c,aHp, aDmg, aPrix, aPortee) {}
	virtual *Action agit() = 0;
};

#endif

#ifndef DRONESNIPER_HPP
#define DRONESNIPER_HPP

class DroneSniper : public ADistance
{
public:
	DroneSniper(sf::Color c) : ADistance(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

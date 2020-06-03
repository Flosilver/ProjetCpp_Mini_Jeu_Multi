#ifndef ARTILLERIE_HPP
#define ARTILLERIE_HPP

class Artillerie : public ADistance
{
public:
	Artillerie(sf::Color c) : ADistance(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

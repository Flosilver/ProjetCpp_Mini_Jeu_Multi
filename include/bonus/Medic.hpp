#ifndef MEDIC_HPP
#define MEDIC_HPP

class Medic : public Asoin
{
public:
	Medic(sf::Color c) : Asoin(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

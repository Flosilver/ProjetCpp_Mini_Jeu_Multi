#ifndef PRETRE_HPP
#define PRETRE_HPP

class Pretre : public Asoin
{
public:
	Pretre(sf::Color c) : Asoin(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

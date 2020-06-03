#ifndef ATANK_HPP
#define ATANK_HPP

class ATank : public Unite
{
public:
	ATank(sf::Color c,int aHp, int aDmg, int aPrix, int aPortee) : Unite(c,aHp, aDmg, aPrix, aPortee) {}
	virtual *Action agit() = 0;
};

#endif

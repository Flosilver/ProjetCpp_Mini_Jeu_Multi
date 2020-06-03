#ifndef EXOARMURE_HPP
#define EXOARMURE_HPP

class ExoArmure : public ATank
{
public:
	ExoArmure(sf::Color c) : ATank(c, aHp, aDmg, aPrix, aPortee){}
	virtual *Action agit() = 0;
};

#endif

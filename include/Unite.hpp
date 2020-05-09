#ifndef UNITE_HPP
#define UNITE_HPP

#include "Element.hpp"
//#include "Action.hpp"

class Unite : public Element
{
protected:
	int hp;		// point de vie de l'unité
	int dmg;	// >0 = inflige des dégats ; <0 = soigne
	int prix;	// combien il rapporte à l'ennemis quand il meurt
	int portee;	// la distance à laquelle l'unité peut attaquer/soigner

public:
	Unite(sf::Color c) : Element(c), hp(0), dmg(0), prix(0), portee(0) {}
	virtual ~Unite() { std::cout << "dest_Unite" << std::endl; }

	//virtual *Action agit() = 0;
};

#endif

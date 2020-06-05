#ifndef ACOMBATTANT_HPP
#define ACOMBATTANT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Unite.hpp"

class ACombattant : public Unite
{
public:
	ACombattant(const sf::Color& c, int eq, int id, int aHp, int aDmg, int aPrix) : Unite(c, eq, id, aHp, aDmg, aPrix, 3) {}
	virtual ~ACombattant() { std::cout << "\tdest_ACombattant"; }
	ACombattant& operator=(const ACombattant& ac){
		pos = ac.pos;
		couleur = ac.couleur;
		equipe = ac.equipe;
		indice = ac.indice;
		hp = ac.hp;
		dmg = ac.dmg;
		prix = ac.prix;
		portee = ac.portee;
		return *this;
	}
	//virtual *Action agit() = 0;
};

#endif

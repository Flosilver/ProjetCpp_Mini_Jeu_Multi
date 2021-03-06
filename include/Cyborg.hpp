#ifndef CYBORG_HPP
#define CYBORG_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ACombattant.hpp"

class Cyborg : public ACombattant
{
public:
	Cyborg(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos) : ACombattant(c, eq, id, aPos, VIE_CYBORG, DMG_CYBORG, GAIN_CYBORG){}		// couleur, n° equipe, id dans vector<sprites>, vie, dmg, prix rapportée si tuée
	~Cyborg() { std::cout << "\tdest_Cyborg"; }
	Cyborg& operator=(const Cyborg& c){
		pos = c.pos;
		couleur = c.couleur;
		equipe = c.equipe;
		indice = c.indice;
		hp = c.hp;
		dmg = c.dmg;
		prix = c.prix;
		portee = c.portee;
		return *this;
	}
	//virtual *Action agit() = 0;
	const int getHP() const {return hp;}
};

#endif

   

#ifndef SOLDAT_HPP
#define SOLDAT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ACombattant.hpp"

class Soldat : public ACombattant
{
public:
	Soldat(sf::Color c, int eq, int id) : ACombattant(c, eq, id, 20, 6, 12){}		// couleur, n° equipe, id dans vector<sprites>, vie, dmg, prix rapportée si tuée
	~Soldat() { std::cout << "\tdest_Soldat"; }
	Soldat& operator=(const Soldat& s){
		pos = s.pos;
		couleur = s.couleur;
		equipe = s.equipe;
		indice = s.indice;
		hp = s.hp;
		dmg = s.dmg;
		prix = s.prix;
		portee = s.portee;
		return *this;
	}
	//virtual *Action agit() = 0;
};

#endif


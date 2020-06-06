#ifndef HABITATION_HPP
#define HABITATION_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Batiment.hpp"
#include "Unite.hpp"

class Habitation : public Batiment
{
	public:
	Habitation(int eq, int id): Batiment(eq, id, 1, 10){}//std::cout << "hab créée: " << eq << "\tid: " << id << std::endl;}
	Habitation() {}
	~Habitation() { std::cout << "\tdest_Habitation"; }
	Habitation& operator=(const Habitation& h){
		pos = h.pos;
		couleur = h.couleur;
		equipe = h.equipe;
		indice = h.indice;
		coolDown = h.coolDown;
		niveau = h.niveau;
		return *this;
	}
	
	Unite* genereUnite(int id, const sf::Vector2f& posU);	// Factory d'Unite: ACombattant
};

#endif

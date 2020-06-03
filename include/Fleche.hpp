#ifndef FLECHE_HPP
#define FLECHE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Unite.hpp"

class Fleche : public Unite
{
	public:
		Fleche(sf::Color c, int eq, int id, int dmg): Unite(c, eq, id, 1, dmg, 0, 0){}	//couleur, n° équipe, id dans vecteur du jeu, hp, dégats, prix rapporté à l'enemis qd détruite, portée
		~Fleche() { std::cout << "\tdest Fleche" << std::endl; }
		Fleche& operator=(const Fleche& f){
			pos = f.pos;
			couleur = f.couleur;
			equipe = f.equipe;
			indice = f.indice;
			hp = f.hp;
			dmg = f.dmg;
			prix = f.prix;
			portee = f.portee;
			return *this;
		}
		//virtual *Action agit() = 0;
};

#endif

/*#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.hpp"*/

#include "Unite.hpp"
#include "Attaque.hpp"
#include "Deplacement.hpp"


Unite& Unite::operator=(const Unite& u){
		pos = u.pos;
		couleur = u.couleur;
		equipe = u.equipe;
		indice = u.indice;
		hp = u.hp;
		dmg = u.dmg;
		prix = u.prix;
		portee = u.portee;
		return *this;
	}

/* Renvoie la zone où l'unité peut toucher un adversaire */
const sf::IntRect Unite::getHitZone(){
	switch (equipe){
		case 1:			// equipe de gauche -> hit zone a droite
			return sf::IntRect(pos.x + U_SP_W / 2, pos.y, U_SP_W / 2 + portee, U_SP_H);
			break;
		
		case 2:
			return sf::IntRect(pos.x - portee, pos.y, U_SP_W / 2 + portee, U_SP_H);
			break;
			
		default:
			return sf::IntRect(pos.x, pos.y, U_SP_W, U_SP_H);
			break;
	}
	//return sf::IntRect(pos.x + U_SP_W / 2, pos.y, U_SP_W / 2 + portee, U_SP_H);
}

/* générétion d'une action en fonction de l'environement */
Action* Unite::agit(std::vector<IAttaquable*>& v, const sf::Vector2f& aVect){
	for (std::vector<IAttaquable*>::iterator it = v.begin() ; it != v.end() ; ++it){
		IAttaquable* pia = *it;
		IAttaquable& ria = *pia;
		if ( this->getHitZone().intersects(pia->getHitBox()) ){
			return new Attaque(*this, ria);
		}
	}
	return new Deplacement(*this, aVect);
}

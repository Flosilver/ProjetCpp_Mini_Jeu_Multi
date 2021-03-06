#ifndef FLECHE_HPP
#define FLECHE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Unite.hpp"

//class Unite;

class Fleche : public Unite
{
	protected:
		float angle;
		
	public:
		Fleche(sf::Color c, int eq, int id, const sf::Vector2f& aPos, int dmg): Unite(c, eq, id, aPos, 1, dmg, 0, 0), angle(90){}	//couleur, n° équipe, id dans vecteur du jeu, hp, dégats, prix rapporté à l'enemis qd détruite, portée
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
		
		const sf::IntRect getHitZone();
		
		/* méthodes de IPeriodique */
		bool checkTimer(){
			sf::Time tps = timer.getElapsedTime();
			int check = tps.asMilliseconds();
			return check >= FLECHE_DELAI;
		}
		
		/* accesseurs */
		void rotate(float a) { angle += a;}
		void setAngle(float aAngle) { angle = aAngle; }
};


#endif

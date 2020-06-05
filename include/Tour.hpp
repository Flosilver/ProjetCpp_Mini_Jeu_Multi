#ifndef TOUR_HPP
#define TOUR_HPP

#include <SFML/Graphics.hpp>
//#include <string>
#include <iostream>

#include "Element.hpp"
#include "Tourelle.hpp"
#include "config.hpp"


class Tour : public Element
{
	public:
		Tour(int eq, int id): Element(eq,id), hp(HP_MAX), lvl(1), tourelle(eq,id+1){}//std::cout << "tour créée: " << eq << "\tid: " << id << std::endl;}
		Tour() {}
		~Tour() { std::cout << "\tdest_Tour"; }
		Tour& operator=(const Tour& t){
			pos = t.pos;
			couleur = t.couleur;
			equipe = t.equipe;
			indice = t.indice;
			hp = t.hp;
			tourelle = t.tourelle;
			return *this;
		}
		
		/* méthodes du jeu */
		void levelUp(){ lvl++; }		// equipe la tour d'une tourelle  ----const int
			 /*if (lvl < 2){
				 lvl++;
				 return 1;	// SUCCESS
			 }else{
				 std::cout << "MESSAGE: Equipe " << equipe << ": Tour déjà lvl max!" << std::endl;
				 return 0;	// FAIL
			 }
		}*/
		
		Unite* tire(int id){ return tourelle.genereUnite(id); }	// demande à la tourelle de générer une Fleche
		
		const int damageUp() {return tourelle.damageUp();}		// augmente les dégats de la tourelle si possible
		const int porteeUp() {return tourelle.porteeUp();}		// augmente la portée de la tourelle si possible
		
		/* getters */
		const int getLvl() const{return lvl;}
		const int getHp() const {return hp;}
		const Tourelle& getTourelle() const {return tourelle;}
		void setColor(sf::Color c){
			couleur = c;
			tourelle.setColor(c);
		}
		
		void positionneTourelle(const sf::Vector2f& aPos) {tourelle.setPosition(aPos);}
	
	protected:
		int hp;
		int lvl;
		Tourelle tourelle;
};

#endif

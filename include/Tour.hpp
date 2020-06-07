#ifndef TOUR_HPP
#define TOUR_HPP

#include <SFML/Graphics.hpp>
//#include <string>
#include <iostream>

#include "config.hpp"

#include "Element.hpp"
#include "Tourelle.hpp"
#include "IAttaquable.hpp"


class Tour : public Element, public IAttaquable
{
	public:
		Tour(int eq, int id): Element(eq,id), hp(HP_MAX), lvl(1), tourelle(eq,id+1) {}//std::cout << "tour créée: " << eq << "\tid: " << id << std::endl;}
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
		void levelUp(){ 
			std::cout << "tour.lvlup" << std::endl;
			lvl++;
		}		// equipe la tour d'une tourelle  ----const int
			 /*if (lvl < 2){
				 lvl++;
				 return 1;	// SUCCESS
			 }else{
				 std::cout << "MESSAGE: Equipe " << equipe << ": Tour déjà lvl max!" << std::endl;
				 return 0;	// FAIL
			 }
		}*/
		
		Unite* tire(int id, const sf::Vector2f& posU){ return tourelle.genereUnite(id, posU); }	// demande à la tourelle de générer une Fleche
		
		const int damageUp() {return tourelle.damageUp();}		// augmente les dégats de la tourelle si possible
		const int porteeUp() {return tourelle.porteeUp();}		// augmente la portée de la tourelle si possible
		
		/* getters */
		const int getIndice() const {return indice;}
		const int getW() const {return w;}
		const int getH() const {return h;}
		const int getLvl() const {return lvl;}
		const int getHP() const {return hp;}
		const Tourelle& getTourelle() const {return tourelle;}
		void setColor(sf::Color c){
			couleur = c;
			tourelle.setColor(c);
		}
		void setW(int aW) {w = aW;}
		void setH(int aH) {h = aH;}
		
		
		const sf::IntRect getHitBox(){				// Renvoie le rectangle représentant la zone où on peut toucher la Tour
			return sf::IntRect(pos.x, pos.y, w, h);
		}
		void subiAtt(int degats) {hp -= degats;}	// enleve le montant des dégats aux points de vie de la Tour
		void meurt() {vivant = false;}
		const bool estVivant() const {return vivant;}
		const int getEquipe() const {return equipe;}
		const int getPrix() const {return 0;}
		
		void positionneTourelle(const sf::Vector2f& aPos) {tourelle.setPosition(aPos);}
		
		/* méthodes pour IPeriodique */
		bool checkTourelleTimer() {return tourelle.checkTimer();}
		void restartTourelleTimer() {tourelle.restartTimer();}
		
		
	protected:
		int hp;
		int lvl;
		Tourelle tourelle;
		int w = 0;
		int h = 0;
		bool vivant = true;
};

#endif

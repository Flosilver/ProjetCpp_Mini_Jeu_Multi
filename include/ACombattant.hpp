#ifndef ACOMBATTANT_HPP
#define ACOMBATTANT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Unite.hpp"
#include "IAttaquable.hpp"

class ACombattant : public Unite, public IAttaquable
{
	public:
		ACombattant(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos, int aHp, int aDmg, int aPrix) : Unite(c, eq, id, aPos, aHp, aDmg, aPrix, 3) {}
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
		
		/* renvoie la zone où on considère que l'unité peut être touchée */
		const sf::IntRect getHitBox(){
			return sf::IntRect(pos.x, pos.y, U_RECT_W * U_SCALE, U_RECT_H * U_SCALE);
		}
		const int getHP() const {return hp;}
		/* enleve le montant des dégats aux points de vie du ACombattant */
		void subiAtt(int degats) {hp -= degats;}
		const bool estVivant() const {return vivant;}
		void meurt() {
			//std::cout << "mise a mort" << std::endl;
			vivant = false;}
		const int getEquipe() const {return equipe;}
		
		const int getIndice() const {return indice;}
		const int getPrix() const {return prix;}
		
		/* méthodes de IPeriodique */
		bool checkTimer(){
			sf::Time tps = timer.getElapsedTime();
			int check = tps.asMilliseconds();
			return check >= ACOMB_DELAI;
		}
};

#endif

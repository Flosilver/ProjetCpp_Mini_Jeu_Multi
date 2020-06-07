#ifndef BATIMENT_HPP
#define BATIMENT_HPP

/*#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>*/
#include "config.hpp"

#include "Element.hpp"
//#include "Unite.hpp"
class Unite;

class Batiment : public Element, public IPeriodique
{
	public:
		Batiment(int eq, int id): Element(eq, id), niveau(1){}
		Batiment(){}
		//Batiment(sf::Color aCol, int eq, int id, int lvl, int cd): Element(aCol,eq,id), coolDown(cd), niveau(lvl){}
		//Batiment(int eq, int id, int lvl, int cd): Element(eq,id), coolDown(cd), niveau(lvl){}
		virtual ~Batiment() {std::cout << "\tdest_Batiment"; }
		Batiment& operator=(const Batiment& b){
			pos = b.pos;
			couleur = b.couleur;
			equipe = b.equipe;
			indice = b.indice;
			//coolDown = b.coolDown;
			niveau = b.niveau;
			return *this;
		}
		virtual Unite* genereUnite(int id, const sf::Vector2f& posU) = 0;
		
		/* méthodes du jeu */
		void levelUp() { niveau++; }
		
		/* méthodes de IPeriodique */
		//sf::Time restartTimer() {return timer.restart();}
		virtual bool checkTimer() = 0;
		
		/* getter */
		const int getNiveau() const {return niveau;}
		//const int getCoolDown() const {return coolDown;}
	
	protected:
		//int coolDown;	// temps avant de pouvoir regénérer une unité
		int niveau;		// définit le niveau de l'unité générée
	
};
#endif

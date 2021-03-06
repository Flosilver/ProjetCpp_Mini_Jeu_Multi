#ifndef TOURELLE_HPP
#define TOURELLE_HPP

/*#include <SFML/Graphics.hpp>
#include <iostream>*/

#include "config.hpp"

#include "Batiment.hpp"
//#include "Unite.hpp"

class Tourelle: public Batiment
{
	public:
		Tourelle(int eq, int id): Batiment(eq, id), degats(1), portee(200){}//std::cout << "tourelle créée: " << eq << "\tid: " << id << std::endl;}
		Tourelle(){}
		~Tourelle() { std::cout << "\tdest_Tourelle"; }
		Tourelle& operator=(const Tourelle& t);
		
		Unite* genereUnite(int id, const sf::Vector2f& posU);	// Factory d'Unite: Fleche
		
		const int damageUp();		// augmente les dégats des flèches tirées par la tourelle
		const int porteeUp();		// augmente la portée de la tourelle
		
		const int getDegats() const {return degats;}
		const int getPortee() const {return portee;}
		
		/* méthodes de IPeriodique */
		bool checkTimer();
	
	protected:
		int degats;
		int portee;
};

#endif

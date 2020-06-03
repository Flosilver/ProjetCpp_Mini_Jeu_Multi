#ifndef TOURELLE_HPP
#define TOURELLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Batiment.hpp"
#include "Unite.hpp"
#include "Fleche.hpp"

class Tourelle: public Batiment
{
	public:
		Tourelle(int eq, int id): Batiment(eq, id, 1, 100), degats(1), portee(200){}
		Tourelle(){}
		~Tourelle() { std::cout << "\tdest_Tourelle"; }
		Tourelle& operator=(const Tourelle& t);
		
		Unite* genereUnite(int id);	// Factory d'Unite: Fleche
		
		const int damageUp();		// augmente les dégats des flèches tirées par la tourelle
		const int porteeUp();		// augmente la portée de la tourelle
	
	protected:
		int degats;
		int portee;
};

#endif

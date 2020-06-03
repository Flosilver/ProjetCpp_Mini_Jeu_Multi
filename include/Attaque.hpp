#ifndef ATTAQUE_HPP
#define ATTAQUE_HPP

#include <iostream>

#include "Action.hpp"
#include "Unite.hpp"

class Attaque : public Action
{
	protected:
		Unite* cible;
		
	public:
		Attaque(Unite* u, Unite* aCible): Action(u), cible(aCible) {}
		~Attaque() { std::cout << "\tdest_Attaque";}
		Attaque& operator=(const Attaque& a){
			unite = a.unite;
			cible = a.cible;
			return *this;
		}
		
		int gereAction();
		
		Unite* getCible() {return cible;}
};

int Attaque::gereAction(){
	int dmg = unite->getDMG();
	int hp = cible->getHP();
	
	if ( hp - dmg > 0){
		cible->subiAtt(dmg);
		return 1;	// SUCCES
	}
	else{
		return 0;	// FAIL -> décès de la cible
	}
}

#endif

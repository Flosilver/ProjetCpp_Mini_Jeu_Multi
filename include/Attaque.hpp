#ifndef ATTAQUE_HPP
#define ATTAQUE_HPP

//#include <iostream>

#include "Action.hpp"
#include "IAttaquable.hpp"
#include "Mort.hpp"

class Attaque : public Action
{
	protected:
		IAttaquable& cible;
		
	public:
		Attaque(Unite& u, IAttaquable& aCible): Action(u), cible(aCible) {}
		~Attaque() { 
			//delete cible;
			//std::cout << "\tdest_Attaque";
		}
		Attaque& operator=(const Attaque& a){
			unite = a.unite;
			cible = a.cible;
			return *this;
		}
		
		int gereAction();
		
		IAttaquable& getCible() {return cible;}
};

#endif

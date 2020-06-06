#ifndef MORT_HPP
#define MORT_HPP

#include <iostream>

#include "Action.hpp"
#include "Unite.hpp"

class Mort : public Action
{
	protected:
		int equipe;
	
	public:
		Mort(Unite* u) : Action(u) {equipe = ((u->getEquipe())%2) + 1;}
		~Mort() { std::cout << "\tdest_Mort"; }
		Mort& operator=(const Mort& m){
			unite = m.unite;
			return *this;
		}
		
		int gereAction();
};

#endif

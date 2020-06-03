#ifndef MORT_HPP
#define MORT_HPP

#include <iostream>

#include "Action.hpp"
#include "Unite.hpp"

class Mort : public Action
{
	protected:
		
	
	public:
		Mort(Unite* u) : Action(u) {}
		~Mort() { std::cout << "\tdest_Mort"; }
		Mort& operator=(const Mort& m){
			unite = m.unite;
			return *this;
		}
		
		int gereAction();
};

int gereAction(){
	int unite->getIndice();
	
}

#endif

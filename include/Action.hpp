#ifndef ACTION_HPP
#define ACTION_HPP

#include <iostream>
//#include <cstdlib>
//#include <string>

#include "Unite.hpp"

class Action
{
protected:
	Unite* unite;	// unite qui fait l'action

public:
	Action(Unite* u);
	virtual ~Action(){ 
		delete unite;
		std::cout << "\tdest_Action" << std::endl; 
	}
	Action& operator=(const Action& a){
		unite = a.unite;
		return *this;
	}
	
	virtual int gereAction() = 0;
	
	/* accesseur */
	Unite* getUnite() {return unite;}
};

#endif

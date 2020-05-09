#ifndef ACTION_HPP
#define ACTION_HPP

#include "Unite.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

class Action
{
protected:
	Unite *unite;

public:
	Action(Unite* u);
	virtual ~Action(){ std::cout << "dest_Action" << std::endl; }
	virtual void gereAction() = 0;
};

#endif

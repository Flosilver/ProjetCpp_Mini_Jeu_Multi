#ifndef ACTION_HPP
#define ACTION_HPP

#include "Unite.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

class Action
{
protected:
	Unite* unite;

public:
	Action(Unite* u);
	virtual ~Action() {std::cout << "dest_action" << std::endl;}
	virtual void gereAction() = 0;
};


Action::Action(Unite* u) {
	if (u == nullptr)
		throw std::string("***ERROR: Action(Unite* u): pointeur null");
	else
		unite = u;
}

#endif

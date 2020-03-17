#pragma once
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
	virtual void gereAction() = 0;
};


Action::Action(Unite* u) {
	if (u == nullptr) {
		throw std::string("***ERROR: Action(Unite* u): pointeur null");
	}
	unite = u;
}

#endif
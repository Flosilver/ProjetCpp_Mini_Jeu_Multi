#include <string>
#include <iostream>
#include <cstdlib>
#include "Action.hpp"
#include "Unite.hpp"

Action::Action(Unite* u) {
	if (u == nullptr) {
		throw std::string("***ERROR: Action(Unite* u): pointeur null");
	}
	unite = u;
}

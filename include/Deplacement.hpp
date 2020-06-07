#ifndef DEPLACEMENT_HPP
#define DEPLACEMENT_HPP

/*#include <SFML/System.hpp>
#include <iostream>*/

#include "Action.hpp"
#include "Mort.hpp"

class Deplacement : public Action
{
	protected:
		sf::Vector2f deplacement;
		
	public:
		Deplacement(Unite& u, const sf::Vector2f& aVect): Action(u), deplacement(aVect) {}
		~Deplacement() { }//std::cout << "\tdest_Deplacement"; }
		Deplacement& operator=(const Deplacement& d){
			unite = d.unite;
			deplacement = d.deplacement;
			return *this;
		}
		
		int gereAction();
		
		const sf::Vector2f getDeplecement() const {return deplacement;}
};

#endif

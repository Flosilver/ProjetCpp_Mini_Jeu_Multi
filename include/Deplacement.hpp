#ifndef DEPLACEMENT_HPP
#define DEPLACEMENT_HPP

#include <SFML/System.hpp>
#include <iostream>

#include "Action.hpp"
#include "Unite.hpp"

class Deplacement : public Action
{
	protected:
		sf::Vector2f deplacement;
		
	public:
		Deplacement(Unite* u, const sf::Vector2f& aVect): Action(u), deplacement(aVect) {}
		~Deplacement() { std::cout << "\tdest_Deplacement"; }
		Deplacement& operator=(const Deplacement& d){
			unite = d.unite;
			deplacement = d.deplacement;
			return *this;
		}
		
		int gereAction();
		
		const sf::Vector2f getDeplecement() const {return deplacement;}
};

int Deplacement::gereAction(){
	unite->move(deplacement);
	sf::Vector2f pos = unite->getPos();
	
	if (pos.x < -10 || pos.x > 2000 || pos.y < -10 || pos.y > 1100){
		std::cerr << "**ERROR : Déplacement éronné -> MORT unité: " << unite->getIndice() << std::endl;
		return 0;	// Déplacement éronné -> MORT
	}
	
	return 1;	// SUCCESS
}

#endif

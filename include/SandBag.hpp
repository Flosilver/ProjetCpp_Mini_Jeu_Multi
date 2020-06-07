#ifndef SANDBAG_HPP
#define SANDBAG_HPP

#include "config.hpp"

class SandBag: public Unite, public IAttaquable
{
	public:
		SandBag(): Unite(), IAttaquable(){}
		~SandBag() {}
		
		const sf::IntRect getHitBox() {return sf::IntRect();};
		const int getHP() const {return 0;}
		void subiAtt(int degats) {}
		void meurt() {}
		const bool estVivant() const {return true;}
		const int getIndice() const {return -1;}
		const int getEquipe() const {return equipe;}
		const int getPrix() const {return 0;}
		
		bool checkTimer() {return false;}
};

#endif

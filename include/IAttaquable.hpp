#ifndef IATTAQUABLE_HPP
#define IATTAQUABLE_HPP	

#include <SFML/System.hpp>

class IAttaquable
{
	public:
		IAttaquable(){}
		virtual ~IAttaquable(){}
		IAttaquable& operator=(IAttaquable& ia){
			return ia;
		}
	
		virtual const sf::IntRect getHitBox() = 0;
		virtual const int getHP() const = 0;
		virtual void subiAtt(int degats) = 0; // {hp -= degats;}
		virtual void meurt() =0;
		virtual const bool estVivant() const = 0;
		virtual const int getIndice() const = 0;
		virtual const int getEquipe() const = 0;
		virtual const int getPrix() const = 0;
};

#endif

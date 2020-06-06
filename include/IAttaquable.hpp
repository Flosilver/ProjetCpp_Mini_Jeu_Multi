#ifndef IATTAQUABLE_HPP
#define IATTAQUABLE_HPP	

#include <SFML/System.hpp>

class IAttaquable
{
	public:
		IAttaquable(){}
		virtual ~IAttaquable(){}
	
		virtual const sf::IntRect getHitBox() = 0;
		virtual const int getHP() const = 0;
		virtual void subiAtt(int degats) = 0; // {hp -= degats;}
};

#endif

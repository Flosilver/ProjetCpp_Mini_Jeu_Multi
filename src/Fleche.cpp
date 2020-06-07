#include "Fleche.hpp"


const sf::IntRect Fleche::getHitZone(){
	sf::RectangleShape rectShape(sf::Vector2f(U_SP_W, U_SP_W));
	rectShape.setOrigin(U_SP_W/2, U_SP_W/2);
	rectShape.setPosition(pos);
	rectShape.setRotation(angle);
	sf::FloatRect temp = rectShape.getGlobalBounds();
	int left = (int) temp.left;
	int top = (int) temp.top;
	int w = (int) temp.width;
	int h = (int) temp.height;
	return sf::IntRect(left,top,w,h);
}

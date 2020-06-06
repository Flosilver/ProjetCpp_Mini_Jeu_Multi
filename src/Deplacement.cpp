#include "Deplacement.hpp"

int Deplacement::gereAction(){
	unite->move(deplacement);
	sf::Vector2f pos = unite->getPos();
	
	if (pos.x < -10 || pos.x > 2000 || pos.y < -10 || pos.y > 1100){
		std::cerr << "**ERROR : Déplacement éronné -> MORT unité: " << unite->getIndice() << std::endl;
		return 0;	// Déplacement éronné -> MORT
	}
	
	return 1;	// SUCCESS
}

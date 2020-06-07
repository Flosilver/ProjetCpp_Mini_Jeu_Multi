#include "config.hpp"

#include "Deplacement.hpp"

int Deplacement::gereAction(){
	unite.move(deplacement);
	sf::Vector2f pos = unite.getPos();
	
	if (pos.x < -10 || pos.x > 1510 || pos.y < -10 || pos.y > (RW_H-GROUND_H)){
		std::cerr << "**ERROR : Déplacement éronné -> MORT unité: " << unite.getIndice() << std::endl;
		return MORT_ID;	// Déplacement éronné -> MORT
	}
	
	return DEP_ID;	// SUCCESS
}

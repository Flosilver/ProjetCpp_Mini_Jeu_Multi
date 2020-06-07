#include "config.hpp"

#include "Attaque.hpp"

int Attaque::gereAction(){
	int dmg = unite.getDMG();
	int hp = cible.getHP();
	
	cible.subiAtt(dmg);
	
	if ( hp - dmg > 0){
		return ATT_ID;	// SUCCES
	}
	else{
		return MORT_ID;	// FAIL -> décès de la cible
	}
}

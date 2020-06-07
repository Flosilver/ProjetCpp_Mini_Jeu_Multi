#include "config.hpp"

#include "Attaque.hpp"

int Attaque::gereAction(){
	int dmg = unite.getDMG();
	//int hp = cible.getHP();
	
	cible.subiAtt(dmg);
	int hp = cible.getHP();
	
	if ( hp > 0){
		return ATT_ID;	// SUCCES
	}
	else{
		throw Mort(cible);
		return MORT_ID;	// FAIL -> décès de la cible
	}
}

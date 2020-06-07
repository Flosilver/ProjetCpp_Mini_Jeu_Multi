#include "Attaque.hpp"

int Attaque::gereAction(){
	int dmg = unite->getDMG();
	int hp = cible->getHP();
	
	if ( hp - dmg > 0){
		cible->subiAtt(dmg);
		return 1;	// SUCCES
	}
	else{
		return 0;	// FAIL -> décès de la cible
	}
}

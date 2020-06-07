#include <SFML/Graphics.hpp>
#include <iostream>

#include "Habitation.hpp"
#include "Unite.hpp"
#include "Paysan.hpp"
#include "Soldat.hpp"
#include "Cyborg.hpp"


/* Factory d'Unite: ACombattant */
Unite* Habitation::genereUnite(int id, const sf::Vector2f& posU){
		//gérer le prix que coûte 1 unité
		Unite* pu;
		switch(niveau){
		
			case 1://Level 1->Paysan
				/*int aHp = 10;
				int aDmg = 1;
				int aPrix = 3;
				int aPortee = 3;
				//int aCout = 3;*/
				//std::cout << "je genere un paysan" << std::endl;
				
				pu = new Paysan(couleur, equipe, id, posU);
				break;
				
			case 2://Level 2->Soldat
				/*int aHp = 20;
				int aDmg = 6;
				int aPrix = 8;
				int aPortee = 5;
				int aCout = 5;*/
				//std::cout << "je genere un soldat" << std::endl;
				
				pu = new Soldat(couleur, equipe, id, posU);
				break;
				
			case 3://Level 3->Cyborg
			
				/*int aHp = 30;
				int aDmg = 12;
				int aPrix = 14;
				int aPortee = 10;
				int aCout = 10;*/
				//std::cout << "je genere un cyborg" << std::endl;
				
				pu = new Cyborg(couleur, equipe, id, posU);
				break;
		}
		return pu;
}

bool Habitation::checkTimer(){
	sf::Time tps = timer.getElapsedTime();
	int check = tps.asMilliseconds();
	return check >= HAB_DELAI;
}

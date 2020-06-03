#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <iostream>
#include <string>

#include "config.hpp"
#include "Equipe.hpp"
//#include "Habitation.hpp"
//#include "Unite.hpp"

/* Constructeur */
/*Equipe::Equipe(sf::Color c, int eq, int aId){
	couleur = c;
	numero = eq;
	bourse = 30;		// argent de départ du joueur
	hab(c, eq, aId);
}*/

/* Permet de récupérer l'ensemble des unités que possède l'équipe */
//std::vector<Unite*>& Equipe::getUnites(){
	
//}

/*Equipe::Equipe(int eq, int& bat_id, sp_map& sprites, sprite_v& sp_v){
	numero = eq;
	bourse = 30;		// argent de départ du joueur
	bat_id = sp_v.size();
	hab = Habitation(eq, bat_id);
	sp_v.push_back(sprites["habitation"]);
	bat_id = sp_v.size();
	tour = Tour(eq, bat_id);
	sp_v.push_back(sprites[""]);
}*/

/* Destructeur */
Equipe::~Equipe(){
	for( std::list<Unite*>::iterator it = unites.begin() ; it != unites.end() ; ++it ){
		delete *it;
	}
	unites.clear();
	for( std::list<Unite*>::iterator it = listAttUni.begin() ; it != listAttUni.end() ; ++it ){
		delete *it;
	}
	unites.clear();
	listAttUni.clear();
	std::cout << "\tdest_Equipe" << std::endl;
}

Equipe& Equipe::operator=(const Equipe& e){
	couleur = e.couleur;
	numero = e.numero;
	bourse = e.bourse;
	hab = e.hab;
	
	// a completer: remplir les tableaux de l'unite et listAttUnite si non vides
}

/* Ajoute une somme d'argent spécifée en argument à la bourse de l'équipe */
void Equipe::ajoutMonaie(int argent){
	bourse += argent;
}

/* Améliore le batiment Habitation */
const int Equipe::habitationUp(){
	if( hab.getNiveau() < 3 ){
		hab.levelUp();
		return 1;		// SUCCESS
	}
	else{
		std::cout << "***MESSAGE: habitation déjà lvl max" << std::endl;
		return 0;		// FAIL
	}
}

/* demande la création d'une unité de combat */
const int Equipe::creerCombattant(int id){
	//int prixPaysan = -4;
	//int prixSoldat = -8;
	//int prixCyborg = -12;
	
	// On enleve la bonne quantité d'argent à l'équipe en fonction du niveau de l'habitation
	switch(hab.getNiveau()){
		case 1:
			/* on vérifie si l'équipe a assez d'argent */
			if( bourse >= -U_PRIX_P ){	
				ajoutMonaie(U_PRIX_P);	// on enleve l'argent a l'équipe
				//unites.push_back(hab.genereUnite(id));			// on demande à l'habitation de générer l'unité
			}else{
				std::cout << "***MESSAGE: Equipe " << numero << ": pas assez d'argent pour paysan" << std::endl;
				return 0;		// FAIL
			}
			break;
		case 2:
			/* on vérifie si l'équipe a assez d'argent */
			if( bourse >= -U_PRIX_S ){
				ajoutMonaie(U_PRIX_S);	// on enleve l'argent a l'équipe
				//unites.push_back(hab.genereUnite(id));			// on demande à l'habitation de générer l'unité
			}else{
				std::cout << "***MESSAGE: Equipe " << numero << ": pas assez d'argent pour soldat" << std::endl;
				return 0;		// FAIL
			}
			break;
		case 3:
			/* on vérifie si l'équipe a assez d'argent */
			if( bourse >= -U_PRIX_C ){
				ajoutMonaie(U_PRIX_C);	// on enleve l'argent a l'équipe
				//unites.push_back(hab.genereUnite(id));			// on demande à l'habitation de générer l'unité
			}else{
				std::cout << "***MESSAGE: Equipe " << numero << ": pas assez d'argent pour cyborg" << std::endl;
				return 0;		// FAIL
			}
			break;
		default:
			std::cout << "***ERROR: Equipe::creerCombattant(int id): niveau habitation erroné" << std::endl;
	}
	
	unites.push_back(hab.genereUnite(id));			// on demande à l'habitation de générer l'unité
				
	return 1;	// SUCCESS
	
}

const int Equipe::tireFleche(int id){
	try{
		unites.push_back(tour.tire(id));
		return 1;	// SUCCESS
	}
	catch(const int& e){
		// cooldown de la tourelle en cours
		return 0;	// FAIL
	}
}

void Equipe::setColor(sf::Color c){
	this->couleur = c;
	this->hab.setColor(c);
	this->tour.setColor(c);
}

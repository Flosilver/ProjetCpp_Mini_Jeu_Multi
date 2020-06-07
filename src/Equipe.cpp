#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <cstdlib>

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
	tour = e.tour;
	
	if(!e.unites.empty()){
		for( std::list<Unite*>::const_iterator it = e.unites.begin() ; it != e.unites.end() ; ++it ){
			unites.push_back(*it);
		}
	}
	if(!e.listAttUni.empty()){
		for( std::list<Unite*>::const_iterator it = e.listAttUni.begin() ; it != e.listAttUni.end() ; ++it ){
			listAttUni.push_back(*it);
		}
	}
	
	return *this;
	
	// a completer: remplir les tableaux de l'unite et listAttUnite si non vides
}

/* renvoie l'ensemble des éléments IAttaquable que possède l'équipe dans un vecteur, avec la tour en 1ere position */
void Equipe::getIAttaquables(std::vector<IAttaquable*>& eq_iAtt){
	//std::vector<IAttaquable*> res = * new std::vector<IAttaquable*>;
	IAttaquable* test;
	
	/* Ajout de la Tour en 1er élément */
	test = static_cast<IAttaquable*> (&tour);
	if (test != nullptr ){
		//std::cout << "il y a la tour" << std::endl;
		eq_iAtt.push_back(test);
	}
	
	if(!unites.empty()){
		for( std::list<Unite*>::iterator it = unites.begin() ; it != unites.end() ; ++it ){
			test = dynamic_cast<IAttaquable*> (*it);
			if ( test != nullptr ){
				eq_iAtt.push_back(test);
			}
		}
	}
	
	//return res;
}

/* renvoie la référence vers une unité de la liste d'unité de l'équipe grâce à son identifiant */
/*Unite& findUnite(int id){
	Unite* pu;
	for(std::list<Unite*>::iterator it = unites.begin() ; it != unites.end() ; ++it){
		pu = *it;
		if(pu->getIndice() == id){
			return *pu,
		}
	}
	throw std::string("Unite introuvable");
}*/

/* Ajoute une somme d'argent spécifée en argument à la bourse de l'équipe */
void Equipe::ajoutMonaie(const int& argent){
	//bourse += argent;
	bourse = (bourse + argent) < ARGENT_MAX ? (bourse + argent) : ARGENT_MAX;
}

/* Améliore le batiment Habitation */
const int Equipe::habitationUp(){
	if( hab.getNiveau() < 3 ){
		if( hab.getNiveau() == 1 && (bourse-HAB_1TO2) >= 0 ){
			ajoutMonaie(-HAB_1TO2);
			hab.levelUp();
			return 1;		// SUCCESS
		}
		if( hab.getNiveau() == 2 && (bourse-HAB_2TO3) >= 0 ){
			ajoutMonaie(-HAB_2TO3);
			hab.levelUp();
			return 1;		// SUCCESS
		}
		std::cout << "***MESSAGE: Equipe " << numero << ": pas assez d'argent pour habitationUp" << std::endl;
		return 0;
	}
	else{
		std::cout << "***MESSAGE: Equipe " << numero << ": habitation déjà lvl max" << std::endl;
		return 0;		// FAIL
	}
}

/* Améliore le niveau de la tour */
const int Equipe::tourLvlUp(){
	if ( tour.getLvl() == 1){
		if ( (bourse-TOUR_1TO2) >= 0 ){
			ajoutMonaie(-TOUR_1TO2);
			tour.levelUp();
			return 1; 		// SUCCESS
		}
		std::cout << "***MESSAGE: Equipe " << numero << ": pas assez d'argent pour tourLvlUp" << std::endl;
		return 0;
	}
	else{
		std::cout << "***MESSAGE: Equipe " << numero << ": tour déjà lvl max" << std::endl;
		return 0;		// FAIL
	}
}

/* augmente les dégats de la tourelle */
const int Equipe::tourDomageUp(){
	if ( tour.getLvl() == 2){
		if ( (bourse-TOUR_DMG_1TO2) >= 0 ){
			ajoutMonaie(-TOUR_DMG_1TO2);
			return tour.damageUp();
		}
		std::cout << "***MESSAGE: Equipe " << numero << ": pas assez d'argent pour tourDomageUp" << std::endl;
		return 0;		// FAIL
	}
	else{
		std::cout << "***MESSAGE: Equipe " << numero << ": tourelle non débloquée" << std::endl;
		return 0;		// FAIL
	}
}

/* Augmente la portee de la tourelle */
const int Equipe::tourPorteeUp(){
	if ( tour.getLvl() == 2){
		if ( (bourse-TOUR_PORTEE_1TO2) >= 0 ){
			ajoutMonaie(-TOUR_PORTEE_1TO2);
			return tour.porteeUp();
		}
		std::cout << "***MESSAGE: Equipe " << numero << ": pas assez d'argent pour tourPorteeUp" << std::endl;
		return 0;		// FAIL
	}
	else{
		std::cout << "***MESSAGE: Equipe " << numero << ": tourelle non débloquée" << std::endl;
		return 0;		// FAIL
	}
}

/* demande la création d'une unité de combat */
const int Equipe::creerCombattant(int id, const sf::Vector2f& posU){
	//int prixPaysan = -4;
	//int prixSoldat = -8;
	//int prixCyborg = -12;
	
	if(hab.checkTimer()){
		
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
				std::cerr << "***ERROR: Equipe::creerCombattant(int id): niveau habitation erroné" << std::endl;
		}
		
		unites.push_back(hab.genereUnite(id, posU));			// on demande à l'habitation de générer l'unité
		hab.restartTimer();
		return 1;	// SUCCESS
	}
	else{
		return 0;	// FAIL (trop tot)
	}
	
}

const int Equipe::tireFleche(int id, const sf::Vector2f& posU){
	/*try{
		unites.push_back(tour.tire(id, posU));
		return 1;	// SUCCESS
	}
	catch(const int& e){
		// cooldown de la tourelle en cours
		return 0;	// FAIL
	}*/
	if(tour.checkTourelleTimer()){
		unites.push_back(tour.tire(id, posU));
		tour.restartTourelleTimer();
		return 1;	// SUCCESS
	}
	else{
		return 0;	// FAIL
	}
}

void Equipe::setColor(sf::Color c){
	this->couleur = c;
	this->hab.setColor(c);
	this->tour.setColor(c);
}


void Equipe::positionneHab(const sf::Vector2f& aPos){
	hab.setPosition(aPos);
}

void Equipe::positionneTour(const sf::Vector2f& aPos, const sf::Vector2f& tourellePos){
	tour.setPosition(aPos);
	tour.positionneTourelle(tourellePos);
}

void Equipe::tour_setup_dim(int aW, int aH){
	tour.setW(aW);
	tour.setH(aH);
}

#include "Equipe.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <iostream>
#include <string>

/* Constructeur */
Equipe::Equipe(sf::Color c, int i){
	couleur = c;
	id = i;
	bourse = 100;		// argent de départ du joueur
}

/* Permet de récupérer l'ensemble des unités que possède l'équipe */
std::vector<Unite*>& Equipe::getUnites(){
	
}

/* Ajoute une somme d'argent spécifée en argument à la bourse de l'équipe */
void Equipe::ajoutMonaie(int argent){
	bourse += argent;
}

/* Améliore le batiment Habitation */
void Equipe::habitationUp(){
	
}

/* Augmente le nombre de HP de la tour de l'équipe */
void Equipe::tourHPup(){
	
}

/* Augmente les domages causé par la tour */
void Equipe::tourDomageUp(){
	
}

/* Augmente la portée de la tour */
void Equipe::tourPorteeUp(){
	
}

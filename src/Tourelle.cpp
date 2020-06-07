#include <SFML/Graphics.hpp>
#include <iostream>

#include "Tourelle.hpp"
#include "Fleche.hpp"

Tourelle& Tourelle::operator=(const Tourelle& t){
	pos = t.pos;
	couleur = t.couleur;
	equipe = t.equipe;
	indice = t.indice;
	//coolDown = t.coolDown;
	niveau = t.niveau;
	degats = t.degats;
	portee = t.portee;
	return *this;
}

/* Factory d'Unite: Fleche */
Unite* Tourelle::genereUnite(int id, const sf::Vector2f& posU) {
	//if (checkTimer()){
		//coolDown = 0;
		//restartTimer();
		return new Fleche(couleur, equipe, id, posU, degats);
	//}
	/*else if (coolDown == 0){
		coolDown == 100;
		throw 0;	//Fin du coolDown
	}*/
	/*else{
		coolDown++;
		throw 1;	//coolDown en cours
	}*/
}

/* augmente les dégats des flèches tirées par la tourelle */
const int Tourelle::damageUp() {
	if (degats<3){
		degats++;
		return 1;	// SUCCESS
	}
	else{
		std::cout << "MESSAGE: Equipe " << equipe << ": degats de la tourelle déjà au max" << std::endl;
		return 0;	// FAIL
	}
}

/* augmente la portée de la tourelle */
const int Tourelle::porteeUp(){
	if (portee < 400){
		portee += 100;
		return 1;	// SUCCESS
	}
	else{
		std::cout << "MESSAGE: Equipe " << equipe << ": portée de la tourelle déjà au max" << std::endl;
		return 0;	// FAIL
	}
}

bool Tourelle::checkTimer(){
	sf::Time tps = timer.getElapsedTime();
	int check = tps.asMilliseconds();
	return check >= TOURELLE_DELAI;
}

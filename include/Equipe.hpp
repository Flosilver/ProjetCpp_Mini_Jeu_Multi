#ifndef EQUIPE_HPP
#define EQUIPE_HPP

/*#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <cstdlib>*/

#include "config.hpp"

#include "Element.hpp"
#include "Unite.hpp"
#include "Habitation.hpp"
#include "Tour.hpp"
#include "config.hpp"
#include "IAttaquable.hpp"
#include "Mort.hpp"

class Equipe
{
protected:
	sf::Color couleur;				// couleur de l'équipe
	int numero;						// id de l'équipe permet l'identification
	int bourse;						// argent que possède l'équipe
	Habitation hab;					// future liste des batiments possédés par l'équipe , pour l'instant uniquement une habitation
	Tour tour;						// tour de l'equipe que doit détruire l'adversaire
	std::list<Unite*> unites;		// liste des unités possédées par l'équipe
	std::list<Unite*> listAttUni;	// liste d'attente de génération d'unité
	
public:
	Equipe(int eq, int bat_id): numero(eq), bourse(30), hab(eq, bat_id), tour(eq, bat_id+1){}//std::cout << "equipe créée: " << eq << "\tid: " << bat_id << std::endl;}
	//Equipe(int eq, int bat_id, const sp_map& sprites, sprite_v& sp_v);//: numero(eq), bourse(30), hab(eq, bat_id), tour(eq,bat_id+1){}
	Equipe(){}
	//Equipe(int eq, int& bat_id, sprite_v& bat_sp, sp_map& sprites);
	~Equipe();
	Equipe& operator=(const Equipe& e);
	std::list<Unite*>& getUnites() { return unites; }
	void getIAttaquables(std::vector<IAttaquable*>& eq_iAtt);	// renvoie l'ensemble des éléments IAttaquable que possède l'équipe dans un vecteur dans le vector mis en argument, avec la tour en 1ere position
	//Unite& findUnite(int id);
	
	// fonction linkées au jeu
	void ajoutMonaie(const int& argent);							// donne ou enleve de l'argent à l'équipe en fonction du signe de l'argument: >0 : ajout / <0 : retrait
	const int habitationUp();									// augmente le niveau de l'habitation
	const int tourLvlUp();// { return tour.levelUp(); }			// augmente de 1 le niveau de la Tour et bébloque l'usage de la tourelle
	const int tourDomageUp();// { return tour.damageUp(); }		// augmente les dégats de la tourelle de la tour si elle est construite
	const int tourPorteeUp();// { return tour.porteeUp(); }		// augmente la portée de la tourelle de la tour si elle est construite
	const int creerCombattant(int id, const sf::Vector2f& posU);// argument = indice de la nouvelle unité dans le tableau de sprite du jeux  / retourne 1 si l'unité est créée, 0 sinon
	const int tireFleche(int id, const sf::Vector2f& posU);		// permet la création des fleches
	
	/* eccesseurs de l'habitation */
	const int getHabLvl() const {return hab.getNiveau();};
	void positionneHab(const sf::Vector2f& aPos);				// place l'habitation sur le terrain
	
	/* accesseurs de la tour */
	const int getTourLvl() const {return tour.getLvl();}	// renvoie le niveau de la tour de l'équipe
	const int getTourHp() const {return tour.getHP();}		// renvoie les HP de la Tour de l'esuipe
	void positionneTour(const sf::Vector2f& aPos, const sf::Vector2f& tourellePos);				// place la tour sur le terrain et la tourelle aussi
	void tour_setup_dim(int aW, int aH);
	const int getTourPortee() const {return tour.getTourelle().getPortee();}
	
	// getters et setters
	const int getNum() const {return numero;}
	const int getBourse() const {return bourse;}
	void setColor(sf::Color c);
	const sf::Color& getCol() const {return couleur;}
	//std::list<Unite*>& getUnites() {return unites;}
};

#endif

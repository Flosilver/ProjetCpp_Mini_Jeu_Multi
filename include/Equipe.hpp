#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include "Element.hpp"
#include "Unite.hpp"

class Equipe
{
private:
	sf::Color couleur;				// couleur de l'équipe
	int id;							// id de l'équipe permet l'identification
	int bourse;						// argent que possède l'équipe
	std::list<Element*> elements;			// liste de ce que possède l'équipe, cela réuni les batiments et les unités
	std::list<Unite*> listAttUni;	// liste d'attente de génération d'unité
	
public:
	Equipe(sf::Color c, int i);
	~Equipe() {std::cout << "dest_Equipe" << std::endl;
		elements.clear();
		listAttUni.clear();}
	std::vector<Unite*>& getUnites();
	
	// fonction linkées au jeu
	void ajoutMonaie(int argent);
	void habitationUp();
	void tourHPup();
	void tourDomageUp();
	void tourPorteeUp();
	
	// getters et setters
	const int getId() const {return id;}
	const int getBourse() const {return bourse;}
};


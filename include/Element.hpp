#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
//#include <cstdlib>
//#include <string>

class Element
{
	protected:
		sf::Vector2f pos;
		sf::Color couleur;
		int equipe;	// equipe a laquelle l'élément appartient
		int indice;	// position dans le vecteur sprites du jeu (normalement)
		
		//void setPosition(const sf::Vector2f aPos) {pos = aPos;}

	public:
		Element(int eq, int id) : pos(-1, -1), couleur(sf::Color()), equipe(eq), indice(id) {}
		Element(const sf::Color& c, int eq, int id) : couleur(c), pos(-1, -1), equipe(eq), indice(id) {}	// A faire: modifier la position en fonction de l'identifiant lors de la créartion
		Element(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos) : couleur(c), pos(aPos), equipe(eq), indice(id) {}
		Element(){}
		virtual ~Element() { std::cout << "\tdest_Element" << std::endl; }
		Element& operator=(const Element& e){
			pos = e.pos;
			couleur = e.couleur;
			equipe = e.equipe;
			indice = e.indice;
			return *this;
		}
		
		/* accesserus */
		const int getIndice() const {return indice;}
		const int getEquipe() const {return equipe;}
		const sf::Vector2f getPos() const {return pos;}
		const sf::Color& getColor() const {return couleur;}
		void setPosition(const sf::Vector2f& aPos) {pos = aPos;}
		void setColor(const sf::Color& c) {couleur = c;}
};

#endif

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Equipe.hpp"


class Element
{
protected:
	sf::Vector2i pos;
	Equipe equipe;	// l'équipe à laquelle l'unité appartient

public:
	Element(Equipe& e) : pos(-1, -1), equipe(e) {}
	virtual ~Element() { std::cout << "dest_elem" << std::endl; }
	const sf::Vector2i getPos() const {return pos;} const
	sf::Vector2i& getPos() {return pos;}
	Equipe& getEquipe() {return equipe;}
};

#endif

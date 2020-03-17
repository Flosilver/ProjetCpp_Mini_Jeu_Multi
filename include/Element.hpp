#pragma once
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>

class Element
{
protected:
	sf::Vector2i pos;
	sf::Color couleur;

public:
	Element(sf::Color c) : couleur(c), pos(-1, -1) {}
	virtual ~Element() { std::cout << "dest_elem" << std::endl; }
};

#endif
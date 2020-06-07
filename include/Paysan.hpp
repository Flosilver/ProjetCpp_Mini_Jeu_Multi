#ifndef PAYSAN_HPP
#define PAYSAN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ACombattant.hpp"

class Paysan : public ACombattant
{
public:
	Paysan(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos) : ACombattant(c, eq, id, aPos, VIE_PAYSAN, DMG_PAYSAN, GAIN_PAYSAN){}		// couleur, n° equipe, id dans vector<sprites>, vie, dmg, prix rapportée si tuée
	~Paysan() { std::cout << "\tdest_Paysan"; }
	Paysan& operator=(const Paysan& p){
		pos = p.pos;
		couleur = p.couleur;
		equipe = p.equipe;
		indice = p.indice;
		hp = p.hp;
		dmg = p.dmg;
		prix = p.prix;
		portee = p.portee;
		return *this;
	}
	//virtual *Action agit() = 0;
	const int getHP() const {return hp;}
};

#endif

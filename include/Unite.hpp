#ifndef UNITE_HPP
#define UNITE_HPP

#include "Element.hpp"
//#include "Action.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.hpp"

class Unite : public Element
{
protected:
	int hp;		// point de vie de l'unité
	int dmg;	// >0 = inflige des dégats ; <0 = soigne
	int prix;	// combien il rapporte à l'ennemis quand il meurt
	int portee;	// la distance à laquelle l'unité peut attaquer/soigner

public:
	Unite(): Element(sf::Color(),0,0), hp(0), dmg(0), prix(0), portee(0) {}
	Unite(sf::Color c, int eq, int id, int aHp, int aDmg, int aPrix, int aPortee) : Element(c, eq, id), hp(aHp), dmg(aDmg), prix(aPrix), portee(aPortee) {}
	virtual ~Unite() { std::cout << "\tdest_Unite" << std::endl; }
	Unite& operator=(const Unite& u){
		pos = u.pos;
		couleur = u.couleur;
		equipe = u.equipe;
		indice = u.indice;
		hp = u.hp;
		dmg = u.dmg;
		prix = u.prix;
		portee = u.portee;
		return *this;
	}

	void move(const sf::Vector2f aPos) {pos += aPos;}
	void subiAtt(int degats) {hp -= degats;}
	//virtual *Action agit() = 0;
	
	/* accesseurs */
	int& getHP() {return hp;}
	const int getDMG() const {return dmg;}
};

#endif

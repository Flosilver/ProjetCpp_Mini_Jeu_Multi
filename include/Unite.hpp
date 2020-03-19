#ifndef UNITE_HPP
#define UNITE_HPP

#include "Element.hpp"
#include "Action.hpp"
#include <SFML/Graphics.hpp>

class Unite : public Element
{
protected:
	int hp;		// point de vie de l'unit�
	int dmg;	// >0 = inflige des d�gats ; <0 = soigne
	int prix;	// combien il rapporte � l'ennemis quand il meurt
	int portee;	// la distance � laquelle l'unit� peut attaquer/soigner

public:
	Unite(Equipe& e) : Element(e), hp(0), dmg(0), prix(0), portee(0) {}
	virtual ~Unite() { std::cout << "dest_Unite" << std::endl; }

	virtual Action* agit() = 0;
	const int getHP() const {return hp;}
	int& getHP() {return hp;}
	const int getDmg() const {return dmg;}
	const int getPrix() const {return prix;}
	const int getPortee() const {return portee;}
};

#endif

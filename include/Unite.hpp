#ifndef UNITE_HPP
#define UNITE_HPP

#include "Element.hpp"
//#include "Action.hpp"
/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>*/

#include "config.hpp"

//#include "Action.hpp"
class Action;
#include "IAttaquable.hpp"

class Unite : public Element
{
protected:
	int hp;		// point de vie de l'unité
	int dmg;	// >0 = inflige des dégats ; <0 = soigne
	int prix;	// combien il rapporte à l'ennemis quand il meurt
	int portee;	// la distance à laquelle l'unité peut attaquer/soigner
	
	bool vivant = true;

public:
	Unite(): Element(sf::Color(),0,0), hp(0), dmg(0), prix(0), portee(0) {}
	Unite(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos, int aHp, int aDmg, int aPrix, int aPortee) : Element(c, eq, id, aPos), hp(aHp), dmg(aDmg), prix(aPrix), portee(aPortee) {}
	virtual ~Unite() { std::cout << "\tdest_Unite" << std::endl; }
	Unite& operator=(const Unite& u);

	void move(const sf::Vector2f aPos) {pos += aPos;}
	//void subiAtt(int degats) {hp -= degats;}
	const sf::IntRect getHitZone();
	void meurt() {vivant = false;}
	Action* agit(std::vector<IAttaquable*>& v, const sf::Vector2f& aVect);
	
	/* accesseurs */
	const int getHP() const {return hp;}
	const int getDMG() const {return dmg;}
	const int getPrix() const {return prix;}
	const int getPortee() const {return portee;}
	
	const bool estVivant() {return vivant;}
};

#endif

#include "catch.hpp"
#include "Unite.hpp"

TEST_CASE( "test Unite", "[Unite]" ) {
	//Unite(sf::Color c, int eq, int id, int aHp, int aDmg, int aPrix, int aPortee);
	
	//Unite(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos, int aHp, int aDmg, int aPrix, int aPortee)
	Unite U = Unite(sf::Color::White, 1, 2 ,sf::Vector2f (-1,-1) ,4 ,5 ,6,7);
	REQUIRE( U.getHP() == 4 );
	REQUIRE( U.getDMG() == 5 );
	REQUIRE( U.estVivant() == true );
	U.meurt();
	REQUIRE( U.estVivant() == false );
	//REQUIRE( U.prix == 5 );
	//REQUIRE( U.portee == 6 );
	
	SECTION("Fonctions"){
		//void move(const sf::Vector2f aPos) {pos += aPos;}
		//void subiAtt(int degats) {hp -= degats;}
		U.move(sf::Vector2f(1,1));
		REQUIRE( U.getPos() == sf::Vector2f (0,0) );
	}
	
	SECTION("Copie"){
		Unite U2 = U;
		REQUIRE( U2.getHP() == 4 );
		REQUIRE( U2.getDMG() == 5 );
	}
}

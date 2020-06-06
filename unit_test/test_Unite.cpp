#include "catch.hpp"
#include "Unite.hpp"

TEST_CASE( "test Unite", "[Unite]" ) {
	//Unite(sf::Color c, int eq, int id, int aHp, int aDmg, int aPrix, int aPortee);
	Unite U = Unite(sf::Color::White, 1, 2 ,3 ,4 ,5 ,6);
	REQUIRE( U.getHP() == 3 );
	REQUIRE( U.getDMG() == 4 );
	//REQUIRE( U.prix == 5 );
	//REQUIRE( U.portee == 6 );
	
	SECTION("Fonctions"){
		//void move(const sf::Vector2f aPos) {pos += aPos;}
		//void subiAtt(int degats) {hp -= degats;}
		U.move(sf::Vector2f(1,1));
		U.subiAtt(2);
		REQUIRE( U.getPos() == sf::Vector2f(0,0));
		REQUIRE( U.getHP() == 1);
	}
	
	SECTION("Copie"){
		Unite U2 = U;
		REQUIRE( U2.getHP() == 3 );
		REQUIRE( U2.getDMG() == 4 );
	}
}

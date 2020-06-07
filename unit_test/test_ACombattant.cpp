#include "catch.hpp"
#include "ACombattant.hpp"



TEST_CASE( "creation Combattant", "[ACombattant]" ) {
	//ACombattant(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos, int aHp, int aDmg, int aPrix)
	ACombattant A = ACombattant(sf::Color::White, 1, 2, sf::Vector2f (-1,-1), 3, 4, 5);
    REQUIRE( A.getPos() == sf::Vector2f(-1,-1));
    REQUIRE( A.getIndice() == 2);
    REQUIRE( A.getHP() == 3);
    REQUIRE( A.getDMG() == 4);
    
    SECTION("copie"){
		ACombattant A2 = A;
		REQUIRE( A2.getPos() == sf::Vector2f(-1,-1));
		REQUIRE( A2.getIndice() == 2);
		REQUIRE( A2.getHP() == 3);
		REQUIRE( A2.getDMG() == 4);
		
	}
}



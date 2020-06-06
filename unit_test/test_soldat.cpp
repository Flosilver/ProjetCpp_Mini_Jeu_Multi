#include "catch.hpp"
#include "Soldat.hpp"



TEST_CASE( "creation Soldat", "[Soldat]" ) {
	Soldat S = Soldat(sf::Color::Blue, 1, 2);
    REQUIRE( S.getHP() == 20);
    REQUIRE( S.getDMG() == 6);
    REQUIRE( S.getPos() == sf::Vector2f(-1,-1));
    REQUIRE( S.getIndice() == 2);
    
    SECTION("copie"){
		Soldat S2 = S;
		REQUIRE( S2.getHP() == 20);
		REQUIRE( S2.getDMG() == 6);
		REQUIRE( S2.getPos() == sf::Vector2f(-1,-1));
		REQUIRE( S2.getIndice() == 2);
	}
}



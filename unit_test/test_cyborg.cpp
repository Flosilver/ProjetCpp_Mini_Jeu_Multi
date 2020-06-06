#include "catch.hpp"
#include "Cyborg.hpp"



TEST_CASE( "creation Cyborg", "[Cyborg]" ) {
	Cyborg C = Cyborg(sf::Color::Blue, 1, 2);
    REQUIRE( C.getHP() == 30);
    REQUIRE( C.getDMG() == 12);
    REQUIRE( C.getPos() == sf::Vector2f(-1,-1));
    REQUIRE( C.getIndice() == 2);
    
    SECTION("Copie"){
		Cyborg C2 = C;
		REQUIRE( C2.getHP() == 30);
		REQUIRE( C2.getDMG() == 12);
		REQUIRE( C2.getPos() == sf::Vector2f(-1,-1));
		REQUIRE( C2.getIndice() == 2);
	}
}



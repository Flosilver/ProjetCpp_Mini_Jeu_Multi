#include "catch.hpp"
#include "Fleche.hpp"



TEST_CASE( "creation fleche", "[Fleche]" ) {
	Fleche F = Fleche(sf::Color::Blue, 1, 2, 3);
    REQUIRE( F.getHP() == 1);
    REQUIRE( F.getDMG() == 3);
    REQUIRE( F.getPos() == sf::Vector2f(-1,-1));
    REQUIRE( F.getIndice() == 2);
    
    SECTION("Copie"){
		Fleche F2 = F;
		REQUIRE( F2.getHP() == 1);
		REQUIRE( F2.getDMG() == 3);
		REQUIRE( F2.getPos() == sf::Vector2f(-1,-1));
		REQUIRE( F2.getIndice() == 2);
	}
}



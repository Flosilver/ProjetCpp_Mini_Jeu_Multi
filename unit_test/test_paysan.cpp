#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Paysan.hpp"



TEST_CASE( "creation paysan", "[paysan]" ) {
	Paysan P = Paysan(sf::Color::Blue, 1, 2);
    REQUIRE( P.getHP() == 10);
    REQUIRE( P.getDMG() == 1);
    REQUIRE( P.getPos() == sf::Vector2f(-1,-1));
    REQUIRE( P.getIndice() == 2);
    
    SECTION("Copie"){
		Paysan P2 = P;
		REQUIRE( P2.getHP() == 10);
		REQUIRE( P2.getDMG() == 1);
		REQUIRE( P2.getPos() == sf::Vector2f(-1,-1));
		REQUIRE( P2.getIndice() == 2);
	}
}



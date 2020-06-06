#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Paysan.hpp"

//Paysan(const sf::Color& c, int eq, int id, const sf::Vector2f& aPos) : ACombattant(c, eq, id, aPos, 10, 1, 6){}		// couleur, n° equipe, id dans vector<sprites>, vie, dmg, prix rapportée si tuée
	

TEST_CASE( "creation paysan", "[paysan]" ) {
	Paysan P = Paysan(sf::Color::Blue, 1, 2, sf::Vector2f (-1,-1));
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



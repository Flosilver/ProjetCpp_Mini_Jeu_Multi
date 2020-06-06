#include "catch.hpp"
#include "Element.hpp"

TEST_CASE( "test Element", "[Element]" ) {
	//Element(int eq, int id) : pos(-1, -1), equipe(eq), indice(id) {}
	Element E = Element(1,2);
	REQUIRE( E.getIndice() == 2 );
	REQUIRE( E.getPos() == sf::Vector2f(-1,-1) );
	E.setPosition(sf::Vector2f(3,3));
	E.setColor(sf::Color::Red);
	REQUIRE( E.getPos() == sf::Vector2f(3,3) );
	
	SECTION("Copie"){
		Element E2 = E;
		REQUIRE( E.getIndice() == 2 );
		REQUIRE( E.getPos() == sf::Vector2f(3,3) );
	}
}

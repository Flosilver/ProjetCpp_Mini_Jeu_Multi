#include "catch.hpp"
#include "config.hpp"

#include "Mort.hpp"
#include "Paysan.hpp"


TEST_CASE( "test Mort", "[Mort]" ) {
	Unite* pu = new Paysan(sf::Color::White, 1, 0, sf::Vector2f());
	Unite& ru = *pu;
	Mort m(ru);
	
	REQUIRE(m.getUnite().getIndice() == 0);
	
	//Mort M = Mort(&U);
	}
	

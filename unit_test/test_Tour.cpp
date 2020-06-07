#include "catch.hpp"
#include "Tour.hpp"
#include "Tourelle.hpp"


TEST_CASE( "creation Tour", "[Tour]" ) {
	Tour T = Tour(1,2);
	REQUIRE( T.getLvl() == 1 );
	REQUIRE( T.getHP() == 10000 );
	Tourelle To = T.getTourelle();
	REQUIRE( To.getNiveau() == 1 );
	T.damageUp();
	T.porteeUp();
	To = T.getTourelle();
	REQUIRE( T.getTourelle().getPortee() == 300 );
	REQUIRE( T.getTourelle().getDegats() == 2 );
	REQUIRE( To.getNiveau() == 1 );
	T.damageUp();
	T.porteeUp();
	To = T.getTourelle();
	REQUIRE( T.getTourelle().getPortee() == 400 );
	REQUIRE( T.getTourelle().getDegats() == 3 );
	REQUIRE( To.getNiveau() == 1 );
	
	SECTION("Copie"){
		Tour T2 = T;
		REQUIRE( T2.getLvl() == 1 );
		REQUIRE( T2.getHP() == 10000 );
		Tourelle To2 = T.getTourelle();
		REQUIRE( To2.getNiveau() == 1 );
	}
}

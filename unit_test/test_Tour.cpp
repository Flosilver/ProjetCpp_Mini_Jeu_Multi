#include "catch.hpp"
#include "Tour.hpp"
#include "Tourelle.hpp"


TEST_CASE( "creation Tour", "[Tour]" ) {
	Tour T = Tour(1,2);
	REQUIRE( T.getLvl() == 1 );
	REQUIRE( T.getHP() == 200 );
	Tourelle To = T.getTourelle();
	REQUIRE( To.getCoolDown() == 100 );
	REQUIRE( To.getNiveau() == 1 );
	T.damageUp();
	T.porteeUp();
	/*
	REQUIRE( T.getPortee() == 200 );
	REQUIRE( T.getDegats) == 2 );*/
	
	SECTION("Copie"){
		Tour T2 = T;
		REQUIRE( T2.getLvl() == 1 );
		REQUIRE( T2.getHP() == 200 );
		Tourelle To2 = T.getTourelle();
		REQUIRE( To2.getCoolDown() == 100 );
		REQUIRE( To2.getNiveau() == 1 );
	}
}

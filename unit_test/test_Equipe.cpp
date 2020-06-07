#include "catch.hpp"
#include "Equipe.hpp"
#include "Unite.hpp"

TEST_CASE( "test Equipe", "[Equipe]" ) {
	Equipe E =  Equipe(1,2);
	//std::list<Unite*>::iterator it;
	Unite* pu;
	while(!E.creerCombattant(2,sf::Vector2f (-1,-1))){}
	//if(unites
	REQUIRE( E.getUnites().size() == 1);
	//it = E.getUnites().end();
	//--it;
	pu = E.getUnites().back();
	REQUIRE( pu->getHP() == 100 );
	REQUIRE( pu->getDMG() == 1 );
	REQUIRE( E.getBourse() == 26);
	REQUIRE( E.getTourLvl() == 1 );
	E.ajoutMonaie(500);
	REQUIRE( E.getBourse() == 526 );
	E.tourLvlUp();
	REQUIRE( E.getTourLvl() == 2 );
	REQUIRE( E.getHabLvl() == 1 );
	REQUIRE( E.getNum() == 1 );


	
}

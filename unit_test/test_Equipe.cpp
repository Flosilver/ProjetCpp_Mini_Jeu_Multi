#include "catch.hpp"
#include "Equipe.hpp"
#include "Unite.hpp"

TEST_CASE( "test Equipe", "[Equipe]" ) {
	Equipe E =  Equipe(1,2);
	//std::list<Unite*>::iterator it;
	Unite* pu;
	E.creerCombattant(2,sf::Vector2f (-1,-1));
	//if(unites
	REQUIRE( E.getUnites().size() == 1);
	//it = E.getUnites().end();
	//--it;
	pu = E.getUnites().back();
	REQUIRE( pu->getHP() == 10 );
	REQUIRE( pu->getDMG() == 1 );
	REQUIRE( E.getBourse() == 30);
	REQUIRE( E.getTourLvl() == 1 );
	E.ajoutMonaie(500);
	REQUIRE( E.getBourse() == 530 );
	E.tourLvlUp();
	REQUIRE( E.getTourLvl() == 2 );
	REQUIRE( E.getHabLvl() == 1 );
	REQUIRE( E.getNum() == 1 );
	/*
	E.tour_setup_dim(10,20);
	REQUIRE( E.getW() == 10 );
	REQUIRE( E.getH() == 20 );*/
	
	
	SECTION("Copie"){
		Equipe E2 = E;
		REQUIRE( E2.getBourse() == 430);
		REQUIRE( E2.getTourLvl() == 2 );
		
	}
	
}

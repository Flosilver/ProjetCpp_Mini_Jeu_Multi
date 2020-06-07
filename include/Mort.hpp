#ifndef MORT_HPP
#define MORT_HPP

#include <iostream>

#include "Action.hpp"
#include "Unite.hpp"
#include "IAttaquable.hpp"
#include "SandBag.hpp"

class Mort : public Action
{
	protected:
		int equipe;
		IAttaquable& iatt;
	
	public:
		Mort(Unite& u) : Action(u), iatt(* new SandBag()), equipe(0) {}
		Mort(IAttaquable& a): Action(* new SandBag()), iatt(a) {equipe = ((iatt.getEquipe())%2) + 1;}
		//Mort(): Action(* new SandBag()), iatt(* new SandBag()), equipe(0) {}
		~Mort() { }//std::cout << "\tdest_Mort"; }
		Mort& operator=(const Mort& m){
			unite = m.unite;
			equipe = m.equipe;
			iatt = m.iatt;
			return *this;
		}
		
		//void setUnite(Unite& u) {unite = u;}
		//void setIAttaquable(IAttaquable& a);// {iatt = a;}
		
		IAttaquable& getIAtt() {return iatt;};
		const int getEquipe() const {return equipe;}	// 0: si mort d'une unité dû au Deplacement, 1 ou 2 sinon
		int gereAction();
};

#endif

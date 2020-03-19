#ifndef ATTAQUE_HPP
#define ATTAQUE_HPP

#include "Action.hpp"

class Attaque : public Action
{
	private:
	Unite* cible;
	
	public:
	Attaque(Unite* u, Unite* c): Action(u){if (c == nullptr) 
												throw std::string("***ERROR: Attaque(Unite* u, Unite* c): pointeur null");
											else
												cible = c;}
	~Attaque() {std::cout << "dest_attaque"} << std::endl;}
	void gereAction();
};

void Action::gereAction(){
	int degats = (*unite).getDmg();
	int hpCible = (*cible).getHP();
	hpCible -= degats;
	if(hpCible <= 0){
		(*unite).getEquipe().getBourse() += cible.getPrix()/2;
	}
}

#endif

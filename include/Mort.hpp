#ifndef MORT_HPP
#define MORT_HPP

#include "Action.hpp"

class Mort: public Action{
	
	public:
	Mort(Unite* u): Action(u) {}
	~Mort() {std::cout << "dest_mort" << std::endl;}
	void gereAction();	
};

void Mort::gereAction(){
	(*unite).getEquipe().getElements().remove(*unite);	// Equipe a coder notemment le vecteur d'éléments!
}


#endif

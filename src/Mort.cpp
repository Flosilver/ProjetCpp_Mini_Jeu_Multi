#include "Mort.hpp"

int Mort::gereAction(){
	if(unite.getIndice() == -1){
		iatt.meurt();
		//std::cout << "cela" << std::endl;
		return 1;		// SUCCESS
	}
	else if(iatt.getIndice() == -1){
		unite.meurt();
		//std::cout << "ceci" << std::endl;
		return 1;		// SUCCESS
	}
	return 0;		// FAIL
}

/*void Mort::setIAttaquable(IAttaquable& a){
	iatt = a;
	equipe = (iatt.getEquipe() % 2) + 1;
}*/

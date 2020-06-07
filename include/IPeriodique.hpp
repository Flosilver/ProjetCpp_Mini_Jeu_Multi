#ifndef IPERIODIQUE_HPP
#define IPERIODIQUE_HPP

#include <SFML/System.hpp>

class IPeriodique
{
	protected:
		sf::Clock timer;
		
	public:
		IPeriodique() {}
		virtual ~IPeriodique() {}
		
		virtual bool checkTimer() = 0;
		sf::Time restartTimer() {return timer.restart();}
};

#endif

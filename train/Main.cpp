#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	int r = 255;
	int g = 0;
	int b = 0;
	sf::Color col(r,g,b);
	shape.setFillColor(col);
	int rotation = 0;
	
	sf::Clock timer;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
				
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Escape){
					window.close();
				}
			}
		}
		
		/*if ( r == 255 ){ rotation = 0;}
		if ( r == 255 && g == 255 ){ rotation = 1;}
		if ( g == 255 ){ rotation = 1;}
		if ( b == 255 ){ rotation = 2;}*/
		
		if ( r + g + b == 255){
			if ( r == 255 ){ rotation = 0;}
			if ( g == 255 ){ rotation = 1;}
			if ( b == 255 ){ rotation = 2;}
		}
		if ( r + g + b == 510 ){
			if ( r == 255 && g == 255 ){ rotation = 3;}
			if ( g == 255 && b == 255 ){ rotation = 4;}
			if ( b == 255 && r == 255 ){ rotation = 5;}
		}
		
		sf::Time time = timer.getElapsedTime();
		float sec = time.asSeconds();
		
		if (sec >= 0.01){
			switch (rotation){
				case 0:
					g++;
					//std::cout << "g++" << std::endl;
					break;
					
				case 1:
					b++;
					//std::cout << "b++" << std::endl;
					break;
					
				case 2:
					r++;
					//std::cout << "r++" << std::endl;
					break;
				
				case 3:
					r--;
					//std::cout << "r--" << std::endl;
					break;
					
				case 4:
					g--;
					//std::cout << "g--" << std::endl;
					break;
					
				case 5:
					b--;
					//std::cout << "b--" << std::endl;
					break;
					
				default:
					break;
			}
			col.r = r;
			col.g = g;
			col.b = b;
			
			shape.setFillColor(col);
			timer.restart();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

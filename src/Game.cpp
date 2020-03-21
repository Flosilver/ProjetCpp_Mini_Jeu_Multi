#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

sf::RenderWindow window;
sf::Texture tx_paysan;
sf::Texture tx_background;
sf::Texture tx_ground;
enum moves{WalkR, WalkL, AttR, AttL, DieR, DieL};
//std::vector<sf::Sprite> sprites;
//std::vector<sf::Vector2i> anim_sprites;
sf::Vector2i anim(0,WalkR);
int cpt_sprites = 0;
int spriteW = 24;
int spriteH = 32;

sf::Sprite& generePaysan(sf::Texture texture);
void gestion_clavier();

int main()
{
	window.create(sf::VideoMode::getDesktopMode(), "Tower Defense MiniJeu");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	
	// Initialisation du background et du ground du terrain
	sf::Sprite sprite_background;
	if (!tx_background.loadFromFile("tiles/background.jpg")){
		std::cout << "***ERROR: tx_background.loadFromFile(\"background.png\"): failed" << std::endl;
		return EXIT_FAILURE;
	}
	tx_background.setSmooth(true);
	sprite_background.setTexture(tx_background);
	
	sf::Sprite sprite_ground;
	if (!tx_ground.loadFromFile("tiles/ground.png")){
		std::cout << "***ERROR: tx_ground.loadFromFile(\"ground.png\"): failed" << std::endl;
		return EXIT_FAILURE;
	}
	tx_ground.setSmooth(true);
	sprite_ground.setTexture(tx_ground);
	sprite_ground.setPosition(0,window.getSize().y-tx_ground.getSize().y);
	
	if (!tx_paysan.loadFromFile("tiles/paysan.png")){
		std::cout << "***ERROR: tx_paysan.loadFromFile(\"paysan.png\"): failed" << std::endl;
		return EXIT_FAILURE;
	}
	sf::Sprite sprite_paysan;
	sprite_paysan.setTexture(tx_paysan);
	sprite_paysan.scale(3,3);
	sprite_paysan.setTextureRect(sf::IntRect(anim.x * spriteW, anim.y * spriteH, spriteW, spriteH));
	sprite_paysan.setPosition(10, window.getSize().y-tx_ground.getSize().y-spriteH*3);
	
	// Gestion de la fenêtre
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		// gestion clavier
		gestion_clavier();
		
		
		// Déplacement/Animation des combatants
		/*for (int i=0 ; i<cpt_sprites ; i++){
			anim_sprites[cpt_sprites].x++;
			if (anim_sprites[cpt_sprites].x * spriteW >= tx_paysan.getSize().x){
				anim_sprites[cpt_sprites].x = 0;
			}
			if ()
		}*/

		// Nettoyage de la fenêtre
		window.clear();
		
		// Remplissage de la fenêtre avec les éléments permanant
		window.draw(sprite_background);
		window.draw(sprite_ground);
		
		window.draw(sprite_paysan);
		
		// Affiche du contenu de la fenêntre
		window.display();
	}
	
	//sprites.clear();
	//anim_sprites.clear();

	return 0;
}


sf::Sprite& generePaysan(sf::Texture texture){
	sf::Sprite sprite_paysan;
	sprite_paysan.setTexture(texture);
	//sprite_paysan.setPosition(10, window.getSize().y-tx_ground.getSize().y-spriteH);
	
	return sprite_paysan;
}

void gestion_clavier(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		std::cout << "Génération d'un paysan, id:" << cpt_sprites << std::endl;
		/*sprites.push_back(generePaysan(tx_paysan));
		sf::Vector2i v(anim);
		anim_sprites.push_back(v);*/
		cpt_sprites++;
	}
}

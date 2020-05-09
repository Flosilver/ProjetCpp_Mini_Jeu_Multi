#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Equipe.hpp"


/* variables propres au jeu */
sf::RenderWindow window;
enum moves{WalkR, WalkL, AttR, AttL, DieR, DieL};
sf::Clock timer;

std::vector<sf::Sprite> sprites;		// vector des sprites présents sur le jeux
std::vector<sf::Vector2i> anim_sprites;	// vector des animations de chaque sprite

/* elements certainement déplaçable dans un objet mémoire à faire plus tard si le temps nous le permet */
sf::Color red_color(250,50,50);			// couleur de l'équipe bleue
sf::Color blue_color(sf::Color::Cyan);	// couleur de l'équipe rouge
sf::Texture tx_paysan;
sf::Texture tx_background;
sf::Texture tx_ground;
sf::Texture tx_habitation;

/* pseudo arguments */
Equipe eq1(red_color, 1);
Equipe eq2(blue_color, 2);
int etat = 0;

/* définition des méthodes du main */
//void genereSprite(sf::Sprite& sprite_dst, sf::Texture& tx_src, std::string& file);
void gestion_clavier();

int main(){
	
	// création de la fenêtre
	window.create(sf::VideoMode::getDesktopMode(), "Tower Defense MiniJeu");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	
	// Initialisation du background et du ground du terrain
	sf::Sprite sprite_background;
	if (!tx_background.loadFromFile("tiles/background.jpg")){
		std::cout << "***ERROR: tx_background.loadFromFile(\"background.jpg\"): failed" << std::endl;
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
	sprite_ground.setPosition(0,window.getSize().y-tx_ground.getSize().y);	// postionne le sol au bon endroit dans la fenêtre
	
	// Initialisation sprite d'habitation
	//sf::Sprite sprite_habitation;
	if (!tx_habitation.loadFromFile("tiles/habitation.png")){
		std::cout << "***ERROR: tx_habitation.loadFromFile(\"habitation.png\"): failed" << std::endl;
		return EXIT_FAILURE;
	}
	tx_habitation.setSmooth(true);
	//sprite_habitation.setTexture(tx_habitation);
	
	
	// Gestion de la fenêtre
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
			}	
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::A){
					std::cout << "affichage de la maison" << std::endl;
					sf::Sprite sprite_habitation;
					sprite_habitation.setTexture(tx_habitation);
					sprites.push_back(sprite_habitation);
				}
				if (event.key.code == sf::Keyboard::S){
					std::cout << "nombre de sprites: " << sprites.size() << std::endl;
				}
			}
		}
		
		//gestion_clavier();
		
		// Nettoyage de la fenêtre
		window.clear();
		
		// Remplissage de la fenêtre avec les éléments permanant
		window.draw(sprite_background);
		window.draw(sprite_ground);
		
		// Affichage des sprites
		for (unsigned i=0 ; i<sprites.size() ; i++){
			window.draw(sprites[i]);
		}
		
		// Affiche du contenu de la fenêntre
		window.display();
	}
	
	sprites.clear();
	anim_sprites.clear();
	
	return 0;
}

/* méthode qui récupère les intéractions clavier */
void gestion_clavier(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		std::cout << "affichage de la maison" << std::endl;
		sf::Sprite sprite_habitation;
		sprite_habitation.setTexture(tx_habitation);
		sprites.push_back(sprite_habitation);
		/*sf::Vector2i v(anim);
		anim_sprites.push_back(v);*/
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		std::cout << "nombre de sprites: " << sprites.size() << std::endl;
	}
}

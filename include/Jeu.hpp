#ifndef JEU_HPP
#define JEU_HPP

/*#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

#include "config.hpp"

#include "Equipe.hpp"


class Jeu
{
	private:
		int bat_id = 0;				// indice pour le prohain batiment créé
		int unit_id = 0;			// indice pour la prochaine unité créée
		
		Equipe eq1;
		Equipe eq2;
		
		int tourG_W;				// largeur de la tour de gauche
		int tourG_H;				// hauteur de la tour de gauche
		int tourD_W;				// largeur de la tour de droite
		int tourD_H;				// hauteur de la tour de droite
		
		/* attributs du menu */
		std::array<sf::Color, 4> couleurs_joueurs{ {sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Green} };
		sf::Color bout_play_col;
		int r,g,b;
		int rotation = 0;
		
		sf::IntRect rect_menu;
		sf::Clock menu_timer;
		int increment = DEFILEMENT;
		
		int col_jg = 0;		// indice de la couleur du joueur de gauche
		int col_jd = 1;		// indice de la couleur du joueur de droite
		
		int casqueG_W;
		int casqueG_H;
		int casqueD_W;
		int casqueD_H;
		
		int play_but_W;
		int play_but_H;
		
		int bk_menu_W;
		int bk_menu_H;
	
	public:
		Jeu(tx_map& textures, sp_map& sprites);			// Constructeur
		~Jeu();											// Destructeur
		Jeu& operator=(const Jeu& j);
	
		sf::RenderWindow window;	// fenêtre du jeu
		int win_W;					// largeur de la fenêtre
		int win_H;					// hauteur de la fenêtre
		
		
		int etat = 0;
		
		//path_t names;
		//tx_map textures;
		//sp_map sprites;
		
		
		sprite_v menu_sp;	// vector des sprites du menu
		txt_v menu_txt;		// vector des textes du menu
		
		sprite_v bat_sp;	// vector des sprites des batiments présents sur le jeux
		sprite_v unite_sp;	// vector des sprites des unitées du jeux
		vec2i_v anim_sp;	// vector des animations de chaque sprite d'unitée
		
		void getWinSize();
		
		/* Menu */
		void menu_setup(sp_map& sprites, const sf::Font& font);
		void menu_Event(sf::Event& event);
		void menu_update();
		void show_menu();
				
		/* Méthodes static */
		static void Initialise(const char* list_file, tx_map& textures, sp_map& sprites);		// Initailise le jeu de manière static. Renvoie false si échoué, true sinon
		
		static bool LoadNames(const char* list_file, path_map& names);								// initialise le nom des textures du jeux et les associe à leur chemin. Renvoie false si échoué, true sinon
		static bool LoadTextures(const path_map& names, tx_map& textures);	// initialise les textures grâce à leur nom et leur chemin. Renvoie false si échoué, true sinon
		static bool LoadSprites(const tx_map& textures, sp_map& sprites);	// initialise les sprites des textures grâce à leur nom et leur texture. Renvoie false si échoué, true sinon
		
		void update(){}
};


#endif

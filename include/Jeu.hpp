#ifndef JEU_HPP
#define JEU_HPP

/*#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>*/

/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
#include <ctime>*/

#include "config.hpp"

#include "Equipe.hpp"
#include "Attaque.hpp"
#include "Deplacement.hpp"
#include "Mort.hpp"


class Jeu
{
	private:
		
		Equipe eq1 = Equipe(1, 0);
		Equipe eq2 = Equipe(2, 3);
		
		/* attributs du menu */
		sprite_v menu_sp;	// vector des sprites du menu
		txt_v menu_txt;		// vector des textes du menu
		
		std::array<sf::Color, NB_COL> couleurs_joueurs{ {sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Green} };
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
		
		/* attributs du jeu */
		sprite_v bandeau_sp;	// vector des sprites du bandeau de commande du jeu
		txt_v bandeau_txt;		// vector des textes du bandeau de commande du jeu
		
		sprite_v terrain_sp;	// vector des sprites du terrain de jeu
		
		sprite_v bat_sp;	// vector des sprites des batiments présents sur le jeux
		sprite_v unite_sp;	// vector des sprites des unitées du jeux
		vec2i_v anim_sp;	// vector des animations de chaque sprite d'unitée
		
		int bat_id = 0;				// indice pour le prohain batiment créé
		int unit_id = 0;			// indice pour la prochaine unité créée
		std::list<int> id_libre;
		
		int tourG_W;				// largeur de la tour de gauche
		int tourG_H;				// hauteur de la tour de gauche
		int tourD_W;				// largeur de la tour de droite
		int tourD_H;				// hauteur de la tour de droite
			
		int tourelle_W;				// largeur de la tourelle
		int tourelle_H;				// hauteur de la tourelle
		
		sf::Sprite vie_jg;
		sf::Sprite vie_jd;
		sf::IntRect rect_vie_jg = sf::IntRect(0,0,VIE_W,VIE_H);
		sf::IntRect rect_vie_jd = sf::IntRect(0,0,VIE_W,VIE_H);
		
		sf::Clock tour_timer;	// timer pour l'ajout de monaie
		sf::Clock anim_timer;	// timer pour l'animation des sprites des unites
		
		sf::Vector2f popG;		// position d'apparition des unites de l'equipe1
		sf::Vector2f popD;		// position d'apparition des unites de l'equipe2
		
		/* End */
		int winner = 0;
		sprite_v end_sp;
		sf::Text fin;
	
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
		
		/* Menu */
		
		/* Game */
		
		void getWinSize();
		
		/* Menu */
		void menu_setup(sp_map& sprites, const sf::Font& font);
		void menu_Event(sf::Event& event, sp_map& sprites, const sf::Font& font);
		void menu_update();
		void show_menu();
		
		/* Game */
		void terrain_setup(sp_map& sprites);
		void show_terrain();
		
		void bandeau_setup(sp_map& sprites, const sf::Font& font);
		void bandeau_update();
		void show_bandeau();
		
		void action_update(std::list<Action*>& actions);
		void action_gestion(std::list<Action*>& actions);
		void gestion_unites();
		
		void game_setup(sp_map& sprites, const sf::Font& font);
		void game_Event(sf::Event& event, sp_map& sprites);
		void game_update(sp_map& sprites, const sf::Font& font);
		void show_game();
		
		void end_setup(sp_map& sprites, const sf::Font& font, int eq);
		void end_Event(sf::Event& event);
		void show_end();
				
		/* Méthodes static */
		static void Initialise(const char* list_file, tx_map& textures, sp_map& sprites);		// Initailise le jeu de manière static. Renvoie false si échoué, true sinon
		
		static bool LoadNames(const char* list_file, path_map& names);								// initialise le nom des textures du jeux et les associe à leur chemin. Renvoie false si échoué, true sinon
		static bool LoadTextures(const path_map& names, tx_map& textures);	// initialise les textures grâce à leur nom et leur chemin. Renvoie false si échoué, true sinon
		static bool LoadSprites(const tx_map& textures, sp_map& sprites);	// initialise les sprites des textures grâce à leur nom et leur texture. Renvoie false si échoué, true sinon
		
		void update(){}
};


#endif

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <map>
#include <vector>


typedef std::map<std::string, std::string> path_map;
typedef std::map<std::string, sf::Texture> tx_map;
typedef std::map<std::string, sf::Sprite> sp_map;

typedef std::vector<sf::Sprite> sprite_v;
typedef std::vector<sf::Vector2i> vec2i_v;
typedef std::vector<sf::Text> txt_v;


/* Fenetre generale */
#define RW_W 1500		// largeur de la fenetre
#define RW_H 1000		// hauteur de la fenetre
//#define WIN_S_H 1025	// hauteur de size de fenetre

/* Menu */
#define DEFILEMENT 3 	// Incrément de décalage du menu
//#define COULEUR_JOUEUR std::array<sf::Color, 4>{ {sf::Color::Yellow, sf::Color::Blue, sf::Color::Red, sf::Color::Green} }
#define SCA_SELECT 0.7f	// scale up des casque de selection de couleur
#define D_TIME 0.001		// intervalde temps entre chaque variation de couleur du bouton play
#define NB_COL 4		// nombre de couleurs pour les couleurs de équipes


/* Jeu */
#define GROUND_H 40		// hauteur de la texture du sol du jeu
#define BANDEAU_H 120	// hauteur du bandeau gris pour les boutons
#define D_BUT 5			// Ecart entre chaque bouton (en pixel)

#define VIE_W 300
#define VIE_H 15

#define ARG_W 200		// largeur de l'emplacement de l'argent
#define COMM_W 80		// largeur des commandes
#define COMM_H 100		// hauteur des commandes
#define MONNAIE_COL sf::Color(231,192,12)	// couleur du texte de l'argent des Equipes
#define MONNAIE_SIZE 25						// charactereSize du texte de l'argent des Equipes
#define MONNAIE_POSX 10
#define MONNAIE_POSY 35
#define PRIX_SIZE 8				// charactereSize du texte des prix des boutons
#define PRIX_POSX 10
#define PRIX_POSY 83

#define TOUR_1TO2 100			// prix pour passer de tour lvl1 à lvl2
#define TOUR_DMG_1TO2 200		// prix pour augmenter les dégats de la tourelle
#define TOUR_PORTEE_1TO2 200	// prix pour augmenter la portée de la tourelle
#define HAB_1TO2 75				// prix pour passer de hab lvl1 à lvl2
#define HAB_2TO3 150			// prix pour passer de hab lvl2 à lvl3
#define PAYSAN_PRIX 4			// prix pour générer un paysan
#define SOLDAT_PRIX 8			// prix pour générer un soldat
#define CYBORG_PRIX 12			// prix pour générer un cyborg

#define TOUR_POSX 200
#define TOURELLE_POSY 500

#define TOUR1_MONNAIE 10		// argent généré par la tour de niveau 1 donné à l'équipe à intervalle de temps régulier
#define TOUR2_MONNAIE 15		// argent généré par la tour de niveau 2 donné à l'équipe à intervalle de temps régulier
#define MONEY_TIME 2		// intervalle de temps où les tours génèrent de l'argent

#define ARGENT_MAX 999		// argent max que peut posséder une équipe

/* Unitées */
#define U_RECT_W 24		// largeur des sprites des unitées
#define U_RECT_H 32		// hauteur des sprites des unitées
#define U_SCALE 3		// variable d'élargissement des unitées
#define U_SP_W U_RECT_W*U_SCALE
#define U_SP_H U_RECT_H*U_SCALE
#define U_POS_SOL GROUND_H - U_SP_H

#define U_PRIX_P -PAYSAN_PRIX		// prix que coûte un paysan à créer
#define U_PRIX_S -SOLDAT_PRIX		// prix que coûte un soldat à créer
#define U_PRIX_C -CYBORG_PRIX	// prix que coûte un cyborg à créer
//#define U_POS_L sf::Vector2f(10, WIN_H - GROUND_H - U_SCALE * U_SP_H)	// Position d'apparition des unités à gauche
//#define U_POS_R sf::Vector2f(1910, WIN_H - GROUND_H - U_SCALE * U_SP_H)	// Position d'apparition des unités à droite

/* Animation et déplacement */
typedef enum {WalkR, WalkL, AttR, AttL, DieR, DieL} move_t;
#define U_MOVE_R sf::Vector2f(2,0)	// déplacement des unitées vers la droite
#define U_MOVE_L sf::Vector2f(-2,0)	// déplacement des unitées vers la gauche

/* Tour */
#define HP_MAX 200		// nombre de point de vie max de la tour
/*#define TOUR_W 100
#define TOUR_H 500
#define TOUR_G_POS sf::Vector2f(10, TOUR_H - GROUND_H)
#define TOUR_D_POS sf::Vector2f(10 + TOUR_W, TOUR_H - GROUND_H)*/

/*class config
{
	public:
		/* Fenetre du jeux */
		//config(const sf::RenderWindow& rw): WIN_W(rw.getSize().x), WIN_H(rw.getSize().y);
		
		
		//int WIN_W;
		//int WIN_H;
		/* Unitées */
		//static const enum moves{WalkR, WalkL, AttR, AttL, DieR, DieL};					// enumeration pour l'animation des unitées
		//static const sf::Vector2f U_POS_L(200, WIN_H - GROUND_H - U_SCALE * U_SP_H);	// Position d'apparition des unités à gauche
		//static const sf::Vector2f U_POS_R(1720, WIN_H - GROUND_H - U_SCALE * U_SP_H);	// Position d'apparition des unités à droite
		
		/* Texture */
	
//};

#endif

#include "config.hpp"
#include "Jeu.hpp"
#include "JeuException.hpp"

Jeu::Jeu(tx_map& textures, sp_map& sprites){
	// Fenetre
	window.create(sf::VideoMode::getDesktopMode(), "BATTEZ-VOUS.EXE");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	
	sf::Vector2u size;
	size = window.getSize();
	win_W = size.x;
	win_H = size.y;
	
	eq1 = Equipe(1, bat_id);//, sprites, bat_sp);
	bat_id += 3;
	std::cout << bat_id << std::endl;
	
	eq2 = Equipe(2, bat_id);
	bat_id += 3;
	std::cout << bat_id << std::endl;
	
	/* Ajout au jeu des sprites des habitations, des tours et des tourelles */
	// Equipe 1
	bat_sp.push_back(sprites["habitation"]);
	bat_sp.push_back(sprites["tourG"]);
	bat_sp.push_back(sprites["tourelle"]);
	// Equipe 2
	bat_sp.push_back(sprites["habitation"]);
	bat_sp.push_back(sprites["tourD"]);
	bat_sp.push_back(sprites["tourelle"]);
	bat_sp[(bat_sp.size())-1].rotate(180.f);
	
	tourG_W = textures["tourG"].getSize().x;
	tourG_H = textures["tourG"].getSize().y;
	
	tourG_W = textures["tourG"].getSize().x;
	tourG_H = textures["tourG"].getSize().y;
	
	casqueG_W = textures["casqueG"].getSize().x;
	casqueG_H = textures["casqueG"].getSize().y;
	casqueD_W = textures["casqueD"].getSize().x;
	casqueD_H = textures["casqueD"].getSize().y;
	
	play_but_W = textures["but_play"].getSize().x;
	play_but_H = textures["but_play"].getSize().y;
	
	bk_menu_W = textures["bk_menu"].getSize().x;
	bk_menu_H = textures["bk_menu"].getSize().y;
	
}

Jeu::~Jeu(){
	//names.clear();
	//std::cout << "dest names\t";
	/*textures.clear();
	std::cout << "dest textures\t";
	sprites.clear();
	std::cout << "dest sprites\t";*/
	
	bat_sp.clear();
	std::cout << "dest sprites de batiment\t";
	unite_sp.clear();
	std::cout << "dest sprites des unites\t";
	anim_sp.clear();
	std::cout << "dest vecteurs d'animation des sprites\tdest_Jeu" << std::endl;
	
	menu_sp.clear();
	menu_txt.clear();
}

Jeu& Jeu::operator=(const Jeu& j){
	sf::Vector2u size;
	size = j.window.getSize();
	win_W = size.x;
	win_H = size.y;
	
	window.create(sf::VideoMode(win_W,win_H), "BATTEZ-VOUS.EXE");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	
	bat_id = j.bat_id;
	unit_id = j.unit_id;
	
	//names = j.names;
	//textures = j.textures;
	//Jeu::LoadSprites(textures, sprites);
	
	return *this;
}

/* Lecture du fichier texte qui liste les textures du jeu */
bool Jeu::LoadNames(const char* list_file, path_map& names){
	
	std::ifstream list(list_file);	// on ouvre le fichier en lecture
	
	if(list){	// on vérifie s'il est bien ouvert
		std::string ligne;
		std::string chemin;
		while(getline(list, ligne,'|'))  // tant que l'on peut mettre la ligne du fichier dans ligne
		{
			getline(list, chemin);  // tant que l'on peut mettre la ligne dans "contenu"
			//std::cout << ligne << "\t\t";  // on l'affiche
			//std::cout << chemin << std::endl;  // on l'affiche
			names[ligne] = chemin;//on associe le nom de la texture à un chemin
		}
		return true;	// SUCCESS
			
	}else{
		std::cout << "***ERROR: Jeu::LoadNames(): Impossible de lire " << list_file << std::endl;
		return false;	// ECHEC de lecture
	}
}

/* Initialise la map des textures du jeu */
bool Jeu::LoadTextures(const path_map& names, tx_map& textures){
	
	for (path_map::const_iterator it = names.begin() ; it != names.end() ; ++it){
		if(!textures[it->first].loadFromFile(it->second)){
			std::cout << "***ERROR: tx_bandeau.loadFromFile(" << it->second << "): failed" << std::endl;
			return false;
		}
	}
	
	return true;
}

/* Initialise les sprites grâce aux textures du jeu */
bool Jeu::LoadSprites(const tx_map& textures, sp_map& sprites){
	
	for (tx_map::const_iterator it = textures.begin() ; it != textures.end() ; ++it){
		sprites[it->first].setTexture(it->second);
	}
	
	return true;
}


void Jeu::Initialise(const char* list_file, tx_map& textures, sp_map& sprites){
	
	//Jeu jeu;	
	/*this->textures.clear();
	std::cout << "dest textures\t";
	this->sprites.clear();
	std::cout << "dest sprites\t";
	
	this->bat_sp.clear();
	std::cout << "dest sprites de batiment\t";
	this->unite_sp.clear();
	std::cout << "dest sprites des unites\t";
	this->anim_sp.clear();
	std::cout << "dest vecteurs d'animation des sprites\tdest_Jeu" << std::endl;*/
	textures.clear();
	sprites.clear();
	
	bool b1, b2, b3;
	
	path_map chemins;
	
	// Récupération des noms et chemins des textures
	b1 = Jeu::LoadNames(list_file, chemins);
	b2 = Jeu::LoadTextures(chemins, textures);
	b3 = Jeu::LoadSprites(textures, sprites);
	
	chemins.clear();
	
	if(!(b1 && b2 && b3)){
		throw JeuException("Erreur pendant le chargement des textures");
	}
	
	/* Ajout au jeu des sprites des habitations, des tours et des tourelles */
	// Equipe 1
	/*this->bat_sp.push_back(this->sprites["habitation"]);
	this->bat_sp.push_back(this->sprites["tourG"]);
	this->bat_sp.push_back(this->sprites["tourelle"]);
	// Equipe 2
	this->bat_sp.push_back(this->sprites["habitation"]);
	this->bat_sp.push_back(this->sprites["tourD"]);
	this->bat_sp.push_back(this->sprites["tourelle"]);
	this->bat_sp[this->bat_sp.size()-1].rotate(180.f);
	
	this->tourG_W = this->textures["tourG"].getSize().x;
	this->tourG_H = this->textures["tourG"].getSize().y;
	
	this->tourG_W = this->textures["tourG"].getSize().x;
	this->tourG_H = this->textures["tourG"].getSize().y;
	
	//return jeu;*/
}

void Jeu::getWinSize(){
	sf::Vector2u size;
	size = this->window.getSize();
	win_W = size.x;
	win_H = size.y;
}

/* Méthodes du menu */

/* Permet d'initialiser le menu avant la boucle while du jeu */
void Jeu::menu_setup(sp_map& sprites, const sf::Font& font){
	bout_play_col = sf::Color(255, 0, 0);
	menu_sp.clear();
	menu_txt.clear();
	
	// background du menu: indice 0
	menu_sp.push_back(sprites["bk_menu"]);
	if( win_W == 0 || win_H == 0){
		throw JeuException("***ERROR: Jeu::setup_menu: initialisation du background failed");
	}
	rect_menu = sf::IntRect(0,0,win_W,win_H);
	menu_sp[0].setTextureRect(rect_menu);
	
	// bouton play: indice 1
	menu_sp.push_back(sprites["but_play"]);
	menu_sp[1].setPosition((win_W - play_but_W)/2, (win_H - play_but_H)/2);
	
	// casqueG: indice 2
	menu_sp.push_back(sprites["casqueG"]);
	menu_sp[2].scale(SCA_SELECT,SCA_SELECT);
	menu_sp[2].setPosition(win_W/4 - casqueG_W / 2, 5 * win_H / 8);
	menu_sp[2].setColor(couleurs_joueurs[col_jg]);
	
	// casqueG: indice 3
	menu_sp.push_back(sprites["casqueD"]);
	menu_sp[3].scale(SCA_SELECT,SCA_SELECT);
	menu_sp[3].setPosition(3 * win_W / 4 - (casqueD_W / 4), 5 * win_H / 8);
	menu_sp[3].setColor(couleurs_joueurs[col_jd]);
	
	std::cout << font.getInfo().family << std::endl;
	
	// bouton play txt: indice 0
	menu_txt.push_back(sf::Text());//"JOUER!", font, 130));
	menu_txt[0].setFont(font);
	menu_txt[0].setString("JOUER!");
	menu_txt[0].setCharacterSize(130);
	menu_txt[0].setPosition((win_W)/2 - 230, 5*(win_H)/11);
	menu_txt[0].setFillColor(bout_play_col);
	
	// texte de selection jg: indice 1
	menu_txt.push_back(sf::Text());//"Choix de la couleur avec <SpaceBar>", font, 25));
	menu_txt[1].setFont(font);
	menu_txt[1].setString("Choix de la couleur avec <SpaceBar>");
	menu_txt[1].setCharacterSize(25);
	menu_txt[1].setPosition(win_W / 20, win_H - 40);
	menu_txt[1].setFillColor(couleurs_joueurs[col_jg]);
	
	// texte de selection jd: indice 2
	menu_txt.push_back(sf::Text());//"Choix de la couleur avec <Up>", font, 25));
	menu_txt[2].setFont(font);
	menu_txt[2].setString("Choix de la couleur avec <Up>");
	menu_txt[2].setCharacterSize(25);
	menu_txt[2].setPosition(13 * win_W / 20, win_H - 40);
	menu_txt[2].setFillColor(couleurs_joueurs[col_jd]);
	
	menu_timer.restart();
}

/* gère les event dans le menu */
void Jeu::menu_Event(sf::Event& event){
	if (event.type == sf::Event::Closed){
		window.close();
	}
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Escape){
			window.close();
		}
		
		/* Choix des couleurs des joueurs */		
		if(event.key.code == sf::Keyboard::Space){
			if((col_jg + 1)%4 != col_jd){
				col_jg = (col_jg + 1)%4;
			}
			else{
				col_jg = (col_jg + 2)%4;
			}
			menu_sp[2].setColor(couleurs_joueurs[col_jg]);
			menu_txt[1].setFillColor(couleurs_joueurs[col_jg]);
		}
		
		if(event.key.code == sf::Keyboard::Up){
			if((col_jd + 1)%4 != col_jg){
				col_jd = (col_jd + 1)%4;
			}
			else{
				col_jd = (col_jd + 2)%4;
			}
			menu_sp[3].setColor(couleurs_joueurs[col_jd]);
			menu_txt[2].setFillColor(couleurs_joueurs[col_jd]);
		}
	}
	if (event.type == sf::Event::MouseButtonPressed){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if (event.mouseButton.x > menu_sp[1].getPosition().x && event.mouseButton.x < (menu_sp[1].getPosition().x + play_but_W) && event.mouseButton.y > menu_sp[1].getPosition().y && event.mouseButton.y < (menu_sp[1].getPosition().y + play_but_H) ){
				//sprite_bouton.setTexture(tx_bouton_enf);
				//std::cout << "bouton cliqué!" << std::endl;
				
				// Libération de l'espace mémoire
				menu_sp.clear();
				menu_txt.clear();
				
				// Passage à l'état de jeu
				etat = 1;
			}
		}
	}
}

void Jeu::menu_update(){
	// Gestion du défilement du background
	int a = (bk_menu_W - (rect_menu.left + rect_menu.width));
	if ( a <= 0 || rect_menu.left < 0 ){
		increment = -increment;
	}
	rect_menu.left += increment;
	menu_sp[0].setTextureRect(rect_menu);
	
	// Gestion de la couleur du bouton play
	r = bout_play_col.r;
	g = bout_play_col.g;
	b = bout_play_col.b;
	
	// Rotation de la couleur
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
	sf::Time time = menu_timer.getElapsedTime();
	float sec = time.asSeconds();
	
	if (sec >= D_TIME){
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
		bout_play_col.r = r;
		bout_play_col.g = g;
		bout_play_col.b = b;
		
		menu_txt[0].setFillColor(bout_play_col);
		menu_timer.restart();
	}
}

void Jeu::show_menu(){
	//std::cout << "------\nwin_size: [" << win_W << ";" << win_H << "]" << std::endl;
	//std::cout << "---\nmenu_sp.size(): " << menu_sp.size() << "\tmenu_txt.size(): " << menu_txt.size() << std::endl;
	for (size_t i=0 ; i < menu_sp.size() ; ++i){
		window.draw(menu_sp[i]);
	}
	for (size_t i=0 ; i < menu_txt.size() ; ++i){
		//std::cout << "r[" << i << "]: " << static_cast<unsigned int>(menu_txt[i].getFillColor().r) << "\tg[" << i << "]: " << static_cast<unsigned int>(menu_txt[i].getFillColor().g) << "\tb[" << i << "]: " << static_cast<unsigned int>(menu_txt[i].getFillColor().b);
		//std::string str = menu_txt[i].getString();
		//std::cout << "txt[" << i << "] = " << str;
		//std::cout << "\t\tPosition: [" << menu_txt[i].getPosition().x << " : " << menu_txt[i].getPosition().y << "]" << std::endl;
		window.draw(menu_txt[i]);
	}
	window.display();
}






int main(void){
	/* Initialisation du random */
	srand(time(NULL));
	
	/* Initialisation du jeux */
	tx_map textures;
	sp_map sprites;
	try{	
		std::cout << "------\nInitialisation des textures et des sprites que le Jeu nécessite:\n" << std::endl;	
		Jeu::Initialise("tiles/list_tx.txt", textures, sprites);
		std::cout << std::endl;
	}
	catch (const JeuException& e){
		std::cerr << e.what() << std::endl;
		return 0;
	}
	
	Jeu jeu(textures,sprites);
	
	std::cout << "fin de la création" << std::endl;
	
	
	/* Initialisation des fonts */
	sf::Font menu_font;
	sf::Font monnaie_font;
	
	if (!menu_font.loadFromFile("tiles/Pixel Digivolve.otf")){
		std::cerr << "***ERROR: menu_font.loadFromFile(tiles/Pixel Digivolve.otf): failed" << std::endl;
		return EXIT_FAILURE;
	}
	if (!monnaie_font.loadFromFile("tiles/Pixelmania.ttf")){
		std::cerr << "***ERROR: monnaie_font.loadFromFile(tiles/Pixelmania.ttf): failed" << std::endl;
		return EXIT_FAILURE;
	}
	
	/* Initialisation du menu */
	try{
		jeu.menu_setup(sprites, menu_font);
	}catch (const JeuException& e){
		std::cerr << e.what() << std::endl;
		return 0;
	}
	
	/* Boucle du jeu */
	while(jeu.window.isOpen()){
		sf::Event event;
		
		// Nettoyage de la fenêtre
		jeu.window.clear();
		jeu.getWinSize();
		
		switch (jeu.etat){
			/* Menu */
			case 0:
				while (jeu.window.pollEvent(event))
				{
					jeu.menu_Event(event);
				}
				jeu.menu_update();
				jeu.show_menu();
				break;
			
			/* Jeu */
			case 1:
				textures.clear();
				sprites.clear();
				exit(1);
				break;
			
			/* Ecran de victoire */
			case 2:
				textures.clear();
				sprites.clear();
				exit(1);
				break;
				
			/* Erreur d'état */
			default:
				textures.clear();
				sprites.clear();
				exit(1);
				break;
		}
	}
	
	textures.clear();
	sprites.clear();
	
	return 0;
}

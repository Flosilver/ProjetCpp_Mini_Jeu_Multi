#include "config.hpp"
#include "Jeu.hpp"
#include "JeuException.hpp"

Jeu::Jeu(tx_map& textures, sp_map& sprites){
	// Fenetre
	window.create(sf::VideoMode(RW_W, RW_H) /*::getDesktopMode()*/, "BATTEZ-VOUS.EXE", sf::Style::Close);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	
	sf::Vector2u size;
	size = window.getSize();
	win_W = size.x;
	win_H = size.y;
	
	std::cout << "win_W: " << win_H << "\twin_H: " << win_H << std::endl;
	
	//eq1 = Equipe(1, bat_id);//, sprites, bat_sp);
	bat_id += 3;
	std::cout << bat_id << std::endl;
	std::cout << eq1.getTourHp() << std::endl;
	
	//eq2 = Equipe(2, bat_id);
	bat_id += 3;
	std::cout << bat_id << std::endl;
	
	tourG_W = textures["tourG"].getSize().x;
	tourG_H = textures["tourG"].getSize().y;
	
	tourD_W = textures["tourD"].getSize().x;
	tourD_H = textures["tourD"].getSize().y;
	
	tourelle_W = textures["tourelle"].getSize().x;
	tourelle_H = textures["tourelle"].getSize().y;
	
	casqueG_W = textures["casqueG"].getSize().x;
	casqueG_H = textures["casqueG"].getSize().y;
	casqueD_W = textures["casqueD"].getSize().x;
	casqueD_H = textures["casqueD"].getSize().y;
	
	play_but_W = textures["but_play"].getSize().x;
	play_but_H = textures["but_play"].getSize().y;
	
	bk_menu_W = textures["bk_menu"].getSize().x;
	bk_menu_H = textures["bk_menu"].getSize().y;
	
	vie_jg = sf::Sprite(textures["vie"], rect_vie_jg);
	vie_jd = sf::Sprite(textures["vie"], rect_vie_jd);
	
	vie_jg.setPosition(0, win_H - GROUND_H + 5);
	vie_jd.setPosition(1500-VIE_W, win_H - GROUND_H + 5);
}

Jeu::~Jeu(){
	//names.clear();
	//std::cout << "dest names\t";
	/*textures.clear();
	std::cout << "dest textures\t";
	sprites.clear();
	std::cout << "dest sprites\t";*/
	
	menu_sp.clear();
	menu_txt.clear();
	
	bandeau_sp.clear();
	bandeau_txt.clear();
	
	terrain_sp.clear();
	
	bat_sp.clear();
	std::cout << "dest sprites de batiment\t";
	unite_sp.clear();
	std::cout << "dest sprites des unites\t";
	anim_sp.clear();
	std::cout << "dest vecteurs d'animation des sprites\tdest_Jeu" << std::endl;
}

Jeu& Jeu::operator=(const Jeu& j){
	sf::Vector2u size;
	size = j.window.getSize();
	win_W = size.x;
	win_H = size.y;
	
	window.create(sf::VideoMode(RW_W, RW_H), "BATTEZ-VOUS.EXE", sf::Style::Close);
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
void Jeu::menu_Event(sf::Event& event, sp_map& sprites, const sf::Font& font){
	if (event.type == sf::Event::Closed){
		window.close();
	}
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Escape){
			window.close();
		}
		
		/* Choix des couleurs des joueurs */		
		if(event.key.code == sf::Keyboard::Space){
			if((col_jg + 1)%NB_COL != col_jd){
				col_jg = (col_jg + 1)%NB_COL;
			}
			else{
				col_jg = (col_jg + 2)%NB_COL;
			}
			menu_sp[2].setColor(couleurs_joueurs[col_jg]);
			menu_txt[1].setFillColor(couleurs_joueurs[col_jg]);
		}
		
		if(event.key.code == sf::Keyboard::Up){
			if((col_jd + 1)%NB_COL != col_jg){
				col_jd = (col_jd + 1)%NB_COL;
			}
			else{
				col_jd = (col_jd + 2)%NB_COL;
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
				std::cout << "on passe au jeu" << std::endl;
				// Libération de l'espace mémoire
				menu_sp.clear();
				menu_txt.clear();
				
				
				
				game_setup(sprites, font);
				
				// Passage à l'état de jeu
				etat = 1;
			}
		}
	}
}

void Jeu::menu_update(){
	// Gestion du défilement du background
	if(menu_sp.size() == 0 || menu_txt.size() == 0){
		return;
	}
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

/* Méthodes du menu */

/* Initialise le bandeau de commande du jeu */
void Jeu::bandeau_setup(sp_map& sprites, const sf::Font& font){
	// metal bar: indice 0
	bandeau_sp.push_back(sprites["metal_bar"]);
	sf::IntRect rect_gestion(0,0,win_W,BANDEAU_H);
	bandeau_sp[0].setTextureRect(rect_gestion);
	
	// argent eq1: indice 1
	bandeau_sp.push_back(sprites["argent"]);
	bandeau_sp[1].setPosition(D_BUT,D_BUT);
	
	// tourUp eq1: indice 2
	bandeau_sp.push_back(sprites["tour_upG"]);
	bandeau_sp[2].setPosition(bandeau_sp[1].getPosition().x + ARG_W + D_BUT, D_BUT);
	
	// tourDmgUp eq1: indice 3
	bandeau_sp.push_back(sprites["tour_dmg_upG"]);
	bandeau_sp[3].setPosition(bandeau_sp[2].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	// tourPorteeUp eq1: indice 4
	bandeau_sp.push_back(sprites["tour_portee_upG"]);
	bandeau_sp[4].setPosition(bandeau_sp[3].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	// habUp eq1: indice 5
	bandeau_sp.push_back(sprites["hab_upG"]);
	bandeau_sp[5].setPosition(bandeau_sp[4].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	// unite+ eq1: indice 6
	bandeau_sp.push_back(sprites["unite_plusG"]);
	bandeau_sp[6].setPosition(bandeau_sp[5].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	// argent eq2: indice 7
	bandeau_sp.push_back(sprites["argent"]);
	bandeau_sp[7].setPosition(win_W/2 + D_BUT,D_BUT);
	
	// tourUp eq2: indice 8
	bandeau_sp.push_back(sprites["tour_upD"]);
	bandeau_sp[8].setPosition(bandeau_sp[7].getPosition().x + ARG_W + D_BUT, D_BUT);
	
	// tourDmgUp eq2: indice 9
	bandeau_sp.push_back(sprites["tour_dmg_upD"]);
	bandeau_sp[9].setPosition(bandeau_sp[8].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	// tourPorteeUp eq2: indice 10
	bandeau_sp.push_back(sprites["tour_portee_upD"]);
	bandeau_sp[10].setPosition(bandeau_sp[9].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	// habUp eq2: indice 11
	bandeau_sp.push_back(sprites["hab_upD"]);
	bandeau_sp[11].setPosition(bandeau_sp[10].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	// unite+ eq2: indice 12
	bandeau_sp.push_back(sprites["unite_plusD"]);
	bandeau_sp[12].setPosition(bandeau_sp[11].getPosition().x + COMM_W + D_BUT, D_BUT);
	
	for (int i=0 ; i<=6 ; i=i+6){
		// argent : indice 0 ou 6
		bandeau_txt.push_back(sf::Text());
		bandeau_txt[i].setFont(font);
		bandeau_txt[i].setString(std::to_string(eq1.getBourse()));
		bandeau_txt[i].setFillColor(MONNAIE_COL);
		bandeau_txt[i].setCharacterSize(MONNAIE_SIZE);
		bandeau_txt[i].setPosition(bandeau_sp[i+1].getPosition().x + MONNAIE_POSX, bandeau_sp[i+1].getPosition().y + MONNAIE_POSY);//sprite_argent.getPosition().x + 10,sprite_argent.getPosition().y + 35
		
		// prix tourUp : indice 1 ou 7
		bandeau_txt.push_back(sf::Text());
		bandeau_txt[i+1].setFont(font);
		bandeau_txt[i+1].setString(std::to_string(TOUR_1TO2));
		bandeau_txt[i+1].setFillColor(MONNAIE_COL);
		bandeau_txt[i+1].setCharacterSize(PRIX_SIZE);
		bandeau_txt[i+1].setPosition(bandeau_sp[i+2].getPosition().x + PRIX_POSX, bandeau_sp[i+2].getPosition().y + PRIX_POSY);
		
		// prix tourDmgUp : indice 2 ou 8
		bandeau_txt.push_back(sf::Text());
		bandeau_txt[i+2].setFont(font);
		bandeau_txt[i+2].setString(std::to_string(TOUR_DMG_1TO2));
		bandeau_txt[i+2].setFillColor(MONNAIE_COL);
		bandeau_txt[i+2].setCharacterSize(PRIX_SIZE);
		bandeau_txt[i+2].setPosition(bandeau_sp[i+3].getPosition().x + PRIX_POSX, bandeau_sp[i+3].getPosition().y + PRIX_POSY);
		
		// prix tourPorteeUp : indice 3 ou 9
		bandeau_txt.push_back(sf::Text());
		bandeau_txt[i+3].setFont(font);
		bandeau_txt[i+3].setString(std::to_string(TOUR_PORTEE_1TO2));
		bandeau_txt[i+3].setFillColor(MONNAIE_COL);
		bandeau_txt[i+3].setCharacterSize(PRIX_SIZE);
		bandeau_txt[i+3].setPosition(bandeau_sp[i+4].getPosition().x + PRIX_POSX, bandeau_sp[i+4].getPosition().y + PRIX_POSY);
		
		// prix habUp : indice 4 ou 10
		bandeau_txt.push_back(sf::Text());
		bandeau_txt[i+4].setFont(font);
		bandeau_txt[i+4].setString(std::to_string(HAB_1TO2));
		bandeau_txt[i+4].setFillColor(MONNAIE_COL);
		bandeau_txt[i+4].setCharacterSize(PRIX_SIZE);
		bandeau_txt[i+4].setPosition(bandeau_sp[i+5].getPosition().x + PRIX_POSX, bandeau_sp[i+5].getPosition().y + PRIX_POSY);
		
		// prix unitePlus : indice 5 ou 11
		bandeau_txt.push_back(sf::Text());
		bandeau_txt[i+5].setFont(font);
		bandeau_txt[i+5].setString(std::to_string(PAYSAN_PRIX));
		bandeau_txt[i+5].setFillColor(MONNAIE_COL);
		bandeau_txt[i+5].setCharacterSize(PRIX_SIZE);
		bandeau_txt[i+5].setPosition(bandeau_sp[i+6].getPosition().x + PRIX_POSX, bandeau_sp[i+6].getPosition().y + PRIX_POSY);
	}
}

void Jeu::terrain_setup(sp_map& sprites){
	// background: indice 0
	terrain_sp.push_back(sprites["background"]);
	
	// ground: indice 1
	terrain_sp.push_back(sprites["ground"]);
	terrain_sp[1].setPosition(0, win_H - GROUND_H);
}

/* Permet d'initialiser la fenetre de jeu avant le passage à l'état 1 */
void Jeu::game_setup(sp_map& sprites, const sf::Font& font){
	
	/* Initialisation du terrain */
	this->terrain_setup(sprites);
	
	/* Initialisation du bandeau de commande */
	this->bandeau_setup(sprites, font);
	
	
	/* Initialisation des couleurs des Equipes*/
	eq1.setColor(couleurs_joueurs[col_jg]);
	eq2.setColor(couleurs_joueurs[col_jd]);
	
	/* Ajout au jeu des sprites des habitations, des tours et des tourelles */
	// Equipe 1
	// Habitaion eq1: indice 0
	bat_sp.push_back(sprites["habitation"]);
	bat_sp[0].setPosition(500, 500);
	bat_sp[0].setColor(eq1.getCol());
	eq1.positionneHab(bat_sp[0].getPosition());	// on position l'habitation de l'équipe 1
	
	// Tour eq1: indice 1
	bat_sp.push_back(sprites["tourG"]);
	bat_sp[1].setPosition(TOUR_POSX - tourG_W, win_H - GROUND_H - tourG_H);
	bat_sp[1].setColor(eq1.getCol());
	
	// Tourelle eq1: indice 2
	bat_sp.push_back(sprites["tourelle"]);
	bat_sp[2].setPosition(TOUR_POSX - tourG_W, TOURELLE_POSY);
	eq1.positionneTour(bat_sp[1].getPosition(), bat_sp[2].getPosition());	// on positionne la tour et la tourelle de l'équipe 1 dans le jeu
	
	
	// Equipe 2
	// Habitation eq2: indice 3
	bat_sp.push_back(sprites["habitation"]);
	bat_sp[3].setPosition(1000, 550);
	bat_sp[3].setColor(eq2.getCol());
	eq2.positionneHab(bat_sp[3].getPosition());	// on position l'habitation de l'équipe 2
	
	// Tour eq2: indice 4
	bat_sp.push_back(sprites["tourD"]);
	bat_sp[4].setPosition( win_W - TOUR_POSX, win_H - GROUND_H - tourD_H);
	bat_sp[4].setColor(eq2.getCol());
	
	// Tourelle eq1: indice 5
	bat_sp.push_back(sprites["tourelle"]);
	bat_sp[5].rotate(180.f);
	bat_sp[5].setPosition(win_W - TOUR_POSX - (tourelle_W - tourD_W) + tourelle_W, TOURELLE_POSY + tourelle_H);
	eq2.positionneTour(bat_sp[4].getPosition(), bat_sp[5].getPosition());	// on positionne la tour et la tourelle de l'équipe 2 dans le jeu
	
	
	// Initialisation de la barre de vie des Equipes
	// vie eq1: indice 6
	
	
	
	/*bat_sp.push_back(sprites["habitation"]);
	bat_sp.push_back(sprites["tourG"]);
	bat_sp.push_back(sprites["tourelle"]);
	// Equipe 2
	bat_sp.push_back(sprites["habitation"]);
	bat_sp.push_back(sprites["tourD"]);
	bat_sp.push_back(sprites["tourelle"]);
	bat_sp[(bat_sp.size())-1].rotate(180.f);*/
	
	tour_timer.restart();
}

/* Gestion des evenement de la fenêtre lors du jeu */
void Jeu::game_Event(sf::Event& event){
	if (event.type == sf::Event::Closed){
		window.close();
	}
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Escape){
			window.close();
		}
		
		// evenement claviers de l'équipe 1
		if (event.key.code == sf::Keyboard::A){
			eq1.tourLvlUp();
		}
		if (event.key.code == sf::Keyboard::Q){
			eq1.tourDomageUp();
		}
		if (event.key.code == sf::Keyboard::S){
			eq1.tourPorteeUp();
		}
		if (event.key.code == sf::Keyboard::Z){
			if(eq1.habitationUp()){		// on test si on peut effectivement monter le niveau de l'habitaion
				int h1 = eq1.getHabLvl();
				if (h1 == 2){
					bandeau_txt[4].setString(std::to_string(HAB_2TO3));
					bandeau_txt[5].setString(std::to_string(SOLDAT_PRIX));
				}
				if (h1 == 3){
					bandeau_txt[5].setString(std::to_string(CYBORG_PRIX));
				}
			}
		}
		
		// evenement claviers de l'équipe 2
		if (event.key.code == sf::Keyboard::Numpad1){
			eq2.tourLvlUp();
		}
		if (event.key.code == sf::Keyboard::Numpad4){
			eq2.tourDomageUp();
		}
		if (event.key.code == sf::Keyboard::Numpad5){
			eq2.tourPorteeUp();
		}
		if (event.key.code == sf::Keyboard::Numpad2){
			if(eq2.habitationUp()){		// on test si on peut effectivement monter le niveau de l'habitaion
				int h2 = eq2.getHabLvl();
				if (h2 == 2){
					bandeau_txt[10].setString(std::to_string(HAB_2TO3));
					bandeau_txt[11].setString(std::to_string(SOLDAT_PRIX));
				}
				if (h2 == 3){
					bandeau_txt[11].setString(std::to_string(CYBORG_PRIX));
				}
			}
		}
	}
}

/* méthode d'update du bandeau de commande du jeu */
void Jeu::bandeau_update(){
	bandeau_txt[0].setString(std::to_string(eq1.getBourse()));
	bandeau_txt[6].setString(std::to_string(eq2.getBourse()));
}

/* méthode d'update du jeu à chaque itération de la boucle while */
void Jeu::game_update(){
	// update de la vie
	rect_vie_jg.top = VIE_H * 100 - VIE_H * (eq1.getTourHp() / HP_MAX) * 100;
	rect_vie_jd.top = VIE_H * 100 - VIE_H * (eq2.getTourHp() / HP_MAX) * 100;
	
	vie_jg.setTextureRect(rect_vie_jg);
	vie_jd.setTextureRect(rect_vie_jd);
	
	int t1 = eq1.getTourLvl();
	int t2 = eq2.getTourLvl();
	
	sf::Time time = tour_timer.getElapsedTime();
	float sec = time.asSeconds();
	if (sec >= MONEY_TIME){
		if (t1 == 1){
			eq1.ajoutMonaie(TOUR1_MONNAIE);
		}else{
			eq1.ajoutMonaie(TOUR2_MONNAIE);
		}
		if (t2 == 1){
			eq2.ajoutMonaie(TOUR1_MONNAIE);
		}else{
			eq2.ajoutMonaie(TOUR2_MONNAIE);
		}
		
		tour_timer.restart();
	}
	
	this->bandeau_update();
	
}

/* Dessine sur la fenetre du jeu les éléments du terrain */
void Jeu::show_terrain(){
	for (int i=0 ; i<terrain_sp.size() ; i++){
		window.draw(terrain_sp[i]);
	}
	//window.display();
}

/* Dessine sur la fenetre du jeu les éléments du bandeau de commande */
void Jeu::show_bandeau(){
	int t1 = eq1.getTourLvl();	// niveau de la tour de l'équipe 1
	int t2 = eq2.getTourLvl();	// niveau de la tour de l'équipe 2
	
	int h1 = eq1.getHabLvl();
	int h2 = eq2.getHabLvl();
	
	for (int i=0 ; i<bandeau_sp.size() ; i++){
		if ( i == 2 && t1 > 1){
			continue;
		}
		if ( (i == 3 || i == 4) && t1 < 2 ){
			continue;
		}
		if( i == 5 && h1 == 3){
			continue;
		}
		if ( i == 8 && t2 > 1){
			continue;
		}
		if ( (i == 9 || i == 10) && t2 < 2 ){
			continue;
		}
		if( i == 11 && h2 == 3){
			continue;
		}
		window.draw(bandeau_sp[i]);
	}
	for (int i=0 ; i<bandeau_txt.size() ; i++){
		if ( i == 1 && t1 > 1){
			continue;
		}
		if ( (i == 2 || i == 3) && t1 < 2 ){
			continue;
		}
		if ( i == 7 && t2 > 1){
			continue;
		}
		if ( (i == 8 || i == 9) && t2 < 2 ){
			continue;
		}
		window.draw(bandeau_txt[i]);
	}
	//window.display();
}

/* Dessine les éléments du jeu et les affiche sur la fenetre */
void Jeu::show_game(){
	this->show_terrain();
	this->show_bandeau();
	
	window.draw(vie_jg);
	window.draw(vie_jd);
	
	int t1 = eq1.getTourLvl();
	int t2 = eq2.getTourLvl();
	
	for (int i=0 ; i<bat_sp.size() ; ++i){
		if ( i == 2 && t1 < 2 ){
			continue;
		}
		if ( i == 5 && t2 < 2 ){
			continue;
		}
		window.draw(bat_sp[i]);
	}
	
	window.display();
}



/*------------------------------------------------MAIN------------------------------------------------------*/
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
	sf::Font jeu_font;
	
	if (!menu_font.loadFromFile("tiles/Pixel Digivolve.otf")){
		std::cerr << "***ERROR: menu_font.loadFromFile(tiles/Pixel Digivolve.otf): failed" << std::endl;
		return EXIT_FAILURE;
	}
	if (!jeu_font.loadFromFile("tiles/Pixelmania.ttf")){
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
	
	std::cout << "menu initialisé" << std::endl;
	
	//jeu.etat = 1;
	//jeu.game_setup(sprites, jeu_font);
	
	/* Boucle du jeu */
	while(jeu.window.isOpen()){
		sf::Event event;
		
		// Nettoyage de la fenêtre
		jeu.window.clear();
		
		switch (jeu.etat){
			/* Menu */
			case 0:
				while (jeu.window.pollEvent(event))
				{
					jeu.menu_Event(event,sprites,jeu_font);
				}
				jeu.menu_update();
				jeu.show_menu();
				break;
			
			/* Jeu */
			case 1:
				while (jeu.window.pollEvent(event)){
					jeu.game_Event(event);
				}
				jeu.game_update();
				jeu.show_game();
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

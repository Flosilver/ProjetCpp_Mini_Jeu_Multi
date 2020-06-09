# AGE OF TOWER DEFENSE



###### Auteurs: Florentin Beroujon et Helene Chapron
Lien vers le git: [ProjetCpp_Mini_Jeu_Multi](https://github.com/Flosilver/ProjetCpp_Mini_Jeu_Multi.git)

-----------------
Dans ce Tower Defense, battez-vous en faisant évoluer votre armée!  Tout d’abord, chaque joueur doit choisir sa couleur puis lancer le jeu en appuyant sur “Jouer”. Une fois le jeu lancé, vous controlez chacun votre tour (à gauche et à droite). Vous pouvez faire évoluer votre tour, puis améliorer sa portée ou sa puissance!
Vous pouvez également amméliorer une habitation et entraîner des unités qui défendront votre tour et attaqueront l'ennemi.
La partie se termine quand les PV de l’un des deux joueurs atteint 0.
Les commandes sont les suivantes!


                                joueur gauche/joueur droite
Tour Up:    A/1
Tour dommages Up:	Q/4
Tour portée Up:		S/5
Habitation Up:		Z/2
génération d’unité:	E/3


BATTEZ-VOUS!

---
## Réalisation du projet:


Florentin s’est occupé de la complétion et création des classes et de l’optimisation
Helene s’est occupé de la gestion graphique du jeu, du design, la création des classes, des tests unitaires

---
## Le projet


Dans ce jeu, seulement la classe de base "ACombattant" a été implantée. A l'origine, d'autres classes étaient prévues et pourront être rajoutées par la suite: ces classe sont indiquées en jaune sur l'UML et donc n'ont pas été développées. Les mécanismes du jeu correspondent à ceux que nous souhaitions et nous sommes fier d'avoir réussi à créer un jeu ludique et assez joli, avec les graphismes presque exclusivement réalisés par nos soins.
Malgré nos efforts, quelques fonctions n'ont pas pu être implémentées. Par exemple, les flèches tirées par les tourelles ont leur structures et un début de fonction qui n'est pas parfaitement opérationnel.
Pour les tests unitaires: à cause de changements tardifs, certains tests ne sont malheureusement pas complets.

---
## Compilation et exécution du programme:


ce programme se compile avec la commande:
> "make"

, tout en étant placé dans le répertoire du jeu. 

Il s'exécute avec la commande:

> "./game"

---
## liste des bibliothèques, frameworks et outils externes utilisés:


Pour faire les tests unitaires, nous avons utilisé catch2.
Pour l'interface graphique, nous avons utilisé SFML.

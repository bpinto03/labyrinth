# labyrinth
Labyrinth generator designed in C. UGE Project

## Compile
Pour compiler le projet, il suffit d’utiliser make, make clean supprimera les .o et make 
mrproper désinstallera le programme.

## Options
Les options disponibles sont :
 --mode=texte, affiche le labyrinthe en ascii dans le terminal.
 --taille=lignexcolonne, initialise la taille du labyrinthe.
 --graine=X où x est un char * formant un nombre, permet de générer la graine du 
labyrinthe.
 --attente=X où X est un char * formant un nombre en millisecondes, entre chaque 
étape de suppression, le programme attendra X temps en millisecondes. (Warning avec 
usleep et ansi)
 --unique, qui permet d’obtenir des labyrinthe esthetiques.
 --acces, qui permet de ne pas avoir de cases fermées.
 --opti=X avec X = 1 ou 2. Cette option met attente à 0 et affiche le temps que le 
programme a mis pour générer le labyrinthe. X = 1 utilise la version optimiser de 
suppression, X = 2 utilise la version non optimiser de supression. Par défaut, le 
programme se lance avec la version optimisée.

# lem-in

Algorithmic project made at 42 school

Given a representation of an antfarm in the form of a graph,
      the program has to print it to the standard output as well as a
      way to move all the ants from the start to the end in the smallest
      number of moves.

Example maps can be found in maps/

## Usage

```usage: lem-in < map.lem```

## Precisions sur le parsing
- Le nombre de fourmis sera indique sur la premiere ligne de sorte a etre lu
par un atoi.
- Il ne peut y avoir qu'une seule entree et sortie. Si plusieurs entrees/sorties
sont renseignees, seule la derniere de chaque sera prise en compte comme telle,
les autres seront considerees comme de simples salles.
- L'entree peut etre la meme salle que l'arrivee,
	auquel cas aucun mouvement n'est necessaire.
- Un nom de salle ne doit pas comporter de ' ' ou de '-', en nommer une de telle
facon entrainera un comportement indefini.
- Une ligne n'etant pas un commentaire et comportant un tiret ('-')
decrit un tuyau
- Une ligne n'etant pas un commentaire et ne comportant pas de tiret ('-')
decrit une salle.

### Description d'une salle
- La partie de la ligne a gauche du premier espace (' ') est interpretee comme
le nom de la salle.
- La partie de la ligne a droite du premier espace (' ') est ignoree.
- Si aucun espace (' ') ne figure sur la ligne, on considere que les coordonnees
ont ete omises, et l'integralite de la ligne est interpretee comme
le nom de la salle.

### Description d'un tuyau
- La partie de la ligne a gauche du premier tiret ('-') est interpretee comme
le nom de la premiere salle
- La partie de la ligne a droite du premier tiret ('-') est interpretee comme
le nom de la deuxieme salle
- Si l'une des deux salles n'a pas ete auparavent definie la ligne est ignoree

## BONUS
- Pouvoir passer des fichiers a traiter en arguments a la commande en utilisant
main\_bonus.c
- On peut envoyer une serie de salles puis de pipes puis de nouveau de salles
- Custom error name with -D LEM\_ERROR\_V

## TODO
- Bonus arguments de commande
Peut il y avoir plusieurs arrivees ? Non : "La salle indiquee par [...] end"
Le depart peut il etre larrivee aussi ?
 Si oui on peut simplement ne rien faire
 Sinon on doit travailler

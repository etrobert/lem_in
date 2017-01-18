# lem-in

## Precisions sur le parsing
- Un nom de fichier ne doit pas comporter de ' ' ou de '-', faire de tel
entrainera un comportement indefini.
- Une ligne n'etant pas un commentaire et comportant un tiret decrit un tuyau
- Une ligne n'etant pas un commentaire et ne comportant pas de tiret decrit
une salle

## BONUS
Pouvoir passer des arguments a la commande et que ca le fasse sur tous les fichiers passes
On peut envoyer une serie de salles puis de pipes puis de nouveau de salles
Custom error name

## TODO
Quand la sortie est un voisin de larrivee est ce quon peut tous les faire passer dans le tunnel en un tour ?
Peut il y avoir plusieurs arrivees ? Non : "La salle indiquee par [...] end"
Le depart peut il etre larrivee aussi ?
 Si oui on peut simplement ne rien faire
 Sinon on doit travailler
### Parsing :
Premiere ligne -> atoi
Boucle
 Si dieze premier charactere
  Si dieze deuxieme charactere
   Si Strcmp avec start == 0
    start = true
   Si Strcmp avec end == 0
    end = true
  Sinon
   Ignore
 

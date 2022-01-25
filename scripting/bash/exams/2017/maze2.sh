#!/bin/bash

#Tester la pr�sence des arguments de la ligne de commande
if [ $# -ne 2 ]
then
	echo "Usage : $0 <fichier du labyrinthe> <fichier de la solution>" >&2
	exit 1
fi

#V�rifier qu'il s'agisse de fichiers standards accessibles en lecture
if [ ! -f "$1" ] || [ ! -r "$1" ] || [ ! -f "$2" ] || [ ! -r "$2" ]
then
	echo "Fichier introuvable ou illisible" >&2
	exit 2
fi

#Stocke la grille et la solution du labyrinthe dans des variables
GRILLE=`cat "$1"`
SOLUTION=`cat "$2"`

#Initialiser un compteur pour la longueur du chemin
LONGUEUR=0

#Lire les �l�ments de la solution
set $SOLUTION

#Pour chaque �l�ment de la grille
for GR_ELEMENT in $GRILLE
do
	#R�cup�rer l'�l�ment correspondant de la solution
	SL_ELEMENT=$1
	#Supprimer cet �l�ment des �l�ments restant � traiter
	shift
	#Si cet �l�ment fait partie du chemin propos� pour sortir du labyrinthe
	if [ "$SL_ELEMENT" == "x" ]
	then
		#Tester si cet �l�ment du chemin ne traverse aucun mur
		if [ "$GR_ELEMENT" == "o" ]
		then
			echo "Solution invalide"
			exit 0
		fi
		#Incr�menter la longueur du chemin
		LONGUEUR=$[ $LONGUEUR + 1 ]
	#Tester s'il ne passe pas par l'entr�e et la sortie du labyrinthe
	elif [ "$GR_ELEMENT" == "e" ] || [ "$GR_ELEMENT" == "s" ]
	then
		echo "Solution invalide"
		exit 0
	fi
done

#Afficher la longueur du chemin
echo "Solution valide de longueur $LONGUEUR"

#Terminer le script avec un code de retour significatif
exit 0

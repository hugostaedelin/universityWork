#!/bin/bash

#V�rifier si le nombre d'arguments de la ligne de commande est correct.
#Un message d'erreur est affich� sur le fichier standard des erreurs et
#le script termine avec un code de retour significatif si ce n'est pas le cas.
if [ $# -ne 4 ]; then
	echo "Usage : $0 <source> <cible> <min> <max>" >&2
	exit 1
fi

#V�rifier si le fichier source existe et s'il est accessible en lecture.
#Un message d'erreur est affich� sur le fichier standard des erreurs et
#le script termine avec un code de retour significatif si ce n'est pas le cas.
if [ ! -f "$1" ] || [ ! -r "$1" ]; then
	echo "Fichier source introuvable ou illisible" >&2
    exit 2
fi

#V�rifier si les indices donn�s en 3�me et 4�me arguments sont des entiers.
#Un message d'erreur est affich� sur le fichier standard des erreurs et
#le script termine avec un code de retour significatif si ce n'est pas le cas.
if [ `echo "$3 $4" | egrep "^[0-9]+ [0-9]+$" | wc -l` -le 0 ]; then
    echo "Valeur d'indice incorrecte" >&2
    exit 3
fi

#Vider le fichier cible s'il existe, le cr�er sinon.
#Le script termine avec un code de retour significatif en cas d'erreur.
> "$2" #Utilisation possible de rm et touch
if [ $? -ne 0 ]; then
    exit 4
fi

#Sauvegarde des arguments de la ligne de commande dans des variables.
SOURCE="$1"
CIBLE="$2"
MININD="$3"
MAXIND="$4"

#Parcours des lignes du fichier source et r�cup�ration des noms de fichiers
#associ�s aux indices compris entre MININD et MAXIND dans le fichier cible.
IFS=';'
while read LIGNE; do
    set $LIGNE
    if [ $# -eq 2 ] && [ $1 -ge $MININD ] && [ $1 -le $MAXIND ]; then
        echo "$2" >> "$CIBLE"
    fi
done < "$SOURCE"

#Terminer le script avec un code de retour significatif.
exit 0

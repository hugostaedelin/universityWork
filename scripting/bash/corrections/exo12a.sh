#!/bin/bash

#Teste le nombre d'arguments du script
if [ $# -ne 1 ]
then
	echo "Usage : $0 <nom de fichier/répertoire>"
	exit 1
fi

#Teste que le fichier/répertoire donné en argument existe
if [ ! -f "$1" ] && [ ! -d "$1" ]
then
	echo "Fichier ou répertoire non trouvé"
	exit 2
fi

#Nom du fichier/répertoire à renommer
SOURCE=$1

#Séparer SOURCE et traiter chaque mots issu de cette décomposition
export IFS=$' \t\n'
set $SOURCE

CIBLE=$1
shift
while [ $# -gt 0 ]
do
	CIBLE="${CIBLE}_$1"
	shift
done

#Renommer le fichier en remplacant les espaces par des underscores
mv "$SOURCE" "$CIBLE"

exit 0

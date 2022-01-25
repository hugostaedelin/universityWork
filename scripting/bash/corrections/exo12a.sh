#!/bin/bash

#Teste le nombre d'arguments du script
if [ $# -ne 1 ]
then
	echo "Usage : $0 <nom de fichier/r�pertoire>"
	exit 1
fi

#Teste que le fichier/r�pertoire donn� en argument existe
if [ ! -f "$1" ] && [ ! -d "$1" ]
then
	echo "Fichier ou r�pertoire non trouv�"
	exit 2
fi

#Nom du fichier/r�pertoire � renommer
SOURCE=$1

#S�parer SOURCE et traiter chaque mots issu de cette d�composition
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

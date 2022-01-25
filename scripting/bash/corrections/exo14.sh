#!/bin/bash

#Vérification du nombre d'arguments de la ligne de commande
if [ $# -ne 2 ]
then
	echo "Usage : $0 <Serial> <Brand>"
	exit 1
fi

#Sauvegarde du répertoire courant
CUR=`pwd`

#Vérification de l'existence du répertoire cible et création
#de ce dernier s'il n'existe pas
if [ ! -e "$2" ]
then
  mkdir "$2"
  if [ $? -ne 0 ]
  then
	echo "Création du répertoire $2 impossible"
	exit 2
  fi
else
  cd "$2"
  if [ $? -ne 0 ]
  then
	echo "Impossible d'accéder à $2"
	exit 3
  fi
  cd "$CUR"
fi

#Retrait du droit d'exécution et déplacement dans le répertoire
#cible de tous les fichiers concernés
for FILE in $1[0-9][0-9][0-9][0-9].JPG
do
	chmod a-x "$FILE"
	mv "$FILE" "$2"
done

#Déplacement dans le répertoire cible
cd "$2"

#Mise en minuscules de l'extension des fichiers s'y trouvant
for FILE in *.JPG
do
	mv "$FILE" "${FILE%.JPG}.jpg"
done

#Retour dans le répertoire parent (cd .. pourrait suffire)
cd "$CUR"

#Sortie du script avec un code de retour significatif
exit 0

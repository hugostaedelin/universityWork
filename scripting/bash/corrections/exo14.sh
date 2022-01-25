#!/bin/bash

#V�rification du nombre d'arguments de la ligne de commande
if [ $# -ne 2 ]
then
	echo "Usage : $0 <Serial> <Brand>"
	exit 1
fi

#Sauvegarde du r�pertoire courant
CUR=`pwd`

#V�rification de l'existence du r�pertoire cible et cr�ation
#de ce dernier s'il n'existe pas
if [ ! -e "$2" ]
then
  mkdir "$2"
  if [ $? -ne 0 ]
  then
	echo "Cr�ation du r�pertoire $2 impossible"
	exit 2
  fi
else
  cd "$2"
  if [ $? -ne 0 ]
  then
	echo "Impossible d'acc�der � $2"
	exit 3
  fi
  cd "$CUR"
fi

#Retrait du droit d'ex�cution et d�placement dans le r�pertoire
#cible de tous les fichiers concern�s
for FILE in $1[0-9][0-9][0-9][0-9].JPG
do
	chmod a-x "$FILE"
	mv "$FILE" "$2"
done

#D�placement dans le r�pertoire cible
cd "$2"

#Mise en minuscules de l'extension des fichiers s'y trouvant
for FILE in *.JPG
do
	mv "$FILE" "${FILE%.JPG}.jpg"
done

#Retour dans le r�pertoire parent (cd .. pourrait suffire)
cd "$CUR"

#Sortie du script avec un code de retour significatif
exit 0

#!/bin/bash

if [ $# -ne 4 ]
	then echo "ERREUR : Nombre d'arguments incorrect ou manquant."
	echo "USAGE : <source> <cible> <min> <max>"
	exit 
fi

if [ ! -e $1 ]
	then echo "ERREUR : Fichier source inexistant."
	exit 
fi

if [ ! -r $1 ]
	then echo "ERREUR : Fichier source illisible."
	exit
fi
if [ ! -e $2 ]
then 
	touch $2
	exit
fi
if [ -e $2 ]
then 
	if [! -x $2 ]
	then 
		echo "ERREUR : Le nom du fichier cible ne peut pas être utilisé" 
	exit 
	fi
fi

if [[ $3 != ?([-+])+([0-9]) || $4 != ?([-+])+([0-9]) ]]
then
	echo "ERREUR : Les bornes de tri ne sont pas des entiers (3 et/ou 4ème arguments)."
	exit
fi

echo "Opération de vérification terminée."

ficSource=$1
ficCible=$2
borneMin=$3
borneMax=$4
IFS=';'

while read LIGNE
do
	set $LIGNE
	if [ $1 -ge $borneMin ] && [ $1 -le $borneMax ]
	then
		$2>>$ficCible
	fi
done < "$ficSource"

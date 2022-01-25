#!/bin/bash

#Vérifier le nombre d'arguments
if [ $# -ne 1 ]
then
	echo "Usage : $0 <nom>"
	exit 1
fi

#Tester l'existence du fichier en argument (-e pour fichier standard, répertoire et lien)
if [ ! -e "$1" ]
then
	echo "$1 n'existe pas"
fi

#Tester s'il s'agit d'un lien symbolique (-h pour lien symbolique)
if [ -h "$1" ]
then
	echo "$1 est un lien"
fi

#Tester s'il s'agit d'un fichier standard ou d'un répertoire
if [ -f "$1" ] || [ -d "$1" ]
then
#Si tel est le cas, déterminer les droits dont l'exécutant dispose sur le fichier
	if [ -r "$1" ]
	then
		DROITS="r"
	else
		DROITS=""
	fi
	if [ -w "$1" ]
	then
		DROITS="${DROITS}w"
	fi
	if [ -x "$1" ]
	then
		DROITS="${DROITS}x"
	fi

#Afficher s'il s'agit d'un fichier standard ou d'un répertoire,
#ainsi que les droits déterminés précédemment
	if [ -f "$1" ]
	then
		echo "$1 est un fichier ($DROITS)"
	else
		echo "$1 est un répertoire ($DROITS)"
	fi
fi

#Terminer avec un exit status significatif
exit 0

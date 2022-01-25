#!/bin/bash

#V�rifier le nombre d'arguments
if [ $# -ne 1 ]
then
	echo "Usage : $0 <nom>"
	exit 1
fi

#Tester l'existence du fichier en argument (-e pour fichier standard, r�pertoire et lien)
if [ ! -e "$1" ]
then
	echo "$1 n'existe pas"
fi

#Tester s'il s'agit d'un lien symbolique (-h pour lien symbolique)
if [ -h "$1" ]
then
	echo "$1 est un lien"
fi

#Tester s'il s'agit d'un fichier standard ou d'un r�pertoire
if [ -f "$1" ] || [ -d "$1" ]
then
#Si tel est le cas, d�terminer les droits dont l'ex�cutant dispose sur le fichier
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

#Afficher s'il s'agit d'un fichier standard ou d'un r�pertoire,
#ainsi que les droits d�termin�s pr�c�demment
	if [ -f "$1" ]
	then
		echo "$1 est un fichier ($DROITS)"
	else
		echo "$1 est un r�pertoire ($DROITS)"
	fi
fi

#Terminer avec un exit status significatif
exit 0

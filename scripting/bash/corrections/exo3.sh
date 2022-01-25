#!/bin/bash
echo "Nom du programme : $0"
echo "Nb d'arguments : $#"
echo "Tous les arguments : $@"
echo "Source : $1"
echo "Destination : $2"
if [ $# -eq 2 ]
then
	cp "$1" "$2"
else
	exit 1
fi

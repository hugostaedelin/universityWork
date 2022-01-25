#!/bin/bash
read CHOIX
if [ "$CHOIX" = "o" ] || [ "$CHOIX" = "O" ]
then
	echo "OUI"
	exit 0
fi
if [ "$CHOIX" = "n" ] || [ "$CHOIX" = "N" ]
then
	echo "NON"
	exit 0
fi
echo "Réponse incorrecte"
exit 1

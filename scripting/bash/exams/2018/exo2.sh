#!/bin/bash

#Tester la présence des arguments de la ligne de commande
if [ $# -ne 1 ]
then
	echo "Usage : $0 <ch>" >&2
	exit 1
fi

if [ `echo "$1" | egrep '^[A-Za-z0-9]+$' | wc -l` -eq 0 ]
then
	echo "ch ne doit être composée que de lettres et de chiffres" >&2
	exit 2
fi

NB=0

for f in *
do
	if [ -f "$f" ] && [ `echo "$f" | egrep '^[A-Za-z0-9]+$' | wc -l` -eq 1 ] && ./exo1.sh "$f" "$1"
	then
		echo "$f"
		NB=$[ $NB + 1 ]
	fi
done

echo "Nombre de fichier(s) trouvé(s) : $NB"

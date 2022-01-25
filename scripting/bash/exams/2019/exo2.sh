#!/bin/bash

#V�rifier si le nombre d'arguments de la ligne de commande est correct.
#Un message d'erreur est affich� sur le fichier standard des erreurs et
#le script termine avec un code de retour significatif si ce n'est pas le cas.
if [ $# -ne 2 ]
then
	echo "Usage : $0 <first letter> <last letter>" >&2
	exit 1
fi

#V�rifier si les param�tres sont des lettres de l'alphabet, majuscules ou non.
#Un message d'erreur est affich� sur le fichier standard des erreurs et
#le script termine avec un code de retour significatif si ce n'est pas le cas.
if [ `echo "$1 $2" | egrep "(^[a-z] [a-z]$)|(^[A-Z] [A-Z]$)" | wc -l` -le 0 ]
then
    echo "Param�tres de la ligne de commande invalides" >&2
    exit 2
fi

#Pour chaque fichier standard commencant par une lettre de l'intervalle
#d�fini par l'utilisateur, si ce dernier est autoris� � lire le fichier,
#alors lancer le script de l'exercice 1 sur ce fichier.
for FICHIER in [$1-$2]*
do
	if [ -f "$FICHIER" ] && [ -r "$FICHIER" ]
	then
		./exo1.sh "$FICHIER"
	fi
done

#Terminer le script avec un code de retour significatif.
exit 0

#!/bin/bash

FICHIER="$1"

#Récupération des mots
MOTS=""
while read LIGNE
do
	if [ "$LIGNE" != "" ]
	then
		set $LIGNE
		if [ $# -ge 2 ]
		then
			TMP="$@"
			MOTS="$MOTS $1 ${TMP##* }"
		fi
	fi
done < "$FICHIER"

#Récupération des lettres
LETTRES=""
for MOT in $MOTS
do
	TMP="${MOT#?}"
	PL="${MOT%$TMP}"
	TMP="${MOT%?}"
	DL="${MOT#$TMP}"
	LETTRES="$LETTRES $PL $DL"
done

echo "$LETTRES" >> FUSION.TXT

#Terminer le script avec un code de retour significatif
exit 0

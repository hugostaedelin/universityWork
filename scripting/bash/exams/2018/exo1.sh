#!/bin/bash

#Tester la pr�sence des arguments de la ligne de commande
if [ $# -ne 2 ]
then
	echo "Usage : $0 <ch1> <ch2>" >&2
	exit 2
fi

CH1="$1"
CH2="$2"

while [ "$CH1" != "" ]
do
	if [ "$CH2" == "" ]
	then
		exit 1
	fi
	#R�cup�rer le prochain caract�re � tester dans CH1
	TMP="${CH1#?}"		#// Correspond a la r�cup�ration du premier caractere
	C1="${CH1%$TMP}"	#// Premier caract�re a tester dans CH1
	CH1="$TMP" 		#// supprimer le premier caract�re
	#V�rifier s'il est pr�sent dans CH2
	DEB=""
	FIN="$CH2"
	TROUVE=0
	while [ "$FIN" != "" ]
	do
		TMP="${FIN#?}"		#// Correspond a la r�cup�ration du premier caractere
		C2="${FIN%$TMP}"	#// Premier caract�re a tester dans FIN (ou CH2)
		FIN="$TMP"		#// supprimer le premier caract�re
		if [ "$C1" == "$C2" ]
		then
			#S'il est pr�sent, alors il est retir� de CH2
			CH2="$DEB$FIN"
			FIN=""
			TROUVE=1
		else
			DEB="$DEB$C2"
		fi
	done
	if [ $TROUVE -eq 0 ]
	then
		exit 1
	fi
done
exit 0

#!/bin/bash
if [ $# -ne 1 ]
then
	echo "Usage : $0 <fichier>"
	exit 1
fi

LIST=
while read LINE
do
	while [ `echo "$LINE" | egrep [a-zA-Z0-9_] | wc -l` -ne 0 ]
	do
		#Suppression des espaces et des symboles de ponctuation
		TMP=${LINE#*[a-zA-Z0-9_]}
		TMP=${LINE%$TMP}
		TMP=${TMP%?}
		LINE=${LINE#$TMP}
		#Récupération du prochain mot
		TMP=${LINE%%[!a-zA-Z0-9_]*}
		#Suppression du mot
		LINE=${LINE#$TMP}
		#Concaténation du mot
		LIST="$LIST\n$TMP"
		done
done < "$1"
LIST=`echo -e "$LIST" | egrep .+ | sort`

TOTALWORDS=`echo "$LIST" | wc -w`
echo "Nombre de mots dans ce texte : $TOTALWORDS"

if [ $TOTALWORDS -eq 0 ]
then
	exit 0
fi

DIFFWORDS=1
PREV=" "
for MOT in $LIST
do
	if [ "$MOT" != "$PREV" ]
	then
		if [ "$PREV" != " " ]
		then
			DIFFWORDS=$[ $DIFFWORDS + 1 ]
		fi
		PREV="$MOT"
	fi
done
echo "Nombre de mots différents dans ce texte : $DIFFWORDS"

PREV=" "
for MOT in $LIST
do
	if [ "$MOT" == "$PREV" ]
	then
		IDWORDS=$[ $IDWORDS + 1 ]
	else
		if [ "$PREV" != " " ]
		then
			echo "$PREV $IDWORDS"
		fi
		IDWORDS=1
		PREV="$MOT"
	fi
done
echo "$PREV $IDWORDS"

exit 0

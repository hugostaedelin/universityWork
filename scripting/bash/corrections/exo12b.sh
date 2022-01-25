#!/bin/bash
if [ "$#" -ne 1 ]
then
	echo "Il faut exactement un argument à cette fonction"
	exit 1
fi
if [ -f "$1" ] || [ -d "$1" ]
then
	for i in $1
	do
		final="${final}$i_"
	done
else
	echo "Fichier ou repertoire non trouvé"
	exit 2
fi
final="${final%_}"
echo "$final"
mv "$1" "$final"

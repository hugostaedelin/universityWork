#bin/bash

while read LIGNE
do
	echo $LIGNE
done < $1

#UTILISATION IFS
while read LIGNE
do
set $LIGNE
 

echo "Nombre de mots dans ce texte :"
echo "Nombre de mots différents dans ce texte :"
echo "Nombre de fois ou carotte est écrit :"
echo "Nombre de fois ou haricot est écrit :"
echo "Nombre de fois ou patate est écrit :"
echo "Nombre de fois ou poireau est écrit :"

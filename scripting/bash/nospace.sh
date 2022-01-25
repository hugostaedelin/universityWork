#!/bin/bash
#TEST=`echo $TOTO | sed 's/_/ /g'`
#echo $TEST
#TOTO="Bonjour tous le monde.txt"
#echo $TOTO
#TEST=${TOTO/ /_/ }
#echo $TEST
for file in "${@}";
do
	mv "$file" "${file// /_}"
done

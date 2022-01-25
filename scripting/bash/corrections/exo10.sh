#!/bin/bash
if [ $# -ne 1 ]
then
	echo "Usage : $0 <nom>"
	exit 2
fi

#if egrep "^$1" /etc/passwd > /dev/null
if [ `cat /etc/passwd | egrep "^$1" | wc -l` -ne 0 ]
then
	echo "L'utilisateur recherché a un compte sur la machine"
	exit 0
else
	echo "L'utilisateur recherché n'a pas de compte sur la machine"
	exit 1
fi

#solution utilisant set au lieu de egrep
UTILISATEUR="$1"
while read LIGNE
do
	set $LIGNE
	if [ "$1" = "$UTILISATEUR" ]
	then
		echo "L'utilisateur recherché a un compte sur la machine"
		exit 0
	fi
done < /etc/passwd
echo "L'utilisateur recherché n'a pas de compte sur la machine"
exit 1

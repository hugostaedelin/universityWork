#!/bin/bash

search=""
search=`grep $1:* /etc/passwd`
if [ "$search" != "" ] 
then echo $search
     echo "L'utilisateur dispose d'un compte et existe."
else echo "Compte inexistant."
fi

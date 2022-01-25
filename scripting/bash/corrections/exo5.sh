#!/bin/bash

# Executer simplement echo "$11" ne marche pas (il faut utiliser echo "${11}").
# Dans cet exercice, on va s'obliger à utiliser $9 au lieu de ${11} (utiliser seulement $1, $2, ..., $9).

shift
shift
echo "$9"

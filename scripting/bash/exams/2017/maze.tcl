#!/bin/wish
frame .fichiers

label .fs1 -text "Fichier contenant la grille du labyrinthe"
entry .es1 -textvariable fichier1

label .fs2 -text "Fichier contenant la solution proposée"
entry .es2 -textvariable fichier2

frame .boutons

button .tester -text "Vérifier" -command {
    exec bash ./maze.sh "$fichier1" "$fichier2"
}

button .quitter -text "Quitter" -command exit

pack .boutons -side left -fill y
pack .fichiers -side top -fill x
pack .fs1 .es1 .fs2 .es2 -in .fichiers -side top -fill x
pack .quitter -in .boutons -side bottom -fill x
pack .tester -in .boutons -side left -fill y

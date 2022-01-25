#!/bin/wish
frame .ftop
frame .fmid
frame .fbot
frame .fl1
frame .fl2

label .fs -text "Fichier source"
entry .es -textvariable source

label .fc -text "Fichier cible"
entry .ec -textvariable cible

label .lmin -text "Indice minimum"
entry .emin -textvariable indmin

label .lmax -text "Indice maximum"
entry .emax -textvariable indmax

button .filter -text "FILTRER" -command {
    exec bash ./filter.sh "$source" "$cible" "$indmin" "$indmax"
}

button .quitter -text "QUITTER" -command exit

pack .ftop .fmid .fbot -side top -fill x
pack .fl1 -in .ftop -side left
pack .fl2 -in .fmid -side left
pack .fs .fc -in .fl1 -side top -fill x
pack .lmin .lmax -in .fl2 -side top -fill x
pack .es .ec -in .ftop -side top -fill x
pack .emin .emax -in .fmid -side top -fill x
pack .quitter -in .fbot -side right
pack .filter -in .fbot -side top -fill x

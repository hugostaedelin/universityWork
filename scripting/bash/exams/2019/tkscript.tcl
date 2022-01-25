#!/bin/wish

frame .boutons
frame .labels
frame .general

label .fs -text "Première lettre"
entry .es -textvariable arg0

label .fc -text "Dernière lettre"
entry .ec -textvariable arg1

button .azmin -text "a-z" -command {
    exec bash ./script.sh a z
}

button .azmaj -text "A-Z" -command {
    exec bash ./script.sh A Z
}

button .script -text "LANCER" -command {
    exec bash ./script.sh "$arg0" "$arg1"
}

button .quitter -text "QUITTER" -command exit

pack .quitter -side bottom -fill x
pack .general -fill x
pack .script -in .general -side right -fill y
pack .boutons -in .general -side left -fill y
pack .azmin .azmaj -in .boutons -fill x
pack .labels -in .general -side left -fill y
pack .fs .fc -in .labels -fill x
pack .es -in .general -fill x
pack .ec -in .general -fill x

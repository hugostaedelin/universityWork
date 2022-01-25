#!/usr/bin/wish
frame .f

label .lp -text "Paramètre"
entry .ep -textvariable param

button .b -text "LANCER" -command {
	exec bash ./exo2.sh "$param"
}

button .q -text "QUITTER" -command exit

pack .f -side top -fill x

pack .lp -in .f -side left
pack .b .ep -in .f -side right
pack .q -side bottom -fill x

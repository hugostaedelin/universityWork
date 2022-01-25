#!/usr/bin/wish
frame .f

label .l -text "Entrez le nom de la machine distante"
entry .e -textvariable nom

button .c -text "CONNECTER" -command {
	exec ssh -X $nom xeyes
}
button .q -text "QUITTER" -command exit

pack .f -side top -fill x
pack .l -in .f -side left
pack .e -in .f -fill x
pack .c -fill x
pack .q -side bottom -fill x

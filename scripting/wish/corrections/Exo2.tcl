#!/usr/bin/wish
button .o -text "OUI" -command {
	puts "oui"
	exit
}
button .n -text "NON" -command {
	puts "non"
	exit
}
pack .o -side left
pack .n -side right


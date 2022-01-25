#!/usr/bin/wish
button .o -text "OUI" -command {
	puts "OUI"
	exit
}
button .n -text "NON" -command {
	puts "NON"
}
pack .o -side left
pack .n -side right 

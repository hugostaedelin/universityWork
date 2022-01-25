#!/usr/bin/wish
frame .f
frame .f2

button .q -text "QUITTER" -command exit
button .c -text "COPIE LOCALE -> DISTANT" -command {
puts "distant"
}

button .d -text "COPIE DISTANT -> LOCAL" -command {
puts "local"
}

label .m -text "Machine distante"
label .log -text "Login"
label .fics -text "Fichier(s) source(s)"
label .fict -text "Fichier(s) cible(s)"

entry .md -textvariable machine
entry .lo -textvariable login
entry .sFic -textvariable srcFile
entry .tFic -textvariable targetFile

pack .f -fill x
pack .f2 -fill x

pack .m -in .f -fill x
pack .md -in .f -fill x

pack .log -in .f -fill x
pack .lo -in .f -fill x

pack .fics -in .f -side left
pack .fict -in .f -side right 


pack .sFic -in .f2 -side left
pack .tFic -in .f2 -side right

pack .q -side bottom -fill x
pack .d -side bottom -fill x

pack .c -side bottom -fill x

#!/usr/bin/wish
frame .f
button .q -text "X" -command 
{
exec echo "$nom" > fic
puts "$nom"
exit
}
label .l -text "Entrer votre nom"
entry .e -textvariable nom
pack .f -fill x
pack .l -in .f -side left
pack .e -in .f -fill x
pack .q -side right -fill x

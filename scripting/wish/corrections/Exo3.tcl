#!/usr/bin/wish
 frame .ft

 label .lm -text "Machine distante"
 entry .em -textvariable machine
 label .ll -text "Login"
 entry .el -textvariable login

 frame .fl
 label .lfs -text "Fichier(s) source(s)"
 entry .efs -textvariable fs

 frame .fr
 label .lfc -text "Fichier(s) cible(s)"
 entry .efc -textvariable fc

 button .c1 -text "COPIE LOCAL -> DISTANT" -command {
    exec scp $fs $login@$machine:$fc
 }
 button .c2 -text "COPIE DISTANT -> LOCAL" -command {
    exec scp $login@$machine:$fs $fc
 }
 button .q -text "QUITTER" -command exit

 pack .lm .em .ll .el .ft -side top -fill x

 pack .fl -in .ft -side left -fill x
 pack .fr -in .ft -side right -fill x

 pack .lfs .efs -in .fl -side top -fill x
 pack .lfc .efc -in .fr -side top -fill x

 pack .q .c2 .c1 -side bottom -fill x


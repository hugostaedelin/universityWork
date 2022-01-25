# Pour tous les fichiers du répertoire courant dont la date de dernière modification est celle d'aujourd'hui, changer cette date en "06/06/2019"

$todays = ls | where-object { $_.LastWriteTime.toShortDateString() -eq (get-date).toShortDateString() }

foreach ( $jour in $todays ) { $jour.lastWriteTime = "06/06/2019" }

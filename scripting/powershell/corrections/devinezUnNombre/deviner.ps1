$NB = Get-Random -Minimum 1 -Maximum 10000
Write-Host "Nombre : $NB"
#Boucle tant que l'utilisateur n'a pas trouvé
do {
    [int] $choix = Read-Host -Prompt "Proposez un nombre "
    if ($choix -lt $NB) {
        Write-Host "Trop petit"
    }
    if ($choix -gt $NB) {
        Write-Host "Trop grand"
    }
} while ($choix -ne $NB)
Write-Host "Gagné"

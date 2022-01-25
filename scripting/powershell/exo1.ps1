$nombre = Get-Random -minimum 1 -maximum 5
do
{
    [int] $choix = Read-Host -prompt "Proposez un nombre"
    if ($choix -ge $nombre)
    {
        Write-Host "Trop grand"
    }
    if ($choix -lt $nombre)
    {
        Write-Host "Trop petit"
    }
}
while ($choix -ne $nombre)
Write-Host "Bravo vous avez trouvé le nombre"
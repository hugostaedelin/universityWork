do
{
    $i = 0
    $nom = "TMP"
    while ($i -lt 5)
    {
        $nb = Get-Random -Minimum 0 -Maximum 10
        $nom = "$nom$nb"
        $i = $($i+1)
    }
    $nom = "${nom}.TMP"
}
while (Test-Path "$nom")
Write-Host "$nom"
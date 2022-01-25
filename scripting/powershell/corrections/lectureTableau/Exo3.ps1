$contenu = Get-Content "exemple.txt"
$ligne1 = $contenu[0]
$taille = $ligne1.Length
$T = New-Object char[] $taille
$i = 0
while ($i -lt $taille) {
$T[$i]=$ligne1[$i]
$i=$($i+1)
}
Write-Host $T

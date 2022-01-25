$chaine = cat exemple.txt
$T = New-Object string "" 
$T = $chaine[0]
$i = 0
Write-Host "Rangement de chaque caractere dans une case du tableau T et affichage :"
while($i -ne $T.Length)
{
   write-host "T[$i] =" $T[$i]
   $i = $($i+1)
} 

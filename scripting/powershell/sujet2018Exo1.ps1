# Ligne de code indispensable pour mettre en place une interface graphique
[void][Reflection.Assembly]::LoadWithPartialName('System.Windows.Forms')
# Créations des composants de l'interface graphique
$clairLabel = New-Object System.Windows.Forms.Label
$cryptLabel = New-Object System.Windows.Forms.Label
$clair = New-Object System.Windows.Forms.TextBox
$crypt = New-Object System.Windows.Forms.TextBox
$quitButton = New-Object System.Windows.Forms.Button
$generateButton = New-Object System.Windows.Forms.Button
$cesarForm = New-Object System.Windows.Forms.Form

# Paramétrage de clairLabel
$clairLabel.AutoSize = $true
$clairLabel.Location = New-Object System.Drawing.Point(50, 50)
$clairLabel.Text = 'Texte en clair'

# Paramétrage de cryptLabel
$cryptLabel.AutoSize = $true
$cryptLabel.Location = New-Object System.Drawing.Point(50, 100)
$cryptLabel.Text = 'Texte chiffré'

# Paramétrage de clair
$clair.Size = New-Object System.Drawing.Size(150, 25)
$clair.Location = New-Object System.Drawing.Point(300, 50)

# Paramétrage de crypt
$crypt.Size = New-Object System.Drawing.Size(150, 25)
$crypt.Location = New-Object System.Drawing.Point(300, 100)

# Paramétrage de quitButton
$quitButton.Size = New-Object System.Drawing.Size(150, 25)

$quitButton.Location = New-Object System.Drawing.Point(50, 150)
$quitButton.Text = 'Quitter'
$quitButton.Add_Click({$cesarForm.Close()})

# Paramétrage de generateButton
$generateButton.Size = New-Object System.Drawing.Size(150, 25)
$generateButton.Location = New-Object System.Drawing.Point(300, 150)
$generateButton.Text = 'Chiffrer'
#Rajout du code manquant
$generateButton.Add_Click({		
    #Correspondance ALPHABET --- CODE CESAR
    $alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_"
    $code = "DEFGHIJKLMNOPQRSTUVWXYZ_ABC"
    #Recuperation du texte ecrit
    $chaine = $clair.Text
    $i = 0
    $long = $chaine.Length
    $encryptage = ""
    $txt = ""
    #Boucle tant que i n'est pas =  à la longueur de la chaine
    while($i -ne $long)
    {
        #récupération du caractère numéro i de la chaine et de l'indice dans la case de $alpha
        $carac= $chaine[$i]
        $indice = $alpha.IndexOf($carac)
        #Si le caractère n'est pas compris dans le tableau de char $alpha
        if($indice -eq -1)
        {
            $crypt.Text = "Caractère non pris en charge"
        }
        #Sinon le caractère est contenu dans le tableau de char $alpha
        else
        {
            $encryptage = $chaine.Replace($carac, $code[$indice])
            $lettre = $encryptage[$i]
            $txt = "$txt$lettre"
            $i = $($i+1)
        }
    }  
    $crypt.Text = $txt
})

# Paramétrage de cesarForm
$cesarForm.Size = New-Object System.Drawing.Size(525, 270)
$cesarForm.Controls.Add($clairLabel)
$cesarForm.Controls.Add($cryptLabel)
$cesarForm.Controls.Add($clair)
$cesarForm.Controls.Add($crypt)
$cesarForm.Controls.Add($quitButton)
$cesarForm.Controls.Add($generateButton)
$cesarForm.Text = 'Chiffre de César'
$cesarForm.ShowDialog()
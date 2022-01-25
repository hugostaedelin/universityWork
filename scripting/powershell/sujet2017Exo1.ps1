# Ligne de code indispensable pour mettre en place une interface graphique
[void][Reflection.Assembly]::LoadWithPartialName('System.Windows.Forms')

# Créations des composants de l'interface graphique
$extensionLabel = New-Object System.Windows.Forms.Label
$extensionBox = New-Object System.Windows.Forms.TextBox
$listButton = New-Object System.Windows.Forms.Button
$quitButton = New-Object System.Windows.Forms.Button
$listLabel = New-Object System.Windows.Forms.Label
$listForm = New-Object System.Windows.Forms.Form

# Paramétrage de extensionLabel
$extensionLabel.AutoSize = $true
$extensionLabel.Location = New-Object System.Drawing.Point(50, 50)
$extensionLabel.Text = 'Extension des fichiers à lister'

# Paramétrage de extensionBox
$extensionBox.Size = New-Object System.Drawing.Size(100, 25)
$extensionBox.Location = New-Object System.Drawing.Point(250, 50)
$extensionBox.Text = 'LOG'

# Paramétrage de listButton
$listButton.Size = New-Object System.Drawing.Size(300, 25)
$listButton.Location = New-Object System.Drawing.Point(50, 150)
$listButton.Text = 'Lister les fichiers'
$listButton.Add_Click({
$ext = $extensionBox.get_text()
if ($ext.length -eq 0 -or $ext[0] -ne ".") # PAS DE == en POWERSHELL MAIS -eq
{
    $ext = ".$ext"
}
$fileCreated = 0
foreach ($f in ls "*$ext") #AJOUT DU LS DANS LA COMMANDE
{
    if (-not $f.IsReadOnly) #OUBLI DES PARENTHESES ET l'OPERATEUR EST -not
    {
        if ($fileCreated -eq 0) # PAS DE == en POWERSHELL MAIS -eq
        {
            $f.name >> "LIST.TXT" #OUBLI D'UN CHEVRON >
        }
        else
        {
            $f.name >> "LIST.TXT"
        }
            $fileCreated = $($fileCreated + 1)
        }
    }
    if ($fileCreated -eq 0) # PAS DE == en POWERSHELL MAIS -eq
    {
        $listLabel.Text = "Aucun fichier n'a été trouvé."
    }
    else
    {
       $listLabel.Text = "LIST.TXT a été créé. Il contient $fileCreated noms de fichiers." #OUBLI DU $ devant fileCreated
    }
})

# Paramétrage de quitButton
$quitButton.Size = New-Object System.Drawing.Size(300, 25)
$quitButton.Location = New-Object System.Drawing.Point(50, 250)
$quitButton.Text = 'Quitter'
$quitButton.Add_Click({$listForm.Close()})

# Paramétrage de listLabel
$listLabel.AutoSize = $true
$listLabel.Location = New-Object System.Drawing.Point(50, 350)

# Paramétrage de listForm
$listForm.Size = New-Object System.Drawing.Size(425, 450)
$listForm.Controls.Add($extensionLabel)
$listForm.Controls.Add($extensionBox) #OUBLI DU TXTBOX
$listForm.Controls.Add($listButton)
$listForm.Controls.Add($listLabel)
$listForm.Controls.Add($quitButton)
$listForm.Text = 'Générateur de listes de fichiers'
$listForm.ShowDialog() #OUBLI DU SHOWDIALOG

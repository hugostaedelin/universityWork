# Ligne de code indispensable pour mettre en place une interface graphique
[void][Reflection.Assembly]::LoadWithPartialName('System.Windows.Forms')

# Cr�ations des composants de l'interface graphique
$filePrefixLabel = New-Object System.Windows.Forms.Label
$fileNameLabel = New-Object System.Windows.Forms.Label
$filePrefix = New-Object System.Windows.Forms.TextBox
$fileName = New-Object System.Windows.Forms.TextBox
$quitButton = New-Object System.Windows.Forms.Button
$generateButton = New-Object System.Windows.Forms.Button
$tmpGeneratorForm = New-Object System.Windows.Forms.Form

# Param�trage de filePrefixLabel
$filePrefixLabel.AutoSize = $true
$filePrefixLabel.Location = New-Object System.Drawing.Point(50, 50)
$filePrefixLabel.Text = 'Pr�fixe du nom de fichier � g�n�rer'

# Param�trage de fileNameLabel
$fileNameLabel.AutoSize = $true
$fileNameLabel.Location = New-Object System.Drawing.Point(50, 100)
$fileNameLabel.Text = 'Nom de fichier g�n�r�'

# Param�trage de filePrefix
$filePrefix.Size = New-Object System.Drawing.Size(150, 25)
$filePrefix.Location = New-Object System.Drawing.Point(300, 50)
$filePrefix.Text = 'TMP'

# Param�trage de fileName
$fileName.Size = New-Object System.Drawing.Size(150, 25)
$fileName.Location = New-Object System.Drawing.Point(300, 100)

# Param�trage de quitButton
$quitButton.Size = New-Object System.Drawing.Size(150, 25)
$quitButton.Location = New-Object System.Drawing.Point(50, 150)
$quitButton.Text = 'Quitter'
$quitButton.Add_Click({$tmpGeneratorForm.Close()})

# Param�trage de generateButton
$generateButton.Size = New-Object System.Drawing.Size(150, 25)
$generateButton.Location = New-Object System.Drawing.Point(300, 150)
$generateButton.Text = 'G�n�rer'
$generateButton.Add_Click({
do {
  $tmpName = $filePrefix.get_text()
  $i = 0
  while ($i -lt 5) {
    $i = $($i+1)
	$nb = Get-Random -minimum 0 -maximum 10
	$tmpName = "${tmpName}$nb"
  }
  $tmpName = "${tmpName}.TMP"
} while (Test-Path "$tmpName")
$fileName.Text = "$tmpName"
})

# Param�trage de tmpGeneratorForm
$tmpGeneratorForm.Size = New-Object System.Drawing.Size(500, 270)
$tmpGeneratorForm.Controls.Add($filePrefixLabel)
$tmpGeneratorForm.Controls.Add($fileNameLabel)
$tmpGeneratorForm.Controls.Add($filePrefix)
$tmpGeneratorForm.Controls.Add($fileName)
$tmpGeneratorForm.Controls.Add($quitButton)
$tmpGeneratorForm.Controls.Add($generateButton)
$tmpGeneratorForm.Text = 'G�n�rateur de noms de fichiers temporaires'
$tmpGeneratorForm.ShowDialog()

# Ligne de code indispensable pour mettre en place une interface graphique
[void][Reflection.Assembly]::LoadWithPartialName('System.Windows.Forms')

# Créations des composants de l'interface graphique
$nbSymbolesLabel = New-Object System.Windows.Forms.Label
$passWordLabel = New-Object System.Windows.Forms.Label
$nbSymboles = New-Object System.Windows.Forms.TextBox
$passWord = New-Object System.Windows.Forms.TextBox
$quitButton = New-Object System.Windows.Forms.Button
$generateButton = New-Object System.Windows.Forms.Button
$generateLetButton = New-Object System.Windows.Forms.Button
$generateDigButton = New-Object System.Windows.Forms.Button
$pwdGeneratorForm = New-Object System.Windows.Forms.Form

# Paramétrage de nbSymbolesLabel
$nbSymbolesLabel.AutoSize = $true
$nbSymbolesLabel.Location = New-Object System.Drawing.Point(50, 50)
$nbSymbolesLabel.Text = 'Nombre de caractères'

# Paramétrage de passWordLabel
$passWordLabel.AutoSize = $true
$passWordLabel.Location = New-Object System.Drawing.Point(50, 100)
$passWordLabel.Text = 'Mot de passe généré'

# Paramétrage de nbSymboles
$nbSymboles.Size = New-Object System.Drawing.Size(150, 25)
$nbSymboles.Location = New-Object System.Drawing.Point(300, 50)
$nbSymboles.Text = '10'

# Paramétrage de passWord
$passWord.Size = New-Object System.Drawing.Size(150, 25)
$passWord.Location = New-Object System.Drawing.Point(300, 100)

# Paramétrage de quitButton
$quitButton.Size = New-Object System.Drawing.Size(150, 25)
$quitButton.Location = New-Object System.Drawing.Point(50, 150)
$quitButton.Text = 'Quitter'
$quitButton.Add_Click({$pwdGeneratorForm.Close()})

# Paramétrage de generateButton
$generateButton.Size = New-Object System.Drawing.Size(150, 25)
$generateButton.Location = New-Object System.Drawing.Point(300, 150)
$generateButton.Text = 'Générer'
$generateButton.Add_Click({
  $symboles = "ABCDEF0123456789"
  [int] $nbSym = $nbSymboles.Text
  $i = 0
  $p = ""
  while ($i -lt $nbSym)
  {
    $i = $($i+1)
	$indice = Get-Random -minimum 0 -maximum $symboles.length
	$c = $symboles[$indice]
	$p = "${p}$c"
  }
  $passWord.text = $p
})

# Paramétrage de generateLetButton
$generateLetButton.Size = New-Object System.Drawing.Size(400, 25)
$generateLetButton.Location = New-Object System.Drawing.Point(50, 250)
$generateLetButton.Text = 'Générer Lettre'
$generateLetButton.Add_Click({
  $symboles = "ABCDEF"
  [int] $nbSym = $nbSymboles.Text
  $i = 0
  $p = ""
  while ($i -lt $nbSym)
  {
    $i = $($i+1)
	$indice = Get-Random -minimum 0 -maximum $symboles.length
	$c = $symboles[$indice]
	$p = "${p}$c"
  }
  $passWord.text = $p
})

# Paramétrage de generateDigButton
$generateDigButton.Size = New-Object System.Drawing.Size(400, 25)
$generateDigButton.Location = New-Object System.Drawing.Point(50, 350)
$generateDigButton.Text = 'Générer Chiffre'
$generateDigButton.Add_Click({
  $symboles = "0123456789"
  [int] $nbSym = $nbSymboles.Text
  $i = 0
  $p = ""
  while ($i -lt $nbSym)
  {
    $i = $($i+1)
	$indice = Get-Random -minimum 0 -maximum $symboles.length
	$c = $symboles[$indice]
	$p = "${p}$c"
  }
  $passWord.text = $p
})

# Paramétrage de pwdGeneratorForm
$pwdGeneratorForm.Size = New-Object System.Drawing.Size(500, 500)
$pwdGeneratorForm.Controls.Add($nbSymbolesLabel)
$pwdGeneratorForm.Controls.Add($passWordLabel)
$pwdGeneratorForm.Controls.Add($nbSymboles)
$pwdGeneratorForm.Controls.Add($passWord)
$pwdGeneratorForm.Controls.Add($quitButton)
$pwdGeneratorForm.Controls.Add($generateButton)
$pwdGeneratorForm.Controls.Add($generateLetButton)
$pwdGeneratorForm.Controls.Add($generateDigButton)
$pwdGeneratorForm.Text = 'Générateur de mots de passe'
$pwdGeneratorForm.ShowDialog() 


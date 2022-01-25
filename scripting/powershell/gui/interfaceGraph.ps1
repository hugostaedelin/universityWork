
# Ligne de code indispensable pour mettre en place une interface graphique
[void][Reflection.Assembly]::LoadWithPartialName('System.Windows.Forms')

# Créations des composants de l'interface graphique
$nbCaracLabel = New-Object System.Windows.Forms.Label
$pwdGeneratedLabel = New-Object System.Windows.Forms.Label
$nbValeur = New-Object System.Windows.Forms.TextBox
$pwdGeneratedTxtBox = New-Object System.Windows.Forms.TextBox
$quitButton = New-Object System.Windows.Forms.Button
$generateButton = New-Object System.Windows.Forms.Button
$generateLetterMinButton = New-Object System.Windows.Forms.Button
$generateLetterMajButton = New-Object System.Windows.Forms.Button
$generateNbButton = New-Object System.Windows.Forms.Button
$tmpGeneratorForm = New-Object System.Windows.Forms.Form

# Paramétrage de nbCaracLabel
$nbCaracLabel.AutoSize = $true
$nbCaracLabel.Location = New-Object System.Drawing.Point(50, 50)
$nbCaracLabel.Text = 'Nombre de caractères'

# Paramétrage de pwdGeneratedLabel
$pwdGeneratedLabel.AutoSize = $true
$pwdGeneratedLabel.Location = New-Object System.Drawing.Point(50, 100)
$pwdGeneratedLabel.Text = 'Mot de passe généré'

# Paramétrage de nbValeur
$nbValeur.Size = New-Object System.Drawing.Size(150, 25)
$nbValeur.Location = New-Object System.Drawing.Point(300, 50)
$nbValeur.Text = ''

# Paramétrage de pwdGeneratedTxtBox
$pwdGeneratedTxtBox.Size = New-Object System.Drawing.Size(150, 25)
$pwdGeneratedTxtBox.Location = New-Object System.Drawing.Point(300, 100)

# Paramétrage de quitButton
$quitButton.Size = New-Object System.Drawing.Size(150, 25)
$quitButton.Location = New-Object System.Drawing.Point(50, 150)
$quitButton.Text = 'Quitter'
$quitButton.Add_Click({$tmpGeneratorForm.Close()})

# Paramétrage de generateButton
$generateButton.Size = New-Object System.Drawing.Size(150, 25)
$generateButton.Location = New-Object System.Drawing.Point(300, 150)
$generateButton.Text = 'Générer'
$generateButton.Add_Click({
    $lettre = "ABCDEF0123456789abcdef"
	$i = 0
	[int] $nb = $nbValeur.Text
	while($i -ne $nb)
	{
		$nbChar = Get-Random -minimum 0 -maximum 23
		$pwdChar = $lettre[$nbChar]
		$pwdTotal = "$pwdTotal$pwdChar"
		$i = $($i+1)	
	}
	$pwdGeneratedTxtBox.Text = "$pwdTotal"
})

# Paramétrage de generateLetterMinButton
$generateLetterMinButton.Size = New-Object System.Drawing.Size(400, 25)
$generateLetterMinButton.Location = New-Object System.Drawing.Point(50, 250)
$generateLetterMinButton.Text = 'Générer Lettre Minuscule'
$generateLetterMinButton.Add_Click({
    $lettre = "abcdef"
	$i = 0
	[int] $nb = $nbValeur.Text
	while($i -ne $nb)
	{
		$nbChar = Get-Random -minimum 0 -maximum 6
		$pwdChar = $lettre[$nbChar]
		$pwdTotal = "$pwdTotal$pwdChar"
		$i = $($i+1)	
	}
	$pwdGeneratedTxtBox.Text = "$pwdTotal"
})

# Paramétrage de generateLetterMajButton
$generateLetterMajButton.Size = New-Object System.Drawing.Size(400, 25)
$generateLetterMajButton.Location = New-Object System.Drawing.Point(50, 300)
$generateLetterMajButton.Text = 'Générer Lettre Majuscule'
$generateLetterMajButton.Add_Click({
    $lettre = "ABCDEF"
	$i = 0
	[int] $nb = $nbValeur.Text
	while($i -ne $nb)
	{
		$nbChar = Get-Random -minimum 0 -maximum 6
		$pwdChar = $lettre[$nbChar]
		$pwdTotal = "$pwdTotal$pwdChar"
		$i = $($i+1)	
	}
	$pwdGeneratedTxtBox.Text = "$pwdTotal"
})

# Paramétrage de generateNbButton
$generateNbButton.Size = New-Object System.Drawing.Size(400, 25)
$generateNbButton.Location = New-Object System.Drawing.Point(50, 350)
$generateNbButton.Text = 'Générer Chiffre'
$generateNbButton.Add_Click({
	$i = 0
	[int] $nb = $nbValeur.Text
	while($i -ne $nb)
	{
		$nbInt = Get-Random -minimum 0 -maximum 10
		$pwdTotal = "$pwdTotal$nbInt"
		$i = $($i+1)	
	}
	$pwdGeneratedTxtBox.Text = "$pwdTotal"
})


# Paramétrage de tmpGeneratorForm
$tmpGeneratorForm.Size = New-Object System.Drawing.Size(500, 500)
$tmpGeneratorForm.Controls.Add($nbCaracLabel)
$tmpGeneratorForm.Controls.Add($pwdGeneratedLabel)
$tmpGeneratorForm.Controls.Add($nbValeur)
$tmpGeneratorForm.Controls.Add($pwdGeneratedTxtBox)
$tmpGeneratorForm.Controls.Add($quitButton)
$tmpGeneratorForm.Controls.Add($generateButton)
$tmpGeneratorForm.Controls.Add($generateLetterMajButton)
$tmpGeneratorForm.Controls.Add($generateLetterMinButton)
$tmpGeneratorForm.Controls.Add($generateNbButton)
$tmpGeneratorForm.Text = 'Générateur de mots de passe'
$tmpGeneratorForm.ShowDialog()

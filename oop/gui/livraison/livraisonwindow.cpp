#include "livraisonwindow.h"
#include "fiche.h"
#include <QMessageBox>

LivraisonWindow::LivraisonWindow(std::vector<tarif>& tarifs, int noTarif, livraison& livr, QWidget* parent) : QWidget{parent}, d_tarif{tarifs}, d_livraison{livr}, d_numeroTarif{0}
{
    vue_cree();
    vue_afficheDestination(d_numeroTarif);
    vue_afficheTypeLivraison(d_livraison);
    vue_affichePrix(prixLivraisonCourante());
}

void LivraisonWindow::vue_cree()
{
    this->setWindowTitle("Livraison*");
    auto layoutPrincipal = new QHBoxLayout{this};
    layoutPrincipal->setSpacing(20); // Espacement général de 20

    // Conteneur Boutons
    auto layoutBoutons = new QVBoxLayout{this};
    auto resetBtn = new QPushButton{"Ré-initialiser"};
    auto buyBtn = new QPushButton{"Acheter"};
    auto quitBtn = new QPushButton{"Quitter"};
    auto barre = new QFrame{};
    barre->setFrameStyle(QFrame::VLine);
    layoutBoutons->addWidget(resetBtn,0,Qt::AlignLeft);
    layoutBoutons->addWidget(buyBtn,0,Qt::AlignLeft);
    layoutBoutons->addWidget(quitBtn,0,Qt::AlignLeft);
    layoutPrincipal->addLayout(layoutBoutons);
    layoutPrincipal->addWidget(barre,0,Qt::AlignLeft);
    setLayout(layoutPrincipal);

    // Conteneur Destination
    auto layoutDestination = new QVBoxLayout{this};
    auto texteDestination = new QLabel{"Destination"};
    d_radioDestinations = new QButtonGroup{this};
    layoutDestination->addWidget(texteDestination,0,Qt::AlignTop);
    for(unsigned int i = 0; i < d_tarif.size(); ++i)
    {
        auto radio = new QRadioButton{QString::fromStdString(d_tarif[i].destination())};
        d_radioDestinations->addButton(radio, i);
        layoutDestination->addWidget(radio, 0, Qt::AlignLeft);
        setLayout(layoutDestination);
    }
    layoutDestination->addStretch(0);
    layoutPrincipal->addLayout(layoutDestination);

    // Conteneur Type
    auto layoutType = new QVBoxLayout{this};
    auto texteType = new QLabel{"Type"};
    d_express = new QCheckBox{"Express"};
    d_fragile = new QCheckBox{"Fragile"};
    layoutType->addWidget(texteType,0,Qt::AlignTop);
    layoutType->addWidget(d_express,0,Qt::AlignTop);
    layoutType->addWidget(d_fragile,0,Qt::AlignTop);
    setLayout(layoutType);
    layoutType->addStretch(0);
    layoutPrincipal->addLayout(layoutType);

    // Conteneur Prix
    auto layoutPrix = new QVBoxLayout{this};
    auto textPrix = new QLabel{"Prix"};
    d_labelPrix = new QLabel{" "};
    layoutPrix->addWidget(textPrix, 0, Qt::AlignTop);
    layoutPrix->addWidget(d_labelPrix, 0, Qt::AlignTop);
    layoutPrix->addStretch(0);
    setLayout(layoutPrix);
    layoutPrincipal->addLayout(layoutPrix);

    connect(d_radioDestinations, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &LivraisonWindow::onDestination);
    connect(d_express, &QCheckBox::stateChanged, this, &LivraisonWindow::onExpress);
    connect(d_fragile, &QCheckBox::stateChanged, this, &LivraisonWindow::onFragile);
    connect(quitBtn , &QPushButton::clicked, this, &LivraisonWindow::onQuitter);
    connect(resetBtn, &QPushButton::clicked, this, &LivraisonWindow::onReinitialiser);
    connect(buyBtn, &QPushButton::clicked, this, &LivraisonWindow::onAcheter);
}

void LivraisonWindow::vue_afficheDestination(int i)
{
    d_radioDestinations->button(i);
}

void LivraisonWindow::vue_affichePrix(double prix)
{
    d_labelPrix->setText(QString::number(prix,'f',2));
}

double LivraisonWindow::prixLivraisonCourante()
{
    return d_tarif[d_numeroTarif].prix(d_livraison);
}

void LivraisonWindow::onDestination(int id)
{
    d_numeroTarif = id;
    vue_affichePrix(d_tarif[d_numeroTarif].prixNormal());
}

void LivraisonWindow::vue_afficheTypeLivraison(livraison livr)
{
    d_express->setChecked(livr.estExpress());
    d_fragile->setChecked(livr.estFragile());
}

void LivraisonWindow::onExpress(int )
{
    d_livraison.rendExpress(d_express->isChecked());
    vue_affichePrix(d_tarif[d_numeroTarif].prixExpress());
    if(d_livraison.estExpress()&&d_livraison.estFragile()){
        vue_affichePrix(d_tarif[d_numeroTarif].prixExpressFragile());
    }
    else{
        vue_affichePrix(prixLivraisonCourante());
    }

    /*/ Deuxième façon de faire (cas ou on ne dispose pas des cases à cocher en mémoire dans "d_express" et "d_fragile")
	
    d_livraison.rendExpress(etat == Qt::Checked);
    vue_affichePrix(d_tarif[d_numeroTarif].prixExpress());
    if(d_livraison.estFragile()&&d_livraison.estExpress()){
        vue_affichePrix(d_tarif[d_numeroTarif].prixExpressFragile());
    }
    else{
        vue_affichePrix(prixLivraisonCourante());
    }
    /*/
}

void LivraisonWindow::onFragile(int )
{
    d_livraison.rendFragile(d_fragile->isChecked());
    vue_affichePrix(d_tarif[d_numeroTarif].prixFragile());
    if(d_livraison.estExpress()&&d_livraison.estFragile()){
        vue_affichePrix(d_tarif[d_numeroTarif].prixExpressFragile());
    }
    else {
        vue_affichePrix(prixLivraisonCourante());
    }

    /*/ Deuxième façon de faire (cas ou on ne dispose pas des cases à cocher en mémoire dans "d_express" et "d_fragile")
	
    d_livraison.rendFragile(etat == Qt::Checked);
    vue_affichePrix(d_tarif[d_numeroTarif].prixFragile());
    if(d_livraison.estFragile()&&d_livraison.estExpress()){
        vue_affichePrix(d_tarif[d_numeroTarif].prixExpressFragile());
    }
    else{
        vue_affichePrix(prixLivraisonCourante());
    }
    /*/
}

void LivraisonWindow::onQuitter()
{
    if(d_achetee == false)
    {
        QMessageBox dialog{QMessageBox::Question, "Confirmation","Livraison non achetée\nVoulez-vous vraiment quitter ?",QMessageBox::Yes|QMessageBox::No};
        if(dialog.exec() == QMessageBox::Yes) close();
    }
    else close();
}

void LivraisonWindow::onReinitialiser()
{
    this->setWindowTitle("Livraison*");
    d_numeroTarif = 0;
    d_radioDestinations->button(d_numeroTarif)->toggle();
    d_livraison.reInitialise();
    vue_afficheTypeLivraison(d_livraison);
    vue_affichePrix(prixLivraisonCourante());
}

void LivraisonWindow::onAcheter()
{
    QMessageBox{QMessageBox::Information,"Information","Livraison achetée"}.exec();
    fiche f{};
    const std::string nFout = "livraison.txt";
    f.imprimeBonLivraison(d_livraison, d_tarif[d_numeroTarif], nFout);
    vue_afficheEtatAchat(d_achetee=true);
}

void LivraisonWindow::vue_afficheEtatAchat(bool achetee)
{
    if(achetee == true)
    {
        this->setWindowTitle("Livraison");
    }
    else this->setWindowTitle("Livraison*");
}

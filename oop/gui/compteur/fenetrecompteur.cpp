#include "fenetrecompteur.h"

/*
fenetreCompteur::fenetreCompteur(int compteur, QWidget* parent) : 	QWidget{ parent }, d_compteur{compteur}
{
    resize(100, 300);
    setMinimumSize(100, 300);
    auto boutonMoins = new QPushButton{"-", this};
    boutonMoins->setGeometry(10, 20, 60, 50);
    auto boutonPlus = new QPushButton{"+", this};
    boutonPlus->setGeometry(170, 20, 60, 50);
    //auto btnCpt = new QPushButton{ QString::number(d_compteur), this };
    // On garde en mémoire le btn compteur via un pointeur au lieu de déclarer une new var (utile pour la maj de l'affichage)
    d_boutonCompteur = new QPushButton{QString::number(d_compteur), this};
    d_boutonCompteur->setGeometry(90, 20, 80, 50);
}
*/
fenetreCompteur::fenetreCompteur(int compteur, QWidget* parent) : 	QWidget{ parent }, d_compteur{compteur}
{
    resize(250, 100);
    setMinimumSize(250, 100);
    vueCreer();
    vueAfficherCompteur();
}

fenetreCompteur::fenetreCompteur(int compteur) : d_compteur{compteur}, d_compteurInitial{compteur}
{
    vueCreer();
    vueAfficherCompteur();
}
void fenetreCompteur::onMoins()
{
    donneesDecrementerCompteur();
    vueAfficherCompteur();
}

void fenetreCompteur::onPlus()
{
    donneesIncrementerCompteur();
    vueAfficherCompteur();
}
void fenetreCompteur::onReinitialise()
{
    donneeReinitialiserCompteur();
    vueAfficherCompteur();
}

void fenetreCompteur::donneesIncrementerCompteur()
{
    ++d_compteur;
}
void fenetreCompteur::donneesDecrementerCompteur()
{
    --d_compteur;
}
void fenetreCompteur::donneeReinitialiserCompteur()
{
    d_compteur = d_compteurInitial;
}
void fenetreCompteur::vueAfficherCompteur()
{
    d_boutonCompteur->setText(QString::number(d_compteur));
}

void fenetreCompteur::vueCreer()
{
    auto boutonMoins = new QPushButton{"-", this};
    boutonMoins->setGeometry(10, 20, 60, 50);
    auto boutonPlus = new QPushButton{"+", this};
    boutonPlus->setGeometry(170, 20, 60, 50);
    d_boutonCompteur = new QPushButton{"" ,this}; // 2 solutions : soit d_boutonCompteur = new QPushButton{"",this};
    d_boutonCompteur->setGeometry(80, 20, 80, 50);
    connect(boutonMoins, &QPushButton::clicked, this, &fenetreCompteur::onMoins);
    connect(boutonPlus, &QPushButton::clicked, this, &fenetreCompteur::onPlus);
    connect(d_boutonCompteur, &QPushButton::clicked, this, &fenetreCompteur::onReinitialise);
}

/*
void fenetreCompteur::vueCreer()
{
    d_boutonCompteur = new QPushButton{"",this};
    connect(d_boutonCompteur, &QPushButton::clicked, this, &fenetreCompteur::onReinitialise);
}
*/




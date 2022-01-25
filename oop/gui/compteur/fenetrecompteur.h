#include <QApplication>
#include <QPushButton>
#ifndef FENETRECOMPTEUR_H
#define FENETRECOMPTEUR_H

class fenetreCompteur : public QWidget
{
    Q_OBJECT
public:
    fenetreCompteur(int compteur = 0, QWidget* parent = nullptr);
    fenetreCompteur(int compteur);
private:
    int d_compteur;
    int d_compteurInitial;
    QPushButton* d_boutonCompteur;
    void donneeReinitialiserCompteur();
    void donneesIncrementerCompteur();
    void donneesDecrementerCompteur();
    void vueAfficherCompteur();
    void vueCreer();
private slots:
    void onMoins();
    void onPlus();
    void onReinitialise();
};

#endif // FENETRECOMPTEUR_H

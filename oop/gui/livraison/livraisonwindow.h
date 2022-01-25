#ifndef LIVRAISONWINDOW_H
#define LIVRAISONWINDOW_H

#include <QWidget>
#include "tarif.h"
#include "livraison.h"
#include <vector>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>

class LivraisonWindow : public QWidget
{
    Q_OBJECT

public:
    LivraisonWindow(std::vector<tarif>& tarifs, int noTarif, livraison& livr, QWidget* parent = nullptr) ;

private:
    std::vector<tarif> d_tarif;
    livraison d_livraison;
    int d_numeroTarif;
    QButtonGroup* d_radioDestinations;  // Garde en mémoire le groupe de bouton
    QLabel* d_labelPrix;                // Garde en mémoire le prix pour l'afficher
    QCheckBox* d_express;               // Garde en mémoire la case express
    QCheckBox* d_fragile;               // Garde en mémoire la case fragile
    void vue_cree();
    void vue_afficheDestination(int i);
    void vue_affichePrix(double prix);
    double prixLivraisonCourante();
    void vue_afficheTypeLivraison(livraison livr);
    bool d_achetee;
    void vue_afficheEtatAchat(bool achetee);

private slots:
    void onDestination(int id);
    void onExpress(int etat);
    void onFragile(int etat);
    void onQuitter();
    void onReinitialiser();
    void onAcheter();
};

#endif // LIVRAISONWINDOW_H

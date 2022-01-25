#include "livraisonwindow.h"
#include <vector>
#include <QApplication>

std::vector<tarif>tarification()
{
     //tarif(double p, double pe, double pf, double pef) :
     tarif t1{"France", 10,20,15,60};
     tarif t2{"Belgique", 20,30,25,70};
     tarif t3{"Suisse", 30,40,35,80};
     tarif t4{"USA", 40,50,45,90};
     return {t1,t2,t3,t4};
}

int main(int argc, char *argv[])
{
    std::vector<tarif>tarifs = tarification();
    livraison livr{};
    QApplication a(argc, argv);
    LivraisonWindow w{tarifs,0,livr};
    w.show();
    return a.exec();
}

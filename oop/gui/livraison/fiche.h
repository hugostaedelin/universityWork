#ifndef FICHE_H
#define FICHE_H
#include <iostream>
#include "livraison.h"
#include "tarif.h"
#include <fstream>

class fiche
{
public:
    fiche();
    void imprimeBonLivraison(livraison& livr, tarif& t, const std::string& nFout);
private:
    void imprime(livraison& livr, tarif& t, std::ostream& ost);

};

#endif // FICHE_H

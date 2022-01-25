#include "fiche.h"

fiche::fiche()
{}

void fiche::imprime(livraison& livr, tarif& t, std::ostream& ost)
{
    ost<<"Livraison"<<std::endl;
    ost<<"Pays de destination : "<<t.destination()<<std::endl;
    std::string chaineL, chaineC;
    if(livr.estExpress()==true)         chaineL = "normale";
    else                                chaineC = "express";
    if(livr.estFragile()==false)        chaineC = "normal";
    else                                chaineC = "fragile";
    ost<<"Livraison : "<<chaineL<<std::endl;
    ost<<"Colis : "<<chaineC<<std::endl;
    ost<<"Prix : "<<t.prix(livr)<<" Euros";
}

void fiche::imprimeBonLivraison(livraison& livr, tarif& t, const std::string& nFout)
{
    std::ofstream fout(nFout);
    fout<<"Livraison"<<std::endl;
    fout<<"Pays de destination : "<<t.destination()<<std::endl;
    std::string chaineL, chaineC;
    if(livr.estExpress()==true)         chaineL = "express";
    else                                chaineL = "normale";
    if(livr.estFragile()==false)        chaineC = "normal";
    else                                chaineC = "fragile";
    fout<<"Livraison : "<<chaineL<<std::endl;
    fout<<"Colis : "<<chaineC<<std::endl;
    fout<<"Prix : "<<t.prix(livr)<<" Euros";
}

#include <iostream>
#include "table.h"
using namespace std;

void afficher(Table tab)
{
    for(int i=0; i<tab.dimension(); ++i)
    {
        cout<<tab[i]<<" "<<i<<endl;
    }
}

void testConstructeurRecopie()
{
    Table t{};
    t.ajouter(1);
    t.ajouter(2);
    t.ajouter(3);
    Table g{t};
    afficher(g);
}

void testSupprimer()
{
    Table t{};
    for(int i=0;i<10;++i)
    {
        t.ajouter(i*i);
    }
    t.supprimer(9);
    afficher(t);
}

void testAffectation()
{
    Table t{};
    for(int i=1;i<4;++i)
    {
        t.ajouter(i);
    }
    Table c{};
    c = t;
    t.ajouter(64);
    afficher(c);
}

bool testEgalite()
{
    Table t{};
    for(int i=1;i<4;++i)
    {
        t.ajouter(i);
    }
    Table c{t};
    if(t == c) return true;
    else return false;
}

void testInsertion()
{
    Table t{};
    t.ajouter(1);
    t.ajouter(2);
    t.ajouter(3);
    t.inserer(4, 1);
    afficher(t);
}

int main()
{
    //testConstructeurRecopie();
    //testSupprimer();
    //testAffectation();
    //testEgalite();
    //testInsertion();
}

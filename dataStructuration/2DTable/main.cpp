#include <iostream>
#include "Tableau2D.h"
using namespace std;

void affichage(Tableau2D Tab)
{
    for(int i=0;i<Tab.get_nl();++i)
    {
        for(int j=0;j<Tab.get_nc();++j)
        {
            cout<<Tab(i,j)<<"\t";
        }
        cout<<endl;
    }
}

void remplissage(Tableau2D Tab)
{
    int k = 1 ;
    for(int l = 0 ; l < Tab.get_nl() ; l++)
    for(int c = 0 ; c < Tab.get_nc() ; c++)
    Tab(l,c) = k++ ;
    //affichage(Tab);
}

void testRecopie(Tableau2D Tab)
{
    remplissage(Tab);
    Tableau2D Copie{Tab};
    affichage(Copie);
}



int main()
{
    Tableau2D Tab{10, 10};
    testRecopie(Tab);
    //remplissage(Tab);
}

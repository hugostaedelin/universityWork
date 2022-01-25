#include "bourse.h"
#include <iostream>
#include <vector>
using namespace std;

void test1()
{
    bourse b;
    b.lit(cin);
    cout<<"Equivalent : "<<b.equivalentPiecesBronze();
}
/*
bourse sommeBourses(const vector<bourse>& bourses)
{
    int bronze = 0;
    for(int i = 0; i < bourses.size() ; ++i)
    {
        bronze += bourses[i].equivalentPiecesBronze() ;
    }
    //for(auto b : bourses) { bronze += b.equivalentPiecesBronze(); }
    return bourse{bronze};
}
*/
ostream& operator<<(ostream& ost, const bourse& b)
{
    b.affiche(ost);
    return ost;
}

istream& operator>>(istream& ist, bourse& b)
{
    b.lit(ist);
    return ist;
}

bourse operator+(int val, const bourse& b)
{
    return {b + val};
}

bourse sommeBourses(const vector<bourse>& bourses)
{
    bourse somme{};
    for(int i = 0; i < bourses.size() ; ++i)
    {
        somme += bourses[i];
    }
    return somme;
}

void test2()
{
    int nbBourse;
    cout<<"Nb bourse ?"<<endl;
    cin>>nbBourse;
    vector<bourse> bourses;
    for(int i = 0; i < nbBourse; ++i)
    {
        bourse b;
        cout<<"bourse :" ; cin>>b;
        cout<<endl;
        bourses.push_back(b);
    }
    cout<<"Somme : "<<sommeBourses(bourses);
}



int main()
{
 //   test1();
   // test2();
}

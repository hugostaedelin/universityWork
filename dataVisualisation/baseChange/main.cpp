#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int codage(int valeur, int base)
{
    vector<int>T;
	int modulo = 0;
	while(valeur != 0)
    {
        modulo = valeur%base;
        valeur /= base;
        T.push_back(modulo);
    }
    reverse(T.begin(),T.end());
    for(int j = 0; j < T.size(); j++)
    {
        cout<<T[j] ;
    }
}

int decodage(int valeur, int base)
{
    int facteur = 1;
    int modulo;
    int res = 0;
    while(valeur != 0)
    {
        modulo = valeur%10;
        res += modulo * facteur;
        valeur /= 10;
        facteur *= base;
    }
    return res;
}

int transcodage(int valeur, int initbase, int destbase)
{
    valeur = decodage(valeur,initbase);
    codage(valeur, destbase);
}

int compRestreint(int valeur, int baseSource, int chiffre)
{

}

void test()
{
    codage(555,5);
}

int main()
{
    test();
}

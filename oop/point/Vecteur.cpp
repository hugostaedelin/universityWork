#include "Vecteur.h"
#include <math.h>

using namespace std;



vecteur::vecteur(double X,double Y) : d_X(X),d_Y(Y)
{
}

vecteur::vecteur() : d_X(0),d_Y(0)
{
}

vecteur::vecteur(point p1,point p2) : d_X{p2.X()-p1.X()},d_Y{p2.Y()-p1.Y()}
{
}

double vecteur::norme() const
{

    return temp=sqrt(d_X*d_X+d_Y*d_Y);

}

void vecteur::changeNorme(double n) const
{

    double an=norme();
    double coef=sqrt(n/an)
    d_X *=coef;
    d_Y *=coef;
}

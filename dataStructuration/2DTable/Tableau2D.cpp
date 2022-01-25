#include <iostream>
#include "Tableau2D.h"

using namespace std;

// TODO Constructeur par défaut
Tableau2D::Tableau2D() : d_nl{0}, d_nc{0}, d_v{nullptr}, d_tab{nullptr}
{

}

// TODO Constructeur avec taille initiale
Tableau2D::Tableau2D(int nl, int nc) : d_nl{nl}, d_nc{nc}
{
    d_v = new double[d_nl*d_nc];
    d_tab = new double*[d_nl];
    for(int i = 0; i < d_nl; ++i)
    {
        d_tab[i] = d_v+i*d_nc;
    }
}

// TODO Constructeur par recopie
Tableau2D::Tableau2D(const Tableau2D& t) :  d_nl{t.d_nl}, d_nc{t.d_nc}, d_v{new double[d_nl * d_nc]}, d_tab{new double*[d_nl]}
{
    for(int l = 0; l < d_nl; l++)
    {
        d_tab[l] = d_v+l*d_nc;
    }
    for(int i = 0; i < d_nl*d_nc; ++i)
    {
        d_v[i] = t.d_v[i];
    }
}

// TODO Destructeur
Tableau2D::~Tableau2D()
{
    delete[] d_tab;
    delete[] d_v;
}

// TODO Retourne la taille du tableau
int Tableau2D::get_nl() const
{
    return d_nl;
}

int Tableau2D::get_nc() const
{
    return d_nc;
}

// TODO Accéder aux valeurs par indexage
double& Tableau2D::operator()(int l, int c)
{
    return d_v[l*d_nc+c];
}

double Tableau2D::operator()(int l, int c) const
{
    return d_v[l*d_nc+c];
}


// TODO Opérateur d'égalité
bool Tableau2D::operator==(const Tableau2D &t) const
{
    return (d_nc == t.d_nc && d_nl == t.d_nl && d_v == t.d_v && d_tab == t.d_tab);
}

// TODO Opérateur d'affectation
Tableau2D& Tableau2D::operator=(const Tableau2D &t)
{
    d_nc = t.d_nc;
    d_nl = t.d_nl;
    d_tab = t.d_tab;
    d_v = t.d_v;
    return *this;
}


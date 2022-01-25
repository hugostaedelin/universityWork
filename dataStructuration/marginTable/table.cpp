#include <iostream>
#include "Table.h"

using namespace std;

// Constructeur par défaut
Table::Table() : d_table{nullptr}, d_n{0}, d_capacite{0}
{

}

// Constructeur par recopie
Table::Table(const Table& t)
{
    d_table = t.d_table;
    d_n = t.d_n;
    d_capacite = t.d_capacite;
}

// Destructeur
Table::~Table()
{
    delete[] d_table;
}

// Ajouter l'élément v à la fin du tableau
void Table::ajouter(double v)
{
    if (d_n == d_capacite)
    {
        d_capacite *= CM;
        double* tab = new double[d_capacite];
        for(int i = 0; i < dimension(); ++i)
        {
            tab[i] = d_table[i];
        }
        delete[] d_table;
        d_table = tab;
    }
    d_table[d_n++] = v;
}

// Retourne la taille du tableau
int Table::dimension() const
{
    return d_n;
}

// Accéder aux valeurs par indexage
double& Table::operator[](int i)
{
    return d_table[i];
}

double Table::operator[](int i) const
{
    return d_table[i];
}

// Supprimer une valeur
void Table::supprimer(int i)
{
    if(i > dimension())
    {
       return;
    }
    for(int j=i; j<dimension() ; ++j)
    {
       d_table[j] = d_table[j+1];
    }
    d_n--;
}

// Opérateur d'égalité
bool Table::operator==(const Table &t) const
{
    return (t.d_table == d_table && t.d_n == d_n);
}

// Opérateur d'affectation
Table& Table::operator=(const Table &t)
{
    d_table = t.d_table;
    d_n = t.d_n;
    d_capacite = t.d_capacite;
    return *this;
}

// Insérer la valeur v à la position i, on suppose 0 <= i <= d_n
void Table::inserer(double v,int i)
{
    double* tab = new double[d_n];
    for(int j = 0; j < i; ++j)
    {
        tab[j] = d_table[j];
    }
    delete[] d_table;
    d_table = tab;
    d_table[d_n] = v;
    d_n++;
}

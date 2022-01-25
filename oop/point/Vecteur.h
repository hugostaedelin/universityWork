#ifndef VECTEUR_H_INCLUDED
#define VECTEUR_H_INCLUDED
#include "point.h"

class point;

class vecteur{

public:
    vecteur(double X,double Y); //constructeur
    vecteur(); //(0.0)
    vecteur(const point&p1,const point&p2);
    double x() const;
    double y() const;
    double norme() const;
    void changeNorme(double n);
private :
    double d_X,d_Y;

};

#endif // VECTEUR_H_INCLUDED

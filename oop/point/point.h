#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class vecteur;

class point{

public:
    point(double X,double Y);
    point();//(0,0)
    double X() const;
    double Y() const;
    void deplaceEn(double X,double Y);
    void deplaceDe(double dX,double dY);
    void deplaceDe(const vecteur& V);
    double distance(const point&p)const;
    void affiche(ostream& ost) const;
    void lit(istream& ist);
    /**
        p=p1+p2 -> p1.operateur+(p2)
        p= 3.14 * p -> 3.14.operateur*(p) ---> PAS POSSIBLE  //ecrit d'abord 3.14 car c'est les maths fdp c'est comme ça
        ->Bonne solution -> operateur*(3.14,p)
    */
    point operator+(const point& p)const;
    point& operator+=(const point &p);
    point operator/(double valeur) const;
    point& operator/=(double valeur);
    point& operator+=(const point& p);
    bool operator==(const point& p) const;
    bool operator!=(const point& p) const;
    friend operator*(double valeur,const point& p);
private:
    double d_X,d_Y;
};

point isoBarycentre(const vector<point>&p); // = la moeyenne
point barycentre(const vector<point> &p,const vector<double> & poids)

#endif // POINT_H_INCLUDED

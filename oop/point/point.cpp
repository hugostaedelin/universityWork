#include <iostream>
#include "point.h"
#include <math.h>
#include <string>


using namespace std;

point::point(double X,double Y): d_X{X},d_Y{Y}
{}

point::point():d_X{0.0},d_Y{0.0}
{}

double point::X() const
{
    return d_X;
}

double point::Y() const
{
    return d_Y;
}

void point::deplaceDe(double dX,double dY)
{
    d_X += d_X;
    d_Y += d_Y;
}

void point::deplaceDe(const vecteur& V)
{
    d_X += V.X();
    d_Y += V.Y();
}

void point::deplaceEn(double X,double Y)
{
    d_X = X;
    d_Y = Y;
}

double point::distance(const point&p) const
{

    double pX=p.d_X-d_Y;
    double pY=p.d_Y-d_Y;
    return sqrt(pX*pX+pY*pY);

}

void point::affiche(ostream& ost) const
{
    ost<<"( "<<d_X<<",- "<<d_Y<<endl;
}

void point::lit(istream& ist)
{
    char chara;
    ist>>chara>>d_X>>chara>>d_Y>>chara;
}

point point::operator+(const point& p) const
{
    point Inter{d_X + p.d_X ,d_Y + p.d_Y};
    return Inter;
}

point& point::operator+=(const point& p)
{
    d_X+=p.d_X;
    d_Y+=p.d_Y;

    return *this;
}

point point::operator/(double Valeur) const
{

    return point{d_X / Valeur,d_Y / Valeur};
}

point& point::operator/=(double Valeur)
{
    d_X /= Valeur;
    d_Y /= Valeur;

    return *this
}


point operator*(double Valeur,const point& p)
{

    return {Valeur*p.d_X,Valeur*.p.d_Y} //autre methode de return encore
}

 point& point::operator+=(double Valeur)
 {
     d_X /= Valeur;
     d_Y /= Valeur;

     return *this;
}


point isoBarycentre(const vector<point> &p)
{

    point Moyenne;

    for(int i=0,i<p.size(),i++)
    {
        Moyenne+= p[i];
    }

    return Moyenne/p.size();

}

point barycentre(const vector<point>&p,const vector<double> & poids)
{
    point Moyenne{0.0,0.0};
    double Total=0.0;

    for(int i=0,i<p.size(),i++)
    {
        Moyenne+= p[i]*poids[i];
        Total+=poids[i];
    }

    return Moyenne/Total;
}

bool point::operator==(const point& p) const
{
    if(d_X == p.d_X && d_Y == p.d_Y) return true;
    else return false;
}

bool point::operator!=(const point &p) const
{
    if(d_X != p.d_X && d_Y != p.d_Y) return true;
    else return false;

    /** ou

        if(d_X == p.d_X && d_Y == p.d_Y) return true;
        else return false;

    */
}

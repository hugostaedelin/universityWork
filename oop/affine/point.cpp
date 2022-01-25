#include "point.h"
#include "transfoaffine.h"
#include <iostream>
#include <cmath>
using namespace std;

point::point(double x, double y) : d_x(x), d_y(y)
{}

point::point() : d_x(0), d_y(0)
{}

double point::recupX() const
{
	return d_x;
}
double point::recupY() const
{
	return d_y;
}

void point::deplaceEn(double x, double y)
{
	d_x = x;
	d_y = y;
}

void point::deplaceDe(double x, double y)
{
	d_x += x;
	d_y += y;
}

double point::distance(const point& p) const
{
	// Méthode 1 : double dx = p.recupX() - d_x;
	// OU meilleure méthode
	double dx = p.d_x - d_x;
	double dy = p.d_y - d_y;
	return sqrt(dx*dx + dy*dy);
}

void point::affiche(ostream &ost) const
{
	ost << '(' << d_x << ',' << d_y << ')' << endl;  // Rappel : Un caractère se lit avec 'c'
													 // Une chaîne se lit avec "s" (différence des guillemets)
}

void point::lit(istream &ist)
{
	char c;
	ist >> c >> d_x >> c >> d_y >> c;
}
/*
void point::print(ostream &sout) const
{
	sout << '(' << d_x << ',' << d_y << ')' << endl;  // Rappel : Un caractère se lit avec 'c'
													 // Une chaîne se lit avec "s" (différence des guillemets)
}

void point::read(istream &sin)
{
	char c;
	sin >> c >> d_x >> c >> d_y >> c;
}
*/
void operator<<(ostream &oflux, point& p)
{
    p.affiche(oflux);
}

void operator>>(istream &iflux, point& p)
{
    p.lit(iflux);
}

point& point::operator*=( transfoAffine& A)
{
    A.transforme(*this);
    return *this;
}

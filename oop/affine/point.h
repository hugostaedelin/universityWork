#pragma once
#include "transfoaffine.h"
using namespace std;
class transfoAffine;

#ifndef POINT_H
#define POINT_H
class point {
public:
	point(double x, double y);
	point(); // Constructeur par défaut (0,0);
	double recupX() const;
	double recupY() const;
	void deplaceEn(double x, double y); // On modifie les points donc pas de const
	void deplaceDe(double x, double y);
	double distance(const point& p) const;
	void affiche(ostream& ost)	const;
	void lit(istream& ist);
	//void print(ostream& ost)	const;
	//void read(istream& ist);

	point& operator*=(transfoAffine& A);

private:
	double d_x, d_y;
};

#endif
	void operator<<(ostream &oflux, point& p);
	void operator>>(istream &iflux, point& p);

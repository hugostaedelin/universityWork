#include <iostream>
#include "point.h"
using namespace std;
class point;

#ifndef TRANSFOAFFINE_H
#define TRANSFOAFFINE_H
class transfoAffine {
public:
	transfoAffine();
	transfoAffine(double a, double b, double c, double d, double e, double f);
	transfoAffine(point& P, double o);
	transfoAffine(double coeff);
	transfoAffine(const point& t);
	void transforme(point& p);
	void print(ostream& sout)	const;
	void read(istream& sin);
    transfoAffine& operator*=(const transfoAffine B);
	point operator*(const point& p) ;
    transfoAffine operator*(const transfoAffine& B);
private:
	double d_a, d_b, d_c, d_d, d_e, d_f;
};

#endif

void operator<<(ostream &oflux,const transfoAffine& tf);
void operator>>(istream &iflux,  transfoAffine& tf);

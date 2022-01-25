#include "transfoaffine.h"
#include <iostream>
#include <cmath>
using namespace std;

// constructeur par défaut
transfoAffine::transfoAffine() : d_a(0),
								d_b(0),
								d_c(0),
								d_d(0),
								d_e(0),
								d_f(0)
{}

// constructeur qui récupère les coeffs
transfoAffine::transfoAffine(double a, double b, double c, double d, double e, double f) : d_a(a),
																							d_b(b),
																							d_c(c),
																							d_d(d),
																							d_e(e),
																							d_f(f)
{}
// constructeur qui prend un point P et un angle O avec les coefficients données du TP (cf liste init)
transfoAffine::transfoAffine(point& c, double o) : d_a{ cos(o) },
													d_b{ -sin(o) },
													d_c{ sin(o) },
													d_d{ cos(o) },
													d_e{ c.recupX() * (1 - cos(o)) + c.recupY() * sin(o) },
													d_f{ c.recupY() * (1 - cos(o)) - c.recupX() * sin(o) }
{}

// constructeur avec le coefficient en paramètre c
transfoAffine::transfoAffine(double c) : d_a(c),
                                        d_b(0.0),
                                        d_c(0.0),
                                        d_d(c),
                                        d_e(0.0),
                                        d_f(0.0)
{}

// constructeur avec les coordonnées (x,y) du point t
transfoAffine::transfoAffine(const point& t) : d_a(1.0),
                                               d_b(0.0),
                                               d_c(0.0),
                                               d_d(1.0),
                                               d_e{t.recupX()},
                                               d_f{t.recupY()}
{}


void transfoAffine::transforme(point& p)
{
	double x = d_a * p.recupX() + d_b * p.recupY() + d_e;
	double y = d_c * p.recupX() + d_d * p.recupY() + d_f;
	point t{ x, y };
	p = t;
}

void transfoAffine::print(ostream& sout)	const
{
    sout<<'['<<'('<<d_a<<','<<d_b<<','<<d_c<<','<<d_d<<')'<<','<<'('<<d_e<<','<<d_f<<')'<<']'<<endl;
}

void transfoAffine::read(istream& sin)
{
    char c;
	sin >> c >> c >> d_a >> c >> d_b >> c >> d_c >> c >> d_d >> c >> c >> c >> d_e >> c >> d_f >> c >> c ;
}

void operator<<(ostream &oflux,const transfoAffine& tf)
{
    tf.print(oflux);
}

void operator>>(istream &iflux,  transfoAffine& tf)
{
    tf.read(iflux);
}

point transfoAffine::operator*(const point& p)
{
    point c{p};
    transforme(c);
    return c;
}

transfoAffine& transfoAffine::operator*=(const transfoAffine B)
{
    double a = (d_a*B.d_a + d_b*B.d_c);
    double b = (d_a*B.d_b + d_b+B.d_d);
    double c = (d_c*B.d_a + d_d*B.d_c);
    double d = (d_c*B.d_b + d_d*B.d_d);
    double e = (d_a*B.d_e + d_b*B.d_f+d_e);
    double f = (d_c*B.d_e + d_d*B.d_f+d_f);

    d_a = a;
    d_b = b;
    d_c = c;
    d_d = d;
    d_e = e;
    d_f = f;
    return *this;
}

transfoAffine transfoAffine::operator*(const transfoAffine& B)
{
    return {(d_a*B.d_a + d_b*B.d_c), (d_a*B.d_b + d_b+B.d_d), (d_c*B.d_a + d_d*B.d_c), (d_c*B.d_b + d_d*B.d_d),(d_a*B.d_e + d_b*B.d_f+d_e),(d_c*B.d_e + d_d*B.d_f+d_f)};
}





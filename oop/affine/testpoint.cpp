#include <iostream>
#include <fstream>
#include "point.h"
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*
void testConstructeur()
{
	double x, y;
	cout << "x : "; cin >> x; cout<<endl;
	cout << "y : "; cin >> y;
	point p{x,y};
	cout << "point " << p.recupX() << " " << p.recupY();
}
void testDeplace()
{
	point p{};
	double x, y;
	cout << ". . "; cin >> x >> y;
	p.deplaceEn(x, y);
	cout << "point " << p.recupX() << " " << p.recupY();
}

void testDistance()
{
	double x1, y1;
	cout << "Coordonnees :"; cin >> x1 >> y1;
	point p1{x1,y1};
	point p2{};
	cout << "distance P1 et P2 =" << p1.distance(p2)<<endl;
	cout << "distance P2 et P1 =" << p2.distance(p1)<<endl;
	cout << "distance P1 et P1 =" << p1.distance(p1)<<endl;
}

void testAffiche()
{
	point p{};
	cout << "Entrez un point :";
	p.lit(cin);
	cout << "Vous avez entre :";
	p.affiche(cout);
}

const string fn = "coord.txt";
void testFichier()
{
	ifstream f{ fn };
	point p{ 3.2,-4 };
	p.lit(f);
	f.close();
	ifstream fl{ fn };
	p.lit(fl);
	fl.close();
	cout << " point lu :";
	p.affiche(cout);
}

void tp1()
{
    cout << "Test constructeur. ";  testConstructeur(); cout << endl;
	cout << "Test deplace. "; testDeplace(); cout << endl;
	cout << "Test distance. "; testDistance(); cout << endl;
	cout << "Test fichier. "; testFichier(); cout << endl;
}
*/

void testReadPrintPoint()
{
    point p;
	cout << "Entrez un point : ";
	p.lit(cin);
	cout << "Vous avez entre : ";
	p.affiche(cout);
}

void testSurchargesPoint()
{
    point p;
    point c{0.0 , 0.0};
	cout << "Entrez un point : ";
	p.lit(cin);
	transfoAffine tf{c, M_PI};
	p *= tf;
	p.affiche(cout);
}


void tp2pt()
{
    //testReadPrintPoint();
    testSurchargesPoint();
}
/*
int main()
{
	tp2pt();
}
*/

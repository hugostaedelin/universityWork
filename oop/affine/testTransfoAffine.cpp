#include <iostream>
#include "graphics.h"
#include <cmath>
#include "point.h"
#include "transfoaffine.h"
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void testTransformationParDefaut()
{
	double x, y;
	cout << "(x , y) : "; cin >> x >> y;
	point p{ x,y };
	transfoAffine tf{};
	tf.transforme(p);
	cout << "Point : ";
	p.affiche(cout);
}

void testCoeffs()
{
	double x, y;
	cout << "(x , y) : "; cin >> x >> y;
	point p{ x,y };
	transfoAffine tf{ 1,0,0,1,0,0 };
	tf.transforme(p);
	cout << "Point : ";
	p.affiche(cout);
}

void testAngle()
{
	double x, y;
	cout << "(x , y) : "; cin >> x >> y;
	point p{ x,y };
	point c{};
	transfoAffine tf{ c, (M_PI / 2) };
	tf.transforme(p);
	cout << "Point : ";
	p.affiche(cout);
}

void afficherPoint(point& p, int c)
{
    setcolor(c);
    circle(p.recupX(), p.recupY(), 5);
}

void testTransfoGraph()
{
    double x, y, angle;
	cout << "(x , y) et angle : "; cin >> x >> y >> angle;
	point c{ x,y }; // Centre de rotation
	opengraphsize(500,500);
	afficherPoint(c, WHITE);           // Affichage centre rotation
	cout << "(x , y) : "; cin >> x >> y;
	point p{ x,y };
	afficherPoint(p, RED);             // Affiche point P
	transfoAffine tf{c, angle};        // Transformation
	tf.transforme(p);
	afficherPoint(p, YELLOW);          // Affiche point P transformé
	getch();
	closegraph();
}

void testMystere()
{
    transfoAffine tf1{ 0.5, 0, 0, 0.5, 0, 0 };
    transfoAffine tf2{ 0.5, 0, 0, 0.5, 200, 0};
    transfoAffine tf3{ 0.5, 0, 0, 0.5, 100, 200 };
    point p{10,10};
    int it;
    cout << "nb iteration :"; cin >> it;
    opengraphsize(500,500);
    for(it ; it > 0 ; --it)
    {
        int rnb = (3*(rand() / (RAND_MAX+0.001)));
        switch(rnb)
        {
            case 0: tf1.transforme(p); plot(p.recupX(),p.recupY()); break;
            case 1: tf2.transforme(p); plot(p.recupX(),p.recupY()); break;
            case 2: tf3.transforme(p); plot(p.recupX(),p.recupY()); break;
        }
    }
   	getch();
	closegraph();
}

void tp1()
{
    cout << "Transfo Affine par defaut" << endl; testTransformationParDefaut();
	cout << "Test constructeur avec coeffs" << endl; testCoeffs();
	cout << "Test constructeur avec point et angle O" << endl; testAngle();

	//Test du cercle
	point p{50,50};
    afficherPoint(p, 3);

    //Test transformation
    testTransfoGraph();

    // Test figure mystère
    testMystere();
}

void testPrintReadTransfo()
{
    transfoAffine tf;
	cout << "[(a,b,c,d),(e,f)] : ";
	tf.read(cin);
	cout << "Affichage : ";
	tf.print(cout);
}

void translationPointT()
{
    point p{};
    cout << "Entrez un point :";
	p.lit(cin);
	transfoAffine tf{p};
	tf.transforme(p);
	cout << "Point : ";
	p.affiche(cout);
}

void translationCoeff()
{
    point p{1,1};
    double coeff;
    cout << "Entrez un coeff :"; cin>>coeff;
    transfoAffine tf{coeff};
    tf.transforme(p);
    p.affiche(cout);
}

void testMystere2()
{
    transfoAffine tf1{ 0.5, -0.5, 0.5, 0.5, 300, 100 };
    transfoAffine tf2{ -0.5, -0.5, 0.5, -0.5, 700, 200};
    point p{10,10};
    int it;
    cout << "nb iteration :"; cin >> it;
    opengraphsize(800,800);
    for(it ; it > 0 ; --it)
    {
        int rnb = (2*(rand() / (RAND_MAX+0.001)));
        switch(rnb)
        {
            case 0: tf1.transforme(p); plot(p.recupX(),p.recupY()); break;
            case 1: tf2.transforme(p); plot(p.recupX(),p.recupY()); break;
        }
    }
   	getch();
	closegraph();
}

void testMystere3()
{
    point trans1{200,0};
    point trans2{400,0};
    point c{};

    transfoAffine tf1{1/3};
    transfoAffine tf2{trans1};
    transfoAffine rot{c, M_PI/3};
    tf2 *= rot * tf1;

    transfoAffine tf3{trans2, -M_PI/3};
    tf3 *= tf2 * tf1;

    transfoAffine tf4{trans2};
    tf4 *= tf1;

    point p{110,10};
    int it;
    cout << "nb iteration :"; cin >> it;
    opengraphsize(600,500);
    for(it ; it > 0 ; --it)
    {
        int rnb = (4*(rand() / (RAND_MAX+0.001)));
        switch(rnb)
        {
            case 0: tf1.transforme(p); plot(p.recupX(),p.recupY()); break;
            case 1: tf2.transforme(p); plot(p.recupX(),p.recupY()); break;
            case 2: tf3.transforme(p); plot(p.recupX(),p.recupY()); break;
            case 4: tf4.transforme(p); plot(p.recupX(),p.recupY()); break;
        }
    }
   	getch();
	closegraph();
}


void testSurcharges()
{
    point p1;
    point p2{};
    point c{0.0 , 0.0};
	cout << "Entrez un point : ";
	p1.lit(cin);
	transfoAffine tf{c, M_PI};
	p2 = tf * p1;
	p2.affiche(cout);
}


void tp2()
{
    // Test lecture & affichage
    //testPrintReadTransfo();
    // Test translation point avec tx et ty
    //translationPointT();
    // Test affinité avec coeff
    //translationCoeff();
    // figure mystère 2
    //testMystere2();
    //testSurcharges();
    // figure mystère 3
    testMystere3();
}

int main()
{
    tp2();
}


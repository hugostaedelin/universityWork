#include <iostream>
#include "point.h"
#include <fstream>

using namespace std;


void testConstructeur()
{
    double X,Y;
    cout<<"coordonées ?";
    cin>>X>>Y;
    point p{X,Y};
    cout<<"point :"<<p.X()<<" "<<p.Y();
}

void testDeplace()
{
    point p{};
    double X,Y;
    cout<<" ",cin>>X>>Y;
    p.deplaceEn(X,Y);
    cout<<p.X()<<" "<<p.Y();
}

void testDistance()
{
    double  Xl,Yl;
    cout<<"coord ";cin>>Xl>>Yl;
    point p1{Xl,Yl};
    point p2{Xl+4,Yl+3};
    cout<<"p1p2= "<<p1.distance(p2)<<endl;
    cout<<"p2p1= "<<p2.distance(p1)<<endl;
    cout<<"p1p1= "<<p1.distance(p1)<<endl;
}


void testLit()
{
    point p;
    cout<<"Entrez un point ";
    p.lit(cin);
    cout<<"Vous avez entré :  ";
    p.affiche(cout);

}

void testFichiers()
{

    ofstream f{"test.txt"};
    point p{3.2,-4.1};
    p.affiche(f);
    f.close();

    ifstream fl("test.txt");
    p.lit(fl);
    f.close();

}


int main()
{

    testLit();

    return 0;
}

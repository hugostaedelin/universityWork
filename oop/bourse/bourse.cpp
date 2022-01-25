#include "bourse.h"
#include <iostream>
#include <vector>
using namespace std;
bourse::bourse() : d_or{0}, d_bronze{0}
{}

bourse::bourse(int piecesBronze) : d_or{0}, d_bronze{piecesBronze}
{
    convertitBronzeEnOr();
}

bourse::bourse(int piecesOr, int piecesBronze) : d_or{piecesOr}, d_bronze{piecesBronze}
{
    convertitBronzeEnOr();
}

int bourse::piecesOr() const
{
    return d_or;
}

int bourse::piecesBronze() const
{
    return d_bronze;
}

int bourse::equivalentPiecesBronze() const
{
    return {70*d_or + d_bronze};
}

void bourse::affiche(ostream& ost) const
{
    ost<<"Or : "<<d_or<<" bronze : "<<d_bronze<<endl;
}

void bourse::lit(istream& ist)
{
    string txt;
    ist>>txt>>d_or>>txt>>d_bronze;
    convertitBronzeEnOr();
}

void bourse::convertitBronzeEnOr()
{
    while(d_bronze >= 70)
    {
        d_or++;
        d_bronze -= 70;
    }
}

bourse bourse::operator+(const bourse& b) const
{
    return{d_or + b.d_or , d_bronze + b.d_bronze};
}

bourse& bourse::operator+=(const bourse& b)
{
    d_or+= b.d_or;
    d_bronze += b.d_bronze;
    convertitBronzeEnOr();
    return *this;
}

bourse bourse::operator+(int val)
{
    return{d_or, d_bronze+val};
}

bourse& bourse::operator+=(int val)
{
    d_bronze += val;
    convertitBronzeEnOr();
    return *this;
}


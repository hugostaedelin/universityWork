#include <iostream>
using namespace std;

class bourse
{
    public:
        bourse();
        bourse(int piecesBronze);
        bourse(int piecesOr, int piecesBronze);
        int piecesOr() const;
        int piecesBronze() const;
        int equivalentPiecesBronze() const;
        void affiche(ostream& ost) const;
        void lit(istream& ist);

        bourse operator+(const bourse& b) const;
        bourse& operator+=(const bourse& b);
        bourse operator+(int val);
        bourse& operator+=(int val);

    private:
        void convertitBronzeEnOr();
        int d_bronze, d_or;
};



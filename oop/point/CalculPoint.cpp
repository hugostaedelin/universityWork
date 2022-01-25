#include <iostream>
#include "point.h"
#include <vector>

vector<point> pointProchesDe(const vector<point>& P,double limite,const point& pcible)
{

    vector<point>pproches{};
    for(int i = 0;i<P.size();++i)
    {
        if(P[i].distance(pcible)<limite)
        {
            pproches.push_back(P[i]);
        }
    }

    return pproches;
    //pproches.shrink_to_fit(); --> permet de re tailler le tableau a la bonne taille (suppresion case inactive)
}

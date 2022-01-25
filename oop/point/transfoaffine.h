#ifndef TRANSFOAFFINE_H_INCLUDED
#define TRANSFOAFFINE_H_INCLUDED

#include "point.h"

class  transfoaffine{

    public:
        transfoaffine();
        void transforme(p)(point& p);


    private:
        double d_a,d_b,d_c,d_d,d_e,d_e;


};

#endif // TRANSFOAFFINE_H_INCLUDED

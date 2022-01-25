#include "transfoaffine.h"


transfoaffine::transfoaffine(): d_a{0},d_b{0},d_c{0},d_d{0},d_e{0},d_f{0}
{
}

void transforme(point& p)
{
    p.d_X = transfoaffine.d_a*p.d_X + transfoaffine.d_b*p.d_Y + transfoaffine.d_e;
    p.d_X = transfoaffine.d_c*p.d_X + transfoaffine.d_d*p.d_Y + transfoaffine.d_f;
}

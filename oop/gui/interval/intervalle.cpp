#include "intervalle.h"

intervalle::intervalle() : d_min{0.0}, d_max{0.0}
{}

intervalle::intervalle(double min, double max) : d_min{min}, d_max{max}
{}

double intervalle::max() const
{
    return d_max;
}

double intervalle::min() const
{
    return d_min;
}

void intervalle::changeMin(double min)
{
    d_min = min;
}

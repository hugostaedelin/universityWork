#include "viewport.h"
#include <cmath>

viewport::viewport()
{}
int viewport::xVersPixel(double x) const
{
    return static_cast<int>(round(d_xleft+(x-d_xmin)/d_dx));
}
double viewport::pixelVersX(int x) const
{
    return d_xmin+(x-d_xleft)*d_dx;
}
void viewport::updateDX()
{
    d_dx = (d_xmax-d_xmin)/(d_xright-d_xleft);
}
void viewport::updateDY()
{
    d_dy = (d_ymax-d_ymin)/(d_ytop-d_ybottom);
}
void viewport::changeFrameX(double xmin, double xmax)
{
    d_xmin=xmin;
    d_xmax=xmax;
    updateDX();
}
void viewport::changeFrameY(double ymin, double ymax)
{
    d_ymin=ymin;
    d_ymax=ymax;
    updateDY();
}
void viewport::changeFrame(double xmin, double xmax, double ymin, double ymax)
{
    d_xmin=xmin;
    d_xmax=xmax;
    d_ymin=ymin;
    d_ymax=ymax;
    updateDX();
    updateDY();
}
void viewport::changeWindow(int xleft, int ybottom, int xright, int ytop)
{

}
void viewport::changeWindowX(int xleft, int xright)
{

}
void viewport::changeWindowY(int ybottom, int ytop)
{

}


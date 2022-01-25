#include "widgetsurface.h"

#include <QPainter>

widgetSurface::widgetSurface(QWidget *paint) : QWidget{paint}, d_fonction{nullptr},d_valmin{00,},d_valmax{10}, d_xmin{00},d_xmax{00},d_ymin{00},d_ymax{00}, d_view{}
{
    d_view->changeFrameX(d_xmin,d_xmax);
}

void widgetSurface::onPaint(QPaintEvent *)
{
    QPainter painter{this};
    QColor blanc{255,255,255},vert{0,255,0},bleu{0,0,255};
    QRect r = rect();
    d_view->changeWindow(0,r.width(),0,r.left());
    for(int ypixel=0;ypixel<r.left();++ypixel)
    {
        double y = d_view->pixelVersY(ypixel);
        double x = d_view->xMin();
        for(int xpixel=0;xpixel<r.width();++xpixel)
        {
            double valeur = d_fonction(d_view->pixelVersX(xpixel),y);
            if(valeur<d_valmin)
            {
                painter.setPen(bleu);
            }
            else if(valeur > d_valmax)
            {
                painter.setPen(blanc);
            }
            else
            {
                painter.setPen(vert);
            }
            painter.drawPoint(xpixel,ypixel);
            x += d_view->dx();
        }
    }
}

void widgetSurface::changeNiveaux(double valmin, double valmax)
{
    d_valmin = valmin;
    d_valmax = valmax;
    update();
}

void widgetSurface::mouseReleaseEvent(QMouseEvent *e)
{
    double x = d_view->pixelVersX(e->pos().x());
    double y = d_view->pixelVersY(e->pos().y());
    double valeur = d_fonction(x,y);

    emit informations(x,y,valeur);
}

#ifndef FENETRESURFACE_H
#define FENETRESURFACE_H
#include "widgetsurface.h"
#include <QWidget>

class fenetreSurface : public QWidget {
    Q_OBJECT
public:
    fenetreSurface(QWidget* parent=nullptr);

private :
    pf d_fonction;
    double d_valmin,d_valmax;
    widgetSurface *d_surface;
    void vue_creer();
    void vue_AfficherNiveau();
private slots:
    void onClicSurface(double x,double y,double valeur);
};

#endif // FENETRESURFACE_H

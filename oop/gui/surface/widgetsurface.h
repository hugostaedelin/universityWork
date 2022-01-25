#ifndef WIDGETSURFACE_H
#define WIDGETSURFACE_H

#include "viewport.h"

#include <QMouseEvent>
#include <QWidget>

using pf = double(*)(double,double);

class widgetSurface : public QWidget
{
            Q_OBJECT
public:
  widgetSurface(QWidget *parent = nullptr);
  void changeFonction(pf);
  void changeNiveaux(double valmin,double valmax);
  void changeIntervalle(double xmin,double xmax,double ymin,double ymax);
private:
  pf d_fonction;
  double d_valmin,d_valmax;
  double d_xmin, d_xmax;
  double d_ymin,d_ymax;
  viewport* d_view;
  void onPaint(QPaintEvent *e); //méthode rappel de bas niveau
  void mouseReleaseEvent(QMouseEvent *e);
signals:
  void informations(double x , double y ,double valeur);

        };
#endif // WIDGETSURFACE_H

#ifndef INTERVALLE_H
#define INTERVALLE_H

#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>

class intervalle
{
public :
    intervalle (double min=-1.0 , double max=1.0);
    double min() const;
    void changeMin(double min);
};





#endif // INTERVALLE_H

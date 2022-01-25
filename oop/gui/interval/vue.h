#ifndef VUE_H
#define VUE_H

#include <QApplication>
#include "QMainWindow"
#include "intervalle.h"
#include "QLabel"

class vue : public QObject{
    Q_OBJECT
public:
    vue(QMainWindow *window);
    void cree();
    void afficheIntervalle(const intervalle& interv);
signals :
    void changerIntervalle();
private:
    QMainWindow *d_win;
    QLabel *d_textIntervalle;
};

#endif // VUE_H

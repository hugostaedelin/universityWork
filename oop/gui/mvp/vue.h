#ifndef VUE_H
#define VUE_H

#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <intervalle.h>

class vue: public QObject //pour qu'elle puisse émettre des objets
{
    Q_OBJECT
public:
    vue(QMainWindow* window); // pas un widget pcq sinon on ne pourra pas rajouter des menus
    void cree();
    void afficheIntervalle(const intervalle& interv);
    signals:
        void changerIntervalle();
private:
    QMainWindow *d_win;
    QLabel* d_texteIntervalle;
};

#endif // VUE_H

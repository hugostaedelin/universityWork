#include "fenetreintervalle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    intervalle t{-1.0, 1.0};
    fenetreIntervalle w{t};
    w.show();
    return a.exec();
}

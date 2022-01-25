#include "mainwindow.h"
#include "fenetrecompteur.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};
    fenetreCompteur f{};
    f.show();

    app.exec();
}

#include "fenetresurface.h"

#include <QVBoxLayout>

fenetreSurface::fenetreSurface(QWidget* parent) : QWidget{parent}
{
    vue_creer();
}

void fenetreSurface::vue_creer()
{
    d_surface = new widgetSurface{};
    auto layout = new QVBoxLayout{};
    layout->addWidget(d_surface);
    connect(d_surface,& widgetSurface::informations,this,&fenetreSurface::onClicSurface);
}

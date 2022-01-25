#include "C:\\Users\\BE-EcoTherm\\Documents\\Etudes\\2019-20\\S4\\InterfacesGraphiques\\TDpostCCI\\widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include <QLabel>








Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


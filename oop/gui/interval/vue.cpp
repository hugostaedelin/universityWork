#include "vue.h"
#include "QVBoxLayout"
#include "QPushButton"

vue::vue(QMainWindow *window) : d_win(window)
{}

void vue::cree()
{
    auto mainLayout = new QVBoxLayout{};
    d_textIntervalle = new QLabel{"(min = ,max = )"};
    mainLayout->addWidget(d_textIntervalle);
    auto boutonChange = new QPushButton{"Change"};
    mainLayout->addWidget(boutonChange);
    auto central = new QWidget{};
    central->setLayout(mainLayout);
    d_win->setCentralWidget(central);
    connect(boutonChange,&QPushButton::clicked,this,&vue::changerIntervalle);
}

void vue::afficheIntervalle(const intervalle &interv)
{
    d_textIntervalle->setText(QString{"min = %1,max = %2"}.arg(interv.min()).arg(interv.max()));
}

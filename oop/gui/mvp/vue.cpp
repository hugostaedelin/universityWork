#include "vue.h"
#include <QBoxLayout>
#include <QPushButton>
#include <intervalle.h>
#include <QString>

void vue::cree()
{
    auto mainLayout=new QVBoxLayout{};
    d_texteIntervalle=new QLabel{"(min:,max:)"};
    mainLayout -> addWidget(d_texteIntervalle);
    auto boutonChanger=new QPushButton{"Changer"};
    mainLayout -> addWidget (boutonChanger);
    auto central=new QWidget{};
    central-> setLayout (mainLayout);
    d_win -> setCentralWidget(central);
    connect(boutonChanger, &QPushButton::clicked, this, &vue::changerIntervalle);
}

void vue::afficheIntervalle(const intervalle& interv)
{
    d_texteIntervalle -> setText( QString{"(min=%1,max=%2)"},
                                   arg(interv.min()),
                                   arg(interv.max()) );
}


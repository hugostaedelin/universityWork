#include "dialogueintervalle.h"
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include <Qt>


dialogueIntervalle::dialogueIntervalle(QWidget* parent): QDialog{parent}, d_initial{}
{
    vue_creer();
    vue_afficheIntervalle(d_initial);
}

void dialogueIntervalle::vue_creer()
{
    d_min=new QLineEdit{" "};
    d_max=new QLineEdit{" "};
    auto boutonValider=new QPushButton("Valider");
    auto boutonReset=new QPushButton("Reset");
    auto boutonAnnuler=new QPushButton("Annuler");
    connect(boutonValider,&QPushButton::clicked, this, &dialogueIntervalle::onValider);
    connect(boutonReset,&QPushButton::clicked, this, &dialogueIntervalle::onReset);
    connect(boutonAnnuler,&QPushButton::clicked, this, &QDialog::reject);
}

intervalle dialogueIntervalle::getValue()const
{
    bool ok;
    double min, max;
    min = d_min->text().toDouble(&ok);
    max = d_max->text().toDouble(&ok);
    return intervalle{min,max};
}

void dialogueIntervalle::onValider()
{
    bool minOk, maxOk;
    d_min->text().toDouble(&minOk);
    d_max->text().toDouble(&maxOk);
    if(minOk && maxOk)
        //if(minOk<maxOk) normalement on aurait du etre plus precis, a faire
    {
        accept();
    }
    else
    {
        QDialog::QMessageBox(Qt::warning)
    }
}


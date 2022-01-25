#include "dialogueIntervalle.h"
#include "QMessageBox"

#include <QPushButton>

dialogueIntervalle::dialogueIntervalle(QWidget *parent)  :QDialog{parent} , d_initial{}
{
    vue_creer();
    vue_AfficherIntervalle(d_initial);
    //a écrire soit même , pareil que dans QWidget de ma main
}

void dialogueIntervalle::vue_creer()
{
    d_min = new QLineEdit{""};
    d_max= new QLineEdit{""};
    auto boutonValider = new QPushButton{"Valider"};
    auto boutonReset = new QPushButton{"Reset"};
    auto boutonAnnuler = new QPushButton{"Annuler"};

    connect(boutonValider,&QPushButton::clicked,this,&dialogueIntervalle::onValide);
    connect(boutonReset,&QPushButton::clicked,this,&dialogueIntervalle::onReset);
    connect(boutonAnnuler,&QPushButton::clicked,this,&QDialog::reject);
}

void dialogueIntervalle::vue_AfficherIntervalle(const intervalle &interv)
{
    d_min->setText(QString::number(interv.min(),'f',4));
}

intervalle dialogueIntervalle::getValue() const
{
    bool ok;
    double min,max;
    min = d_min->text().toDouble(&ok);
    max = d_max->text().toDouble(&ok);
    return intervalle{min,max};
}

void dialogueIntervalle::SetValue(const intervalle &interv)
{
    d_initial = interv;
    vue_AfficherIntervalle(d_initial);
}

void dialogueIntervalle::onReset()
{
    vue_AfficherIntervalle(d_initial);
}

void dialogueIntervalle::onValide()
{
    bool minOk,maxOk;
    d_min->text().toDouble(&minOk);
    d_max->text().toDouble(&maxOk);

    if(minOk && maxOk)
    {
        accept();
    }
    else
    {
        QMessageBox msg{QMessageBox::Warning,"Attention","pas de valeurs",QMessageBox::Ok};
    }

}

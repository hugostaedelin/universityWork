#include "fenetreIntervalle.h"
#include "QDialog"

fenetreIntervalle::fenetreIntervalle(const intervalle& interv, QWidget *parent) : QMainWindow{parent}, d_intervalle{interv}, d_vue{this}
{
    d_vue.cree();
    d_vue.afficheIntervalle(d_intervalle);
    connect(&d_vue,&vue::changerIntervalle,this,&fenetreIntervalle::onChangeIntervalle);
}

void fenetreIntervalle::onChangeIntervalle()
{
    dialogueIntervalle dialogue{};
    dialogue.SetValue(d_intervalle);
    int reponse = dialogue.exec();
    if(reponse == QDialog::Accepted)
    {
        d_intervalle= dialogue.getValue();
        d_vue.afficheIntervalle(d_intervalle);
    }
}

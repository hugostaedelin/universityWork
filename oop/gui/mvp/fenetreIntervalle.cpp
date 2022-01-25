#include "fenetreIntervalle.h"
#include <intervalle.h>
#include <QWidget>
#include <QMainWindow>

fenetreIntervalle::fenetreIntervalle(const intervalle& interv, QWidget *parent): QMainWindow{parent}, d_intervalle{interv}, d_vue{this}
{
    d_vue.cree();
    d_vue.afficheIntervalle(d_intervalle);
    connect(&d_vue, &vue::changerIntervalle, this, &fenetreIntervalle::onChangeIntervalle);
}


void fenetreIntervalle::onChangeIntervalle()
{
    dialogueIntervalle dialogue{};
    dialogue.setValue(d_intervalle);
    int reponse=dialogue.exec();
    if(reponse==QDialog::accepted)
    {
        d_intervalle=dialogue.getValue(); //le dialogue est toujours en mémoire
        d_vue.afficheIntervalle(d_intervalle);
    }
}

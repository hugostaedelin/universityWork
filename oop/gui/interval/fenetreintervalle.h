#ifndef FENETREINTERVALLE_H
#define FENETREINTERVALLE_H

#include <QApplication>
#include "intervalle.h"
#include "vue.h"
#include "dialogueIntervalle.h"

class fenetreIntervalle : public QMainWindow{
    Q_OBJECT
public :
    fenetreIntervalle(const intervalle& inter = intervalle{}, QWidget *parent=nullptr);
private :
    intervalle d_intervalle;
    vue d_vue;
private slots:
    void onChangeIntervalle();
};

#endif // FENETREINTERVALLE_H

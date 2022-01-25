#ifndef DIALOGUEINTERVALLE_H
#define DIALOGUEINTERVALLE_H

#include "QDialog"
#include "intervalle.h"
#include "QLineEdit"

class dialogueIntervalle : public QDialog{
    Q_OBJECT;
public:
    dialogueIntervalle(QWidget *parent=nullptr);
    intervalle getValue() const;
    void SetValue(const intervalle & interv);
private:
    intervalle d_initial;
    QLineEdit *d_min;
    QLineEdit *d_max;
    void vue_creer();
    void vue_AfficherIntervalle(const intervalle& interv);
private slots:
    void onValide();
    void onReset();

};

#endif // DIALOGUEINTERVALLE_H

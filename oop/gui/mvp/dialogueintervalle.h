#ifndef DIALOGUEINTERVALLE_H
#define DIALOGUEINTERVALLE_H

#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <intervalle.h>

class dialogueIntervalle: public QDialog
{
    Q_OBJECT
public:
    dialogueIntervalle(QWidget* parent=nullptr);
    intervalle getValue() const;
    void setValue(const intervalle& interv);
private:
    intervalle d_initial; //à cause de reset
    QLineEdit* d_min;
    QLineEdit* d_max;
    void vue_creer();
    void vue_afficheIntervalle(const intervalle& interv);
private slots:
    void onValider();
    void onReset();
};

#endif // DIALOGUEINTERVALLE_H

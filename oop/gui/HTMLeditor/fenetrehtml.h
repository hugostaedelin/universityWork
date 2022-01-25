#ifndef FENETREHTML_H
#define FENETREHTML_H

#include <QMainWindow>
#include "vuehtml.h"
#include "documenthtml.h"

class fenetreHTML : public QMainWindow
{
  Q_OBJECT

public:
  fenetreHTML(QWidget *parent = nullptr);
  ~fenetreHTML();
private:
  vueHTML d_vue;
  documentHTML d_texte;
};

#endif // FENETREHTML_H

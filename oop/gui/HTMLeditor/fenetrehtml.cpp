#include "fenetrehtml.h"

fenetreHTML::fenetreHTML(QWidget *parent)
  : QMainWindow{parent}, d_vue{this}, d_texte{}
{
  d_vue.creerMenus();
  d_vue.cree();
  d_texte.changeControleTexte(d_vue.controleTexte());
}

fenetreHTML::~fenetreHTML()
{

}

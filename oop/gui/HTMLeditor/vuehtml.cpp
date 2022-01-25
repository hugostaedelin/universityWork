#include "vuehtml.h"

vueHTML::vueHTML(QMainWindow *win) : d_win{win}
{
}

void vueHTML::cree()
{
  auto layout = new QVBoxLayout{};
  d_texte = new QPlainTextEdit{""};
  layout->addWidget(d_texte,1);
  auto central = new QWidget{};
  central->setLayout(layout);
  d_win->setCentralWidget(central);
  afficheNomFichier("Document.html");
}

QPlainTextEdit* vueHTML::controleTexte()
{
  return d_texte;
}

void vueHTML::afficheNomFichier(QString nom) const
{
    d_win->setWindowTitle(nom);
}

void vueHTML::creerMenus()
{
    auto menuFichier = d_win->menuBar()->addMenu("&Fichier");
    auto nouv = new QAction{"Nouveau"};
    auto open = new QAction{"Ouvrir"};
    auto save = new QAction{"Enregistrer"};
    auto saveas = new QAction{"Enregistrer sous"};
    auto quit = new QAction{"Quitter"};
    menuFichier->addAction(nouv);
    menuFichier->addSeparator();
    menuFichier->addAction(open);
    menuFichier->addAction(save);
    menuFichier->addAction(saveas);
    menuFichier->addSeparator();
    menuFichier->addAction(quit);

    connect(nouv, &QAction::triggered, this, &vueHTML::nouveau);
    connect(nouv, &QAction::triggered, this, &vueHTML::onNouveau);
    connect(quit, &QAction::triggered, this, &vueHTML::quitter);
    connect(quit, &QAction::triggered, this, &vueHTML::onQuitter);
}
void vueHTML::onNouveau()
{
    cree();
}
void vueHTML::onQuitter()
{
    d_win->close();
}

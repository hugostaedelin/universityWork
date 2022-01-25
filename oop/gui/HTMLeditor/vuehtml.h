#ifndef VUEHTML_H
#define VUEHTML_H

#include <QObject>
#include <QMainWindow>
#include <QBoxLayout>
#include <QPlainTextEdit>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

class QMainWindow;
class QPlainTextEdit;

class vueHTML : public QObject
{
  Q_OBJECT
public:
  explicit vueHTML(QMainWindow *d_win);
  void cree();
  QPlainTextEdit* controleTexte();
  void afficheNomFichier(QString nom) const;
  void creerMenus();
private:
  QMainWindow* d_win;
  QPlainTextEdit* d_texte;
signals:
  void nouveau();
  void ouvrir(QString nomfichier);
  void enregistrer(QString nomfichier);
  void enregistrerSous();
  void quitter();
private slots:
  void onQuitter();
  void onNouveau();
  //void onSave();
};

#endif // VUEHTML_H

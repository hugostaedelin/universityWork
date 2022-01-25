#ifndef DOCUMENTHTML_H
#define DOCUMENTHTML_H

#include <QString>
class QPlainTextEdit;

class documentHTML
{
public:
  documentHTML();
  static QString parDefaut();
  void changeControleTexte(QPlainTextEdit* texte);
  QString texteHTML() const;
  void changeTexteHTML(const QString& texte);
  void initialiseADocumentHTMLVide() const;
  QString nomFichier() const;
  void changeNomFichier(QString nom);
  void remetNomFichierInitial();
  bool ecritDansFichier(QString nomFichier);
private:
  QPlainTextEdit* d_texte;
  QString d_file = "Document.html";
};

#endif // DOCUMENTHTML_H

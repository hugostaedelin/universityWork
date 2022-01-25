#include "documenthtml.h"
#include <QPlainTextEdit>
#include <QTextStream>

documentHTML::documentHTML(): d_texte{nullptr}
{
}

void documentHTML::changeControleTexte(QPlainTextEdit* texte)
{
  d_texte = texte;
}

QString documentHTML::parDefaut()
{
  return "<!DOCTYPE html>\n<html>\n<head>\n<title></title>\n</head>\n<body>\n</body>\n</html>";
}

QString documentHTML::texteHTML() const
{
  return d_texte->toPlainText();
}

void documentHTML::changeTexteHTML(const QString& texte)
{
  d_texte->setPlainText(texte);
}

void documentHTML::initialiseADocumentHTMLVide() const
{
    parDefaut();
}

QString documentHTML::nomFichier() const
{
    return d_file;
}
void documentHTML::changeNomFichier(QString nom)
{
    d_file = nom;
}
void documentHTML::remetNomFichierInitial()
{
    d_file = "Document.html";
}

bool documentHTML::ecritDansFichier(QString nomFichier)
{
    QFile data{nomFichier};
    if (data.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream sout{&data};
        sout<<"texte.html";
        return sout.status() != QTextStream::WriteFailed;
    }
    else if(nomFichier.isEmpty())
    {
       return false;
       QFile data{d_file};
       if(data.open(QIODevice::WriteOnly | QIODevice::Text))
       {

       }
    }
}

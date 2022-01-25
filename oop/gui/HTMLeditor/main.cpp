#include "fenetrehtml.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a{argc, argv};
  fenetreHTML w;
  w.show();

  return a.exec();
}

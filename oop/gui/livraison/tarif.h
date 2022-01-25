#ifndef TARIF_H
#define TARIF_H

#include<iostream>
#include<string>

class livraison;

//class représentant les différents tarifs pour diverses destinations

class tarif {
public:
  tarif(const std::string& dest, double p, double pe, double pf, double pef);
  std::string destination() const;
  double prixNormal()  const;
  double prixExpress() const;
  double prixFragile() const;
  double prixExpressFragile() const;
  double prix(const livraison& l) const;
  void   print(std::ostream& ost) const;
  void   read(std::istream& ist);
private:
  std::string d_destination;
  double d_prixnormal;
  double d_prixexpress;
  double d_prixfragile;
  double d_prixexpressfragile;
};

std::ostream& operator<<(std::ostream& , const tarif& t);
std::istream& operator>(std::istream&, tarif& t);

#endif

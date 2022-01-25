#include"tarif.h"
#include"livraison.h"

tarif::tarif(const std::string& dest, double p, double pe, double pf, double pef) :
  d_destination{dest}, d_prixnormal{p}, d_prixexpress{pe},
  d_prixfragile{pf}, d_prixexpressfragile{pef}
  {}

std::string tarif::destination() const
{
    return d_destination;
}

double tarif::prixNormal()  const
{
    return d_prixnormal;
}

double tarif::prixExpress() const
{
    return d_prixexpress;
}

double tarif::prixFragile() const
{
    return d_prixfragile;
}

double tarif::prixExpressFragile() const 
{
    return d_prixexpressfragile;
}

double tarif::prix(const livraison& l) const
{
  if (l.estFragile())
  {
    if (l.estExpress()) return prixExpressFragile();
    else                return prixFragile();
  }
  else
  {
    if (l.estExpress()) return prixExpress();
    else                return prixNormal();
  }
}

void   tarif::print(std::ostream& ost) const
{
  ost<<d_destination<<' ';
  ost<<d_prixnormal<<' ';
  ost<<d_prixexpress<<' ';
  ost<<d_prixfragile<<' ';
  ost<<d_prixexpressfragile;
}

void   tarif::read(std::istream& ist)
{
  ist>>d_destination;
  ist>>d_prixnormal>>d_prixexpress>>d_prixfragile>>d_prixexpressfragile;
}

std::ostream& operator<<(std::ostream& ost, const tarif& t)
{
  t.print(ost);
  return ost;
}

std::istream& operator>(std::istream& ist, tarif& t)
{
  t.read(ist);
  return ist;
}

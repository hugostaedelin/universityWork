#ifndef LIVRAISON_H
#define LIVRAISON_H

//classe representant les options d'une livraison

class livraison {
public:
  livraison();
  bool estExpress() const;
  bool estFragile() const;
  void rendFragile(bool f =true);
  void rendExpress(bool e =true);
  void reInitialise();
private:
  bool d_fragile;
  bool d_express;
};

#endif

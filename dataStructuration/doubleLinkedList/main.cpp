#include <iostream>
using namespace std;

class ChainonDC
{
    friend class LDC;
private:
    ChainonDC(double val):v(val),suiv{nullptr},prec{nullptr}{}
    double v;
    ChainonDC *suiv;
    ChainonDC *prec;
};

class LDC
{
public:
    // Constructeur et destructeur
    LDC();
    LDC(const LDC& l);
    ~LDC();
    // Calcul de la taille
    int taille() const;
    // Insertion
    void inserer(double val);
    // Suppression
    void supprimer(double val);
    // Test d'egalite
    bool operator==(const LDC &lc) const;
    // Affectation
    LDC& operator=(const LDC &lc);
    // Inversion
    void inverser();
    // Fusion
    void fusion(const LDC &lc);
    // Acces au nieme chainon
    ChainonDC* operator[](int n);
private:
    ChainonDC *t;
};


LDC::LDC() : t{nullptr}
{}

LDC::~LDC()
{
    while(t != nullptr){
        ChainonDC* as = t;
        t = t->suiv;
        delete as;
    }
}

LDC::LDC(const LDC& l) : t{nullptr}
{
    ChainonDC* lc = l.t, *crt = nullptr, *prec = nullptr ;
    while(lc != nullptr)
    {
        crt = new ChainonDC(lc->v);
        // Cas du premier chainon (est-il existant ou pointe-t'il sur rien ?)
        if(prec == nullptr)
        {
            t = crt;
        }
        else
        {
            prec->suiv=crt;     // Liaison avec le suivant
            crt->prec = prec;   // Liaison avec le précédent
            lc=lc->suiv;     // "Incrémentation"
            prec=crt;           // Autre écriture : crt=nullptr;
        }
    }
}

int LDC::taille() const {
	int i = 0;
	ChainonDC* crt = t;
	while(crt != nullptr){
		++i;
		crt = crt->suiv;
	}
	return i;
}


void LDC::inserer(double val)
{
    ChainonDC* n = new ChainonDC(val); // Dans tous les cas, créer un chainon
    // Cas 1 : Liste vide
    if(t == nullptr){
        t = n;
        t->suiv = nullptr;
        t->prec = nullptr;
    }
    // Cas 2 : Insertion avant la tête
    else if(val < t->v)
    {
        t->prec = n; // t est relié à son précédent (n)
        n->suiv = t; // n est relié à son suivant (t)
        t = n ;      // n devient la nouvelle tête t
    }
    // Cas 3 et 4 : Insertion milieu et en queue
    else
    {
        ChainonDC* crt = t, *precC = nullptr;
        while(crt != nullptr && val > crt->v){
            precC=crt;      // precC devient l'élément courant
            crt=crt->suiv;    // "Incrémentation"
        }
        precC->suiv=n;
        n->prec=precC;
        if(crt != nullptr)
        {
            crt->prec=n;
            n->suiv=crt;
        }
    }
}

void LDC::supprimer(double val)
{
    // Cas 1 : liste vide
    if(t == nullptr){
        return;
    }
    // Cas 2 : supprimer la tête
    else if(val == t->v)
    {
        ChainonDC* as = t;
        t=t->suiv;
        if(t!=nullptr)
        {
           t->prec=nullptr;
        }
        delete as;
    }
    // Cas 3 et 4 : supprimer au milieu ou à la fin
    else
    {
        ChainonDC* crt=t, *precC = nullptr;
        while(crt!=nullptr && val < crt->v)
        {
            precC=crt;
            crt=crt->suiv;
        }
        if(crt!=nullptr && crt->v == val)
        {
            ChainonDC* suivC = crt->suiv;
            precC->suiv = suivC;
            if(suivC!=nullptr)
            {
                suivC->prec = precC;
            }
            delete crt;
        }
    }
}

// Q8 : fusionner 2 listes les valeurs doivent être classées par ordre croissant
// Question à la fin d'un examen (plus compliqué que le reste)
void LDC::fusion(const LDC &l)
{
    // En pseudo code
    // c = chainon courant de this
    // cl = chainon courant de l
    // precC = chainon précédent
    // si (c->v < cl->v)
    // alors precC = c
    // c = c->suiv
    // sinon insérer cl entre precC et c
    ChainonDC* crt = t, cl = l.t, precC = nullptr;
    while(c!=nullptr || cl!=nullptr)
    {
        // Cas 1 : Avance sur la liste lc
        if(c!=nullptr && cl!=nullptr && crt->v < cl->v)
        {
            precC=crt;
            crt=crt->suiv;
        }
        // Cas 2 : Avance sur la liste this
        else if(crt!=nullptr && cl!=nullptr && crt->v > cl->v)
        {
            ChainonDC* nc = new ChainonDC(cl->v);
            nc->suiv=crt;
            crt->prec=nc;
            if(precC==nullptr)
            {
                t=nc;
            }
            else
            {
                precC->suiv=nc;
            }
            nc->prec=precC;
            crt=crt->suiv;
        }
        else if(crt!nullptr && cl==nullptr) {}
        // Cas ou la chaine de this est vide
        else if(crt==nullptr && cl!=nullptr)
        {
            ChainonDC* nc = new ChainonDC(cl->v);
            if(precC == nullptr)
            {
                t = nc;
            }
            else
            {
                precC->suiv=nc;
                nc->prec=precC;
            }
            precC=nc;
            cl=cl->suiv;
        }
    }
}

void testAjout(LDC& e)
{
    e.inserer(44.30);
    e.inserer(33.23);
}

void testSuppression(LDC& e)
{
    e.supprimer(33.23);
}

void testTaille(LDC& e)
{
    cout<<e.taille()<<endl;
}

int main()
{
    LDC e;
    testAjout(e);
    testTaille(e);
    testSuppression(e);
    testTaille(e);
}

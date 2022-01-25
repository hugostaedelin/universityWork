#include<iostream>
using namespace std;

class ChainonSC
{
	friend class LCS;
    // Operateur (Q10)
    friend ostream& operator<<(ostream& sout, const LCS& l);
private:
	ChainonSC(double val):v(val),suiv(nullptr){}
	double v;
	ChainonSC *suiv;
};

class LCS
{
public:
	// Constructeur
	LCS();
	// Destructeur
	~LCS();
	// Calcul de la taille
	int taille() const;
	// Insertion
	void inserer(double val);
	// Suppression
	void supprimer(double val);
	// Test d'egalite
	bool operator==(const LCS &lc) const;
	// Affectation
	LCS& operator=(const LCS &lc);
	// Inversion
	void inverser();
	// Fusion
	void fusion(const LCS &lc);
	// Acces au nieme chainon
	ChainonSC* operator[](int n);
// Structure de données
private:
	ChainonSC *t;
};

// Question 1 : Écrire le constructeur et le destructeur de la classe.
//				Écrire aussi le constructeur par recopie.

// Constructeur
LCS::LCS() : t{nullptr} {}

// Destructeur
LCS::~LCS(){
	ChainonSC* c;
	c=t;
	// On gère le cas de la tête et du cas général
	while(c!=nullptr)	{
		ChainonSC* tmp=c;
		c=c->suiv;
		delete tmp;
	}
}

// Question 2 : Écrire une méthode qui retourne la taille de la liste chaînée.
// Pour retourner la taille, il va falloir parcourir la liste et compter le nb d'élément qu'elle contient.
// Donc, l'algorithme sera :
//crt = tête
//tant que crt n’est pas nul (donc ne pointe sur plus rien)
//Incrementer i par pas de 1
//crt = crt->suivant
//retourner i

int LCS::taille() const{
	int i = 0;
	ChainonSC* crt = t;
	while(crt != nullptr)	{
		++i;
		crt = crt->suiv;
	}
	return i;
}

// Question 3 : Écrire une méthode qui permet d’ajouter une valeur de type double à la liste
//				chaînée. Les valeurs doivent être classées par ordre croissant.






// Question 9 : Surchage d'opérateur operator[]
// Sera à l'examen
// Retourne le pointeur du chainon d'index n

ChainonSC* LCS::operator[](int n)
{
    int i = 0;
    ChainonSC* ctr = t;             // On créer un pointeur qui récupère la tête
    while(ctr != nullptr && ctr!=n) // Tant que l'élément (de base la tête) ne pointe pas sur rien
    {
        ++i;                // On parcours la liste
        ctr = ctr->suiv;
    }
    return ctr ;        // On retourne le chainon indexé
}

// Question 10 : Ecrire une fonction qui permet d'envoyer le contenu de la liste chaînée sur un flot
// Renvoie le contenu de la liste sur un flux
// Sera probablement aussi à l'examen

ostream& operator<<(const LCS& l, ostream& sout)
{
    ChainonSC* crt = l.t;
    while(crt != nullptr)
    {
        sout<<crt->v<<" "<<endl;
        crt=crt->suiv;
    }
    return sout;
}



int main(){
	//	v = 5
	//	suiv = null_ptr
	LCS l;
	l.inserer(5);
	// v = 5
	// suiv = 0x003
	l.inserer(10);
	// v = 10
	// suiv = null_ptr
}

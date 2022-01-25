#include <iostream>
#include <cassert>
using namespace std;

#include <stdlib.h>
#include <stdio.h>


class ChainonSC
{
	friend class LCS;
	friend ostream& operator<<(ostream& os, const LCS& l);
private:
	ChainonSC(double val):v(val),suiv(nullptr){}

	double v;
	ChainonSC *suiv;
};

class LCS  
{
public:
	friend ostream& operator<<(ostream& os, const LCS& l);

	// Constructeur
	LCS();
	// Constructeur par recopie
	LCS(const LCS &l);
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
	// Acces au ieme chainon
	ChainonSC* operator[](int i);

private:
	ChainonSC *t;
};


//////////////////////////////////////////////////////////////////////
// Question 1: Construction/Destruction
//////////////////////////////////////////////////////////////////////

LCS::LCS():t(nullptr)
{

}

LCS::LCS(const LCS &l):t(nullptr)
{
	int i=0;
	ChainonSC *lc=l.t,*prevC;
	while(lc)
	{
		ChainonSC *nc=new ChainonSC(lc->v);
		if (t==nullptr)
			t=nc;
		else
			prevC->suiv=nc;
		prevC=nc;
		lc=lc->suiv;
	}
}


LCS::~LCS()
{
	ChainonSC *c=t;
	while(c)
	{
		ChainonSC *tmp=c->suiv;
		delete c;
		c=tmp;
	}
}

/////////////////////////////////////
// Question 2: Calcul de la taille //
/////////////////////////////////////
int LCS::taille() const
{
	int i=0;
	ChainonSC *c=t;
	while(c)
	{
		i++;
		c=c->suiv;
	}
	return i;
}

///////////////////////////
// Question 3: Insertion //
///////////////////////////
void LCS::inserer(double val)
{
	ChainonSC *nc=new ChainonSC(val);
	if (t==nullptr)
	{
		t=nc;
		return;
	}
	if (nc->v<t->v)
	{
		nc->suiv=t;
		t=nc;
		return;
	}
	ChainonSC *precC=nullptr,*c=t;
	while(c!=nullptr && nc->v > c->v)
	{
		precC=c;
		c=c->suiv;
	}
	precC->suiv=nc;
	nc->suiv=c;
}

/////////////////////////////
// Question 4: Suppression //
/////////////////////////////
void LCS::supprimer(double val)
{
	// Declaraztion des pointeurs vers le chainon precedent et le courant
	ChainonSC *precC=nullptr,*c=t;

	// Cas de la liste vide
	if (t==nullptr)
		return;

	// Cas de la suppression de la tete
	if (val==t->v)
	{
		t=c->suiv;
		delete c;
		return;
	}

	// Cas de la suppression au milieu de la liste
	// On cherche d'abord le chainon
	while(c!=nullptr && c->v<val)
	{
		precC=c;
		c=c->suiv;
	}

	// On le supprime ensuite
	if (c!=nullptr && c->v==val)
	{
		precC->suiv=c->suiv;
		delete c;
	}
}

////////////////////////////////
// Question 5: Test d'egalite //
////////////////////////////////
bool LCS::operator==(const LCS &lc) const
{
	if (this==&lc)
		return true;

	ChainonSC *c1=t,*c2=lc.t;
	while (c1!=nullptr && c2!=nullptr && c1->v==c2->v)
	{
		c1=c1->suiv;
		c2=c2->suiv;
	}
	return (c1==nullptr && c2==nullptr);
}

/////////////////////////////
// Question 6: Affectation //
/////////////////////////////
LCS& LCS::operator=(const LCS &lc)
{
	if (this==&lc)
		return *this;

	ChainonSC *c1=t,*precC1=nullptr,*c2=lc.t;
	while (c1!=nullptr && c2!=nullptr)
	{
		c1->v=c2->v;
		precC1=c1;
		c1=c1->suiv;
		c2=c2->suiv;
	}
	if (c1!=nullptr)
	{
		if (precC1!=nullptr)
			precC1->suiv=nullptr;
		else
			t=nullptr;
		while(c1)
		{
			precC1=c1;
			c1=c1->suiv;
			delete precC1;
		}
	}
	else if (c2!=nullptr)
	{
		while(c2!=nullptr)
		{
			c1=new ChainonSC(c2->v);
			if (precC1==nullptr)
				t=c1;
			else
				precC1->suiv=c1;
			precC1=c1;
			c2=c2->suiv;
		}
	}
	return *this;
}

///////////////////////////
// Question 7: Inversion //
///////////////////////////
void LCS::inverser()
{
	if (t==nullptr)
		return;
	if (t->suiv==nullptr)
		return;

	ChainonSC *c1=t,*c2=c1->suiv,*c3=c2->suiv;
	c1->suiv=nullptr;
	while(c2!=nullptr)
	{
		c3=c2->suiv;
		c2->suiv=c1;
		c1=c2;
		c2=c3;
	}
	t=c1;
}

////////////////////////
// Question 8: Fusion //
////////////////////////
void LCS::fusion(const LCS &lc)
{
	ChainonSC *c1=t,*precC1=nullptr,*c2=lc.t;

	while(c1!=nullptr && c2!=nullptr)
	{
		if (c1->v<c2->v)
		{
			precC1=c1;
			c1=c1->suiv;
		}
		else
		{
			ChainonSC *nc=new ChainonSC(c2->v);
			if (precC1==nullptr)
				t=nc;
			else
				precC1->suiv=nc;
			precC1=nc;
			nc->suiv=c1;
			c2=c2->suiv;
		}
	}
	
	while (c1==nullptr && c2!=nullptr)
	{
		ChainonSC *nc=new ChainonSC(c2->v);
		if (precC1==nullptr)
			t=nc;
		else
			precC1->suiv=nc;
		precC1=nc;
		c2=c2->suiv;
	}

}

///////////////////////////////////////
// Question 9: Acces au ieme chainon //
///////////////////////////////////////
ChainonSC* LCS::operator[](int i)
{
	ChainonSC *c=t;
	int idx=0;
	while(idx<i && c!=nullptr)
	{
		idx++;
		c=c->suiv;
	}
	return c;
}

ostream& operator<<(ostream& os, const LCS& l) 
{
	ChainonSC *c=l.t;
	while(c!=nullptr)
	{
		os << c->v << '\t';
		c=c->suiv;
	}
	os << endl;
    return os;
}


int main()
{

	LCS lc1,lc2;

	lc1.inserer(2);
	lc1.inserer(4);
	lc1.inserer(8);
	lc1.inserer(0);
	lc1.inserer(6);

	lc1.inverser();
	lc1.inverser();

	lc1.fusion(lc2);
	lc2.fusion(lc1);


	lc2.supprimer(0);
	lc2.supprimer(8);
	lc2.supprimer(4);
	lc2.supprimer(2);
	lc2.supprimer(6);

	LCS lc3(lc1);
	cout<<lc3;

//	lc1=lc2;
//	lc2=lc1;

	lc2.inserer(1);
	lc2.inserer(3);
	lc2.inserer(5);
	bool test=(lc1==lc2);

//	lc1.fusion(lc2);
//	lc2.fusion(lc1);
//	lc1=lc2;
	lc2=lc1;
	test=(lc1==lc2);


}
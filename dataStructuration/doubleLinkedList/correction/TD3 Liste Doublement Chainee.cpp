#include <stdlib.h>
#include <stdio.h>

class ChainonDC
{
	friend class LDC;
private:
	ChainonDC(double val):v(val),suiv(nullptr),prec(nullptr){}

	double v;
	ChainonDC *suiv;
	ChainonDC *prec;
};

class LDC  
{
public:
	// Constructeur et destructeur
	LDC();
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
	// Acces au ieme chainon
	ChainonDC* operator[](int i);

private:
	ChainonDC *t;
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LDC::LDC():t(nullptr)
{

}

LDC::~LDC()
{
	while(t)
	{
		ChainonDC *tmp=t->suiv;
		delete t;
		t=tmp;
	}
}

/////////////////////////
// Calcul de la taille //
/////////////////////////
int LDC::taille() const
{
	int i=0;
	ChainonDC *c=t;
	while(c)
	{
		i++;
		c=c->suiv;
	}
	return i;
}

///////////////
// Insertion //
///////////////
void LDC::inserer(double val)
{
	ChainonDC *nc=new ChainonDC(val);
	if (t==nullptr)
	{
		t=nc;
		return;
	}
	if (nc->v<t->v)
	{
		nc->suiv=t;
		t->prec=nc;
		t=nc;
		return;
	}
	ChainonDC *precC=nullptr,*c=t;
	while(c!=nullptr && nc->v > c->v)
	{
		precC=c;
		c=c->suiv;
	}
	precC->suiv=nc;
	nc->prec=precC;
	nc->suiv=c;
	if (c!=nullptr)
		c->prec=nc;
}

/////////////////
// Suppression //
/////////////////
void LDC::supprimer(double val)
{
	ChainonDC *precC=nullptr,*c=t;
	while(c!=nullptr && c->v<val)
	{
		precC=c;
		c=c->suiv;
	}
	if (c!=nullptr && c->v==val)
	{
		if (precC!=nullptr)
		{
			precC->suiv=c->suiv;
			if (c->suiv!=nullptr)
				c->suiv->prec=precC;
		}
		else
		{
			t=c->suiv;
			if (t)
				t->prec=nullptr;
		}
		delete c;
	}
}

////////////////////
// Test d'egalite //
////////////////////
bool LDC::operator==(const LDC &lc) const
{
	if (this==&lc)
		return true;

	ChainonDC *c1=t,*c2=lc.t;
	while (c1!=nullptr && c2!=nullptr && c1->v==c2->v)
	{
		c1=c1->suiv;
		c2=c2->suiv;
	}
	return (c1==nullptr && c2==nullptr);
}

/////////////////
// Affectation //
/////////////////
LDC& LDC::operator=(const LDC &lc)
{
	if (this==&lc) 	return *this;

	ChainonDC *c1=t,*precC1=nullptr,*c2=lc.t;
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
			c1=new ChainonDC(c2->v);
			if (precC1==nullptr)
				t=c1;
			else
			{
				precC1->suiv=c1;
				c1->prec=precC1;
			}
			precC1=c1;
			c2=c2->suiv;
		}
	}
	return *this;
}

///////////////
// Inversion //
///////////////
void LDC::inverser()
{
	if (t==nullptr)
		return;
	if (t->suiv==nullptr)
		return;

	ChainonDC *c1=t,*c2=c1->suiv,*c3=c2->suiv;
	c1->suiv=nullptr;
	while(c2!=nullptr)
	{
		c3=c2->suiv;
		c2->suiv=c1;
		c1->prec=c2;
		c1=c2;
		c2=c3;
	}
	c1->prec=nullptr;
	t=c1;
}


////////////
// Fusion //
////////////
void LDC::fusion(const LDC &lc)
{
	ChainonDC *c1=t,*precC1=nullptr,*c2=lc.t;

	while(c1!=nullptr && c2!=nullptr)
	{
		if (c1->v<c2->v)
		{
			precC1=c1;
			c1=c1->suiv;
		}
		else
		{
			ChainonDC *nc=new ChainonDC(c2->v);
			if (precC1==nullptr)
				t=nc;
			else
			{
				precC1->suiv=nc;
				nc->prec=precC1;
			}
			precC1=nc;
			nc->suiv=c1;
			c1->prec=nc;
			c2=c2->suiv;
		}
	}
	
	while (c1==nullptr && c2!=nullptr)
	{
		ChainonDC *nc=new ChainonDC(c2->v);
		if (precC1==nullptr)
			t=nc;
		else
		{
			precC1->suiv=nc;
			nc->prec=precC1;
		}
		precC1=nc;
		c2=c2->suiv;
	}
}

///////////////////////////
// Acces au ieme chainon //
///////////////////////////
ChainonDC* LDC::operator[](int i)
{
	ChainonDC *c=t;
	int idx=0;
	while(idx<i && c!=nullptr)
	{
		idx++;
		c=c->suiv;
	}
	return c;
}

int main()
{

	LDC lc1,lc2;

	lc1.inserer(2);
	lc1.inserer(4);
	lc1.inserer(8);
	lc1.inserer(0);
	lc1.inserer(6);
	ChainonDC* c=lc1[0];

	lc1.inverser();
	lc1.inverser();

	lc1.fusion(lc2);
	lc2.fusion(lc1);

	lc2=lc1;
	lc2.supprimer(0);
	lc2.supprimer(8);
	lc2.supprimer(4);
	lc2.supprimer(2);
	lc2.supprimer(6);

//	lc1=lc2;
//	lc2=lc1;

	lc2.inserer(1);
	lc2.inserer(3);
	lc2.inserer(5);
	bool test=(lc1==lc2);

//	lc1.fusion(lc2);
	lc2.fusion(lc1);
	lc1=lc2;
//	lc2=lc1;
	test=(lc1==lc2);

}
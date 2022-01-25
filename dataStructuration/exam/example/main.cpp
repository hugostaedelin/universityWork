#include <iostream>
#include <cstdlib>

using namespace std;

class Chainon;

class Image
{
	friend ostream& operator<< (ostream& os, const Image& im);

private:
	int d_nbl,d_nbc;		// Nombres de lignes et colonnes
	Chainon *d_tete;		// Pointeur sur le premier chainon (qui
							// correspond au coin supérieur gauche)
public:
	Image(int nbl,int nbc);					// Question 1
	Image(bool **tab, int nbl, int nbc);	// Question 2
	~Image();
	Image& operator=(const Image& im);
	double indiceDeCompression() const;
	int nbPointsBlancs() const;
	void insererLigne(int ligne);
	void insererUnPointAvant(Chainon* ch);
	void insererUnPointApres(Chainon* ch);
	void insererUnPointAuMilieu(Chainon* ch,int idx);
	void insererColonne(int colonne);
	void metPointEnNoir(int l, int c);
};

class Chainon
{
	friend class Image;
	friend ostream& operator<< (ostream& os, const Image& im);
private:
	bool d_coul;		// Couleur (false pour blanc, true pour noir)
	int d_nb;			// Nombre de points de meme couleur
	Chainon* d_suiv;	// Le chainon suivant
	Chainon* d_prec;	// Le chainon precedent
};

////////////////
// Question 1 //
////////////////
Image::Image(int nbl, int nbc):d_nbl{nbl},d_nbc{nbc},d_tete{new Chainon()}
{
	d_tete->d_prec=nullptr;
	d_tete->d_suiv=nullptr;
	d_tete->d_coul=false;
	d_tete->d_nb=nbl*nbc;
}


////////////////
// Question 2 //
////////////////
Image::Image(bool **tab, int nbl, int nbc):d_nbl{nbl},d_nbc{nbc},d_tete{new Chainon()}
{
	d_tete->d_prec=nullptr;
	d_tete->d_suiv=nullptr;
	d_tete->d_coul=tab[0][0];
	d_tete->d_nb=1;
	Chainon *chainon=d_tete;

	for (int i=1;i<d_nbl*d_nbc;i++)
	{
		int c=i%d_nbc;
		int l=(i-c)/d_nbl;
		if (chainon->d_coul==tab[l][c])
			chainon->d_nb++;
		else
		{
			Chainon *tmp=new Chainon();
			tmp->d_suiv=nullptr;
			tmp->d_prec=chainon;
			chainon->d_suiv=tmp;
			chainon=tmp;
			chainon->d_coul=tab[l][c];
			chainon->d_nb=1;
		}
	}
}

////////////////
// Question 3 //
////////////////
Image::~Image()
{
	while(d_tete)
	{
		Chainon *tmp=d_tete->d_suiv;
		delete d_tete;
		d_tete=tmp;
	}
}

////////////////
// Question 4 //
////////////////
ostream& operator<< (ostream& os, const Image& im)
{
	Chainon *tmp=im.d_tete;
	int idx=0;
	while(tmp)
	{
		for (int i=0;i<tmp->d_nb;i++)
		{
			if (tmp->d_coul)
				os<<'x';
			else
				os<<' ';
			int c=idx%im.d_nbc;
			if (c==im.d_nbc-1)
				os<<endl;
			idx++;
		}
		tmp=tmp->d_suiv;
	}

	return os;
}

////////////////
// Question 5 //
////////////////
Image &Image::operator=(const Image& im)
{
	if (this==&im)
		return *this;

	Chainon *tmp1=d_tete,*prevTmp1=nullptr,*tmp2=im.d_tete;
	while(tmp1 && tmp2)
	{
		tmp1->d_coul=tmp2->d_coul;
		tmp1->d_nb=tmp2->d_nb;
		prevTmp1=tmp1;
		tmp1=tmp1->d_suiv;
		tmp2=tmp2->d_suiv;
	}
	if (!tmp1 && tmp2)
	{
		while (tmp2)
		{
			tmp1=new Chainon();
			tmp1->d_suiv=nullptr;
			tmp1->d_coul=tmp2->d_coul;
			tmp1->d_nb=tmp2->d_nb;
			if (prevTmp1)
			{
				prevTmp1->d_suiv=tmp1;
				tmp1->d_prec=prevTmp1;
			}
			else
			{
				d_tete=tmp1;
				tmp1->d_prec=nullptr;
			}
			prevTmp1=tmp1;
			tmp2=tmp2->d_suiv;
		}
	}
	else if (tmp1 && !tmp2)
	{
		if (prevTmp1)
			prevTmp1->d_suiv=nullptr;
		else
			d_tete=nullptr;
		while(tmp1)
		{
			prevTmp1=tmp1;
			tmp1=tmp1->d_suiv;
			delete prevTmp1;
		}
	}
	d_nbl=im.d_nbl;
	d_nbc=im.d_nbc;

	return *this;
}

////////////////
// Question 6 //
////////////////
double Image::indiceDeCompression() const
{
	int c=0;
	Chainon *tmp=d_tete;
	while(tmp)
	{
		c++;
		tmp=tmp->d_suiv;
	}
	return static_cast<double>(d_nbl*d_nbc)/static_cast<double>(c);
}

////////////////
// Question 7 //
////////////////
int Image::nbPointsBlancs() const
{
	int c=0;
	Chainon *tmp=d_tete;
	while(tmp)
	{
		if (!tmp->d_coul)
			c+=tmp->d_nb;
		tmp=tmp->d_suiv;
	}
	return c;
}


//////////////////////////////////////////////////////////////
// Question 8												//
// L'image est composee d'au moins une ligne et une colonne //
//////////////////////////////////////////////////////////////
void Image::insererLigne(int ligne)
{
	if (ligne==0)
	{
		// Cas de l'insertion a la ligne 0
		if (d_tete->d_coul)
			d_tete->d_nb+=d_nbc;
		else
		{
			Chainon *c=new Chainon();
			c->d_suiv=d_tete;
			c->d_prec=nullptr;
			d_tete->d_prec=c;
			d_tete=c;
			c->d_nb=d_nbc;
			c->d_coul=true;
		}
	}
	else if (ligne==d_nbl)
	{
		// Cas de l'insertion a la ligne d_nbl
		// Cherche le dernier chainon
		Chainon *tmp=d_tete;
		while(tmp->d_suiv)
			tmp=tmp->d_suiv;
		if (tmp->d_coul)
			tmp->d_nb+=d_nbc;
		else
		{
			Chainon *c=new Chainon();
			c->d_suiv=nullptr;
			c->d_prec=tmp;
			tmp->d_suiv=c;
			c->d_nb=d_nbc;
			c->d_coul=true;
		}
	}
	else
	{
		// Deplacement au chainon correspondant au debut de la ligne
		Chainon *tmp=d_tete;
		int nbPts=tmp->d_nb;
		while(tmp && nbPts<ligne*d_nbc)
		{
			tmp=tmp->d_suiv;
			nbPts+=tmp->d_nb;
		}
		if (nbPts==ligne*d_nbc)
		{
			// Debut de ligne correspond au debut du chainon
			if (tmp->d_coul)
				tmp->d_nb+=d_nbc;
			else
				tmp->d_prec->d_nb+=d_nbc;
		}
		else
		{
			// Debut de ligne se trouve au milieu d'un chainon
			if (tmp->d_coul)
				// Chainon de meme couleur
				tmp->d_nb+=d_nbc;
			else
			{
				// Chainon de couleur differente
				Chainon *c1=new Chainon;
				c1->d_suiv=tmp->d_suiv;
				tmp->d_suiv->d_prec=c1;
				c1->d_coul=tmp->d_coul;
				c1->d_nb=nbPts-ligne*d_nbc;
				tmp->d_nb-=c1->d_nb;
				Chainon *c2=new Chainon;
				c2->d_prec=tmp;
				tmp->d_suiv=c2;
				c2->d_suiv=c1;
				c1->d_prec=c2;
				c2->d_coul=true;
				c2->d_nb=d_nbc;
			}
		}
	}
	d_nbl++;
}

////////////////
// Question 9 //
////////////////
void Image::insererUnPointAvant(Chainon* ch)
{
	if (ch->d_coul)
	{
		ch->d_nb++;
		return;
	}

	// Insertion du point avant le chainon
	if (ch->d_prec)
		ch->d_prec->d_nb++;
	else
	{
		Chainon *nc=new Chainon;
		nc->d_coul=true;
		nc->d_nb=1;
		nc->d_prec=nullptr;
		nc->d_suiv=ch;
		ch->d_prec=nc;
		d_tete=nc;
	}
}

void Image::insererUnPointApres(Chainon* ch)
{
	if (ch->d_coul)
	{
		ch->d_nb++;
		return;
	}
	// Insertion du point a la fin du chainon
	if (ch->d_suiv)
		ch->d_suiv->d_nb++;
	else
	{
		Chainon *nc=new Chainon;
		nc->d_coul=false;
		nc->d_nb=ch->d_nb;
		nc->d_prec=ch->d_prec;
		nc->d_suiv=ch;

		ch->d_prec=nc;
		ch->d_coul=true;
		ch->d_nb=1;
	}
}

void Image::insererUnPointAuMilieu(Chainon* ch,int idx)
{
	if (ch->d_coul)
	{
		ch->d_nb++;
		return;
	}

	// Insertion du point au milieu du chainon
	Chainon *nc1=new Chainon;
	Chainon *nc2=new Chainon;

	nc1->d_coul=false;
	nc1->d_nb=ch->d_nb-(ch->d_nb-idx);
	nc2->d_coul=true;
	nc2->d_nb=1;

	ch->d_nb=ch->d_nb-nc1->d_nb;

	nc1->d_prec=ch->d_prec;
	if (nc1->d_prec)
		nc1->d_prec->d_suiv=nc1;
	else
		d_tete=nc1;
	nc1->d_suiv=nc2;
	nc2->d_prec=nc1;
	nc2->d_suiv=ch;
	ch->d_prec=nc2;
}


void Image::insererColonne(int colonne)
{
	// Cherche le chainon contenant le point
	Chainon *tmp=d_tete,*prevTmp=nullptr;
	int l=0;
	int ptIdx=tmp->d_nb;
	while(tmp)
	{
		while(l*d_nbc+colonne<ptIdx)
		{
			if (l*d_nbc+colonne==ptIdx-tmp->d_nb)
				insererUnPointAvant(tmp);
			else
				insererUnPointAuMilieu(tmp,(l*d_nbc+colonne)-(ptIdx-tmp->d_nb));
			l++;
		}
		prevTmp=tmp;
		tmp=tmp->d_suiv;
		if (tmp)
			ptIdx+=tmp->d_nb;
	}
	if ((d_nbl-1)*d_nbc+colonne==ptIdx)
	{
		// Cas du dernier point
		insererUnPointApres(prevTmp);
	}
	d_nbc++;
}


/////////////////
// Question 10 //
/////////////////
void Image::metPointEnNoir(int l, int c)
{
	// Cherche le chainon contenant le point
	Chainon *tmp=d_tete;
	int ptIdx=tmp->d_nb;
	while(l*d_nbc+c>=ptIdx && tmp)
	{
		tmp=tmp->d_suiv;
		ptIdx+=tmp->d_nb;
	}
	// Si le point est deja noir, il n'y a rien a faire
	if (tmp->d_coul)
		return;

	// Si le point noir est le premier point du chainon
	if (l*d_nbc+c==ptIdx-tmp->d_nb)
	{
		tmp->d_nb--;
		if (tmp->d_prec==nullptr)
		{
			// Insertion du chainon en tete
			Chainon *ch=new Chainon;
			ch->d_prec=nullptr;
			ch->d_suiv=tmp;
			tmp->d_prec=ch;
			d_tete=ch;
			ch->d_coul=true;
			ch->d_nb=1;
		}
		else
			tmp->d_prec->d_nb++;
	}
	// Si le point noir est le dernier point du chainon
	else if (l*d_nbc+c==ptIdx-1)
	{
		tmp->d_nb--;
		if (tmp->d_suiv==nullptr)
		{
			// Insertion du chainon a la fin
			Chainon *ch=new Chainon;
			ch->d_suiv=nullptr;
			ch->d_prec=tmp;
			tmp->d_suiv=ch;
			ch->d_coul=true;
			ch->d_nb=1;
		}
		else
			tmp->d_suiv->d_nb++;
	}
	// S'il est au milieu du chainon
	else
	{
		Chainon *ch1=new Chainon;
		Chainon *ch2=new Chainon;
		ch1->d_nb=1;
		ch1->d_coul=true;
		ch2->d_nb=ptIdx-(l*d_nbc+c)-1;
		ch2->d_coul=false;

		tmp->d_nb=tmp->d_nb-(ch1->d_nb+ch2->d_nb);
		ch2->d_suiv=tmp->d_suiv;
		tmp->d_suiv=ch1;
		ch1->d_prec=tmp;
		ch1->d_suiv=ch2;
		ch2->d_prec=ch1;
	}
}

int main(int argc, char *argv[])
{
	// Pour le debugage
	bool tmp[5][6]={{false,false,false,false,false,false},
					{true, true, true, true, false,true},
					{true, true, true, false,false,false},
					{false,false,false,false,false,false},
					{false,false,false,true, true ,true }};
	bool **tab=new bool*[5];
	for (int i=0;i<5;i++)
	{
		tab[i]=new bool[6];
		for (int j=0;j<6;j++)
            tab[i][j]=tmp[i][j];
	}

	Image im(tab,5,6);
	Image im2(2,2);
	im2=im;
	cout<<im<<"-"<<endl;

	cout<<"Indice de compression: "<<im.indiceDeCompression()<<endl;
	cout<<"Nb points blancs: "<<im.nbPointsBlancs()<<endl;

/*	im.insererLigne(0);
	im.insererLigne(0);
	cout<<im<<"-"<<endl;

	im.insererLigne(7);
	cout<<im<<"-"<<endl;
	im.insererLigne(7);
	cout<<im<<"-"<<endl;

	im.insererLigne(4);
	cout<<im<<"-"<<endl;

	im.insererLigne(2);
	cout<<im<<"-"<<endl;*/

/*	cout<<endl<<"-------------"<<endl;
	cout<<im<<"-------------"<<endl;
	im.metPointEnNoir(0,0);
	cout<<im<<"-------------"<<endl;
	im.metPointEnNoir(4,5);
	cout<<im<<"-------------"<<endl;
	im.metPointEnNoir(2,3);
	cout<<im<<"-------------"<<endl;
	im.metPointEnNoir(0,5);
	cout<<im<<"-------------"<<endl;
	im.metPointEnNoir(4,0);
	cout<<im<<"-------------"<<endl;*/

	cout<<im<<"-------------"<<endl;
	im.insererColonne(6);
	cout<<im<<"-------------"<<endl;

}

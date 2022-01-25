#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void genereCarres(int n, const string &nomFichier)
{
	ofstream f(nomFichier);
	f << "P3" << endl;
	f << 2*n << "  " << 2*n << endl;
	f << "255" << endl;

    string couleur1 = "255 0 0 ";   //Rouge
    string couleur2 = "0 255 0 ";   //Vert
    string couleur3 = "0 0 255 ";   //Bleu
    string couleur4 = "255 255 0 "; //Jaune

	//Boucle de ligne
	for(int i = 0; i<n; i++)
	{
		//Boucle pour rouge
		for(int j = 0; j < n; j++)
		{
			f<< couleur1;
		}
		//Boucle pour vert
		for(int j = 0; j < n; j++)
		{
			f<<couleur2;
		}
		f << endl;
	}

    //Boucle de ligne
	for(int i = 0 ; i<n; i++)
	{
		//Boucle pour bleu
		for(int j = 0; j < n; j++)
		{
			f<< couleur3;
		}
		//Boucle pour jaune
		for(int j = 0; j < n; j++)
		{
			f<<couleur4;
		}
	f << endl;
	}
}


bool niveauDeGris(const string &nomFichierIN, const string &nomFichierOUT)
{
	ifstream f1(nomFichierIN);
	if(!f1) return false;
	ofstream f2(nomFichierOUT);
	string type, valMax;
	int largeur, hauteur, valeur1, valeur2, valeur3, niveau;
	f1 >> type >>largeur >> hauteur >> valMax;
	f2 << type << endl << largeur << "  " << hauteur << endl << valMax << endl;

    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            f1 >> valeur1 >> valeur2 >> valeur3;
            niveau = valeur1*0.2126 + valeur2*0.7152 + valeur3*0.0722;
            f2 << niveau << " " << niveau << " " << niveau << " ";
        }
        f2 << endl;
	}
}

bool extraction(const string &nomFichierIN, const string &nomFichierOUT, int l1, int l2, int c1, int c2)
{
	ifstream in(nomFichierIN);
	ofstream out(nomFichierOUT);
    if(in && out)
    {
        string type;
        int largeur, longueur, maxi, skip, r, g, b;
        in>> type >> largeur >> longueur >>maxi;
        out << type << endl << c2-c1+1 << " " << l2-l1+1 << endl << maxi << endl;

        for(int i = 0; i <l1; i++)
        {
            for(int j = 0; j<largeur*3;j++)
            {
                in >> skip;
            }
        }
        for(int i = l1; i<=l2;i++)
        {
            for(int j = 0; j<c1*3;j++)
            {
                in >> skip;
            }
            for(int j = c1; j<=c2;j++)
            {
                in >> r >> g >> b;
                out << r << " " << g << " " << b << " ";
            }
            out << endl;
            for(int j = (c2+1)*3; j<largeur*3;j++)
            {
                in >> skip;
            }
        }
        return true;
    }
    return false;
}

struct pixel
{
    int r, g, b;
};

bool symetrie(const string &nomFichierIN, const string nomFichierOUT)
{
    ifstream in(nomFichierIN);
    ofstream out(nomFichierOUT);
    if(!in && !out)
        return false;
    string type;
    int largeur, hauteur, maxi;
    in >> type >> largeur >> hauteur >> maxi;
    out << type << endl << largeur << " " << hauteur << endl << maxi << endl;
    vector<pixel> T(largeur);
    for(int i =0; i< hauteur;i++)
    {
        for(int j = 0;j<largeur;j++)
        {
            in >> T[j].r >> T[j].g >> T[j].b;
        }
        for(int j = largeur-1;j>=0;j--)
        {
            out << T[j].r << " " << T[j].g << " " << T[j].b << " ";
        }
        out << endl;
    }
    return true;
}

bool rotation(const string &nomFichierIN, const string nomFichierOUT)
{
    ifstream in(nomFichierIN);
    ofstream out(nomFichierOUT);
    if(!in && !out)
        return false;
    string type;
    int largeur, hauteur, maxi;
    in >> type >> largeur >> hauteur >> maxi;
    out << type << endl << hauteur << " " << largeur << endl << maxi << endl;
    vector<vector<pixel> >  T ( hauteur, vector<pixel>( largeur) );
    for(int l = 0; l < hauteur; l++)
    {
        for(int c = 0; c < largeur; c++)
        {
            in >> T[l][c].r >> T[l][c].g >> T[l][c].b;
        }
    }
    for(int c = largeur - 1; c >= 0; c--)
    {
        for(int l = 0; l < hauteur; l++)
        {
            out << T[l][c].r << " " << T[l][c].g << " " << T[l][c].b << " ";
        }
        out << endl;
    }
}

bool negatif(const string &nomFichierIN, const string &nomFichierOUT)
{
	ifstream f1(nomFichierIN);
	if(!f1) return false;
	ofstream f2(nomFichierOUT);
	string type, valMax;
	int largeur, hauteur, valeur1, valeur2, valeur3, moyenne;
	f1 >> type >>largeur >> hauteur >> valMax;
	f2 << type << endl << largeur << "  " << hauteur << endl << valMax << endl;

    for(int j = 0; j < hauteur; j++)
    {
        for(int i = 0; i < largeur; i++)
        {
            f1 >> valeur1 >> valeur2 >> valeur3;
            f2 << 255 - valeur1 << " " << 255 -valeur2 << " " << 255 - valeur3 << " ";
        }
        f2 << endl;
    }
}

bool miseEnEvidence(const string &nomFichierIN, const string &nomFichierOUT)
{
	ifstream f1(nomFichierIN);
	if(!f1) return false;
	ofstream f2(nomFichierOUT);
	string type, valMax;
	int largeur, hauteur, valeur1, valeur2, valeur3, moyenne;
	f1 >> type >>largeur >> hauteur >> valMax;
	f2 << type << endl << largeur << "  " << hauteur << endl << valMax << endl;

    for(int j = 0; j < hauteur; j++)
    {
        for(int i = 0; i < largeur; i++)
        {
            f1 >> valeur1 >> valeur2 >> valeur3;
            if(valeur1 > valeur2*1.3 && valeur1 > valeur3*1.3)
                f2 << valeur1 << " " << valeur2 << " " << valeur3 << " ";
            else
            {
                moyenne = valeur1*0.2126 + valeur2*0.7152 + valeur3*0.0722;
                f2 << moyenne << " " << moyenne << " " << moyenne << " ";
            }
        }
        f2 << endl;
    }
}

bool zoom(const string&nomFichierIN, const string &nomFichierOUT)
{
    ifstream f1(nomFichierIN);
    ofstream f2(nomFichierOUT);
    if(!f1||!f2)
    {
        return false;
    }
    int l, h;
    string chaine;
    f1>>chaine>>l>>h>>chaine;
    f2<<"P3"<<endl<<(l*2)-1<<" "<<(h*2)-1<<endl<<chaine<<endl;
    vector<vector<pixel>> T(l, vector<pixel>(h)); //wahou !
    //enregistrement de toutes les donnees dans un vecteur
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<l;j++)
        {
            f1 >> T[j][i].r >> T[j][i].g >> T[j][i].b;
        }
    }
    //pour chaque colonne
    for(int j=0;j<h-1;j++)
    {
        //agrandir la ligne ou on a les infos
        for(int i=0;i<l-1;i++)
        {
            f2<<T[i][j].r<<" "<<T[i][j].g<<" "<<T[i][j].b<<" ";
            f2<<(T[i][j].r+T[i+1][j].r)/2<<" "<<(T[i][j].g+T[i+1][j].g)/2<<" "<<(T[i][j].b+T[i+1][j].b)/2<<" ";
        }
        //ajouter la dernière case
        f2<<T[l-1][j].r<<" "<<T[l-1][j].g<<" "<<T[l-1][j].b<<endl;
        //ligne intermediaire
        for(int i=0;i<l-1;i++)
        {
            f2<<(T[i][j].r+T[i][j+1].r)/2<<" "<<(T[i][j].g+T[i][j+1].g)/2<<" "<<(T[i][j].b+T[i][j+1].b)/2<<" ";
            f2<<(T[i][j].r+T[i][j+1].r+T[i+1][j].r+T[i+1][j+1].r)/4<<" "<<(T[i][j].g+T[i][j+1].g+T[i+1][j].g+T[i+1][j+1].g)/4<<" "<<(T[i][j].b+T[i][j+1].b+T[i+1][j].b+T[i+1][j+1].b)/4<<" ";
        }
        //ajouter la dernière case
        f2<<(T[l-1][j].r+T[l-1][j+1].r)/2<<" "<<(T[l-1][j].g+T[l-1][j+1].g)/2<<" "<<(T[l-1][j].b+T[l-1][j+1].b)/2<<endl;
    }
    //derniere ligne
    for(int i=0;i<l-1;i++)
    {
        f2<<T[i][h-1].r<<" "<<T[i][h-1].g<<" "<<T[i][h-1].b<<" ";
        f2<<(T[i][h-1].r+T[i+1][h-1].r)/2<<" "<<(T[i][h-1].g+T[i+1][h-1].g)/2<<" "<<(T[i][h-1].b+T[i+1][h-1].b)/2<<" ";
    }
    //ajouter la dernière case
    f2<<T[l-1][h-1].r<<" "<<T[l-1][h-1].g<<" "<<T[l-1][h-1].b;
}


/*
void echange(const string&nomFichierIN, const string &nomFichierOUT)
{
    ifstream fin(nomFichierIN);
    ofstream fout(nomFichierOUT);
        int r,g,b,maxi,largeur,hauteur;
        string format;
        fin>>format>>largeur>>hauteur>>maxi;
        fout<<format<<endl<<largeur<<" "<<hauteur<<endl<<maxi<<endl;
        for(int i = 0 ; i < hauteur ; i++)
        {
            for(int j = largeur/2 ; j < largeur; j++)
            {
                fin>>r>>g>>b;
                for(int k = 0 ; k < largeur/2; k++)
                {
                    fout<<r<<" "<<g<<" "<<b<<" ";
                }
                fout << endl;
            }

            for(int j = 0 ; j < largeur/2 ; j++)
            {
                fin>>r>>g>>b;
                for(int k = largeur/2 ; k <largeur ; k++)
                {
                    fout<<r<<" "<<g<<" "<<b<<" ";
                }
                fout << endl;
            }
        }
}
*/


void echange(const string&nomFichierIN, const string &nomFichierOUT)
{
    ifstream fin(nomFichierIN);
    ofstream fout(nomFichierOUT);
        int r,g,b,maxi,largeur,hauteur,skip;
        string format;
        fin>>format>>largeur>>hauteur>>maxi;
        fout<<format<<endl<<largeur<<" "<<hauteur<<endl<<maxi<<endl;
        vector<pixel>P(largeur);
        for(int i = 0 ; i < hauteur ; i++)
        {
            for(int j = 0 ; j < largeur/2; j++)
            {
               fin>>P[j].r>>P[j].g>>P[j].b;
            }
            for(int j = largeur/2; j < P.size() ; j++)
            {
                fin>>P[j].r>>P[j].g>>P[j].b;
            }

            for(int k = largeur/2 ; k < P.size() ; k++)
            {
                fout<<P[k].r<<" "<<P[k].g<<" "<<P[k].b<<" ";
            }

            for(int j = 0 ; j < largeur/2 ; j++)
            {
                fin>>P[j].r>>P[j].g>>P[j].b;
            }

            for(int j = largeur/2 ; j > P.size() ; j++)
            {
                fin>>P[j].r>>P[j].g>>P[j].b;
            }

            for(int k = 0 ; k < largeur ; k++)
            {
                fout<<P[k].r<<" "<<P[k].g<<" "<<P[k].b<<" ";
            }
            fout<<endl;
        }
}

int main()
{
    //genereCarres(50, "test.ppm");
    //niveauDeGris("test.ppm","test2.ppm");
    //extraction("test.ppm","test3.ppm", 0,50,0,50);
    //symetrie("test.ppm","test4.ppm");
    //rotation("Poissons.ppm","test5.ppm");
    //negatif("Poissons.ppm","test6.ppm");
    //miseEnEvidence("Bouquet.ppm","test7.ppm");
    //zoom("Poissons.ppm","test8.ppm");
    echange("PoissonsAgrandit.ppm", "ccf2018.ppm");
}

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void genereCarres(int n, const string &nomFichier) {
	ofstream outf(nomFichier);  //On essaye d'ouvrir le fichier

	if (outf)  //On teste si tout est OK
	{
		outf << "P3" << endl;
		outf << 2 * n << " " << 2 * n << endl;
		outf << "255" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				outf << "255 0 0 ";
			}
			for (int k = 0; k < n; k++)
			{
				outf << "0 255 0 ";
			}
			outf << endl;
		}
		for (int l = 0; l < n; l++)
		{
			for (int m = 0; m < n; m++)
			{
				outf << "0 0 255 ";
			}
			for (int o = 0; o < n; o++)
			{
				outf << "255 255 0 ";
			}
			outf << endl;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}
struct pixel {
	int r;
	int v;
	int b;
};

bool niveauDeGris(const string& nomFichierIN, const string &nomFichierOUT)
{
	ifstream fIN(nomFichierIN);
	if (!fIN)
	{
		cout << "Erreur de lecture." << endl; 
		return false;
	}
	else
	{
		ofstream fOUT(nomFichierOUT);
		string ch; int r, v, b, h, l, moy = 0;
		fIN >> ch;
		fOUT << ch << endl;
		fIN >> l >> h;
		fOUT << l << " " << h << endl;
		fIN >> ch;
		fOUT << ch << endl;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < l; j++)
			{
				fIN >> r >> v >> b;
				moy = (r + v + b) / 3;
				fOUT << moy << " " << moy << " " << moy << " ";
			}
			fOUT << endl;
		}
	}
	return true;
}

bool extraction(const string &nomFichierIN, const string &nomFichierOUT, int l1, int l2, int c1, int c2)
{
    ifstream in(nomFichierIN);
    ofstream out(nomFichierOUT);
    string type;
    int largeur, longueur, max, skip, r, g, b;
    if(in && out)
    {
        in>>type>>largeur>>longueur>>max;
        out<<type<<endl<<c2-c1+1<<" "<<l2-l1+1<<endl<<max<<endl;

        for(int i = 0; i <l1; i++)
        {
            for(int j = 0; j<largeur*3;j++)
            {
                in >>r>>g>>b;
            }
        }
        for(int i = l1; i<=l2;i++)
        {
            for(int j = 0; j<c1;j++)
            {
                in >>r>>g>>b;
            }
            for(int j = c1; j<=c2-c1;j++)
            {
                in >> r >> g >> b;
                out << r<<" "<< g<<" "<< b<<" ";
            }
            out << endl;
            for(int j = 0; j<largeur *3;j++)
            {
                in >>r>>g>>b;
            }

        }
    return true;
    }
    else
    {
        return false;
    }
}

bool symetrieV(string nomFichierIN, string nomFichierOUT)
{
	ifstream in(nomFichierIN);
	ofstream out(nomFichierOUT);
	if (!in || !out)
	{
		return false;
	}
	int l, h, maxi;
	string format;
	in >> format >> l >> h >> maxi;
	out << format << endl << l << " " << h << endl << maxi << endl;
	vector <pixel> P(l);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l; j++)
		{
			in >> P[j].r >> P[j].v >> P[j].b;
		}
		for (int j = l - 1; j >= 0; j--)
		{
			out << P[j].r << " " << P[j].v << " " << P[j].b << " ";
		}
		out << endl;
	}
	return true;

}

/*
bool rotationG(const string&nomFichierIN, const string &nomFichierOUT)
{
	ifstream fin(nomFichierIN);
	ofstream fout(nomFichierOUT);
	// Verification du fichier
	if (!fin || !fout)
	{
		return false;
	}
	int l, h, maxi;
	string format;
	fin >> format >> l >> h >> maxi;
	fout << format << endl << h << " " << l << endl << maxi << endl;

	// Déclaration d'un tableau 2D (soit P initialisé avec l et h)
	vector <vector <pixel>> P(l, vector<pixel>(h));
	for (int j = 0; j < P.size(); j++)
	{
		for (int k = l - 1; k >= 0; k--)
		{
			fin >> P[k][j].r;
			fin >> P[k][j].v;
			fin >> P[k][j].b;
		}
	}

	for (int i = 0; i < l; i++)
	{
		for (int k = 0; k < h; k++)
		{
			fout << P[i][k].r << " " << P[i][k].v << " " << P[i][k].b << " ";
		}
		fout << endl;
	}
}
*/

void rotationG(const string NomFichierIN, const string NomFichierOUT)
{

	ifstream IN(NomFichierIN);
	ofstream OUT(NomFichierOUT);
	vector <vector<pixel>> Tab;

	string type;
	int hauteur, largeur, maxi;
	IN >> type >> largeur >> hauteur >> maxi;
	OUT << type << endl << hauteur << " " << largeur << endl << maxi << endl;

	Tab.resize(largeur);					// Resize du tableau 2D par la largeur
	for (int i = 0; i < Tab.size(); i++)
	{
		Tab[i].resize(largeur);				// Pour chaque sous-vecteur du vecteur, on resize à largeur
	}
	
	for (int j = 0; j < Tab.size(); j++) // Inverse les pixels 
	{
		for (int cpt = largeur - 1; cpt >= 0; cpt--) // passage de largeur à hauteur --- Ma nouvelle hauteur = ma largeur
		{																			//	 Ma nouvelle largeur = ma hauteur
			IN >> Tab[cpt][j].r;
			IN >> Tab[cpt][j].v;
			IN >> Tab[cpt][j].b;
		}
	}

	// Ecriture dans le fichier OUT
	for (int i = 0; i < largeur; i++)
	{
		for (int cpt = 0; cpt < hauteur; cpt++)
		{
			OUT << Tab[i][cpt].r << " " << Tab[i][cpt].v << " " << Tab[i][cpt].b << " ";
		}
		OUT << endl;
	}
}

pixel moyenne(const pixel& p1, const pixel& p2)
{
	pixel p;
	p.r = (p1.r + p2.r) / 2;
	p.v = (p1.v + p2.v) / 2;
	p.b = (p1.b + p2.b) / 2;
	return p;
}

pixel moyenne(const pixel& p1, const pixel& p2, const pixel& p3, const pixel& p4)
{
	pixel p;
	p.r = (p1.r + p2.r + p3.r + p4.r) / 4;
	p.v = (p1.v + p2.v + p3.v + p4.v) / 4;
	p.b = (p1.b + p2.b + p3.b + p4.b) / 4;

	return p;
}

bool zoom(const string&nomFichierIN, const string &nomFichierOUT)
{
	ifstream fin(nomFichierIN);
	ofstream fout(nomFichierOUT);
	if (!fin) return false;
	int hauteur, largeur, maxi;
	string type;
	fin >> type >> largeur >> hauteur >> maxi;
	fout << type << endl << 2*hauteur-1 << " " << 2*largeur-1 << endl << maxi << endl;
	pixel p;
	vector<pixel>l1, l2;
	for (int j = 0; j < largeur; j++)
	{
		fin >> l1[j].r >> l1[j].v >> l1[j].b;
	}
	fout << l1[0].r << " " << l1[0].v << " " << l1[0].b << " ";
	for(int i = 0 ; i < hauteur; i+2)
	{
		
	}
	return true;
}


int main()
{
	const string fnIN = "Poissons.ppm";
	const string fnOUT = "symetrie.ppm";
	const string fnEXT = "extrait.ppm";
	const string fnROT = "rotation.ppm";
	const string fnZOOM = "zoom.ppm";
	//genereCarres(10, fnIN);
	//symetrieV(fnIN, fnOUT);
	//extraction(fnIN, fnEXT, 50, 100, 0, 50);
	//rotationG(fnIN, fnROT);
	zoom(fnIN, fnZOOM);
}

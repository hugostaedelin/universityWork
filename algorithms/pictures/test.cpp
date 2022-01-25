#include <iostream>
#include <fstream>

/**
    Un fichier ppm (portable pix map) est un fichier texte qui stocke une image couleur selon le format suivant :
        - P3 : 2 caractères qui indiquent le type d'image stockés dans le fichier (pour notre tp on utilise P3)
        -lh : 2 entiers qui indiqueront la largeur et la hauteur de l'image (en px)
        - 255 La valeure max utilisée pour coder les couleurs (toujours 255 pour notre TD)
        -r..v..b.. pixels de l'image. Chaque pixel est codé par 3 entier (rouge,vert,bleu) compris entre 0 et 255.
                   les pixels sont données ligne par ligne en partant du coin supérieur gauche de l'image.

*/
/**
    Exercice 1 : ecrire la fonction généreCarré(int n, const string &NomFichier) qui stocke l'image suivante dans
    le fichier dont le nom est est stoker dans le paramètre nomFichier

    exercice 2 : ecrire la fonction DeGris(const string &Fichier IN , const string &Fichier OUT) qui
                stocke dans le fichier Fichier OUT la représentation en niveau de gris de l'image de
                Fichier IN

    exercice 3 : nom


*/
using namespace std;


void generaCarres(int n, const string &fichier)
{

    ofstream f(fichier);

    f<<"P3"<< endl;
    f<<2*n<< " " << 2*n << endl;
    f<<"255" << endl;
        for (int i=0; i<n; i++)
        {
            for (int j=0;j<n; j++)
            {
                    f<< "255 0 0 " ;
            }
            for (int j=n; j<2*n; j++)
            {
                    f<< "0 0 255 " ;
            }
        f<<endl;
        }
        for (int m=n; m<2*n; m++)
        {
            for (int j=0; j<n; j++)
            {
                f<< "0 255 0 " ;
            }
            for (int j=n; j<2*n; j++)
            {
                f << "255 255 0 " ;
            }
        }
        f<<endl;
}

void NiveauxDeGris(const string &FichierIN,const string &FichierOUT)
{
        ifstream fIN(FichierIN);
        ofstream fOUT(FichierOUT);

        string Inter;

        int r,v,b,gris;

        getline(fIN,Inter); // bonne reponse-->ou simplement fIN>>Inter;
        fOUT<<Inter<< endl;
        getline(fIN,Inter);
        fOUT<<Inter<< endl;
        getline(fIN,Inter);
        fOUT<<Inter<< endl;

        while(!fIN.eof())
        {

            fIN>>r;
            fIN>>v;
            fIN>>b>>ws;

            gris=(r+v+b)/3;

            fOUT<<gris<<" "<<gris<<" "<<gris<<endl;

        }

}

/********************************************************************************************************/
/*	Exercice 4																							*/
/*		Ecrire la fonction symetrie(nomFichierIN,nomFichierOUT) qui effectue l'opération suivante		*/
/*		(Réalisation d'une symétrie verticale de l'image																								*/
/********************************************************************************************************















*/















/**
void PetiteImage(const string &FichierIN,const int LargeurDepart,const int LargeurArrive,const int HauterDepart,const int HauteurArrive)
{

        ifstream fIN(FichierIN);
        ofstream fOUT("test.ppm");
        string Poubelle;
        string Taille;
        int r,v,b;

        fOUT<<"P3"<< endl;
        fOUT<<LargeurArrive-LargeurDepart<<" "<< HauteurArrive-HauterDepart<< endl;
        fOUT<<"255" << endl;

        getline(fIN,Poubelle);
        getline(fIN,Taille);
        getline(fIN,Poubelle);

        for (int i=0; i<100; i++)
        {
            for (int j=0;j<100; j++)
            {

                    fIN>>r;
                    fIN>>v;
                    fIN>>b>>ws;

                    if(i>HauterDepart && i<HauteurArrive && j>LargeurDepart && j<LargeurArrive)
                    {

                         fOUT<<r<<" "<<v<<" "<<255<<endl;
                         cout<<r;
                    }
            }
        }
}
*/

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

int main()
{
    string NomFichier="fichier.ppm";
    string FichierGris="Gris.ppm";

    generaCarres(100,NomFichier);
    extraction(NomFichier,"test.ppm",50,100,0,50);

    return 0;
}

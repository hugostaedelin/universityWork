#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
/**
    @brief Initialise un tableaux de reels T.
*/
vector<double>T;
/**
    @brief Initialise un tableaux de reels V.
*/
vector<double>V;
/**
    @brief Initialise un tableaux d'entiers S.
*/
vector<int>S;

/**
    @version 1.0
    @param[in] T - Tableau de reels
    @brief Effectue la saisie d'un nombre d'elements dans un tableau de reels.
*/
void saisie(vector<double> &T)
{
	int taille ;
	do	{
            cout << "Saisir le nombre d'elements (> = 0)"<< endl;
            cin >> taille;
		}
		while(taille < 0);
	T.resize(taille);
	for(int i = 0 ; i < taille ; i++)
	{
		cout << "Saisir la valeur pour l'indice" << i << endl;
		cin >> T[i];
	}
}
/**
    @version 2.0
    @param[in] S - Tableau d'entiers
    @brief Effectue la saisie d'un nombre d'elements dans un tableau de reels a l'aide de la methode "push_back".
*/
void saisie(vector<int> &S)
{
	int taille ;
	do	{
		cout << "Saisir le nombre d'elements (> = 0)"<< endl;
		cin >> taille;
		} while(taille < 0);
	T.resize(0); // ou T.clear()
	T.reserve(taille);
	for(int i = 0 ; i < taille ; i++)
	{
		int valeur ;
		cout << "Saisir la valeur pour l'indice" << i << endl;
		cin >> valeur;
		T.push_back(valeur);
	}
}
/**
    @version 1.0
    @param[in] T - Tableau de reels
    @brief Affiche les valeurs du tableau de reels.
*/
void AfficheTableau(const vector<double> &T) // Ajout d'un const car la fonction ne modifie pas
{
	for(int i = 0 ; i < T.size() ; i++)
	{
		cout << T[i] << endl ; // Caractère spécial : \t pour la tabulation
	}
}

/**
    @version 1.0
    @param[in] T - Tableau de reels,  nomFichier - Chaine de caractere correspondant au nom du fichier
    @brief Realise la lecture d'un fichier (par exemple un fichier texte)
*/
void lit(vector<double> &T, const string &nomFichier)
{
    int nbElement;
    ifstream fic(nomFichier);
	fic >> nbElement;
	T.resize(nbElement);
	for(int i = 0 ; i < nbElement ; i++)
	{
		fic>>T[i];
	}
}

/**
    @version 1.0
    @param[in] T - Tableau de reels
    @brief
*/
void initRandTable(vector<double>&T,double n, double min, double max)
{
	T.resize(n);
	for(int i = 0 ; i < T.size() ; i++)
	{
		T[i] = rand() * ((max / RAND_MAX) - (min / RAND_MAX)) + min;
	}
}

/**
    @version 1.0
    @param[in] T - Tableau de reels
    @brief Realise un tri par insertion dans le tableau de reels et affiche le nombre de fois ou l'instruction caracteristique est realisee.
*/
int complexiteTriMin(vector<double> &T)
{
    double mini;
    int posMini;
    int compteur = 0;
  	for(int i = 0 ; i < T.size()-1 ; i++)
    {
      // On cherche le minimum de T[i .. T.size()-1]
      mini = T[i] ;
	  posMini = i ;

      for(int j = i + 1 ; j < T.size(); j++)
      {
        compteur++;
        if (T[j] < mini)
        {

            mini = T[j];
            posMini = j;

        }
      }
      compteur++;
      T[posMini] = T[i];
      T[i] = mini;
    }
    cout<<"Nombre de fois ou l'instruction j < T.size() est effectue : "<<compteur<<endl<<endl;
    return compteur;
}

/**
    @version 1.0
    @param[in] T - Tableau de reels
    @brief Realise un tri par selection du minimum dans le tableau de reels et affiche le nombre de fois ou l'instruction caracteristique est realisee.
*/
int complexiteTriInsertion(vector<double> &T)
{
    int compteur = 0;
	for(int i = 1 ; i < T.size(); i++)
	{
	    double aux = T[i];
		double j = i - 1 ;
		while(j >= 0 && T[j] > aux)
		{
		    compteur++;
			T[j+1] = T[j] ;
			j-- ;
		}
		T[j+1] = aux;
		compteur++;
	}
    cout<<"Nombre de fois ou l'instruction j >= 0 est effectue : "<<compteur<<endl<<endl;
    return compteur;
}

/**
    @version 1.0
    @param[in] 	nomTri - Chaine de caractere correspondant au nom du fichier
    @brief Sauvegarde le nombre de fois ou les instructions caracteristiques sont effectuees dans un fichier .xls.
*/
void sauvegarder(const string nomTri)
{
    ofstream f(nomTri);
    f << "triMin" << "\t" << "triInsertion" << "\t" << "Reels" << "\n";
    for(int i = 1000; i <= 20000; i = i+1000)
    {
        initRandTable(T,i,0.0,1000.0);
        V = T;
        f << complexiteTriMin(T) << "\t";
        f << complexiteTriInsertion(V) << "\t";
        f << i << "\n";
    }
}

/**
    @version 1.0
    @param[in] T - Tableau de reels
    @brief Realise un tri par insertion dans le tableau de reels.
*/
void triInsertion(vector<double> &T)
{
	for(int i = 1 ; i < T.size(); i++)
	{
	    double aux = T[i];
		double j = i - 1 ;
		while(j >= 0 && T[j] > aux)
		{
			T[j+1] = T[j] ;
			j-- ;
		}
		T[j+1] = aux;
	}
}

/**
    @version 1.0
    @param[in] T - Tableau de reels
    @brief Realise un tri par selection du minimum dans le tableau de reels.
*/
void triMin(vector <double> &T){
   double temp;
   for (int i = 0; i < T.size(); ++i)
    {
       for (int j = i+1; j < T.size(); ++j)
       {
           if (T[j] < T[i])
           {
               temp = T[i];
               T[i] = T[j];
               T[j] = temp;
           }
       }
   }
}

/**
    @version 1.0
    @param[in] T - Tableau de reels, x - Entier de recherche
    @brief Realise des tests pour voir si un element specifique est present.
*/
int estPresent(int x, const vector<int> &T)
{
  int i = 0 ;
  while(i< T.size() && T[x] != x)
  {
		i++ ;
  }
  if(i == T.size())  {return -1;}
  else return i ;
  // AUTRE METHODE
  //return i == T.size() ? -1 ; 1 // Simplification des retours -> Utilisation de l'opérateur conditionnel ? ;
}

/**
    @version 1.0
    @param[in]
    @brief Fonction principale. Elle initialise les fonctions et le nom des fichiers.
*/
int main()
{
    const string nomFichier = "fic.txt";
    const string nomTri = "valeurs.xls";
    srand(time(0));
    //initRandTable(T,8,0,1600);
    //lit(T,nomFichier);
    //triMin(T);
    AfficheTableau(T);
    sauvegarder(nomTri);
}

double Test;
for(int i = 0; i<VR.size(); i++)
{
    Test = VR[i];
    for(int j = i+1 ; j<VR.size(); j++)
    {
        if(VR[j] == Test)
        {
            for(int k = j+1; k<VR.size(); k++)
            {
                VR[k-1] = VR[k];
            }
            j = j -1;
            VR.pop_back();
        }
    }
}


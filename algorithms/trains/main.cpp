#include <iostream>
#include <vector>
using namespace std;
/**
@brief Initialise le tableau d'entier V (V[j] correspond au numero de train reseve par le passager j).
*/
vector<int>V;
/**
@brief Initialise le tableau d'entier P (P[j] contient le numero du train attribue au voyageur j).
*/
vector<int>P;

/**
	@version 1.0
	@param V tableau de voyageur, k nb train, c nb max de voyageur dans le train
	@brief Teste si tous le train numero i doit circuler.
*/
bool doitCirculer(const vector<int>&V, int i)
{
	int j = 0;
	while(j < V.size() && V[j] != i)
    {
        j++;
    }
	return j<V.size();
}

/**
	@version 1.0
	@param V tableau de voyageur, k nb train, c nb max de voyageur dans le train
	@brief Teste si tous les trains doivent circuler.
*/
bool tousLesTrains(const vector<int> &V, int k)
{
    int i = 0;
	while(i < k && doitCirculer(V, i))
    {
        i++;
    }
	return i == k ;
}
/**
	@version 1.0
	@param V tableau de voyageur, k nb train, c nb max de voyageur dans le train
	@brief Retourne si tous les voyages peuvent prendre le train de leurs choix
*/
bool reservationsPossibles(const vector<int> &V, int k, int c)
{
	vector<int>M(k, 0);
	for(int j = 0 ; j < V.size(); j++)
	{
		M[V[j]]++;
	}
	int i = 0;
	while(M[i] <= c && i < M.size())
    {
        i++;
    }
	return i == M.size();
}
/**
	@version 2.0
	@param V tableau de voyageur, k nb train, c nb max de voyageur dans le train
	@brief Retourne true si tous les voyages peuvent prendre le train de leurs choix ou false si ce n'est pas le cas.
*/
bool reservationPossibles(const vector<int> &V, int k, int c)
{
	vector<int>M(k, 0);
	for(int i = 0; i < V.size() ; i++)
	{
		M[V[i]]++;
		if(M[V[i]] > c) return false;
	}
	return true;
}
/**
	@version 1.0
	@param V tableau de voyageur, k nb train, c nb max de voyageur dans le train
	@brief return true s'il est possible de répartir les voyages dans les différents trains
*/
bool repartitionPossible(const vector <int> &V, int k, int c)
{
    vector<int> M(k, 0);
    for(int j = 0; j<V.size(); j++) {
        M[V[j]]++;
    }
    for( int i = M.size(); i >= 0; i--)
    {
        if(M[i] > ((M.size()-i)*c))
        {
            return false;
        }
    }
    return true;
}

void initRandTable(vector<int>&V,int n, int min, int max)
{
	V.resize(n);
	for(int i = 0 ; i < V.size() ; i++)
	{
		V[i] = rand() * ((max / RAND_MAX) - (min / RAND_MAX)) + min;
	}
}

int main()
{
    V.resize(5);
	V[0] = 2 ;
	V[1] = 4 ;
	V[2] = 3 ;
	V[3] = 4 ;
	V[4] = 1 ;
    //initRandTable(V, 10, 0, 20);
    int k = 5 ;
    int c = 20;
    int i = k-1;
    cout<<doitCirculer(V, i)<<endl;
    cout<<tousLesTrains(V, k)<<endl;
    cout<<reservationPossibles(V, k, c)<<endl;
}

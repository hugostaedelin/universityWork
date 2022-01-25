#include <iostream>

using namespace std;

class Table
{
public:
    Table();
    Table(const Table& t);
    void ajouter(double v, int index);
    double& operator[](int i);
    ~Table();

    int taille() const;
    void supprimer(int i);
    void supprimerElements(int i_d, int nb);
    bool operator==(const Table& t) const;
    Table& operator+=(const Table& tb);
    Table& operator=(const Table& tb);
private:
    double* d_table;
    int d_n;
};
// Question 1 : Écrire le constructeur de la classe
Table::Table() : d_table{nullptr}, d_n{0}
{

}
// Question 2 : Écrire le destructeur de la classe
Table::~Table()
{
    delete[] d_table; // Libération de la mémoire (les [] sont pour le tableau dynamique)
}
// Question 3 : Écrire le constructeur par recopie

Table::Table(const Table& tab)
{
    d_table = tab.d_table;
    d_n = tab.d_n;
}

void Table::ajouter(double v, int index)
{
    double* table = new double[d_n];
    for(int i = 0; i < index; i++)
    {
        table[i] = d_table[i];
    }
    delete[] d_table;
    d_table = table;
    d_table[d_n] = v;
    d_n++;
}

void Table::supprimer(int i){
    if(i > d_n)
    {
        return;
    }
    for(int j=i; j<d_n ; j++)
    {
        d_table[j] = d_table[j+1];
    }
    d_n--;
}

void Table::supprimerElements(int i_d, int nb)
{
    for (int i = i_d; i < d_n; ++i)
    {
    d_table[i] = d_table[i+nb];
    }
    d_n-= nb;
}

double& Table::operator[](int i)
{
    return d_table[i];
}

Table& Table::operator=(const Table& tab)
{
    d_table = tab.d_table;
    d_n = tab.d_n;
    return *this;
}

bool Table::operator==(const Table& t) const
{
    return (t.d_n == d_n && t.d_table == d_table);
}

Table& Table::operator+=(const Table& t)
{
    for(int i=d_n; i < d_n+t.d_n ; i++)
    {
        d_table[i] = t.d_table[i-d_n];
    }
    d_n += t.d_n;
    return *this;
}

int Table::taille() const
{
    return d_n;
}

void afficher(Table& t)
{
    for(int i=0; i<t.taille(); i++)
    {
        cout<<t[i]<<endl;
    }
}

void test1()
{
    Table tab;
    tab.ajouter(16.0,0);
    tab.ajouter(139.0,1);
    cout<<tab[0]<<endl;
    cout<<tab[1]<<endl;
    cout<<" "<<endl;
    afficher(tab);
}
void testSuppression()
{
    Table tab;
    tab.ajouter(16,0);
    tab.ajouter(139,1);
    tab.ajouter(0,2);
    tab.ajouter(2,3);
    tab.supprimer(1);
    afficher(tab);
}
void test3()
{
    Table tab;
    tab.ajouter(1,0);
    tab.ajouter(2,1);
    tab.ajouter(3,2);
    Table aj{tab};
    tab+=aj;
    afficher(tab);
}
void test4()
{
    Table tab;
    tab.ajouter(1,0);
    tab.ajouter(2,1);
    tab.ajouter(3,2);
    cout<<"tab : ";
    afficher(tab);
    cout<<endl;
    Table aff;
    aff=tab;
    cout<<"aff : ";
    afficher(aff);
}
bool estEgal(Table& t1, Table& t2)
{
    if(t1==t2) return true;
    return false;
}
void testEgalite()
{
    Table tab;
    tab.ajouter(1,0);
    tab.ajouter(2,1);
    tab.ajouter(3,2);
    Table aj{tab};
    if(estEgal(tab, aj)==true) cout<<"1";
    else cout<<"0";
}
void testRecopie()
{
    Table tab;
    tab.ajouter(1,0);
    tab.ajouter(2,1);
    tab.ajouter(3,2);
    Table cop{tab};
    afficher(cop);
}

int main()
{
    test4();
}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int codage(int valeur, int base)
{
	vector<int>T;
	int modulo = 0;
	while (valeur != 0)
	{
		modulo = valeur % base;
		valeur /= base;
		T.push_back(modulo);
	}
	reverse(T.begin(), T.end());
	stringstream ss;
	string s;
	for (int j = 0; j < T.size(); j++)
	{
		ss << T[j];
	}
	int res = stoi(ss.str());
	return res;
}

int decodage(int valeur, int base)
{
	int facteur = 1;
	int modulo;
	int res = 0;
	while (valeur != 0)
	{
		modulo = valeur % 10;
		res += modulo * facteur;
		valeur /= 10;
		facteur *= base;
	}
	return res;
}

int transcodage(int valeur, int initbase, int destbase)
{
	int val = decodage(valeur, initbase);
	int val2 = codage(val, destbase);
	return val2;
}

int restComp(int valeur, int initbase, int nbchiffres)
{
	int	res = 0;
	if (valeur < 0)
	{
		int absE = abs(valeur);
		int codVal = codage(absE, 10);
		res = (pow(initbase, nbchiffres) - 1 - codVal);
		return res = codage(res, initbase);
	}
	else return res = codage(valeur, initbase) - 1;
}

int vraiComp(int valeur)
{
	return valeur = valeur + 1;
}

void printFloat(float valeur)
{
	
}

void test()
{
	cout << codage(555, 5) << endl;
	cout << decodage(4210, 5) << endl;
	cout << transcodage(10011, 2, 8) << endl;
}

void test1()
{
	cout << restComp(-542, 10, 4) << endl;
	cout << vraiComp(restComp(-542, 10, 4)) << endl;
}

int main()
{
	test();
}

// Renvoie les points de p qui sont à une distance < limite du point pcible
// Appel et utilisation de la classe point
// la fonction s'appellera pointsProchesDe(const vector<point>&P, double limite, const point& pcible)
// son type sera vector<point>

#include <iostream>
#include "point.h"
#include <vector>

using namespace std;

vector<point> pointsProchesDe(const vector<point>&P, double limite, const point& pcible)
{
	vector<point>pproches{};
	pproches.reserve(P.size());
	for (int i = 0; i < P.size(); ++i)
	{
		if (P[i].distance(pcible) < limite)
		{
			pproches.push_back(P[i]);
		}
	}
	pproches.shrink_to_fit();
	return pproches;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mouvements.cpp
 * Author: maillot
 * 
 * Created on 13 juin 2019, 17:21
 */

#include "Mouvements.h"

/*
1. (1⁄2pt) Écrire le constructeur par défaut de cette classe qui initialise une liste
de mouvements vide.
 */
Mouvements::Mouvements() : d_ancre('X', 0) {
    d_ancre.d_s = d_ancre.d_p = &d_ancre;
}

/*
2. (1⁄2pt) Écrire la méthode vide() : vrai si la liste est vide, faux sinon.
 */
bool Mouvements::vide() const {
    return d_ancre.d_s == &d_ancre;
}

/*
3. (1pt) Écrire la méthode supprimer_dernier() qui supprime le dernier mou-
vement de la liste supposée non-vide.
 */
void Mouvements::supprimer_dernier() {
    Chainon* as = d_ancre.d_p;
    d_ancre.d_p = as->d_p;
    d_ancre.d_p->d_s = &d_ancre;
    delete as;
}

/*
4. (1pt) Écrire la méthode ajouter(crt, f, n) qui ajoute un nouveau mouve-
ment à la liste de sorte qu’il se trouve entre celui pointé par crt et l’ancien
suivant de crt . Les paramètres f et n définissent ce nouveau mouvement.
Remarques importantes :
— crt est supposé pointer sur un chaînon de la liste.
— f est supposée être une face correcte et différente de celle du chaînon de
crt et de son suivant.
— n est supposé être un entier correct, c’est-à-dire −1, 1 ou 2.
 */
void Mouvements::ajouter(Chainon* crt, char f, int n) {
    Chainon *nm = new Chainon(f, n);
    nm->d_p = crt;
    nm->d_s = crt->d_s;
    nm->d_p->d_s = nm;
    nm->d_s->d_p = nm;
}

/*
5. (2pts) Écrire le constructeur par recopie.
 */
Mouvements::Mouvements(const Mouvements& orig) : d_ancre('X', 0) {
    Chainon* ocrt = orig.d_ancre.d_s;
    Chainon* crt = &d_ancre;
    while (ocrt != &orig.d_ancre) {
        // On peut aussi utiliser Mouvements::ajouter(Chainon* crt, char f, int n)
        crt->d_s = new Mouvements::Chainon(ocrt->d_f, ocrt->d_n);
        crt->d_s->d_p = crt;
        crt = crt->d_s;
        ocrt = ocrt->d_s;
    }
    crt->d_s = &d_ancre;
    d_ancre.d_p = crt;
}

/*
6. (1pt) Écrire le destructeur. 
*/
Mouvements::~Mouvements() {
    Chainon* as = d_ancre.d_s;
    while(as != &d_ancre) {
        // On peut aussi utiliser Mouvements::supprimer_dernier()
        d_ancre.d_s = as->d_s;
        delete as;
        as = d_ancre.d_s;
    }
}

/*
7. (3pts) Écrire la surcharge de l’opérateur d’affectation. 
 */
Mouvements& Mouvements::operator=(const Mouvements& m) {
   if (this != &m) {
        Chainon* ocrt = m.d_ancre.d_s;
        Chainon* dcrt = d_ancre.d_s;
        while (ocrt != &m.d_ancre && dcrt != &d_ancre) {
            dcrt->d_f = ocrt->d_f;
            dcrt->d_n = ocrt->d_n;
            ocrt = ocrt->d_s;
            dcrt = dcrt->d_s;
        }
        if (dcrt != &d_ancre) {
            dcrt->d_p->d_s = &d_ancre;
            d_ancre.d_p = dcrt->d_p;
            while (dcrt != &d_ancre) {
                Chainon*as = dcrt;
                dcrt = dcrt->d_s;
                delete as;
            }
        }
        if (ocrt != &m.d_ancre) {
            Chainon*prec = d_ancre.d_p;
            Chainon*nm;
            while (ocrt != &m.d_ancre) {
                nm = new Chainon(ocrt->d_f, ocrt->d_n);
                nm->d_p = prec;
                prec->d_s = nm;
                prec = nm;
                ocrt = ocrt->d_s;
            }
            nm->d_s = &d_ancre;
            d_ancre.d_p = nm;
        }
    }
    return *this;
}

/*
 (a) (1⁄2pt) Écrire une méthode premier() qui retourne un itérateur sur le
premier mouvement (juste après l’ancre).
 */
Mouvements::IterateurConstant Mouvements::premier() const {
    return Mouvements::IterateurConstant(d_ancre.d_s);
}

/*
(b) (1⁄2pt) Écrire une méthode dernier() qui retourne un itérateur sur le
dernier mouvement (l’ancre). 
 */
Mouvements::IterateurConstant Mouvements::dernier() const {
    return Mouvements::IterateurConstant(&d_ancre);
}

/*
9. (4pts) À l’aide de l’itérateur, écrire la surcharge de l’opérateur de redirection
du flux qui affichera
— {} si la liste est vide,
— quelque chose comme {-1R} si la liste ne contient qu’un élément,
— quelque chose comme {-1R, 2Y, 1W} si la liste contient plusieurs éléments. 
 */
ostream& operator<<(ostream& os, const Mouvements& m) {
    Mouvements::IterateurConstant i = m.premier();
    Mouvements::IterateurConstant fin = m.dernier();
    os << "{";
    if (i != fin) {
        os << *i;
        ++i;
        while (i != fin) {
            os << ", ";
            os << *i;
            ++i;
        }
    }
    os << "}";
}

/*
 10. (1pt) Écrire la méthode reduction(n) qui reçoit dans n un nombre de quarts
de tours et qui retourne le nombre de quarts de tours correspondant admis
parmi {−1, 1, 2} ou 0 si la valeur de n revient à ne rien faire.
 */
int Mouvements::reduction(int n) const {
    n = n % 4; // -3, -2, -1, 0, 1, 2, 3
    if (n == -3)
        return 1;
    if (n == -2)
        return 2;
    if (n == 3)
        return -1;
    return n;
}

/*
 11. (5pts) Écrire la méthode ajouter(f, n) qui ajoute à la (fin de la) liste le
mouvement représenté par f et n.
Attention, cette fois il s’agit d’une méthode publique pour laquelle
toutes les précautions sont à prendre afin de contrôler l’intégrité
des données et éviter de retrouver dans la liste des mouvements
mal formés et des mouvements consécutifs s’appliquant à la même
face.
 */
void Mouvements::ajouter(char f, int n) {
    if (f == 'R' || f == 'B' || f == 'W' || f == 'Y' || f == 'O' || f == 'G') {
        n = reduction(n);
        if (n != 0) {
            if (f != d_ancre.d_p->d_f) {
                ajouter(d_ancre.d_p, f, n);
            } else {
                n = reduction(n + d_ancre.d_p->d_n);
                if (n == 0) {
                    supprimer_dernier();
                } else {
                    d_ancre.d_p->d_n = n;
                }
            }
        }
    }
}
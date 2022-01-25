/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mouvements.h
 * Author: maillot
 *
 * Created on 13 juin 2019, 17:21
 */

#ifndef MOUVEMENTS_H
#define MOUVEMENTS_H

#include<ostream>
#include<sstream>

using namespace std;

class Mouvements {
private:

    class Chainon {
    public:
        char d_f; // La face
        int d_n; // Le nombre de quarts de tour
        Chainon* d_s; // Le suivant
        Chainon* d_p; // Le précédent

        Chainon(char f, int n) : d_f(f), d_n(n), d_s(nullptr), d_p(nullptr) {
        }
        friend class Mouvements;
    };
    Chainon d_ancre; // L’ancre est un objet (et non un pointeur)
    void ajouter(Chainon* crt, char f, int n);
    void supprimer_dernier();
    int reduction(int n) const;
public:
    Mouvements();
    Mouvements(const Mouvements& orig);
    ~Mouvements();
    void ajouter(char f, int n);
    bool vide() const;
    Mouvements& operator=(const Mouvements&);
    friend ostream& operator<<(ostream&, const Mouvements&);

    class IterateurConstant {
    private:
        const Chainon* d_c; // Le chainon courant

        IterateurConstant(const Chainon*c) : d_c(c) {
        }
    public:
        // Pour passer au suivant

        IterateurConstant& operator++() {
            d_c = d_c ->d_s;
        }
        // Pour comparer deux itérateurs

        bool operator!=(const IterateurConstant& i) const {
            return i.d_c != d_c;
        }
        // Retourne le code du mouvement, comme "1R" ou "2Y" ou "-1B"

        string operator*() const {
            /* Inutile de comprendre cette ligne. Il suffit de savoir
            qu’elle retourne une chaîne qui représente un mouvement
            comme "1R" ou "2Y" ou "-1B" */
            stringstream s;
            s << d_c->d_n << d_c->d_f;
            return s.str();
        }
        friend class Mouvements;
    };
    
    IterateurConstant premier() const;
    IterateurConstant dernier() const;

};

#endif /* MOUVEMENTS_H */


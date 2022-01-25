/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: maillot
 *
 * Created on 13 juin 2019, 17:20
 */

#include <cstdlib>
#include <iostream>
#include "Mouvements.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Mouvements m;
    cout << m << endl; // {}
    m.ajouter('R', 5); // 5 => 1
    cout << m << endl; // {1R}
    m.ajouter('R', 1); // 1+1=2
    cout << m << endl; // {2R}
    m.ajouter('Y', 0); // Rien
    cout << m << endl; // {2R}
    m.ajouter('R', -2); // 2-2=0 => supression
    cout << m << endl; // {}
    m.ajouter('Y', 2); // Rien de particulier
    cout << m << endl; // {2Y}
    m.ajouter('R', 6); // 6 => 2
    cout << m << endl; // {2Y, 2R}
    m.ajouter('Z', 6); // 'Z' face incorrecte
    cout << m << endl; // {2Y, 2R}
    m.ajouter('R', 1); // 2+1=3 => -1
    cout << m << endl; // {2Y, -1R}
    m.ajouter('R', 1); // 1-1=0 
    cout << m << endl; // {2Y}
    
    Mouvements m2 = m;
    Mouvements m3 = m;
    cout << "--------------------" << endl;
    cout << m2 << endl;
    m2.ajouter('R', 1);
    cout << m2 << endl;
    m2.ajouter('Y', 6);
    cout << m2 << endl;
    cout << "--------------------" << endl;
    m2 = m;
    cout << m2 << endl;
    cout << "--------------------" << endl;
    m3 = m;
    cout << m3 << endl;
    cout << "--------------------" << endl;
    m2 = m3;
    cout << m2 << endl;
    return 0;
}


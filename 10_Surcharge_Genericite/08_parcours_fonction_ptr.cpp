//---------------------------------------------------------
// Demo           : 08_parcours_fonction_ptr
// Fichier        : 08_parcours_fonction_ptr.cpp
// Version        : 01 - 2022.11.07
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : exemple de pointeur utilisé dans une fonction
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>   // EXIT_SUCCESS
#include <cstdio>    // cin.get()
#include <iostream>  // cout et cin
#include <vector>

#include <limits>

using namespace std;

using Ligne   = vector<const int>;
using Matrice = vector<const Ligne>;

//------------------------------------------
int put(int valeur) {
    cout << valeur << " ";
    return valeur;
}

int plus1(int valeur) {
    return valeur + 1;
}

//------------------------------------------
void parcourir(int tab[], size_t taille, int(*f)(int)) {
    for (size_t i=0; i<taille; ++i)
        tab[i] = f(tab[i]);
}

//------------------------------------------
int main() {
   int tab[] ={1, 2, 3, 4, 5, 6};
   const size_t taille = sizeof(tab)/sizeof(int);

   parcourir(tab, taille, put);
   parcourir(tab, taille, plus1);

   cout << endl;
   parcourir(tab, taille, put);

   cout << endl;
   return EXIT_SUCCESS;
}

//      1 2 3 4 5 6
//      2 3 4 5 6 7

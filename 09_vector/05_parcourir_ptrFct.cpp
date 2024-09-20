//---------------------------------------------------------
// Demo           : 05_parcourir_ptrFct
// Fichier        : 05_parcourir_ptrFct.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 01 - 2022-11-24
// But            : parcours avec ptr de fonction
//                  en comparaison à for_each
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm> // for_each

using namespace std;

//---------------------------------------------------------
// types de données
using Vecteur = vector<int>;

//---------------------------------------------------------
// en C++
//---------------------------------------------------------
void afficher   (int  valeur) { cout << valeur << " ";   }
void incrementer(int& valeur) { ++valeur;                }

//---------------------------------------------------------
// en C
//---------------------------------------------------------
void parcourir(int* begin, int* end, void(*fct)(int*)) {
   for (int* crt = begin; crt<end; ++crt)
      fct(crt);
}

void put  (int* ptr) {cout << *ptr << " ";  }
void plus1(int* ptr) {   ++(*ptr);          }

//---------------------------------------------------------
// main
//---------------------------------------------------------
int main() {

   cout << "-------------" << endl;
   cout << "   en C++"     << endl;
   cout << "-------------" << endl;
   Vecteur v = {5, 2, 6, 7, 3, 4, 1, 8};

   for_each(v.begin(), v.end(), afficher);      cout << endl;
   for_each(v.begin(), v.end(), incrementer);
   for_each(v.begin(), v.end(), afficher);      cout << endl;
   cout << endl;

   cout << "-------------" << endl;
   cout << "   en C"       << endl;
   cout << "-------------" << endl;
   int tab[] = {5, 2, 6, 7, 3, 4, 1, 8};
   const size_t TAILLE = sizeof(tab) / sizeof(tab[0]);

   parcourir(tab, tab+TAILLE, put);             cout << endl;
   parcourir(tab, tab+TAILLE, plus1);
   parcourir(tab, tab+TAILLE, put);             cout << endl;

   cout << endl;
   return EXIT_SUCCESS;
}

//      -------------
//         en C++
//      -------------
//      5 2 6 7 3 4 1 8
//      6 3 7 8 4 5 2 9
//
//      -------------
//         en C
//      -------------
//      5 2 6 7 3 4 1 8
//      6 3 7 8 4 5 2 9

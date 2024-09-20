//---------------------------------------------------------
// Demo           : 05_boucle_for_iterator
// Fichier        : 05_boucle_for_iterator.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 02 - 2023-01-24
// But            : montrer les limites d'utilisation de la boucle for:
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

using Vecteur = vector<int>;

//------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur& v);

//------------------------------------------------------
void afficher(int i) {
   cout << i << endl;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   const Vecteur VECTEUR = {0, 1, 2, 3, 4, 5};
   Vecteur vecteur;   // vecteur de travail

   cout << "-------------------------------------"    << endl;
   cout << "vecteur de travail                   "    << endl;
   for (size_t i=0; i<VECTEUR.size(); ++i) {
      cout << "vecteur[" << i << "] = " << VECTEUR[i] << endl;
   }
   cout << endl;

   cout << "-------------------------------------"    << endl;
   cout << "boucle for (__;__;__)                "    << endl;
   vecteur = VECTEUR;
   for (size_t i=0; i<vecteur.size(); ++i) {
      if (i==3) {
         cout << "vecteur[" << i << "] <= erase    " << endl;
         vecteur.erase(vecteur.begin());
      }
      cout << "vecteur[" << i << "] = " << vecteur[i] << endl;
   }
   cout << endl;

   cout << "-------------------------------------"    << endl;
   cout << "iterateur sur vector[3]              "    << endl;
   vecteur = VECTEUR;
   Vecteur::const_iterator it = vecteur.begin() + 3;
   cout << "*it => vecteur.begin() + 3 = " << *it     << endl;
   for (size_t i=0; i<vecteur.size(); ++i) {
      if (i==3) {
         cout << "vecteur[" << i << "] <= erase    " << endl;
         vecteur.erase(vecteur.begin());
      }
      cout << "vecteur[" << i << "] = " << vecteur[i] << endl;
   }
   cout << "*it => vecteur.begin() + 3 = " << *it     << endl;
   cout << endl;

   // https://en.cppreference.com/w/cpp/language/range-for
   cout << "-------------------------------------"    << endl;
   cout << "boucle for (__:__)                   "    << endl;
   vecteur = VECTEUR;
   size_t i = 0;
   for (int e : vecteur) {
      if (i==3) {
         cout << "vecteur[" << i << "] <= erase    " << endl;
         vecteur.erase(vecteur.begin());
      }
      cout << "vecteur[" << i << "] = " << vecteur[i] << endl;
      ++i;
   }
   cout << endl;
}  // main


//------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

//      -------------------------------------
//      vecteur de travail
//      vecteur[0] = 0
//      vecteur[1] = 1
//      vecteur[2] = 2
//      vecteur[3] = 3
//      vecteur[4] = 4
//      vecteur[5] = 5
//
//      -------------------------------------
//      boucle for (__;__;__)
//      vecteur[0] = 0
//      vecteur[1] = 1
//      vecteur[2] = 2
//      vecteur[3] <= erase
//      vecteur[3] = 4
//      vecteur[4] = 5
//
//      -------------------------------------
//      iterateur sur vector[3]
//      *it => vecteur.begin() + 3 = 3
//      vecteur[0] = 0
//      vecteur[1] = 1
//      vecteur[2] = 2
//      vecteur[3] <= erase
//      vecteur[3] = 4
//      vecteur[4] = 5
//      *it => vecteur.begin() + 3 = 4
//
//      -------------------------------------
//      boucle for (__:__)
//      vecteur[0] = 0
//      vecteur[1] = 1
//      vecteur[2] = 2
//      vecteur[3] <= erase
//      vecteur[3] = 4
//      vecteur[4] = 5
//      vecteur[5] = 5

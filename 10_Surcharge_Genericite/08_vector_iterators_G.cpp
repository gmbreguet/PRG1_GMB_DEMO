//---------------------------------------------------------
// Demo           : 08_vector_iterators
// Fichier        : 08_vector_iterators.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 01 - 2023-01-09
// But            : démontrer la possibilité de manipuler des
//                  vecteurs de itérateurs - en mode générique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>       // classe vector
#include <algorithm>    // classe algorithm

using namespace std;

//-------------------------------------------------------------------
template<typename T>
using Iter = typename vector<T>::const_iterator;

//-------------------------------------------------------------------
// opérateur << générique <T>
template<typename T>
ostream& operator << (ostream& os, const vector<T>& v);

//-------------------------------------------------------------------
// opérateur << spécialisé
template<>
ostream& operator << (ostream& os, const vector<Iter<int>>& v);

//-------------------------------------------------------------------
// opérateur < générique pour le sort
template<typename T>
bool compIter(const Iter<T>& lhs, const Iter<T>& rhs) {
   return *lhs < *rhs;
}

//-------------------------------------------------------------------
int main() {
   cout << "----------------------" << endl;
   cout << "vecteur d'entiers"      << endl;
   cout << "----------------------" << endl;
   const vector<int> vInt  = {6, 9, 3, 5 ,2, 1, 7, 4, 8};
   cout << vInt << endl;
   cout << endl;

   cout << "----------------------" << endl;
   cout << "vecteur d'itérateurs"   << endl;
   cout << "----------------------" << endl;
   // vecteur d'itérateurs sur des entiers
   vector<Iter<int>> vIter;
   for (Iter<int> it=vInt.begin(); it!=vInt.end(); ++it)
      vIter.push_back(it);
   cout << vIter << endl;

   // tri du vecteur d'itérateurs
   // NB : le tableau est constant
   //   => ne peut pas être modifié / trié
   sort(vIter.begin(), vIter.end(), compIter<int>);
   cout << vIter << endl;

   // fin du programme
   return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   cout << "]";
   return os;
}

//-------------------------------------------------------------------
template<>
ostream& operator << (ostream& os, const vector<Iter<int>>& v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << *(v[i]);
   }
   cout << "]";
   return os;
}

//      ----------------------
//      vecteur d'entiers
//      ----------------------
//      [6, 9, 3, 5, 2, 1, 7, 4, 8]
//
//      ----------------------
//      vecteur d'itérateurs
//      ----------------------
//      [6, 9, 3, 5, 2, 1, 7, 4, 8]
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]

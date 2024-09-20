//---------------------------------------------------------
// Demo           : 05_vector_iterators
// Fichier        : 05_vector_iterators.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 01 - 2023-01-09
// But            : démontrer la possibilité de manipuler des
//                  vecteurs de itérateurs
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>       // classe vector
#include <algorithm>    // classe algorithm

using namespace std;

//-------------------------------------------------------------------
using Iter = vector<int>::const_iterator;

ostream& operator << (ostream& os, const vector<int>& v);
ostream& operator << (ostream& os, const vector<Iter>& c);

//-------------------------------------------------------------------
bool compIterInt(const Iter lhs, const Iter rhs) {
   return *lhs < *rhs;
}

//-------------------------------------------------------------------
int main() {

   // vecteur d'entiers
   const vector<int> vInt  = {6, 9, 3, 5 ,2, 1, 7, 4, 8};
   cout << vInt << endl;

   // vecteur d'itérateurs sur des entiers
   vector<Iter> vIter;
   for (Iter it=vInt.begin(); it!=vInt.end(); ++it)
      vIter.push_back(it);
   cout << vIter << endl;

   // tri du vecteur d'itérateurs
   // NB : le tableau est constant et ne peut pas être modifié
   sort(vIter.begin(), vIter.end(), compIterInt);
   cout << vIter << endl;

   // fin du programme
   return EXIT_SUCCESS;
}


//-------------------------------------------------------------------
ostream& operator << (ostream& os, const vector<int>& v) {
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
ostream& operator << (ostream& os, const vector<Iter>& v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << *(v[i]);
   }
   cout << "]";
   return os;
}

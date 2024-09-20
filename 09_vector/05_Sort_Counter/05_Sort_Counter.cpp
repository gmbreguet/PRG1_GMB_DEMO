//---------------------------------------------------------
// Demo           : 05_tris_counter
// Fichier        : 05_tris_counter.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 03 - 2023-03-07
// But            : démontrer les tris de base
//                   - tri à bulles
//                   - tri par insertions
//                   - tri par sélection
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // swap, generate, sort
#include <ctime>        // alea::srand(time..)
#include <limits>       // alea::numeric_limits<int>

#include "Data.hpp"
#include "Tris.hpp"

using namespace std;


//---------------------------------------------------------
// fonctions auxiliaires
int  generateur();
//---------------------------------------------------------
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v);

//---------------------------------------------------------
template<typename T>
void showStat(const vector<T>& v) {
//   cout << v << endl;
   cout << "- comparaisons : " << v.front().getComp()     << endl;
   cout << "- affectations : " << v.front().getAssign()   << endl;
   Data<T>::reset();
}

//---------------------------------------------------------
template<typename T, typename Fonction>
void testVecteur(const string& msg, vector<T> v, Fonction fct) {

   cout << endl;
   cout << "================" << endl;
   cout << msg << endl;
   cout << "================" << endl;

   cout << endl;
   cout << "aleatoire" << endl;
   cout << "---------" << endl;
   fct(v);
   showStat(v);

   cout << endl;
   cout << "trie croissant" << endl;
   cout << "--------------" << endl;
   sort(v.begin(), v.end());
   Data<T>::reset();

   fct(v);
   showStat(v);

   cout << endl;
   cout << "trie decroissant" << endl;
   cout << "----------------" << endl;
   reverse(v.begin(), v.end());
   Data<T>::reset();

   fct(v);
   showStat(v);
}

//---------------------------------------------------------
template<typename T, typename Fonction>
void testIterateur(const string& msg, vector<T> v, Fonction fct) {

   cout << endl;
   cout << "================" << endl;
   cout << msg << endl;
   cout << "================" << endl;

   cout << endl;
   cout << "aleatoire" << endl;
   cout << "---------" << endl;
   fct(v.begin(), v.end());
   showStat( vector<T>(v.begin(), v.end()) );

   cout << endl;
   cout << "trie croissant" << endl;
   cout << "--------------" << endl;
   sort(v.begin(), v.end());
   Data<T>::reset();

   fct(v.begin(), v.end());
   showStat( vector<T>(v.begin(), v.end()) );

   cout << endl;
   cout << "trie decroissant" << endl;
   cout << "----------------" << endl;
   reverse(v.begin(), v.end());
   Data<T>::reset();

   fct(v.begin(), v.end());
   showStat( vector<T>(v.begin(), v.end()) );
}

//---------------------------------------------------------
int main() {

//   vector<Data<int>> vect = {7, 3, 5, 2, 9, 8, 1, 4, 6};

   // création du vecteur
   const size_t SIZE = 1'000;
   vector<Data<int>> vect(SIZE);
   generate(vect.begin(), vect.end(), generateur);
   vect.at(0).reset();

   cout << "========================================" << endl;
   cout << "vecteur(" << SIZE << ")"                  << endl;
   cout << "========================================" << endl;

   // par indices
   testVecteur<Data<int>>("bubblesort1",         vect, bubbleSort1<Data<int>>);
   testVecteur<Data<int>>("bubblesort2",         vect, bubbleSort2<Data<int>>);
   testVecteur<Data<int>>("insertSort",          vect, insertSort<Data<int>>);
   testVecteur<Data<int>>("selectionSort",       vect, selectionSort<Data<int>>);

   // par itérateurs
   testIterateur<Data<int>>("bubbleSortIter",    vect, bubbleSortIter<vector<Data<int>>::iterator>);
   testIterateur<Data<int>>("insertSortIter",    vect, insertSortIter<vector<Data<int>>::iterator>);
   testIterateur<Data<int>>("selectionSortIter", vect, selectionSortIter<vector<Data<int>>::iterator>);
   testIterateur<Data<int>>("std::sortIter",     vect, sort<vector<Data<int>>::iterator>);

   return EXIT_SUCCESS;
}



//---------------------------------------------------------
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& d) {
   os << "[";
   for (size_t i=0; i<d.size(); ++i) {
      if (i)
         os << ", ";
      os << d[i];
   }

   os << "]";
   return os;
}


//---------------------------------------------------------
int generateur() {
   // initialisation du générateur
   static bool first = true;
   if (first) {
      srand((unsigned)time(NULL));
      first = false;
   }

   // generation d'une valeur aléatoire
   return rand() % numeric_limits<int>::max();
}

//      ================
//      bubblesort1
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 38
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 0
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 72
//
//      ================
//      bubblesort2
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 56
//      - affectations : 38
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 8
//      - affectations : 0
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 72
//      - affectations : 72
//
//      ================
//      insertSort
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 24
//      - affectations : 35
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 8
//      - affectations : 16
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 52
//
//      ================
//      selectionSort
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 15
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 8
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 12
//
//      ================
//      bubbleSortIter
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 38
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 0
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 72
//
//      ================
//      insertSortIter
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 24
//      - affectations : 46
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 8
//      - affectations : 8
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 80
//
//      ================
//      selectionSortIter
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 14
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 0
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 36
//      - affectations : 8
//
//      ================
//      std::sortIter
//      ================
//
//      aleatoire
//      ---------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 29
//      - affectations : 27
//
//      trie croissant
//      --------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 18
//      - affectations : 0
//
//      trie decroissant
//      ----------------
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      - comparaisons : 18
//      - affectations : 8


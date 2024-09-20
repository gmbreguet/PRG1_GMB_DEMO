//---------------------------------------------------------
// Demo           : 05_tri
// Fichier        : Tris.hpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 01 - 2023-03-26
// But            : implémentation des tris en n^2
//                   - tri à bulles
//                   - tri à insertion
//                   - tri par sélection
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef TRIS
#define TRIS

#include <vector>
#include <algorithm> // swap

//---------------------------------------------------------
// par indices
//---------------------------------------------------------
template<typename T>
void bubbleSort1(std::vector<T>& v) {
   if (v.size() > 0){    // size_t = unsigned => 0 - 1 => BCP
      for (size_t i = 0; i < v.size(); ++i){
         for (size_t j = 0; j < v.size() - i - 1; ++j){
            if (v[j] > v[j + 1]) {
               std::swap(v[j], v[j + 1]); // permutation
            } // if
         } // for j
      } // for i
   } // if
}

//---------------------------------------------------------
template<typename T>
void bubbleSort2(std::vector<T>& v) {
   if (v.size() > 0) {
      bool fini = false;
      while (!fini){
         size_t taille = v.size();
         fini = true;
         for (size_t i = 0; i < taille - 1; ++i){
            if (v[i] > v[i + 1]){
               std::swap(v[i], v[i + 1]);
               fini = false;
            } // if
         } // for
         --taille;
      } // while
   } // if
}

//---------------------------------------------------------
template<typename T>
void insertSort(std::vector<T>& v) {
   T tmp;
   size_t j;
   for (size_t i = 1; i < v.size(); ++i) {
      tmp = v[i];
      j   = i;
      while (j >= 1 and v[j - 1] > tmp) {
         v[j] = v[j - 1];
         --j;
      } // while
      v[j] = tmp;
   } // for
}

//---------------------------------------------------------
template<typename T>
void selectionSort(std::vector<T>& v) {
   if (v.size() > 0) {
      size_t iMin;
      for (size_t i = 0; i < v.size() - 1; ++i) {
         iMin = i;
         for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[iMin])
               iMin = j;
         } // for

         std::swap(v[i], v[iMin]); // permutation
      } // for
   } // if
}


//---------------------------------------------------------
// par itérateurs
//---------------------------------------------------------
template<typename RandomAccessIterator>
void bubbleSortIter(RandomAccessIterator first,
                    RandomAccessIterator last) {

   // au moins 2 éléments à trier
   if (distance(first, last) >= 2) {
      for (RandomAccessIterator i = prev(last); i != first; --i)
         for (RandomAccessIterator j = first; j != i; ++j) {
            if ( *j > *(j+1) )
               iter_swap( j, next(j) );
         }
   } // if
}

//---------------------------------------------------------
template<typename RandomAccessIterator>
void insertSortIter(RandomAccessIterator first,
                    RandomAccessIterator last) {

   // au moins 2 éléments à trier
   if (distance(first, last) >= 2) {
      
      for (RandomAccessIterator i = next(first); i != last; ++i) {

         auto tmp = *i;
         RandomAccessIterator pos = i;

         while (pos != first and *(prev(pos)) > tmp) {
            iter_swap(pos, prev(pos));
            --pos;
         }
         
         *pos = tmp;
      }
         
   } // if
}

//---------------------------------------------------------
template<typename RandomAccessIterator>
void selectionSortIter(RandomAccessIterator first,
                       RandomAccessIterator last) {

   if (distance(first, last) >= 2) {
      for (RandomAccessIterator it = first; it != prev(last); ++it) {
         RandomAccessIterator iterMin = min_element(next(it), last);
         if (*iterMin < *it)
            iter_swap(iterMin, it);
      } // for
   } // if
}


#endif

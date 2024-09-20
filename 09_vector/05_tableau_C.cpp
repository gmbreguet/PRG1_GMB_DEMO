//---------------------------------------------------------
// Demo           : 05_tableau_C
// Fichier        : 05_tableau_C.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2022-11-12
// But            : démontrer l'utilisation de tableaux C
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------
void afficher(const int tab[], size_t taille) {
   // const IMPORTANT pour
   // 1) fonction utilisable pour les tableaux constants
   // 2) accès RO sur le tableau, pas de modifications
   // /!\ sizeof(tab) retourne invariablement la taille du pointeur !!
   // const size_t TAILLE = sizeof(tab) / sizeof(tab[0]);
   cout << "[";
   for (size_t i=0; i<taille; ++i) {
      if (i)
         cout << ", ";
      cout << tab[i];
   }
   cout << "]";
}

//---------------------------------------------------------
// retourne l'indice de la valeur min du tableau (accès en RO)
// CAS PARTICULIER : que retourner pour un tableau vide => exception
// inline : https://en.cppreference.com/w/cpp/language/inline
inline size_t iMin(const int tab[], size_t taille) {
   cout << " => iMin(tab, taille) ";
   size_t iMin = 0;
   for (size_t i=1; i<taille; ++i)
      if (tab[i] < tab[iMin])
         iMin = i;
   return iMin;
}

//---------------------------------------------------------
// retourne une référence sur la valeur min (accès RW)
int& min(int tab[], size_t taille) {
   cout << " => int& min(tab, taille) ";
   return tab[iMin(tab, taille)];
}

//---------------------------------------------------------
// retourne la valeur min (accès RO)
int min(const int tab[], size_t taille) {
   cout << " => int  min(tab, taille) ";
   return tab[iMin(tab, taille)];
}

//---------------------------------------------------------
int main() {

   int entier     = 2;
   int* ptrEntier = &entier;
   
   // un pointeur sur une valeur occupe de la mémoire
   // (re-)voir 04_pointeurs.cpp
   cout << "entier            : " <<  entier             << endl;
   cout << "adr entier        : " << &entier             << endl;
   cout << "ptrEntier         : " <<  ptrEntier          << endl;
   cout << "adr ptrEntier     : " << &ptrEntier          << endl;
   cout << "valeur pointee    : " << *ptrEntier          << endl;
   cout << endl;

   // un tableau C n'occupe QUE la place du tableau
   // l'identificateur n'est qu'un alias de du premier octet
   const int TAB[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
         int tab[] = {0, 0, 0, 0, 0, 5, 6, 7, 8, 9};
   cout << "tab               : " <<  tab                << endl;
   cout << "adr tab           : " << &tab                << endl;
   cout << "&tab[0]           : " << &tab[0]             << endl;
   cout << endl;

   // accès aux éléments d'un tableau (lecture / écriture)
   tab[1]   = 1;
   *(tab+2) = 2;
   *(3+tab) = 3;
   4[tab]   = 4;
   cout << "tab[1]            : " <<  tab[1]             << endl;
   cout << "*(tab+2)          : " <<  *(tab+2)           << endl;
   cout << "*(3+tab)          : " <<  *(3+tab)           << endl;
   cout << "4[tab]            : " <<  4[tab]             << endl;
   ptrEntier = tab+5;
   cout << "ptrEntier[1]      : " <<  ptrEntier[1]       << endl;
   cout << "*(ptrEntier+2)    : " <<  *(ptrEntier+2)     << endl;
   cout << "*(3+ptrEntier)    : " <<  *(3+ptrEntier)     << endl;
   cout << "4[ptrEntier]      : " <<  4[ptrEntier]       << endl;
   cout << "ptrEntier[-1]     : " <<  ptrEntier[-1]      << endl;
   cout << endl;

   // aucune gestion des débordements
   cout << "tab[12]           : " <<  tab[12]            << endl;
   cout << "tab[-3]           : " <<  tab[-3]            << endl;

   // calcul de la taile d'un tableau (nbre d'éléments)
   // sizeof retourne le nbre d'octets d'une variable ou d'un type
   // /!\ POSSIBLE QUE DANS L'ESPACE DE DEFINITION DU TABLEAU C
   const size_t TAILLE = sizeof(tab) / sizeof(tab[0]);
   cout << "sizeof(tab)       : " <<  sizeof(tab)        << endl;
   cout << "sizeof(int)       : " <<  sizeof(int)        << endl;
   cout << "TAILLE            : " <<  TAILLE             << endl;
   cout << endl;

   // parcours dans les tableaux
   tab[7] = -2;
   afficher(tab, TAILLE); cout << endl;
   afficher(TAB, TAILLE); cout << endl;
   cout << endl;

   cout << "min(tab, TAILLE)  : " <<  min(tab, TAILLE)   << endl;
   cout << "min(TAB, TAILLE)  : " <<  min(TAB, TAILLE)   << endl;
   cout << endl;

   min(tab, TAILLE) = -20;
   // min(TAB, TAILLE) = -20;    // pas possible, tableau constant
   cout << endl;
   afficher(tab, TAILLE); cout << endl;


   return EXIT_SUCCESS;
}

//      entier            : 2
//      adr entier        : 0x7ff7bfeff328
//      ptrEntier         : 0x7ff7bfeff328
//      adr ptrEntier     : 0x7ff7bfeff320
//      valeur pointee    : 2
//
//      tab               : 0x7ff7bfeff330
//      adr tab           : 0x7ff7bfeff330
//      &tab[0]           : 0x7ff7bfeff330
//
//      tab[1]            : 1
//      *(tab+2)          : 2
//      *(3+tab)          : 3
//      4[tab]            : 4
//      ptrEntier[1]      : 4
//      *(ptrEntier+2)    : 5
//      *(3+ptrEntier)    : 6
//      4[ptrEntier]      : 7
//      ptrEntier[-1]     : 2
//
//      tab[12]           : 0
//      tab[-3]           : 32759
//      sizeof(tab)       : 40
//      sizeof(int)       : 4
//      TAILLE            : 10
//
//      [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
//      [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
//
//      min(tab, TAILLE)  :  => int& min(tab, taille)  => iMin(tab, taille) 0
//      min(TAB, TAILLE)  :  => int  min(tab, taille)  => iMin(tab, taille) 0
//
//       => int& min(tab, taille)  => iMin(tab, taille)
//      [-20, 1, 2, 3, 4, 5, 6, 7, 8, 9]

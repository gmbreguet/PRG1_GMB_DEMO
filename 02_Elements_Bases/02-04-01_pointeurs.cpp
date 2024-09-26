//---------------------------------------------------------
// Demo           : 02-04-01_pointeurs
// Fichier        : 02-04-01_pointeurs.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2024-09-26
// But            : relation pointeur et valeur pointée
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin


using namespace std;

int main() {

   {
      // pointeur non constant sur variable
      int   entier   = 17;
      int* ptrEntier = &entier; // adresse de entier dans le ptr

      cout << "entier           : " <<  entier           << endl;
      cout << "adr entier       : " << &entier           << endl;
      cout << "ptrEntier        : " <<  ptrEntier        << endl;
      cout << "adr ptrEntier    : " << &ptrEntier        << endl;
      cout << "valeur pointee   : " << *ptrEntier        << endl;
      cout << endl;

      entier = 21;
      cout << "entier           : " <<  entier           << endl;
      cout << "adr entier       : " << &entier           << endl;
      cout << "ptrEntier        : " <<  ptrEntier        << endl;
      cout << "adr ptrEntier    : " << &ptrEntier        << endl;
      cout << "valeur pointee   : " << *ptrEntier        << endl;
      cout << endl;

      *ptrEntier = 42;
      cout << "entier           : " <<  entier           << endl;
      cout << "adr entier       : " << &entier           << endl;
      cout << "ptrEntier        : " <<  ptrEntier        << endl;
      cout << "adr ptrEntier    : " << &ptrEntier        << endl;
      cout << "valeur pointee   : " << *ptrEntier        << endl;
      cout << endl;

      cout << "taille entier    : " << sizeof(entier)    << endl;
      cout << "taille ptrEntier : " << sizeof(ptrEntier) << endl;
   }

   {
      // pointeur non constant sur constante
      const int cste = 12;
      int var        = 3;
      int* ptr;

//    ptr = &cste;         // un ptr avec RW ne peut pas pointer sur une constante (R uniquement)
      ptr = &var;          // un ptr avec RW ne pointer sur une constante (RW)
   }

   {
      // pointeur (R) non constant sur constante
      const int cste = 12;
      int var        = 3;

      const int* ptr;

      ptr = &cste;         // un ptr avec R peut pointer sur une constante (R uniquement)
      ptr = &var;          // un ptr avec R peut pointer sur une variable mais en R seulement
   }

   {
      // pointeur constant
      const int cste = 12;
      int var        = 3;

      int* const ptr = &var;  // sera tjs associé à var, son contenu ne peut pas changer

//    ptr = &cste;         // son affectation n'est plus possible
//    ptr = &var;          // son affectation n'est plus possible
   }

   // fin de programme
   cout << "Presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}

//      entier           : 17
//      adr entier       : 0x7ff7bfeff3a8
//      ptrEntier        : 0x7ff7bfeff3a8
//      adr ptrEntier    : 0x7ff7bfeff3a0
//      valeur pointee   : 17
//
//      entier           : 21
//      adr entier       : 0x7ff7bfeff3a8
//      ptrEntier        : 0x7ff7bfeff3a8
//      adr ptrEntier    : 0x7ff7bfeff3a0
//      valeur pointee   : 21
//
//      entier           : 42
//      adr entier       : 0x7ff7bfeff3a8
//      ptrEntier        : 0x7ff7bfeff3a8
//      adr ptrEntier    : 0x7ff7bfeff3a0
//      valeur pointee   : 42
//
//      taille entier    : 4
//      taille ptrEntier : 8

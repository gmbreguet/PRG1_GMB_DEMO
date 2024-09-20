//---------------------------------------------------------
// Demo           : 04_pointeurs
// Fichier        : 04_pointeurs.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2022-10-20
// But            : relation pointeur et valeur pointée
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin


using namespace std;

int main() {
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

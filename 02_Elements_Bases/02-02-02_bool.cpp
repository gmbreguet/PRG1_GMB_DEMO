//---------------------------------------------------------
// Demo           : 02-02-02_bool
// Fichier        : 02-02-02_bool.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2023-09-25
// But            : utilisation des bool
// Modifications  : 
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin

using namespace std;
int main() {

   // variable de travail
   bool  b;
   cout << boolalpha;   // afficher les bool en false / true

   cout << "-------------"           << endl;
   cout << "   entier"               << endl;
   cout << "-------------"           << endl;
   b= 0;                   cout << b << endl;      // false
   b= 1;                   cout << b << endl;      // true
   b= -1;                  cout << b << endl;      // true
   cout << endl;

   cout << "-------------"           << endl;
   cout << "   char"                 << endl;
   cout << "-------------"           << endl;
   b= 'a';                 cout << b << endl;      // true
   b= 'B';                 cout << b << endl;      // true
   b= '\0';                cout << b << endl;      // false
   cout << endl;

   cout << "-------------"           << endl;
   cout << "   double"               << endl;
   cout << "-------------"           << endl;
   b= 0.0000;              cout << b << endl;      // false
   b= 0.00001;             cout << b << endl;      // true
   b= 1.0 / 3.0 - 0.333;   cout << b << endl;      // true

   // fin de programme
   return EXIT_SUCCESS;
}

//      -------------
//      entier
//      -------------
//      false
//      true
//      true
//
//      -------------
//      char
//      -------------
//      true
//      true
//      false
//
//      -------------
//      double
//      -------------
//      false
//      true
//      true

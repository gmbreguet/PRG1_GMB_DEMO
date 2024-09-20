//---------------------------------------------------------
// Demo           : 02-02-01_saisie_char
// Fichier        : 02-02-01_saisie_char.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2023-09-25
// But            : saisie de valeurs numériques en char
// Modifications  : 
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin

using namespace std;
int main() {

   // variable de travail
   char  c;

   // saisie
   cout << "entrer un caractère : ";
   cin >> c;
   // vider le buffer
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   // afficher la valeur saisie
   cout << endl;
   cout << "valeur saisie"       << endl;
   cout << "car c  : " << c      << endl
        << "int(c) : " << int(c) << endl;

   // fin de programme
   return EXIT_SUCCESS;
}

//      entrer un caractère : 1
//
//      valeur saisie
//      car c  : 1
//      int(c) : 49

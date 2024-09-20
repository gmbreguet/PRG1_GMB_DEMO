//---------------------------------------------------------
// Demo           : 07_classes_dependantes
// Fichier        : main.cpp
// Version        : 03 - 2022-12-19
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : démontrer l'utilisation de classes amies
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

#include "personne.hpp"
#include "date.hpp"

using namespace std;

//--------------------------------------------------------
int main() {
   
   Date     date   (11, 2, 2013);
   Personne charly ("Chappelin", date, Personne::Sexe::HOMME);
   
   cout << date << endl;
   cout << charly << endl;

   return EXIT_SUCCESS;
}

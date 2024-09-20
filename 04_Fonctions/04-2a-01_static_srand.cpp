//---------------------------------------------------------
// Demo           : 04_2a_static_srand
// Fichier        : 04_2a_static_srand.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2022-11-03
// But            : afficher des valeurs aléatoires
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>   // srand
#include <ctime>     // time pour srand

using namespace std;

//---------------------------------------------------------
int random (int min,
            int max);

//---------------------------------------------------------
int main() {

   cout << "[";
   for (int i=0; i<10; ++i) {
      if (i)
         cout << ", ";

      cout << random(-100, 100) << "";
   }
   cout << "]" << endl;
   return EXIT_SUCCESS;
}

//---------------------------------------------------------
int random (int min,
            int max) {

   // initialiser une seule fois le générateur
   static bool first = true;
   if (first) {
      srand ((unsigned)time (NULL));
      first = false;
   }

   // une valeur entre min et max compris
   return (rand() % (max-min+1) ) + min;
}

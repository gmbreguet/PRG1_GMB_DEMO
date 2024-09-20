//---------------------------------------------------------
// Demo           : 04_random
// Fichier        : 04_random.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2022-11-03
// But            : afficher des valeurs aléatoires
// Modifications  :
// Remarque(s)    : https://cplusplus.com/reference/random/default_random_engine
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

//---------------------------------------------------------
int main() {

   const int RANGE_FROM  = -100;
   const int RANGE_TO    = +100;

   random_device                  rand_dev;
   default_random_engine          generator(rand_dev());
   uniform_int_distribution<int>  distr(RANGE_FROM, RANGE_TO);

   cout << "[";
   for (int i=0; i<10; ++i) {
      if (i)
         cout << ", ";

      cout << distr(generator);
   }
   cout << "]" << endl;

   return EXIT_SUCCESS;
}

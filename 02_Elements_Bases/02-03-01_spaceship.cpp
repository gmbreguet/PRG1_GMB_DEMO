//---------------------------------------------------------
// Demo           : 02-03-01_spaceship
// Fichier        : 02-03-01_spaceship.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2023-09-26
// But            : utilisation de l'opérateur <=>
// Modifications  : 
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <compare>
#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin
#include <random>       // random

using namespace std;
int main() {
   // constantes
   const int MIN  =    0;
   const int MAX  = +100;

   // msg de bienvenue
   cout << "Ce programme ..." << endl;

   // génération d'une valeur aléatoire
   random_device                  rand_dev;
   default_random_engine          generator(rand_dev());
   uniform_int_distribution<int>  distr(MIN, MAX);
   const int valeur_aleatoire = distr(generator);
   cout << "valeur aleatoire  [" << MIN << " - " << MAX  << "] : " << valeur_aleatoire << endl;

   // saisie de la valeur utilisateur
   int saisie_utilisateur;
   cout << "entrer une valeur [" << MIN << " - " << MAX  << "] : ";
   cin  >> saisie_utilisateur;

   // calcul et affichage de l'écart
   strong_ordering delta = valeur_aleatoire <=> saisie_utilisateur;

   if (delta < 0)
      cout << "c'est moins"  << endl;
   else if (delta > 0)
      cout << "c'est plus"  << endl;
   else
      cout << "bravo !!"  << endl;

   // fin de programme
   cout << "fin de programme";
   return EXIT_SUCCESS;
}


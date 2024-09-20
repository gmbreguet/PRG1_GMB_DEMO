//---------------------------------------------------------
// Demo           : 05_enum_class
// Fichier        : 05_enum_class.cpp
// Version        : 02 2021-01-26
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : démontrer l'utilisation de vecteur
//                  et d'enum class
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//-------------------------------------------------------------------
enum class Chiffre {ZERO, UN,  DEUX, TROIS, QUATRE,
                    CINQ, SIX, SEPT, HUIT,  NEUF};

const vector<string> CHIFFRE = {"ZERO", "UN",  "DEUX", "TROIS", "QUATRE",
                                "CINQ", "SIX", "SEPT", "HUIT",  "NEUF"};

//-------------------------------------------------------------------
// operateur de flux
ostream& operator<< (ostream& os, const Chiffre& c);

//-------------------------------------------------------------------
// operateur ++ (pré-incrémentation) utile pour la boucle
Chiffre& operator++ (Chiffre& c);

//-------------------------------------------------------------------
int main() {
   cout << "[";

   const Chiffre DEBUT = Chiffre::DEUX;
   const Chiffre FIN   = Chiffre::HUIT;

   for (Chiffre i=DEBUT; i<=FIN; ++i) {
      if (i > DEBUT)
         cout << ", ";

      cout << i;
   }

   cout << "]" << endl;

   return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
ostream& operator<<(ostream& os, const Chiffre& c) {
   os << CHIFFRE.at( size_t(c) );
   return os;
}

//-------------------------------------------------------------------
Chiffre& operator++ (Chiffre& c) {
   c = Chiffre( int(c) + 1 );
   return c;
}

//      [DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT]

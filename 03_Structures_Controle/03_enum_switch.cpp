//---------------------------------------------------------
// Demo           : 03_enum_switch
// Fichier        : 03_enum_switch.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 04 - 2022-11-17
// But            : démo sur les enum et enum class
// Modifications  : ajout switch GNU range extension
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
   {
      cout << "----------------" << endl;
      cout << "   enum         " << endl;
      cout << "----------------" << endl;
      // constantes d'énumération doivent être uniques
      enum Couleur {ROUGE, VERT, BLEU, ROSE, VIOLET};
      enum Fleur   {VIOLETTE, MARGUERITTE, MUGUET};   // ROSE n'est pas possible

      Couleur uneCouleur = ROUGE;

      // affichage des enum
      cout << ROUGE << endl;                          // => 0

      // dans un switch
      switch (uneCouleur) {
         case ROUGE  : cout << "rouge"    << endl; break;
         case VERT   : cout << "vert"     << endl; break;
         case BLEU   : cout << "bleu"     << endl; break;
         case ROSE   : cout << "rose"     << endl; break;
         case VIOLET : cout << "violet"   << endl; break;
      }
      cout << endl;
   }

   {
      cout << "----------------" << endl;
      cout << "   enum class   " << endl;
      cout << "----------------" << endl;

      // constantes d'énumération peuvent être reprises dans d'autres enum class
      enum class Couleur {ROUGE, VERT, BLEU,     ROSE, VIOLET};
      enum class Fleur   {VIOLETTE, MARGUERITTE, ROSE, MUGUET};   // ROSE est possible

      Couleur uneCouleur = Couleur::ROUGE;

      // affichage des enum
//    cout << Couleur::ROUGE << endl;                 // => pas possible d'afficher une couleur
      cout << (int)Couleur::ROUGE << endl;            // => cast nécessaire

      // dans un switch
      switch ( uneCouleur ) {
         case Couleur::ROUGE  : cout << "rouge"    << endl; break;
         case Couleur::VERT   : cout << "vert"     << endl; break;
         case Couleur::BLEU   : cout << "bleu"     << endl; break;
         case Couleur::ROSE   : cout << "rose"     << endl; break;
         case Couleur::VIOLET : cout << "violet"   << endl; break;
      }

      const string COULEUR[] = {"rouge", "vert", "bleu", "rose", "violet"};
      cout << COULEUR[int(uneCouleur)] << endl;
      cout << endl;
   }

   {
      cout << "----------------" << endl;
      cout << "   valeurs      " << endl;
      cout << "----------------" << endl;
      enum Chiffre {ZERO=1, UN, DEUX, TROIS=0, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF=50};
      cout << ZERO << UN << DEUX << TROIS << QUATRE << CINQ << SIX << SEPT << HUIT << NEUF << endl;
      // => 12301234550

      cout << endl;
   }

   {
      cout << "----------------" << endl;
      cout << "   operateurs   " << endl;
      cout << "----------------" << endl;
      enum       EnumEnC   {AA, BB, CC};
      enum class EnumClass {AA, BB=0, CC};

      EnumEnC     enumEnC     = AA;
      EnumClass   enumClass   = EnumClass::AA;

      AA + 1;
//    EnumClass::AA + 1;                     // pas de +

//    enumEnC++;                             // pas de ++
//    enumClass++;                           // pas de ++

      cout << endl;

      // parcourt avec des enum en C
      cout << "enum en C : ";
      for (EnumEnC i=AA; i<CC; i=EnumEnC(int(i)+1))
         cout << i << " ";

      // parcourt avec des enum class
      cout << endl;
      cout << "enum class : ";
      for (EnumClass i=EnumClass::AA; i<EnumClass::CC; i=EnumClass(int(i)+1))
         cout << int(i) << " ";

      cout << endl << endl;
   }

   {
      cout << "----------------" << endl;
      cout << "   switch GNU   " << endl;
      cout << "----------------" << endl;
      cout << "switch GNU range extension => pas recommendé ... !!" << endl;

      char car = 'v';

      switch (car) {
         case '0' ... '9' : cout << "chiffre"      << endl; break;
         case 'a' ... 'z' : cout << "minuscule"    << endl; break;
         case 'A' ... 'Z' : cout << "majuscule"    << endl; break;
         default          : cout << "autre ..."    << endl;
      }
   }

   return EXIT_SUCCESS;
}

//      ----------------
//         enum
//      ----------------
//      0
//      rouge
//
//      ----------------
//         enum class
//      ----------------
//      0
//      rouge
//      rouge
//
//      ----------------
//         valeurs
//      ----------------
//      12301234550
//
//      ----------------
//         operateurs
//      ----------------
//
//      enum en C : 0 1
//      enum class : 0
//
//      ----------------
//         switch GNU
//      ----------------
//      switch GNU range extension => pas recommendé ... !!
//      minuscule

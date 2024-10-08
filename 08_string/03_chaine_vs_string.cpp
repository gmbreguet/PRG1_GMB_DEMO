//---------------------------------------------------------
// Demo           : 03_chaine_vs_string
// Fichier        : 03_chaine_vs_string.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2022-10-10
// But            : comparaisons entre chaine C et string
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
   // -------------
   // operateurs de flux
   // -------------
   // les chaines comme les strings peuvent contenir des caractères spéciaux
   // de mise en forme, interpretés par le terminal
   cout << "chaine en C\navec une mise à la ligne,\tune tabulation et une \0 terminaison"     << endl;
   cout << endl;
   cout << "un string en C\navec une mise à la ligne,\tune tabulation et une \0 terminaison"s << endl;
   cout << endl;

   cout << "une chaine "      // écrite sur deux lignes
           "sur deux ligne";  // .. mais une seule chaine
   cout << endl;

   cout << "-------------" << endl;
   cout << "chaine C"      << endl;
   cout << "-------------" << endl;
   cout << boolalpha;
   cout << "maison < mais   : " << ("maison" < "mais")   << endl;
   cout << "mais   < maison : " << ("mais"   < "maison") << endl;

   cout << (void*) "mais"      << "\t" << "mais"         << endl;
   cout << (void*) "maison"    << "\t" << "maison"       << endl;
   cout << (void*)&"maison"[0] << "\t" << "maison"[0]    << endl;
   cout << endl;

   cout << "-------------" << endl;
   cout << "string"        << endl;
   cout << "-------------" << endl;
   cout << boolalpha;
   cout << "maison < mais   : " << ("maison"s < "mais"s)    << endl;
   cout << "mais   < maison : " << ("mais"s   < "maison"s)  << endl;

   return EXIT_SUCCESS;
}

//      chaine en C
//      avec une mise à la ligne,   une tabulation et une
//
//      un string en C
//      avec une mise à la ligne,   une tabulation et une   terminaison
//
//      une chaine sur deux ligne
//      -------------
//      chaine C
//      -------------
//      maison < mais   : true
//      mais   < maison : false
//      0x100003f18   mais
//      0x100003f11   maison
//      0x100003f11   m
//
//      -------------
//      string
//      -------------
//      maison < mais   : false
//      mais   < maison : true
//      Program ended with exit code: 0

//---------------------------------------------------------
// Demo           : 04_2_passage_parametre
// Fichier        : 04_2_passage_parametre.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2023-10-07
// But            : différents passages de paramètre
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------
// How are references implemented internally?
// https://stackoverflow.com/questions/3954764/how-are-references-implemented-internally

#include <cstdlib>
#include <iostream>

using namespace std;

//-----------------------------------------------
void param_par_copie(int param) {
   cout << " param      : " <<  param << endl;
   cout << "&param      : " << &param << endl;
}

//-----------------------------------------------
void param_par_reference(const int& param) {
   cout << " param      : " <<  param << endl;
   cout << "&param      : " << &param << endl;
}

//-----------------------------------------------
void param_par_adresse(const int* param) {
   cout << " param      : " <<  param << endl;
   cout << "*param      : " << *param << endl;
   cout << "&param      : " << &param << endl;
}

//-----------------------------------------------
int main() {

   int  valeur    = 12;
   int& reference = valeur;

   cout << "-------------------------------" << endl;
   cout << " valeur     : " <<  valeur       << endl;
   cout << "&valeur     : " << &valeur       << endl;

   cout << " reference  : " <<  reference    << endl;
   cout << "&reference  : " << &reference    << endl;

   cout << "-------------------------------" << endl;
   cout << "passage par copie"               << endl;
   param_par_copie(valeur);

   cout << "-------------------------------" << endl;
   cout << "passage par référence"           << endl;
   param_par_reference(valeur);

   cout << "-------------------------------" << endl;
   cout << "passage par adresse"             << endl;
   param_par_adresse(&valeur);

   return EXIT_SUCCESS;
}

//      -------------------------------
//      valeur     : 12
//      &valeur     : 0x16fd7b688
//      reference  : 12
//      &reference  : 0x16fd7b688
//      -------------------------------
//      passage par copie
//       param      : 12
//      &param      : 0x16fd7b63c
//      -------------------------------
//      passage par référence
//       param      : 12
//      &param      : 0x16fd7b688
//      -------------------------------
//      passage par adresse
//       param      : 0x16fd7b688
//      *param      : 12
//      &param      : 0x16fd7b638

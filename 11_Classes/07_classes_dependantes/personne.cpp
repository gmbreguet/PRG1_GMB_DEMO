//---------------------------------------------------------
// Demo           : 07_classes_dependantes
// Fichier        : personne.cpp
// Version        : 03 - 2022-12-19
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : implémentation de la classe personne
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "personne.hpp"
#include <iostream>

using namespace std;

//--------------------------------------------------------
ostream& operator<< (ostream& os, const Personne& personne) {
   os << "nom   = " << personne.nom       << endl;
   os << "annee = " << personne.naissance << endl;
   return os;
}

//--------------------------------------------------------
Personne::Personne(const string& nom,
                   const Date&   date,
                   const Sexe&   sexe)
: nom(nom), naissance(date), sexe(sexe) { }


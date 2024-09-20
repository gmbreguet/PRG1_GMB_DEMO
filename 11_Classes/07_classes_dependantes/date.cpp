//---------------------------------------------------------
// Demo           : 07_classes_dependantes
// Fichier        : date.cpp
// Version        : 03 - 2022-12-19
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : implémentation de la classe date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "date.hpp"

#include <iostream>
using namespace std;

//--------------------------------------------------------
ostream& operator<< (std::ostream& os, const Date& date) {
   os << date.jour << "/" << date.mois << "/" << date.annee;
   return os;
}

//--------------------------------------------------------
Date::Date (const int jour,
            const int mois,
            const int annee) {
   this->jour  = jour;
   this->mois  = mois;
   this->annee = annee;
}

//--------------------------------------------------------
Date::Date (const Date& date) {
   this->jour  = date.jour;
   this->mois  = date.mois;
   this->annee = date.annee;
}

//--------------------------------------------------------
Date& Date::operator= (const Date& date) {
   this->jour  = date.jour;
   this->mois  = date.mois;
   this->annee = date.annee;
   return *this;
}

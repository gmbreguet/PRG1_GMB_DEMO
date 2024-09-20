//---------------------------------------------------------
// Demo           : 07_classes_dependantes
// Fichier        : date.hpp
// Version        : 03 - 2022-12-19
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : classe date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef Date_H
#define Date_H

#include <ostream>

class Date {
   friend std::ostream& operator<< (std::ostream& os, const Date& date);

public:
   Date (const int jour  =    1,
         const int mois  =    1,
         const int annee = 2000);

   Date (const Date& date);

   Date& operator= (const Date& date);

private:
   int jour;
   int mois;
   int annee;
};

#endif


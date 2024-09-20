//---------------------------------------------------------
// Demo           : 07_protected
// Fichier        : date.h
// Version        : 03 - 2022-12-15
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : classe date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef Date_H
#define Date_H

#include <ostream>

//---------------------------------------------------------
class Date {
   
friend class Personne;
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


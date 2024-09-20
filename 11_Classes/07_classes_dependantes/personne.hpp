//---------------------------------------------------------
// Demo           : 07_classes_dependantes
// Fichier        : personne.hpp
// Version        : 03 - 2022-12-19
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : classe personne ...
//                  et utilisation de la clase date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef Personne_H
#define Personne_H

#include <string>
#include "date.hpp"


class Personne {
   friend std::ostream& operator<< (std::ostream& os, const Personne& personne);

public:
   enum class Sexe {HOMME, FEMME};
   Personne (const std::string& nom,
             const Date&        date,
             const Sexe&        sexe);

private:
   const std::string nom;
   const Date        naissance;
   const Sexe        sexe;
};

#endif

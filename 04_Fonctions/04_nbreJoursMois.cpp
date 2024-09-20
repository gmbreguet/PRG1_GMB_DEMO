//---------------------------------------------------------
// Demo           : 04_nbreJoursMois
// Fichier        : 04_nbreJoursMois.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2022-10-20
// But            : affiche le nbre de jours pour un mois / année
//                  saisi par l'utilisateur
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//---------------------------------------------------------
// sous-programme général
int saisie(const string& msgInvite,
           const string& msgErreur,
           int min,
           int max);

//---------------------------------------------------------
// sous-programmes de dates etc ...
bool   estBissextile (int annee);
int    nbreJoursMois (int mois, int annee);
string nomMois       (int mois);

//---------------------------------------------------------
int main() {
   //                   msg invite     msg erreur
   int noMois  = saisie("no mois   ", "erreur de saisie",    1,   12);
   int annee   = saisie("annee"     , "erreur de saisie", 1900, 2200);

   cout << "il y a " << nbreJoursMois(noMois, annee) << " jours en "
                     << nomMois(noMois) << " " << annee << endl;

   cout << endl;
   return EXIT_SUCCESS;
}

//---------------------------------------------------------
int saisie(const string& msgInvite,
           const string& msgErreur,
           int min,
           int max) {

   int          saisie;    // ne peuvent pas être déclarés
   bool         erreur;    // ... dans la boucle

   do {
      // saisie et vérification
      cout << msgInvite << " [" << min << " - " << max << "] : ";
      erreur = not(cin >> saisie) or saisie < min or saisie > max;

      // gestion du flux
      if (erreur) {
         cout << msgErreur << endl;
         cin.clear();
      }

      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(erreur);

   // retour de la valeur saisie
   return saisie;
}

//---------------------------------------------------------
bool estBissextile(int annee) {
   // divisible par 4      ou alors par 4 mais pas par 100
   return (annee % 4 == 0) or (annee % 4 == 0 and annee % 100 != 0);
}

//---------------------------------------------------------
int  nbreJoursMois(int mois, int annee) {
   switch (mois) {
      case  1 : return 31;
      case  2 : return 28 + estBissextile(annee);
      case  3 : return 31;
      case  4 : return 30;
      case  5 : return 31;
      case  6 : return 30;
      case  7 : return 31;
      case  8 : return 31;
      case  9 : return 30;
      case 10 : return 31;
      case 11 : return 30;
      case 12 : return 31;
   }

   return -1;  // cas d'erreur (à définir)
   // en pratique exception, voire un assert
}

//---------------------------------------------------------
string nomMois(int mois) {
   static const vector<string> MOIS = {"janvier", "fevrier", "mars",      "avril",   "mai",      "juin",
                                       "juillet", "aout",    "septembre", "octobre", "novembre", "decembre"};

   // volontairement un .at pour lever une exception
   return MOIS.at( size_t(mois - 1) );
}

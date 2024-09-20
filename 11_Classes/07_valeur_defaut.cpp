//---------------------------------------------------------
// Demo           : 07_valeur_defaut
// Fichier        : 07_valeur_defaut.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2   2022-12-12
// But            : démontrer les valeurs par défauts
//                  des propriétés et constructeurs
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------
// une classe dont les propriétés sont publics
// => pas conseillé
class A {
public:

   //------------------------------------------------------
   A() = default;

   //------------------------------------------------------
   A (int entier, double reel)
//   A (int entier = 10, double reel = 23.4)
   : entier(entier), reel(reel) { };

   //---------------------------------------------------------
   int    entier = 1;
   double reel   = 2.3;
};

//---------------------------------------------------------
// pas "friend" car toutes les propriétés sont publics
// => pas conseillé
ostream& operator<< (ostream& os, const A& a) {
   os << a.entier << " / " << a.reel;
   return os;
}

//---------------------------------------------------------
int main() {
   //------------------------------------------------------
   cout << "constructeur par defaut" << endl;
   A a1;
   cout << "A a1              => " << a1 << endl;
   cout << endl;

   //------------------------------------------------------
   cout << "constructeur avec parametres" << endl;
   A a2(0, 0.0);
   cout << "A a2              => " << a2 << endl;


   return EXIT_SUCCESS;
}

//      constructeur par defaut
//      A a1              => 10 / 23.4
//
//      constructeur avec parametres
//      A a2              => 0 / 0

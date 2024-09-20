//---------------------------------------------------------
// Demo           : 07_constructor_defaut
// Fichier        : 07_constructor_defaut.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2   2022-12-08
// But            : démontrer les bases des constructeurs
//                  par defaut
// Modifications  : 1) ajout constructeur uniforme (C++11)
//                  2) classe avec 2 propriétés publics
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------
// une classe dont les propriétés sont publics
// /!\ PAS RECOMMANDE selon le principe de l'encapsulation
class A {
public:
   int    entier;
   double reel;
};

//---------------------------------------------------------
// pas "friend" car toutes les propriétés sont publics
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
   a1.entier = 1;
   cout << "a1.entier = 1     => " << a1 << endl;
   a1.reel   = 2.3;
   cout << "a1.reel   = 2.3   => " << a1 << endl;
   cout << endl;

   //------------------------------------------------------
   cout << "constructeur par copie" << endl;
   A a2 = a1;
   cout << "A a2 = a1         => " << a2 << endl;
   cout << endl;

   //------------------------------------------------------
   cout << "constructeur par copie" << endl;
   A a3(a2);
   cout << "A a3(a2)          => " << a3 << endl;
   cout << endl;

   //------------------------------------------------------
   cout << "constructeur uniforme (C++11)" << endl;
   A a4 {10, 12.3};
   cout << "A a4 {10, 12.3}   => " << a4 << endl;

   A a5 {11};
   cout << "A a5 {11}         => " << a5 << endl;

   A a6 {};
   cout << "A a6 {}           => " << a6 << endl;
   cout << endl;

   //------------------------------------------------------
   cout << "operateur d'affectation" << endl;
   A a7;       // déclaration
   a7 = a3;    // affectation
   cout << "a7 = a3           => " << a7 << endl;

   a7 = A(a3);   // affectation
   cout << "A(a3)             => " << a7 << endl;

   a7 = {30, 45.6};     // affectation
   cout << "a7 = {20, 34.5}   => " << a7 << endl;

   a7 = {21};           // affectation
   cout << "a7 = {21}         => WARNING : Missing field 'reel' initializer" << endl;

   a7 = A{21};          // affectation
   cout << "a7 = A{21}        => WARNING : Missing field 'reel' initializer" << endl;

   a7 = {};    // affectation
   cout << "a7 = {}           => " << a7 << endl;
   cout << endl;

   return EXIT_SUCCESS;
}

//      constructeur par defaut
//      A a1              => 99600 / 2.12205e-314
//      a1.entier = 1     => 1 / 2.12205e-314
//      a1.reel   = 2.3   => 1 / 2.3
//
//      constructeur par copie
//      A a2 = a1         => 1 / 2.3
//
//      constructeur par copie
//      A a3(a2)          => 1 / 2.3
//
//      constructeur uniforme (C++11)
//      A a4 {10, 12.3}   => 10 / 12.3
//      A a5 {11}         => 11 / 0
//      A a6 {}           => 0 / 0
//
//      operateur d'affectation
//      a7 = a3           => 1 / 2.3
//      A(a3)             => 1 / 2.3
//      a7 = {20, 34.5}   => 30 / 45.6
//      a7 = {21}         => WARNING : Missing field 'reel' initializer
//      a7 = A{21}        => WARNING : Missing field 'reel' initializer
//      a7 = {}           => 0 / 0
//

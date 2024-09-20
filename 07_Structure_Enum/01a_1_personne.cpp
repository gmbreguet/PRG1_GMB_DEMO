//---------------------------------------------------------
// Demo           : 01a_1_personne
// Fichier        : 01a_1_personne.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2023-09-26
// But            : utilisation des struct
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <utility> // pair

using namespace std;

//---------------------------------------------------------
struct Date {
   int jour;
   int mois;
   int annee;
};

//---------------------------------------------------------
struct Personne {
   string nom;
   int    age;
   Date   anniversaire;
};

//---------------------------------------------------------
struct Coord {
   int x, y, z;
};

Coord c = {1, 2, 3};
//---------------------------------------------------------
struct structure {
   int    entier;
   const  char cste = 'A';
   double* ptr      = nullptr;
};

//---------------------------------------------------------
void afficher(const Date& date) {
   cout << date.jour << "."
        << date.mois << "."
        << date.annee;
   cout << endl;
}

//---------------------------------------------------------
//
bool est_bissextile(const Date& date);
void decaller(Date& lhs, int n);
Date prochaine_date(const Date& lhs, int n);
Date creer_date(int jour, int mois, int annee);

bool operator< (const Date& lhs, const Date& rhs) {
   if (lhs.annee != rhs.annee)
      return lhs.annee < rhs.annee;

   if (lhs.mois != rhs.mois)
      return lhs.mois < rhs.mois;

   return lhs.jour < rhs.jour;
}

bool operator== (const Date& lhs, const Date& rhs) {
   return lhs.jour  == rhs.jour and
          lhs.mois  == rhs.mois and
          lhs.annee == rhs.annee;
}

//---------------------------------------------------------
template <typename U1, typename U2>
void afficher(const pair<U1, U2>& p) {
   cout << "[" << p.first << ", " << p.second << "]";
}


//---------------------------------------------------------
template <typename U1, typename U2>
ostream& operator<< (ostream& os, const pair<U1, U2>& p) {
   os << "[" << p.first << ", " << p.second << "]" << endl;
}

enum class DirH {GAUCHE, CENTRE, DROITE};
DirH d1 = DirH::GAUCHE;
DirH d2 = DirH::DROITE;

bool meme_direction (const DirH lhs, const DirH rhs) {
   return lhs == rhs;
}

enum class Jour {LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE};
Jour prochain_jour (Jour jour, int n=1) {
   if (n<0)
      return jour;
   return (Jour)( ((int)jour + n) % 7);
}
//---------------------------------------------------------
//void divmod(int numerateur,
//            int denominateur,
//            int& quotient,
//            int& reste) {
//   quotient = numerateur / denominateur;
//   reste = numerateur % denominateur;
//}
//---------------------------------------------------------
struct Qutient_Reste {
   int quotient;
   int reste;
};
Qutient_Reste divmod(int numerateur,
                     int denominateur) {

   Qutient_Reste resultat;
   resultat.quotient = numerateur / denominateur;
   resultat.reste    = numerateur % denominateur;

   return resultat;

   // ou
   Qutient_Reste resultat {numerateur / denominateur,
                           numerateur % denominateur};
   return resultat;

   // ou
   return Qutient_Reste {numerateur / denominateur,
                         numerateur % denominateur};
}


pair<int, int> divmod2(int numerateur, int denominateur) {

   return pair {numerateur / denominateur,
                numerateur % denominateur};

}



//---------------------------------------------------------
int main() {
   // enum
   if (d1 == d2)
      cout << ".. idem ..";

   cout << (int)prochain_jour(Jour::VENDREDI, 3) << endl;

   // déclaration - par position
   Date date1;                                     // ??, ??, ????
   Date date2 = {1, 2, 2019};                      //  1,  2, 2019
   Date date3 = {1, 2};                            //  1,  2, 0

   Personne Vide;                                  // «»,     ??, ??, ??, ????
   Personne Anna = {"Anna",  4, date2};            // «Anna», 18,  4,  2, 2019
   Personne Jean = {"Jean", 18, {11, 3, 2005}};    // «Jean», 18, 11,  3, 2005
   Personne Paul = {"Paul", 27,  31, 7, 1996 };    // «Paul», 27, 31,  7, 1996

   // déclaration - par position
   Date date4 = {.jour=13, .mois=1, .annee=2007};  // 13,  1, 1998
   Date date5 = {.annee=1998, .mois=6, .jour=7};   //  7,  6, 1998
   Date date6 = {.annee=1998,          .jour=7};   //  7,  0, 1998
   auto [n, a, d] = Anna;

   // est équivalent à
   string j_ = Anna.nom;
   int    m_ = Anna.age;
   Date   a_ = Anna.anniversaire;

   // déclaration - par position
   Date date4 = {.jour=13, .mois=1, .annee=2007};  // 13,  1, 1998
   Date date5 = {.jour=13,          .annee=1998};  // 13,  0, 1998

   // affectation - globale
   date1 = date2;

   date1.jour = 12;
   int mois = date1.mois;

   // référence
   Date& refDate = date1;
   cout << refDate.jour;

   // pointeur
   Date* ptrDate = & date1;
   cout << (*ptrDate).jour;
   cout << ptrDate->jour;

   afficher(date4);
   afficher(date5);

//   auto [ j, m, a ] = date1;
//
//   // est équivalent à
//   int j_ = date1.jour;
//   int m_ = date1.mois;
//   int a_ = date1.annee;

   // comparaison
   //date1 < date2;    // ne compile pas

   // pair
   //   pair<U1, U2>& p;                                // (1)
   //
   //   constexpr pair( const T1& x, const T2& y );     // (2)
   //
   //   template< class U1, class U2 >                  // (4)
   //   constexpr pair( pair<U1, U2>& p );

   pair<int, float> p1;                            // (1) => 0, 0
   cout << "p1.first  : " << p1.first  << endl;
   cout << "p1.second : " << p1.second << endl;

   pair<int, double> p2{65, 3.1415};               // (2) => 65, 3.1415
   cout << "p2 : " << p2 << endl;
   cout << "p2.first  : " << p2.first  << endl;
   cout << "p2.second : " << p2.second << endl;

   pair<char, int> p4{p2};                         // (4) => 'A', 3
   cout << "p4 : " << p4 << endl;

   pair<string, double> pomme       ("pomme"s, 1.75);
   pair<string, double> pomme_promo ("pomme"s, 1.25);
   pair<string, double> poire       ("poire"s, 2.30);
   pair<string, double> poire_promo ("poire"s, 1.90);

   cout << (pomme == poire);              // false
   cout << (pomme == pomme_promo);        // false
   cout << (pomme == pomme);              // true

   cout << (pomme <  poire);              // false  "pomme" < "poire"
   cout << (poire <  pomme);              // true   "poire" < "pomme"
   cout << (pomme <  pomme_promo);        // false  "pomme" == "pomme" mais 1.75 > 1.25
   cout << (pomme_promo <  pomme);        // true   "pomme" == "pomme" et   1.25 < 1.75

   // Le record mondial absolu est de 56,7°C.
   // Il a été établi à Furnace Creek, dans la vallée de la mort,
   // en Californie, le 10 juillet 191
   pair<Date, double> Furnace_Creek  ({10, 7, 1913}, 56.7);
   auto [ date, temp ] = Furnace_Creek;

   int numerateur    = 11;
   int denominateur  =  2;
   int quotient;
   int reste;
   divmod(numerateur, denominateur,
          quotient,   reste);


   return EXIT_SUCCESS;
}

//---------------------------------------------------------
// Demo           : 07_operator
// Fichier        : 07_operator.h
// Version        : 02 - 2022-12-15
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : démontrer les bases des operateurs
//                : NB sans operateur à 3 voies <=>
// Modifications  :
// Remarque(s)    : https://en.cppreference.com/w/cpp/language/operators
//---------------------------------------------------------
#include <iostream>
using namespace std;

//---------------------------------------------------------------------
// pré-déclaration
class Entier;

//---------------------------------------------------------------------
// fonction ordinaire (le friend n'est en fait pas obligatoire)
Entier operator+  (int i, const Entier& e);

//---------------------------------------------------------------------
class Entier {
public:
   friend std::ostream& operator<<(std::ostream& os, const Entier& e);
   friend Entier        operator* (int i, const Entier& e);

   Entier(const Entier& e) : v(e.v) {};
   Entier(const int v=0)   : v(v)   {};
   Entier& operator=(const Entier& autre);

   // operateurs mathématiques
   Entier  operator+  (int i)                   { return Entier(this->v + i); };

   // operateurs d'affectation
   Entier& operator+= (int i)                   { this->v += i;                return *this; };
   Entier& operator++ ()                        { this->v++;                   return *this; };
   Entier  operator++ (int)                     { Entier tmp=*this; ++(*this); return tmp;   };

   // operateurs de comparaison
   bool operator<  (const Entier& autre) const  { return   this->v < autre.v; };
   bool operator>  (const Entier& autre) const  { return     autre < *this;   };
   bool operator<= (const Entier& autre) const  { return not(*this > autre);  };
   bool operator>= (const Entier& autre) const  { return not(*this < autre);  };

   bool operator== (const Entier& autre) const  { return this->v == autre.v;  };
   bool operator!= (const Entier& autre) const  { return not(*this == autre); };

   // cast Entier => int
   operator int()                        const  { return this->v;                }
   
private:
   int v = 0;
};

//---------------------------------------------------------------------
int  main() {

   Entier v1(1);
   Entier v2(2);

   cout << "v1          : " << v1            << endl;
   cout << "v2          : " << v2            << endl;

   cout << boolalpha;   // bool => false / true
   cout << "v1 < v2     : " << (v1 < v2)     << endl;
   cout << "v1 > v2     : " << (v1 > v2)     << endl;
   cout << "v1 <= v2    : " << (v1 <= v2)    << endl;
   cout << "v1 >= v2    : " << (v1 >= v2)    << endl;

   cout << "v1 == v2    : " << (v1 == v2)    << endl;
   cout << "v1 != v2    : " << (v1 != v2)    << endl;

   cout << "v1 + 2      : " << v1 + 2        << endl;
   cout << "3 + v1      : " << 3 + v1        << endl;
   cout << "v1 += 2     : " << (v1 += 2)     << endl;
   cout << "v1++        : " << (v1++)        << endl;
   cout << "++v1        : " << (++v1)        << endl;

   cout << "int(v1)     : " << int(v1)       << endl;
}

//---------------------------------------------------------------------
// operateur de flux <<
ostream& operator <<(ostream& os, const Entier& e) {
   return os << e.v;
}

//---------------------------------------------------------------------
Entier  operator+ (int i, const Entier& e) {
   return Entier(e) + i;
}

//---------------------------------------------------------------------
// operateur d'affectation
Entier& Entier::operator=(const Entier& autre) {
   // si ce sont les mêmes
   if (this == &autre)
      return *this;
   
   // si différents
   this->v = autre.v;
   return *this;
}

//      v1          : 1
//      v2          : 2
//      v1 < v2     : true
//      v1 > v2     : false
//      v1 <= v2    : true
//      v1 >= v2    : false
//      v1 == v2    : false
//      v1 != v2    : true
//      v1 + 2      : 3
//      3 + v1      : 4
//      v1 += 2     : 3
//      v1++        : 3
//      ++v1        : 5
//      int(v1)     : 5

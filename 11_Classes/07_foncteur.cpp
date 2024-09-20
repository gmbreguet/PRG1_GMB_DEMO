//---------------------------------------------------------
// Demo           : 07_foncteur
// Fichier        : 07_foncteur.cpp
// Version        : 01 - 2022-18-19
// Auteur(s)      : (C) BREGUET Guy-Michel
// But            : exemple de foncteur
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>    // count, count_if

using namespace std;

//---------------------------------------------------------
ostream& operator<< (ostream& os, const vector<int>& v);

//---------------------------------------------------
// foncteur de comparaison
class LowerThan {
public:
   LowerThan(const int t) : ref(t) {};
   bool operator() (const int actual) const { return actual < ref; };
private:
   const int ref;
};

//---------------------------------------------------
int main() {

   vector<int> vecteur = {4, 8, 3, 9, 8, 2, 1, 5, 6};
   int         valeur  = 5;

   cout << "vecteur " << vecteur << endl;
   cout << "nbre de " << valeur  << " : " << count   (vecteur.begin(), vecteur.end(),           valeur)  << endl;
   cout << "nbre <  " << valeur  << " : " << count_if(vecteur.begin(), vecteur.end(), LowerThan(valeur)) << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------
ostream& operator<< (ostream& os, const vector<int>& v) {
   os << "[";
   for(size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

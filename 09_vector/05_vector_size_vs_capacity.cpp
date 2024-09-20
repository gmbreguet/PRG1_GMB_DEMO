//---------------------------------------------------------
// Demo           : 05_vector_size_vs_capacity
// Fichier        : 05_vector_size_vs_capacity.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : démontrer l'évolution de size et capacity
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//---------------------------------------------------------
using Vect = vector<int>;

//---------------------------------------------------------
void putHeader (const string& ACTION, int MARGE);
void putDetails(const Vect& v, const string& msg);

//---------------------------------------------------------
const int MARGE   =      17;
const int STEP    =  10'000;
const int MAX     = 100'000;

//---------------------------------------------------------
int main() {

   Vect  v;

   //---------------------------------------------------------
   cout  << "-----------------------------------------------------"  << endl;
   cout << "sizeof de vecteurs : " << endl;
   cout << "Vect(  0)   : " << sizeof(Vect(  0))   << " octets" << endl;
   cout << "Vect( 10)   : " << sizeof(Vect( 10))   << " octets" << endl;
   cout << "Vect(100)   : " << sizeof(Vect(100))   << " octets" << endl;

   //---------------------------------------------------------
   putHeader("RESIZE", MARGE);
   v.resize(100);          putDetails(v, "v(100)");
   v.resize(10'000);       putDetails(v, "v.resize(1000)");
   v.resize(10);           putDetails(v, "v.resize(10)");


   //---------------------------------------------------------
   putHeader("CAPACITY", MARGE);
   v.reserve(10);
   v.shrink_to_fit();      putDetails(v, "v.reserve(10)");
   v.reserve(1000);        putDetails(v, "v.reserve(1000)");
   v.reserve(10);          putDetails(v, "v.reserve(10)");
   v.resize(10);           putDetails(v, "v.resize(10)");
   v.shrink_to_fit();      putDetails(v, "v.shrink_to_fit()");

   //---------------------------------------------------------
   putHeader("PUSH_BACK", MARGE);
   v.resize(0);
   v.shrink_to_fit();
   for (int i=1; i<=MAX; ++i) {
      v.push_back(i);

      // affichage stats
      if (i % STEP == 0)
         putDetails(v, "push_back ... " + to_string(i));
   }
   

   //---------------------------------------------------------
   putHeader("POP_BACK", MARGE);
   for (int i=MAX; i>=0; --i) {
      // affichage stats
      if (i % STEP == 0)
         putDetails(v, "pop_back ... " + to_string(i));

      v.pop_back();
   }

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
void putHeader(const string& ACTION, int MARGE) {
   cout  << "-----------------------------------------------------"  << endl
         << ACTION                                                   << endl
         << setw(MARGE) << right << "INSTRUCTION"
         << setw(MARGE) << right << "TAILLE"
         << setw(MARGE) << right << "CAPACITY"                       << endl
         << "-----------------------------------------------------"  << endl;
}

//---------------------------------------------------------
void putDetails(const Vect& v, const string& msg) {
   cout  << setw(MARGE) << left  << msg
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
}

//      -----------------------------------------------------
//      sizeof de vecteurs :
//      Vect(  0)   : 24 octets
//      Vect( 10)   : 24 octets
//      Vect(100)   : 24 octets
//      -----------------------------------------------------
//      RESIZE
//            INSTRUCTION           TAILLE         CAPACITY
//      -----------------------------------------------------
//      v(100)                         100              100
//      v.resize(1000)               10000            10000
//      v.resize(10)                    10            10000
//      -----------------------------------------------------
//      CAPACITY
//            INSTRUCTION           TAILLE         CAPACITY
//      -----------------------------------------------------
//      v.reserve(10)                   10               10
//      v.reserve(1000)                 10             1000
//      v.reserve(10)                   10             1000
//      v.resize(10)                    10             1000
//      v.shrink_to_fit()               10               10
//      -----------------------------------------------------
//      PUSH_BACK
//            INSTRUCTION           TAILLE         CAPACITY
//      -----------------------------------------------------
//      push_back ... 10000            10000            16384
//      push_back ... 20000            20000            32768
//      push_back ... 30000            30000            32768
//      push_back ... 40000            40000            65536
//      push_back ... 50000            50000            65536
//      push_back ... 60000            60000            65536
//      push_back ... 70000            70000           131072
//      push_back ... 80000            80000           131072
//      push_back ... 90000            90000           131072
//      push_back ... 100000           100000           131072
//      -----------------------------------------------------
//      POP_BACK
//            INSTRUCTION           TAILLE         CAPACITY
//      -----------------------------------------------------
//      pop_back ... 100000           100000           131072
//      pop_back ... 90000            90000           131072
//      pop_back ... 80000            80000           131072
//      pop_back ... 70000            70000           131072
//      pop_back ... 60000            60000           131072
//      pop_back ... 50000            50000           131072
//      pop_back ... 40000            40000           131072
//      pop_back ... 30000            30000           131072
//      pop_back ... 20000            20000           131072
//      pop_back ... 10000            10000           131072
//      pop_back ... 0                   0           131072

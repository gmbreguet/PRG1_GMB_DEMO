//---------------------------------------------------------
// Demo           : 02_numerics_limits_types
// Fichier        : 02_numerics_limits_types.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2020-09-15
// But            : Utilisation de numeric_limits
//                  avec différents types de données
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int main () {

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::min()            : " << numeric_limits<bool>::min()           << endl;
   cout << "numeric_limits<char>::min()            : " << numeric_limits<char>::min()           << endl;
   cout << "numeric_limits<short>::min()           : " << numeric_limits<short>::min()          << endl;
   cout << "numeric_limits<int>::min()             : " << numeric_limits<int>::min()            << endl;
   cout << "numeric_limits<long>::min()            : " << numeric_limits<long>::min()           << endl;
   cout << "numeric_limits<float>::min()           : " << numeric_limits<float>::min()          << endl;
   cout << "numeric_limits<double>::min()          : " << numeric_limits<double>::min()         << endl;
   cout << "numeric_limits<long double>::min()     : " << numeric_limits<long double>::min()    << endl;

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::lowest()         : " << numeric_limits<bool>::lowest()        << endl;
   cout << "numeric_limits<char>::lowest()         : " << numeric_limits<char>::lowest()        << endl;
   cout << "numeric_limits<short>::lowest()        : " << numeric_limits<short>::lowest()       << endl;
   cout << "numeric_limits<int>::lowest()          : " << numeric_limits<int>::lowest()         << endl;
   cout << "numeric_limits<long>::lowest()         : " << numeric_limits<long>::lowest()        << endl;
   cout << "numeric_limits<float>::lowest()        : " << numeric_limits<float>::lowest()       << endl;
   cout << "numeric_limits<double>::lowest()       : " << numeric_limits<double>::lowest()      << endl;
   cout << "numeric_limits<long double>::lowest()  : " << numeric_limits<long double>::lowest() << endl;

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::max()            : " << numeric_limits<bool>::max()           << endl;
   cout << "numeric_limits<char>::max()            : " << numeric_limits<char>::max()           << endl;
   cout << "numeric_limits<short>::max()           : " << numeric_limits<short>::max()          << endl;
   cout << "numeric_limits<int>::max()             : " << numeric_limits<int>::max()            << endl;
   cout << "numeric_limits<long>::max()            : " << numeric_limits<long>::max()           << endl;
   cout << "numeric_limits<float>::max()           : " << numeric_limits<float>::max()          << endl;
   cout << "numeric_limits<double>::max()          : " << numeric_limits<double>::max()         << endl;
   cout << "numeric_limits<long double>::max()     : " << numeric_limits<long double>::max()    << endl;

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::digits           : " << numeric_limits<bool>::digits          << endl;
   cout << "numeric_limits<char>::digits           : " << numeric_limits<char>::digits          << endl;
   cout << "numeric_limits<short>::digits          : " << numeric_limits<short>::digits         << endl;
   cout << "numeric_limits<int>::digits            : " << numeric_limits<int>::digits           << endl;
   cout << "numeric_limits<long>::digits           : " << numeric_limits<long>::digits          << endl;
   cout << "numeric_limits<float>::digits          : " << numeric_limits<float>::digits         << endl;
   cout << "numeric_limits<double>::digits         : " << numeric_limits<double>::digits        << endl;
   cout << "numeric_limits<long double>::digits    : " << numeric_limits<long double>::digits   << endl;

   return EXIT_SUCCESS;
}
//    -----------------------------------------------------------------------------
//    numeric_limits<bool>::min()            : 0
//    numeric_limits<char>::min()            :  
//    numeric_limits<short>::min()           : -32768
//    numeric_limits<int>::min()             : -2147483648
//    numeric_limits<long>::min()            : -9223372036854775808
//    numeric_limits<float>::min()           : 1.17549e-38
//    numeric_limits<double>::min()          : 2.22507e-308
//    numeric_limits<long double>::min()     : 3.3621e-4932
//    -----------------------------------------------------------------------------
//    numeric_limits<bool>::lowest()         : 0
//    numeric_limits<char>::lowest()         :  
//    numeric_limits<short>::lowest()        : -32768
//    numeric_limits<int>::lowest()          : -2147483648
//    numeric_limits<long>::lowest()         : -9223372036854775808
//    numeric_limits<float>::lowest()        : -3.40282e+38
//    numeric_limits<double>::lowest()       : -1.79769e+308
//    numeric_limits<long double>::lowest()  : -1.18973e+4932
//    -----------------------------------------------------------------------------
//    numeric_limits<bool>::max()            : 1
//    numeric_limits<char>::max()            : �
//    numeric_limits<short>::max()           : 32767
//    numeric_limits<int>::max()             : 2147483647
//    numeric_limits<long>::max()            : 9223372036854775807
//    numeric_limits<float>::max()           : 3.40282e+38
//    numeric_limits<double>::max()          : 1.79769e+308
//    numeric_limits<long double>::max()     : 1.18973e+4932
//    -----------------------------------------------------------------------------
//    numeric_limits<bool>::digits           : 1
//    numeric_limits<char>::digits           : 8
//    numeric_limits<short>::digits          : 15
//    numeric_limits<int>::digits            : 31
//    numeric_limits<long>::digits           : 63
//    numeric_limits<float>::digits          : 24
//    numeric_limits<double>::digits         : 53
//    numeric_limits<long double>::digits    : 113

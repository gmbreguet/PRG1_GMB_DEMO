//---------------------------------------------------------
// Demo           : 02-02-03_string_concat
// Fichier        : 02-02-03_string_concat.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 2023-09-25
// But            : utilisation des bool
// Modifications  : 
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin

using namespace std;
int main() {

   // concat de deux string
   string  s1 = string("HEIG") + string("-VD");
   cout << s1 << endl;

   // concat un string avec une chaine
   string  s2 = string("HEIG") + "-VD";
   cout << s2 << endl;

   // concat une chaine avec un string
   string  s3 = "HEIG" + string("-VD");
   cout << s3 << endl;

   // concat un string avec un char
   string  s4 = string("HEIG") + '-';
   cout << s4 << endl;

   // concat un char avec un string
   string  s5 = '-' + string("VD");
   cout << s5 << endl;

   // concat un string avec un entier  => ne compile
//   string  s6 = string("VD") + 8;
//   cout << s6 << endl;

   // concat un entier avec string   => ne compile
//   string  s7 = 1400 + string(" Yverdon");
//   cout << s7 << endl;

   // concat deux chaine   => ne compile
//   string  s8 = "compile" + "pas";
//   cout << s8 << endl;
   cout << (char*)"une chaine" << endl;
   cout << (void*)"une chaine" << endl;

   cout << (char*)"une chaine" << endl;
   cout << (void*)"une chaine" << endl;

   char* ptr1 = "chat";
   char* ptr2 = "chat";

   *(ptr1+1) = 'a';
   ptr1[1] = 'a';

   cout << "ptr1 : " << ptr1 << endl;
   cout << "ptr2 : " << ptr2 << endl;

   cout << "ptr1 : " << (void*)ptr1 << endl;
   cout << "ptr2 : " << (void*)ptr2 << endl;

   // fin de programme
   return EXIT_SUCCESS;
}

//   HEIG-VD
//   HEIG-VD
//   HEIG-VD
//   HEIG-
//   -VD
//   une chaine
//   0x1006dbe08

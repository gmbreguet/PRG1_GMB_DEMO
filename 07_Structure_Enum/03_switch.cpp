#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

   int  i;
   cout << "no jour : ";
   cin  >> i;

   // avec des cas traités individuellement
   switch(i) {
      case 1  : cout << "lundi";    break;
      case 2  : cout << "mardi";    break;
      case 3  : cout << "mercredi"; break;
      case 4  : cout << "jeudi";    break;
      case 5  : cout << "vendredi"; break;
      case 6  : cout << "samedi";   break;
      case 7  : cout << "dimanche"; break;
      default : cout << "autre ... ";
   }

   // l'ordre des case est quelconques
   // ... pas très lisible !!
   switch(i) {
      case 2  : cout << "mardi";    break;
      case 1  : cout << "lundi";    break;
      case 5  : cout << "vendredi"; break;
      case 3  : cout << "mercredi"; break;
      default : cout << "autre ... ";
      case 7  : cout << "dimanche"; break;
      case 4  : cout << "jeudi";    break;
      case 6  : cout << "samedi";   break;
   }

   // avec des cas groupés
   switch(i) {
      default : cout << "autre ... ";           break;
      case 1 :
      case 2 :
      case 3 :
      case 4 :
      case 5 : cout << "jour de la semaine";    break;
      case 6 :
      case 7 : cout << "week-end";
   }

   // accepté par certains compilateurs
   // ... mais pas dans la norme
   switch(i) {
      case 1 ... 5 : cout << "jour de la semaine"; break;
      case 6 ... 7 : cout << "week-end";           break;
      default : cout << "autre ... ";
   }

   // ne compile pas
//   double d = 3.14;
//   switch(d) {
//      case 1  : cout << "lundi";    break;
//      case 2  : cout << "mardi";    break;
//      case 3  : cout << "mercredi"; break;
//      case 4  : cout << "jeudi";    break;
//      case 5  : cout << "vendredi"; break;
//      case 6  : cout << "samedi";   break;
//      case 7  : cout << "dimanche"; break;
//      default : cout << "autre ... ";
//   }

   return EXIT_SUCCESS;
}


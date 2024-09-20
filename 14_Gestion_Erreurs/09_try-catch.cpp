//---------------------------------------------------------
// Demo           : 09_try-catch
// Fichier        : 09_try-catch.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 02 - 2023-01-24
// But            : démontrer les try-catch
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

//-------------------------------------------------
// fonction ordinaire levant une exception
// retour à l'appelant avec une exception en cours
void throwInt() {
   throw 1;
}

//-------------------------------------------------
// fonction ordinaire levant et traitant
// une exception en interne => retour au code normal
void f() {
   try {
      throw 1;
   }
   catch(int i) {
      cout << "dans la fonction : " << i  << endl;
   }
   cout << "retour normal ..."      << endl;
}

//-------------------------------------------------
int main () {

   int valeur;
   
   //-------------------------------------------------
   while (true) {

      // saisie du choix
      cout << "votre choix : ";
      cin  >> valeur;

      int& refInt = valeur;

      try {
         switch (valeur) {
            // gestion des differents cas
            case  0 : throw  valeur;            // => catch(int)
            case  1 : throw  (short)valeur;     // => catch(...)
            case  2 : throw refInt;             // => catch(int)
            case  3 : throw &valeur;            // => catch(const char*)
            case  4 : throw 1.2;                // => catch(...)
            case  5 : throw 'a';                // => catch(char) => catch(double)
            case  6 : throw "chaine";           // => catch(const char*) => catch(const char*)
            case  7 : throw string("string");   // => catch(const string&)
            case  8 : throw true;               // => catch(...)
            case  9 : throwInt();               // => catch(int)
            case 10 : f(); break;               // retour normal
            default : return EXIT_SUCCESS;
         }
      }
      
      //----------------------------------
      // traite exception de type int
      // /!\ ne fonctionne qu'avec des "int", unsigned int est different !!!
      //     const n'a pas d'influence car utile pour la copie (parametre)
      catch (int valeur) {
         cout << "catch(int) : " << valeur << endl;
      }
      
      //----------------------------------
      // traite exception avec un ptr sur entier
      // /!\ un ptr sur un float est un type different !!!
      catch (const int* valeur) {
         cout << "catch(const int*) : " << *valeur << endl;
      }
      
      //----------------------------------
      // traite exception avec des caracteres
      // /!\ pas de conversion implicite avec des entiers
      catch (char car) {
         cout << "catch(char) : " << car << endl;
         try{
            throw 1.2;
         }
         catch(double v) {
            cout << "catch(double) : " << v << endl;
         }
      }
      
      //----------------------------------
      // traite exception avec des chaines de caracteres
      // /!\ le "const" est IMPORTANT !!!!
      //     different d'un string
      catch (const char* chaine) {
         cout << "catch(const char*) : " << chaine << endl;
         //-----------------------------------------------
         // lever une exception dans un traite-exception
         try {
            try {
               throw;      // lever cette meme exception
            }
            catch(int val) {
               cout << "catch(int) : " << chaine << endl;
            }
         }

         //-----------------------------------------------
         catch (const char* chaine) {
            cout << "catch(const char*) : " << chaine << endl;
         }
      }

      //----------------------------------
      // traite exception avec des string
      catch (const string& chaine) {
         cout << "catch(const string&) : " << chaine << endl;
      }

      // traite TOUTES les exceptions (restantes)
      // /!\ doit etre obligatoirement en DERNIERE position (heureusement!)
      // /!\ impossible de recuperer l'objet ici :(
      catch (...) {
         cout << "catch(...)" << endl;
      }
   }

   return EXIT_SUCCESS;
}

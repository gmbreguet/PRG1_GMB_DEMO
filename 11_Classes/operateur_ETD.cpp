#include <iostream>
using namespace std;
class Point {
   int x, y;
  public :
   Point(int abscisse = 0, int ordonnee = 0) : x(abscisse), y(ordonnee) {}
   strong_ordering operator<=>(const Point & rhs) { 
     if (x == rhs.x && y == rhs.y) 
       return strong_ordering::equal;
     if (x < rhs.x || (x == rhs.x && y < rhs.y))
       return strong_ordering::less;
     return strong_ordering::greater;
   }
   // Pourquoi devoir implanter séparément l'opérateur == ???
   bool operator==(const Point & rhs) {return (*this <=> rhs) == strong_ordering::equal;}
};
int main(){
   Point a(1), b{1,0}, c, d{1,1};
   if ( a == b  && c < a && d > b && d != b && a >= b && b <= d) cout << "OK\n";
   else cout << "KO\n";
}

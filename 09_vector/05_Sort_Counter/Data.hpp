//---------------------------------------------------------
// Demo           : 05_tri
// Fichier        : Data.h
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 01 - 2023-03-26
// But            : type Data permettant de compter
//                   - les comparaisons
//                   - les affectations
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef DATA
#define DATA

#include <iostream>

template<typename T>
class Data;

template<typename T>
std::ostream& operator<< (std::ostream& os, const Data<T>& d);

template<typename T>
class Data {

   friend std::ostream& operator<< <T>(std::ostream& os, const Data<T>& d);

public:
   Data()              : value(T()) {};
   Data(const T&    v) : value(v)   {};
   Data(const Data& d);

   bool operator<  (const Data<T>& d) const noexcept;
   bool operator>  (const Data<T>& d) const noexcept;
   bool operator<= (const Data<T>& d) const noexcept;
   bool operator>= (const Data<T>& d) const noexcept;
   bool operator== (const Data<T>& d) const noexcept;
   bool operator!= (const Data<T>& d) const noexcept;

   Data<T>& operator= (const Data<T>& v);

   static void     reset()       noexcept;
   static unsigned getComp()     noexcept;
   static unsigned getAssign()   noexcept;

private:
   static unsigned compare;
   static unsigned assign;
   T               value;
};


//---------------------------------------------------------
template<typename T>
std::ostream& operator<< (std::ostream& os, const Data<T>& d) {
   return os << d.value;
}

//---------------------------------------------------------
template<typename T>
unsigned Data<T>::compare = 0;

template<typename T>
unsigned Data<T>::assign  = 0;

//---------------------------------------------------------
template<typename T>
Data<T>::Data(const Data& d) {
   if (this != & d) {
      compare = d.compare;
      assign  = d.assign;
      value   = d.value;
   }
}

//---------------------------------------------------------
template<typename T>
bool Data<T>::operator< (const Data<T>& d) const noexcept {
   ++Data::compare;
   return this->value < d.value;
}

//---------------------------------------------------------
template<typename T>
bool Data<T>::operator> (const Data<T>& d) const noexcept {
   ++Data::compare;
   return this->value > d.value;
}

//---------------------------------------------------------
template<typename T>
bool Data<T>::operator<= (const Data<T>& d) const noexcept {
   return not (this->value > d.value);
}

//---------------------------------------------------------
template<typename T>
bool Data<T>::operator>= (const Data<T>& d) const noexcept {
   return not (this->value < d.value);
}

//---------------------------------------------------------
template<typename T>
bool Data<T>::operator== (const Data<T>& d) const noexcept {
   ++Data::compare;
   return this->value == d.value;
}

//---------------------------------------------------------
template<typename T>
bool Data<T>::operator!= (const Data<T>& d) const noexcept {
   return not (this->value == d.value);
}


//---------------------------------------------------------
template<typename T>
Data<T>& Data<T>::operator= (const Data<T>& d) {
   if (this != &d) {
      ++Data::assign;
      this->value = d.value;
   }
   return *this;
}

//---------------------------------------------------------
template<typename T>
void Data<T>::reset() noexcept {
   compare = 0;
   assign  = 0;
}

//---------------------------------------------------------
template<typename T>
unsigned Data<T>::getComp() noexcept {
   return compare;
}

//---------------------------------------------------------
template<typename T>
unsigned Data<T>::getAssign() noexcept {
   return assign;
}

#endif

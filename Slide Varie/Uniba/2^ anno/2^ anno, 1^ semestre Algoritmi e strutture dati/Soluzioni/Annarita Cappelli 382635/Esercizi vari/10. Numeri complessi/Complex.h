#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

struct num_compl {
       float reale;
       float immaginario;
};

class Complex {
      public:
             Complex();  // costruttore
             ~Complex();  // distruttore
             
             // operatori
             void creaComplex(float, float);
             void somma(Complex, Complex);
             void prodotto(Complex, Complex);
             float realPart();
             float immPart();
      private:
              num_compl complex;
};

#endif

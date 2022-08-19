#include "Complex.h"

Complex::Complex() {
     creaComplex(0, 0);
};

Complex::~Complex() { };

void Complex::creaComplex(float a, float b) {
     complex.reale=a;
     complex.immaginario=b;
};

void Complex::somma(Complex a, Complex b) {
     complex.reale=a.realPart()+b.realPart();
     complex.immaginario=a.immPart()+b.immPart();
};

void Complex::prodotto(Complex a, Complex b) {
     complex.reale=((a.realPart()*b.realPart())-(a.immPart()*b.immPart()));
     complex.immaginario=((a.realPart()*b.immPart())+(a.immPart()*b.realPart()));
};

float Complex::realPart() {
     return complex.reale;
};

float Complex::immPart() {
      return complex.immaginario;
};





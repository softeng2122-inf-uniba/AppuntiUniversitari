#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex a, b, c;
    float preale, pimm;
    cout << "*** NUMERI COMPLESSI ***" << endl << endl;
    cout << "Inserisci numero complesso a: " << endl;
    cout << "Parte reale: ";
    cin >> preale;
    cout << "Parte immaginaria: ";
    cin >> pimm;
    a.creaComplex(preale, pimm);
    cout << "Inserisci numero complesso b: " << endl;
    cout << "Parte reale: ";
    cin >> preale;
    cout << "Parte immaginaria: ";
    cin >> pimm;
    b.creaComplex(preale, pimm);
    c.somma(a, b);
    cout << "La somma di a e b e' data da c: " << endl;
    cout << "Parte reale: " << c.realPart() << endl;
    cout << "Parte immaginaria: " << c.immPart() << endl;
    c.prodotto(a, b);
    cout << "Il prodotto di a e b e' dato da c: " << endl;
    cout << "Parte reale: " << c.realPart() << endl;
    cout << "Parte immaginaria: " << c.immPart() << endl;
    system("pause");
    return 0;
};
    

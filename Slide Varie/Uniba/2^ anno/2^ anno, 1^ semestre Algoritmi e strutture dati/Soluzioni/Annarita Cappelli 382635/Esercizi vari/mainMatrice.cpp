#ifndef MAIN_H
#include "main.h"
#endif

#ifndef MATRICE_H
#include "Matrice.h"
#endif

int main() {
     Matrice A(3, 3);
     int scalare;
     double det;
     A.acquisisci();
     A.stampa();
     cout << endl << endl;
     cout << "Inserisci scalare per prodotto scalare: ";
     cin >> scalare;
     A.moltiplicazioneScalare(A, scalare);
     A.stampa();
     det=A.determinante();
     cout << endl;
     cout << endl;
     cout << "La matrice inserita ha determinante: " << det << endl;
     cout << endl;
     cout << "Trasposta: " << endl;
     A.trasposta(A);
     A.stampa();
     cout << endl;
     cout << endl;
     if (A.antiSimmetrica(A))
        cout << "La matrice inserita e' antisimmetrica!" << endl;
     else
        cout << "La matrice inserita non e' antisimmetrica!" << endl;
     cout << endl;
     cout << "Bye bye.." << endl << endl;
     system("pause");
     return 0;
}
     
     

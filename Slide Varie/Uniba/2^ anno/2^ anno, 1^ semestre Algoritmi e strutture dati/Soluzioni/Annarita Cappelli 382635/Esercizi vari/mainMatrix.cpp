#ifndef MAIN_H
#include "main.h"
#endif

#ifndef MATRIX_H
#include "Matrix.h"
#endif

int main() {
     Matrix A(3, 3), B(3, 3), C(3, 3);
     A.acquisisci();
     cout << "\nEcco la matrice appena acquisita: " << endl;
     A.stampa();
     cout << endl;
     if (A.matrixUnitaria())
        cout << "La matrice e' unitaria!" << endl;
     else
        cout << "La matrice non e' unitaria!" << endl;
     if (A.matrixQuadrata())
        cout << "La matrice e' quadrata!" << endl;
     else
        cout << "La matrice non e' quadrata!" << endl;
     cout << "Acquisizione matrice B: " << endl << endl;
     B.acquisisci();
     C.sommaMatrix(A, B);
     cout << "Stampa della somma delle matrici: " << endl;
     C.stampa();
     C.prodottoMatrix(A, B);
     cout << endl << endl;
     cout << "Stampa della matrice prodotto riga per colonna: " << endl;
     C.stampa();
     cout << endl;
     cout << "Bye bye...." << endl;
     cout << endl;
     system("pause");
     return 0;
}

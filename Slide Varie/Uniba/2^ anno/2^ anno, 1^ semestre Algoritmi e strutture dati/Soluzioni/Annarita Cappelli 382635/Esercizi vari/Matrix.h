/*
Appello laboratorio 6 aprile 2006
Implementare la struttura dati "Matrice" definita dalle seguenti specifiche:
Tipi:
- MATRICE: famiglia dei vettori bidimensionali A(i,j) di elementi di tipo 
intero, con 1 < i < N, 1 < j < M, 1 < N,M < MAXDIM (costante intera 
fissata a priori)
- DIMENSIONE: sottoinsieme dei numeri naturali compresi fra 1 e MAXDIM
- BOOLEAN: insieme dei valori di verità
Operatori:
- CREAMATRICE (R,C: DIMENSIONE) -> M: MATRICE
Post: M = A(i,j), 1< i < R, 1 < j < C Ù "i,j : A(i,j) = 0 
(matrice RxC con tutti gli elementi nulli)
- MATRICEUNITARIA ( M : Matrice ) -> B : BOOLEAN
Pre: M = A(i,j), 1 < i,j < DIM (matrice quadrata DIMxDIM)
Post: B = True Û "i¹j : A(i,j) = 0 Ù "i=j : A(i,j) = 1 (tutti elementi nulli 
tranne quelli sulla diagnonale che sono tutti 1)
- SOMMAMATRICI ( A,B : MATRICE ) -> S : Matrice
Pre: A = A(i,j), B = B(i,j), 1 < i < N, 1 < j < M (matrici con le stesse 
dimensioni NxM)
Post: S = S(i,j), 1 < i < N, 1 < j < M Ù "i,j : S(i,j) = A(i,j) + B(i,j) 
(ogni elemento di S è dato dalla somma dei corrispondenti elementi di A e B)
- PRODOTTOMATRICIALE ( A,B : MATRICE) -> P : MATRICE
Pre: A = A(i,j), B = B(j,k), 1 < i < L, 1 < j < M, 1 < k < N (il n.ro di righe 
di B corrisponde al n.ro di colonne di A)
Post: S = S(i,j), 1 < i < L, 1 < j < M Ù "i,k : S(i,k) = Sj=1...M ( A(i,j) * B(j,k) ) 
(classico prodotto matriciale righe per colonne)
oltre a due operatori ACQUISISCI e STAMPA che, rispettivamente, acquisiscono 
da tastiera e stampano a video il contenuto di una matrice.
Realizzare un programma che consenta di applicare ciascun operatore a delle 
matrici acquisite di volta in volta, stampando gli operandi ed il risultato.
*/

#ifndef MATRIX_H
#define MATRIX_H
#define MAXDIM 50

#ifndef MAIN_H
#include "main.h"
#endif

#include "math.h"

typedef int dimensione;

class Matrix {
      public:
             Matrix(dimensione, dimensione);  // costruttore
             ~Matrix();  // distruttore
             
             // operatori
             void creaMatrix(dimensione, dimensione);
             bool matrixUnitaria();
             bool matrixQuadrata();
             void sommaMatrix(Matrix, Matrix);
             void prodottoMatrix(Matrix, Matrix);
             void acquisisci();
             void stampa();
      private:
              dimensione N;
              dimensione M;
              int matrix[MAXDIM][MAXDIM];
};

Matrix::Matrix(dimensione r, dimensione c) {
     if (r>0&&c>0&&r<MAXDIM&&c<MAXDIM)
        creaMatrix(r, c);
};

Matrix::~Matrix() { };

void Matrix::creaMatrix(dimensione r, dimensione c) {
     N=r;
     M=c;
     for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
           matrix[i][j]=0;
};

bool Matrix::matrixUnitaria() {
     bool unitaria=true;
     for (int i=0; (i<N&&unitaria); i++)
        for (int j=0; (j<M&&unitaria); j++)
           if (((i!=j)&&matrix[i][j])||((i==j)&&matrix[i][j]!=1))
              unitaria=false;
     return unitaria;
};

bool Matrix::matrixQuadrata() {
     if (N==M)
        return true;
     else
        return false;
};

void Matrix::sommaMatrix(Matrix A, Matrix B) {
     if (A.N == B.N && A.M == B.M && N == A.N && M == A.M)
        for (int i=0; i<N; i++)
           for(int j=0; j<M; j++)
              matrix[i][j]=A.matrix[i][j]+B.matrix[i][j];
};

void Matrix::prodottoMatrix(Matrix A, Matrix B) {
     if (B.M == A.N && N == A.N && M == B.M) {
        for (int i=0; i<N; i++)
           for (int j=0; j<M; j++) {
              matrix[i][j] = 0;
              for (int k=0; k<A.M; k++)
                 matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
           }                 
     }
};

void Matrix::acquisisci() {
     for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
           cout << "Inserisci elemento (" << i << ", " << j << "): ";
           cin >> matrix[i][j];
        }
};

void Matrix::stampa() {
     for (int i=0; i<N; i++) {
        cout << endl;
        for (int j=0; j<M; j++)
           cout << matrix[i][j] << " ";
     }
};

#endif

      

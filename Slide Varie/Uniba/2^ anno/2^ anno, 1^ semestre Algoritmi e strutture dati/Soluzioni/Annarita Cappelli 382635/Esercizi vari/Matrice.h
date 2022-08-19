/*Appello laboratorio 14 giugno 2006
Implementare la struttura dati "Matrice" definita dalle seguenti specifiche:
Tipi:
- MATRICE: famiglia dei vettori bidimensionali A(i,j) di elementi di tipo 
intero, con 1 < i < N, 1 < j < M, 1 < N, M < MAXDIM (costante intera 
fissata a priori)
- DIMENSIONE: sottoinsieme dei numeri naturali compresi fra 1 e MAXDIM
- REAL: insieme dei numeri reali
- BOOLEAN: insieme dei valori di verità
Operatori:
- CREAMATRICE (R,C: DIMENSIONE) -> M: MATRICE
Post: M = A(i,j), 1< i < R, 1 < j < C Ù "i,j : A(i,j) = 0 
(matrice RxC con tutti gli elementi nulli)
- MOLTIPLICAZIONESCALARE( A : MATRICE, c : REAL) -> S : Matrice
Pre: A = A(i,j), 1 < i < L, 1 < j < M
Post: S = S(i,j), 1 < i < L, 1 < j < M Ù "i,j : S(i,j) = c * A(i,j)
- TRASPOSTA ( M : Matrice ) -> S : Matrice
Pre: A = A(i,j), 1 < i < L, 1 < j < M
Post: S = S(j,i), 1 < i < L, 1 < j < M Ù "i,j : S(i,j) = A(j,i)
- DETERMINANTE( A : MATRICE ) -> d : REAL
Pre: A = A(i,j), 1 < i < L, 1 < j < L (matrice quadrata)
Post: d = determinante della matrice A ottenuto con un qualsiasi metodo o 
con lo sviluppo di Laplace dove ogni Ci,j rappresenta il complemento algebrico 
della coppia (i,j), cioè Ci,j è data da ( - 1)i + j per il determinante della 
matrice di ordine n-1, ottenuta dalla A eliminando la riga i-esima e la 
colonna j-esima.
- ANTISIMMETRICA ( A : MATRICE) -> B: BOOLEAN
Pre: A = A(i,j), 1 < i < L, 1 < j < M
Post: B = true se e solo se AT = - A (matrice che coincide con la sua 
trasposta cambiata di segno)
oltre a due operatori ACQUISISCI e STAMPA che, rispettivamente, acquisiscono 
da tastiera e stampano a video il contenuto di una matrice.
Realizzare un programma (main) che consenta di testare gli operatori implementati.
*/

#ifndef MATRICE_H
#define MATRICE_H
#define MAXDIM 50

#include <math.h>

typedef int dimensione;

class Matrice {
      public:
             Matrice(dimensione, dimensione);  // costruttore
             ~Matrice();  // distruttore
             
             // operatori
             void creaMatrice(dimensione, dimensione);
             void moltiplicazioneScalare(Matrice, int);
             void trasposta(Matrice);
             double determinante();
             bool antiSimmetrica(Matrice);
             Matrice eliminaRigaColonna(int, int);
             Matrice inversa();
             bool simmetrica();
             bool triangInf();
             bool predomRighe();
             bool predomCol();
             int norma1();
             int normaInf();
             void acquisisci();
             void stampa();
      private:
              int matrice[MAXDIM][MAXDIM];
              double elem[MAXDIM][MAXDIM];
              dimensione N;
              dimensione M;
};

Matrice::Matrice(dimensione r, dimensione c) {
     if (r>0 && c>0 && r<MAXDIM && c<MAXDIM)
        creaMatrice(r, c);
};

Matrice::~Matrice() { };

void Matrice::creaMatrice(dimensione r, dimensione c) {
     N=r;
     M=c;
     for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
           matrice[i][j]=0;
};

void Matrice::moltiplicazioneScalare(Matrice A, int k) {
     for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
           matrice[i][j]=k*A.matrice[i][j];
};

void Matrice::trasposta(Matrice A) {
     for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
           matrice[i][j]=A.matrice[j][i];
};

bool Matrice::simmetrica() {
   bool simm = true;

   for (int i=0; i<N && simm; i++)
       for (int j=0; j<M && simm; j++)
           if (matrice[i][j] != matrice[j][i])
              simm = false;
   return simm;
};

bool Matrice::triangInf() {
   bool inf = true;
   for (int i=0; i<N && inf; i++)
       for (int j=0; j<M && inf; j++)
           if ((i<j) && matrice[i][j] != 0)
              inf = false;
   return inf;
};

int Matrice::norma1() {
// massimo della somma sulle colonne  
  int max = 0, s = 0;
  
  for (int j=0; j<M; j++) {
      for (int i=0; i<N; i++) 
          s += abs(matrice[i][j]);
      if (s > max)  max = s;
      s = 0;
  }
  return max;
};

int Matrice::normaInf() {
// massimo della somma sulle righe  
  int max = 0, s = 0;
  
  for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) 
          s += abs(matrice[i][j]);
      if (s > max)  max = s;
      s = 0;
  }
  return max;
};

bool Matrice::predomRighe() {
  bool predom = true;
  int max=0, s=0;
  for (int i=0; i<N && predom; i++) {
      for (int j=0; j<M; j++) {
          if (i==j) max = abs(matrice[i][j]);
          else s += abs(matrice[i][j]);
      }
      if (max < s) predom = false;
      s = 0;
  }   
  return predom;
};

bool Matrice::predomCol() {
  bool predom = true;
  int max=0, s=0;
  for (int j=0; j<M && predom; j++) {
      for (int i=0; i<N; i++) {
          if (i==j) max = abs(matrice[i][j]);
          else s += abs(matrice[i][j]);
      }
      if (max < s) predom = false;
      s = 0;
  }
  return predom;
};       

double Matrice::determinante() {
     if (N==1) return (matrice[0][0]);
     if (N==2) return (matrice[0][0]*matrice[1][1]-matrice[0][1]*matrice[1][0]);
     int i=N-1;
     double det=0;
     for (int j=0; j<N; j++) {
        Matrice minore=eliminaRigaColonna(i,j);
        det += matrice[i][j] * (pow((double) -1, (double) i+j) * minore.determinante());
     }
     return det;
};

Matrice Matrice::inversa() {
   Matrice inv(N,M);
   double detA;
   
// if (N == 1) return (el[0][0]);
   detA = determinante();
   for (int i=0; i<N; i++) 
    for (int j=0; j<N; j++) {
     Matrice minore = eliminaRigaColonna(j,i);
     inv.elem[i][j] = (1/detA) * pow((double)-1, (double)(i+j)) * minore.determinante();
//     cout << "(" << inv.elem[i][j] << ")" << " ";
    }
   return inv;     
};

bool Matrice::antiSimmetrica(Matrice A) {
     bool antisimm = true;
     Matrice B (M, N);
     B.trasposta(A);
     for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
           B.matrice[i][j] = -B.matrice[i][j];   
     for (int i=0; i<N && antisimm; i++)
        for (int j=0; j<M && antisimm; j++)
           if (A.matrice[i][j] != B.matrice[i][j])
              antisimm = false;
     return antisimm;
};
     
Matrice Matrice::eliminaRigaColonna(int i, int j) {
    Matrice d(N-1, M-1);    
    int n=0, m;
    for (int riga=0; riga<N; riga++) {
        if (riga != i) {
           m = 0;
           for (int col=0; col<M; col++) {
               if (col != j)
                  d.matrice[n][m++] = matrice[riga][col];
           }
           n++;
        }
    }
    return d;
}; 

void Matrice::acquisisci() {
     for (int i=0; i<N; i++)
         for (int j=0; j<M; j++) {
           cout << "Elemento (" << i+1 << "," << j+1 << ") = ";
           cin >> matrice[i][j];
         }
};

void Matrice::stampa() {
     for (int i=0; i<N; i++) {
         cout << endl;
         for (int j=0; j<M; j++)
             cout << matrice[i][j] << " ";
     }
};     

#endif      



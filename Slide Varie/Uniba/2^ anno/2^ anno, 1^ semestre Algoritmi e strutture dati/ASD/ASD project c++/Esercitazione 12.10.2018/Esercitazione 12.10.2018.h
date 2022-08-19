#ifndef ESERCITAZIONE_H
#define ESERCITAZIONE_H

typedef double tipoelem;

class matrice {
  public:
    matrice(int, int); /* costruttore */
    tipoelem leggimatrice(int, int);
    void scrivimatrice(int, int, tipoelem);
  private:
    int righe;
    int colonne;
    tipoelem **elementi;
};

// costruttore
matrice::matrice(int c, int r){
  colonne = c;
  righe = r;
  // allocazione dinamica della matrice
  int i;
  elementi = new tipoelem* [righe];
  for (i=0; i < righe; i++)
    elementi[i] = new tipoelem[colonne];
  // inizializzazione degli elementi
     ...
}


#endif // ESERCITAZIONE_H

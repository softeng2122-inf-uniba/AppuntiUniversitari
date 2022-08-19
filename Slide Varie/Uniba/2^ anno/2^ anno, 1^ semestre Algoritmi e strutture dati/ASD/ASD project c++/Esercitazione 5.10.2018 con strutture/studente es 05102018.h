#ifndef _STUDENTE
#define _STUDENTE

struct tipostudente{
    int matricola;
    char nome[30];
    char cognome[30];
    int eta;
};

typedef struct tipostudente studente;
int dimensione;

void riempistruttura(studente *);
void visualizzastruttura(studente *);


#endif // STUDENTE_H

/*
Appello laboratorio 6 settembre 2006
Scrivere un programma in C++ che, consenta la gestione dei turni di dipendenti 
di una società. In particolare il turno è formato dai seguenti dati: 
id, nome dipendente, ora inizio turno; un turno è di quattro ore. 
Implementare e testare le seguenti funzioni/metodi:
1. Tabella CaricaTabella() - costruisce la tabella dei turni di un giorno 
(costituito da 24 ore) inserendo le informazioni sui nomi dei dipendenti e i 
turni relativi; Tabella è la struttura dati che memorizza i turni; per 
semplicità si assuma la gestione di turni di un solo giorno;
2. StampaTabella(Tabella) - stampa a video i turni dei dipendenti (un esempio 
è dato in basso);
3. Tabella Ruota(Tabella) - effettua una rotazione in avanti di un posto dei 
nomi dei dipendenti (nel caso dell'esempio se viene applicato l'operatore 
Ruota in posizione 2 si avrebbe: Amelia Marco, 04:00);
4. Tabella Incrementa(Tabella, int) - effettua uno spostamento delle ore in 
avanti di un numero di ore pari all'intero passato alla funzione;
5. Dipendente EstraiDipendente(Tabella, posizione) - restituisce il dipentente 
specificato dalla posizione data; posizione il tipo di dato che determina la 
posizione del dipendente (colonna 1 dell'esempio);
Si è ammessi risolvendo correttamente almeno i primi quattro punti (con 
riserva risolvendo correttamente solo i primi tre).
Esempio parziale tabella:
1 Amelia Marco 00:00
2 Barzagli Andrea 04:00
3 Zaccardo Cristian 08:00
*/


#ifndef MAIN_H
#include "main.h"
#endif

#ifndef TABELLA_H
#include "Tabella.h"
#endif

int main() {
    Tabella tab;
    int input;
    posizione q;
    turno op;
    tab.caricaTabella();
    tab.stampaTabella();
    tab.ruota();
    cout << endl;
    tab.stampaTabella();
    cout << endl;
    cout << "Inserisci valore incremento: ";
    cin >> input;
    tab.incremento(input);
    tab.stampaTabella();
    cout << endl;
    do {
       cout << "Inserisci la posizione di cui si vuol estrarre il dipendente: (da 1 a 6) ";
       cin >> q;
    } while (!((q>=1)&&(q<=6)));
    tab.caricaTabella();
    tab.ruota();
    tab.incremento(input);
    op=tab.estraiDipendente(q);
    cout << "Dipendente id: " << op.id << endl;
    cout << "Cognome: " << op.cognome << endl;
    cout << endl;
    system("pause");
    return 0;
};

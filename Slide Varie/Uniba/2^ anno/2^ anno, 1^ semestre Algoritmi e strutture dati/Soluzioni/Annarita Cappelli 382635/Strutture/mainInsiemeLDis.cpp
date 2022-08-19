#ifndef MAIN_H
#include "main.h"
#endif

#ifndef INSIEMELDIS_H
#include "InsiemeLDis.h"
#endif

void inserimento(InsiemeLDis<string> &ins) {
     string elem;
     int num;
     cout << "Quanti elementi vuoi inserire nell'insieme?" << endl;
     cin >> num;
     for (int i=0; i<num; i++) {
        cout << "Inserisci nome: " << endl;
        cin >> elem;
        ins.inserisci(elem);
     }
     cout << "Insieme inserito con successo!" << endl << endl;
};

int main()
{
    InsiemeLDis<string> insieme1, insieme2, insieme3;
    string elemento;
    cout << "*** Insiemi: realizzazione con liste non ordinate ***" << endl;
    cout << "Inserimento dei valori dell'insieme A: " << endl;
    inserimento(insieme1);
    cout << endl;
    cout << "Inserimento dei valori dell'insieme B: " << endl;
    inserimento(insieme2);
    cout << endl;
    cout << "Ecco gli insiemi che hai inserito: " << endl;
    cout << "A= ";
    insieme1.mostraInsieme();
    cout << endl;
    cout << "B= ";
    insieme2.mostraInsieme();
    cout << endl;
    cout << "Inserisci elemento da cercare in A: " << endl;
    cin >> elemento;
    if (insieme1.appartiene(elemento))
      cout << "L'elemento da te inserito appartiene ad A" << endl;
    else
      cout << "L'elemento da te inserito non appartiene ad A" << endl;
    cout << "Inserisci elemento da cancellare da B: " << endl;
    cin >> elemento;
    insieme2.cancella(elemento);
    cout << "B dopo la cancellazione dell'elemento: " << endl;
    insieme2.mostraInsieme();
    cout << endl;
    insieme3.unione(insieme1, insieme2);
    cout << "UNIONE(A,B)= ";
    insieme3.mostraInsieme();
    cout << endl;
    insieme3.intersezione(insieme1, insieme2);
    cout << "INTERSEZIONE(A,B)= ";
    insieme3.mostraInsieme();
    cout << endl;
    insieme3.differenza(insieme1, insieme2);
    cout << "DIFFERENZA(A,B)= ";
    insieme3.mostraInsieme();
    cout << endl;
    cout << "Programma terminato.. Grazie e arrivederci!" << endl;
    cout << endl;
    system("PAUSE");
    return 0;
}
    

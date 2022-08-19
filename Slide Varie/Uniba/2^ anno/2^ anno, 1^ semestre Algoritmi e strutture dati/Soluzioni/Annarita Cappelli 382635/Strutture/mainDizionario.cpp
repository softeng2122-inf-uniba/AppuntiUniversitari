#ifndef MAIN_H
#include "main.h"
#endif

#ifndef DIZIONARIO_H
#include "Dizionario.h"
#endif

int main(int argc, char *argv[]){
	Dizionario<string, string> d;
	bucket<string, string> a;
	int scelta;
	int i = 0;
	do{
      cout << "Dizionario: menu' principale (" << i << " elementi inseriti)" << endl;
      cout << "----------------------------" << endl << endl;
      cout << "1. Inserimento di un elemento" << endl;
      cout << "2. Cancellazione di un elemento" << endl;
      cout << "3. Aggiornamento di un elemento" << endl;
      cout << "4. Recupero di un elemento" << endl;
      cout << "5. Stampa del dizionario" << endl;
      cout << "6. Fine" << endl << endl;
      do{
         cout << "Scelta: ";
         cin >> scelta;
      } while (!((scelta > 0) && (scelta < 7)));
      cout << endl;
      switch (scelta){
         case 1:
            i++;
            cout << "Inserisci chiave: ";
            cin >> a.chiave;
            cout << "Inserisci vocabolo: ";
            cin >> a.attributo;
            d.inserisci(a);
            break;
         case 2:
            cout << "Inserisci chiave: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.cancella(a.chiave);
               i--;
            } else
               cout << "Parola " << a.chiave << " non trovata" << endl;
            break;
         case 3:
            cout << "Inserisci chiave: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               cout << "Inserisci nuovo vocabolo: ";
               cin >> a.attributo;
               d.aggiorna(a.chiave, a);
               cout << "Dizionario aggiornato" << endl;
            } else
               cout << "Parola " << a.chiave << " non presente" << endl;
            break;
         case 4:
            cout << "Inserisci chiave: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.recupera(a.chiave, a);
               cout << "Attributo di " << a.chiave << " -> " << a.attributo << endl;
            } else
               cout << "Parola " << a.chiave << " non presente" << endl;
            break;
         case 5:
            d.stampa();
            break;
         case 6:
            cout << "bye bye..." << endl;
            break;
      }
      system("PAUSE");
      system("CLS");
   } while (scelta != 6);
   return 0;
}

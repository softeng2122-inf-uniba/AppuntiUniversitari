#ifndef MAIN_H
#include "main.h"
#endif

#ifndef DIZIONARIO_H
#include "Dizionario.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

struct data {
     int giorno;
     int mese;
     int anno;
};

void stampaLista(ListaPtr<bucket<string, data> > & l) {
            lpcell<bucket<string, data> > *temp=l.primoLista();
            bucket<string, data> a;
            while (!l.fineLista(temp)) {
               a=l.leggiLista(temp);
               cout << "Chiave: " << a.chiave << endl;
               cout << "Data: " << a.attributo.giorno << "/" << a.attributo.mese
                    << "/" << a.attributo.anno << endl;
               cout << endl;
               temp=l.succLista(temp);
            }
};

int main(int argc, char *argv[]){
	Dizionario<string, data> d;
	ListaPtr<bucket<string, data> > l;
	bucket<string, data> a;
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
            cout << "Inserisci oggetto: ";
            cin >> a.chiave;
            cout << "Inserisci giorno arrivo: ";
            cin >> a.attributo.giorno;
            cout << "Inserisci mese arrivo: ";
            cin >> a.attributo.mese;
            cout << "Inserisci anno arrivo: ";
            cin >> a.attributo.anno;
            d.inserisci(a);
            break;
         case 2:
            cout << "Inserisci oggetto da cancellare: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.cancella(a.chiave);
               i--;
            } else
               cout << "Oggetto " << a.chiave << " non trovato" << endl;
            break;
         case 3:
            cout << "Inserisci oggetto da aggiornare: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               cout << "Inserisci nuovo giorno arrivo: ";
               cin >> a.attributo.giorno;
               cout << "Inserisci nuovo mese arrivo: ";
               cin >> a.attributo.mese;
               cout << "Inserisci nuovo anno arrivo: ";
               cin >> a.attributo.anno;
               d.aggiorna(a.chiave, a);
               cout << "Dizionario aggiornato" << endl;
            } else
               cout << "Oggetto " << a.chiave << " non presente" << endl;
            break;
         case 4:
            cout << "Inserisci oggetto da recuperare: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.recupera(a.chiave, a);
               cout << "Data arrivo dell'oggetto " << a.chiave << " -> " 
                    << a.attributo.giorno << "/" << a.attributo.mese
                    << "/" << a.attributo.anno << endl;
            } else
               cout << "Oggetto " << a.chiave << " non presente" << endl;
            break;
         case 5:
            l=d.copiaDizionario();
            stampaLista(l);
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

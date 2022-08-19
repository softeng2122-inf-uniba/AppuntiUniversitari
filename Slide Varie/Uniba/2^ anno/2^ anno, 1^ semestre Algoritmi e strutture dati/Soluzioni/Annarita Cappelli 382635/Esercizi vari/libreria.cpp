#ifndef MAIN_H
#include "main.h"
#endif

#ifndef DIZIONARIO_H
#include "Dizionario.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

struct dati {
     string cognome;
     string nome;
     int pezzi;
};

void stampaLista(ListaPtr<bucket<string, dati> > & l) {
            lpcell<bucket<string, dati> > *temp=l.primoLista();
            bucket<string, dati> a;
            while (!l.fineLista(temp)) {
               a=l.leggiLista(temp);
               cout << "Titolo: " << a.chiave << endl;
               cout << "Autore: " << a.attributo.nome << " " << a.attributo.cognome
                    << " pezzi -> " << a.attributo.pezzi << endl;
               cout << endl;
               temp=l.succLista(temp);
            }
};

int main(int argc, char *argv[]){
	Dizionario<string, dati> d;
	ListaPtr<bucket<string, dati> > l;
	bucket<string, dati> a;
	bucket<string, dati> b;
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
      cout << "6. Verifica disponibilita'" << endl;
      cout << "7. Fine" << endl << endl;
      do{
         cout << "Scelta: ";
         cin >> scelta;
      } while (!((scelta > 0) && (scelta < 8)));
      cout << endl;
      switch (scelta){
         case 1:
            i++;
            cout << "Inserisci titolo libro: ";
            cin >> a.chiave;
            cout << "Inserisci cognome autore: ";
            cin >> a.attributo.cognome;
            cout << "Inserisci nome autore: ";
            cin >> a.attributo.nome;
            cout << "Inserisci copie disponibili: ";
            cin >> a.attributo.pezzi;
            d.inserisci(a);
            break;
         case 2:
            cout << "Inserisci titolo libro da cancellare: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.cancella(a.chiave);
               i--;
            } else
               cout << "Libro " << a.chiave << " non trovato" << endl;
            break;
         case 3:
            cout << "Inserisci libro da aggiornare: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.recupera(a.chiave, a);
               cout << "Inserisci copie disponibili: ";
               cin >> b.attributo.pezzi;
               b.chiave=a.chiave;
               b.attributo.cognome=a.attributo.cognome;
               b.attributo.nome=a.attributo.nome;
               d.aggiorna(b.chiave, b);
               cout << "Dizionario aggiornato" << endl;
            } else
               cout << "Libro " << b.chiave << " non presente" << endl;
            break;
         case 4:
            cout << "Inserisci libro da recuperare: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.recupera(a.chiave, a);
               cout << "Titolo: " << a.chiave << " -> " 
                    << a.attributo.nome << " " << a.attributo.cognome
                    << " " << a.attributo.pezzi << " copie disponibili!" << endl;
            } else
               cout << "Libro " << a.chiave << " non presente" << endl;
            break;
         case 5:
            l=d.copiaDizionario();
            stampaLista(l);
            break;
         case 6:
            cout << "Inserisci titolo: ";
            cin >> a.chiave;
            if (d.appartiene(a.chiave)){
               d.recupera(a.chiave, a);
               if (a.attributo.pezzi==0)
                  cout << "Numero copie esaurite!" << endl;
               else
                  cout << "Numero copie disponibili: " << a.attributo.pezzi << endl;
            } else
               cout << "Libro " << a.chiave << " non presente" << endl;
            break;
         case 7:
            cout << "bye bye..." << endl;
            break;
      }
      system("PAUSE");
      system("CLS");
   } while (scelta != 7);
   return 0;
}

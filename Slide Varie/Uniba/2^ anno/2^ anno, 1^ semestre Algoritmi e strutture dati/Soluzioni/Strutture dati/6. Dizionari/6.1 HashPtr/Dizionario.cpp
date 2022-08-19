#include <iostream>
#include <cstdlib>
#include <string.h>

#include "Dizionario.h"

using namespace std;

Dizionario::Dizionario(){
   creaDizionario();
}
Dizionario::~Dizionario(){
   posizione p;
   for (int i = 0; i < M; i++){
      p = dizionario[i].primoLista();
      while (!dizionario[i].fineLista(p)){
         dizionario[i].cancLista(p);
         p = dizionario[i].primoLista();
      }
   }
}
   
void Dizionario::creaDizionario(){
   for (int i = 0; i < M; i++)
      dizionario[i].creaLista();
}
   
bool Dizionario::appartiene(tipochiave k){
   int h = hashWord(k);
   bool trovato = false;
   tipoelem a;
   posizione p = dizionario[h].primoLista();
   while (!(dizionario[h].fineLista(p) || trovato)){
      dizionario[h].leggiLista(a,p);
      if (a.chiave == k)
         trovato = true;
      p = dizionario[h].succLista(p);
   }
   return trovato;
}
   
bool Dizionario::inserisci(tipoelem a){
   int h = hashWord(a.chiave);
   bool inserito = false;
   if (!appartiene(a.chiave)){
      cout << a.chiave << " inserita in posizione " << h << endl;
      dizionario[h].insLista(a, NULL);
      inserito = true;
   } else
      cout << a.chiave << " presente in posizione " << h << endl;
   return inserito;
}

bool Dizionario::cancella(tipochiave k){
   int h = hashWord(k);
   bool trovato = false;
   tipoelem a;
   posizione p = dizionario[h].primoLista();
   while (!(dizionario[h].fineLista(p) || trovato)){
      dizionario[h].leggiLista(a,p);
      if (a.chiave == k){
         dizionario[h].cancLista(p);
         std::cout << "Parola trovata in posizione " << h << " e cancellata" << std::endl; 
         trovato = true;
      }
      p = dizionario[h].succLista(p);
   }
   return trovato;
}
   
bool Dizionario::recupera(tipochiave k, tipoelem &a){
   int h = hashWord(k);
   bool trovato = false;
   posizione p = dizionario[h].primoLista();
   while (!(dizionario[h].fineLista(p) || trovato)){
      dizionario[h].leggiLista(a,p);
      if (a.chiave == k)
         trovato = true;
      else
         p = dizionario[h].succLista(p);
   }
   return trovato;
}

bool Dizionario::aggiorna(tipochiave k, tipoelem a){
   int h = hashWord(k);
   bool trovato = false;
   tipoelem temp;
   posizione p = dizionario[h].primoLista();
   while (!(dizionario[h].fineLista(p) || trovato)){
      dizionario[h].leggiLista(temp,p);
      if (temp.chiave == k){
         dizionario[h].scriviLista(a, p);
         trovato = true;
      } else
         dizionario[h].succLista(p);
   }
   return trovato;
}

void Dizionario::stampa(){
	for(int i = 0; i < M; i++){
		if(!dizionario[i].listaVuota()){
			posizione p = dizionario[i].primoLista();
			tipoelem a;
			int collision = 0;
			cout << "Elementi con chiave " << i << ":" << endl;
			while (!dizionario[i].fineLista(p)){
				dizionario[i].leggiLista(a,p);
				cout << "Campo chiave: " << a.chiave << " Attributo: " << a.attributo.num <<endl;
				p = dizionario[i].succLista(p);
				collision++;
			}
			cout << "Numero di collisioni per la chiave " << i << ": " << collision-1 << "\n" << endl;
		}
	}
	cout << "Per le chiavi non specificate non sono stati trovati elementi"<< endl;
}

int Dizionario::hashWord(tipochiave k){
   unsigned temp = 0;
   for (int i = 0; k[i] != '\0'; i++)
   temp = ((unsigned)k[i]) + (31 * temp);
   return temp % M;
}


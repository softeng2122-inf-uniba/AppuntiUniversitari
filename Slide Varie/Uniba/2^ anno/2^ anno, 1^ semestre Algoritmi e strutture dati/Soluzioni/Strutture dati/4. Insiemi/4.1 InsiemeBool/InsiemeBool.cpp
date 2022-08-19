#include <iostream>
#include <cstdlib>
#include "InsiemeBool.h"
   
InsiemeBool::InsiemeBool(){
   creaInsieme();
}
InsiemeBool::~InsiemeBool(){
   for (int i = 0; i < MAXLUNG; i++){
      insieme[i] = false;
   }
}
		
void InsiemeBool::creaInsieme(){
   for (int i = 0; i < MAXLUNG; i++){
      insieme[i] = false;
   }
}

bool InsiemeBool::insiemeVuoto(){
   bool flag = false;
   for (int i = 0; ((i < MAXLUNG) && (!flag)); i++){
      flag = insieme[i];
   }
   return !flag;
}

bool InsiemeBool::appartiene(tipoelem a){
   return insieme[a];
}

void InsiemeBool::inserisci(tipoelem a){
   insieme[a] = true;
}

void InsiemeBool::cancella(tipoelem a){
   insieme[a] = false;
}

InsiemeBool InsiemeBool::unione(InsiemeBool a){
   InsiemeBool c;
   for (int i = 0; i < MAXLUNG; i++){
      if ((insieme[i] || a.appartiene(i)))
         c.inserisci(i);
   }
   return c;
}

InsiemeBool InsiemeBool::intersezione(InsiemeBool a){
   InsiemeBool c;
   for (int i = 0; i < MAXLUNG; i++){
      if ((insieme[i] && a.appartiene(i)))
         c.inserisci(i);
   }
   return c;
}
InsiemeBool InsiemeBool::differenza(InsiemeBool a){
   InsiemeBool c;
   for (int i = 0; i < MAXLUNG; i++){
      if ((insieme[i] && (!a.appartiene(i))))
         c.inserisci(i);
   }
   return c;
}

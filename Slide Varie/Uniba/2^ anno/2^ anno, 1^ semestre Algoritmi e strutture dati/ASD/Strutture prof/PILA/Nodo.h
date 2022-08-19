//DEFINIZIONE DELLA CLASSE NODO 
#ifndef NODO_H
#define NODO_H
typedef int tipoelem;
class Nodo{
	private:
   	tipoelem elem;
      Nodo* next;
   public:
   	Nodo();
      ~Nodo();
      tipoelem getElem();
      Nodo* getNext();
      void setElem(tipoelem);
      void setNext(Nodo*);
};//end-class
typedef Nodo* posizione;
#endif
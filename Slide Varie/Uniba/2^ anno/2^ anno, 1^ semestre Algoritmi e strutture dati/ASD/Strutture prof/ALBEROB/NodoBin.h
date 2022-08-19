//DEFINIZIONE DEL NODO DELL'ALBERO BINARIO
#ifndef NODOBIN_H
#define NODOBIN_H
typedef int tipoelem;

class NodoBin {
private:
   tipoelem elem;
   NodoBin* sx;	//FIGLIO SINISTRO
   NodoBin* dx;   //FIGLIO DESTRO
   NodoBin* padre;//PADRE
public:
	NodoBin();
   ~NodoBin();
   void setelem(tipoelem);
   void setsx(NodoBin*);
   void setdx(NodoBin*);
   void setpadre(NodoBin*);
   tipoelem getelem();
   NodoBin* getsx();
   NodoBin* getdx();
   NodoBin* getpadre();
};

typedef NodoBin* cellap; //PUNTATORE AL NODO
#endif


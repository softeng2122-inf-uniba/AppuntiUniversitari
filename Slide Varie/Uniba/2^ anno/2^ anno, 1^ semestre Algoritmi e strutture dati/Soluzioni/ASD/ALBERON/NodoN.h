#ifndef NODON_H
#define NODON_H
typedef int tipoelem;
class NodoN{
private:
	tipoelem elem;
   NodoN* padre;
   NodoN* primof;
   NodoN* fratello;
public:
   NodoN();
   ~NodoN();
   void setelem(tipoelem);
   void setpadre(NodoN*);
   void setprimof(NodoN*);
   void setfratello(NodoN*);
   tipoelem getelem();
   NodoN* getpadre();
   NodoN* getprimof();
   NodoN* getfratello();
};
typedef NodoN* cellap;
#endif
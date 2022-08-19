//definizione della classe pila
#ifndef PILA_H
#define PILA_H
class Pila{
	private:
   	posizione testa;
   public:
   	Pila();
      ~Pila();
      void creapila();
      bool pilavuota();
      tipoelem leggipila();
      void fuoripila();
      void inpila(tipoelem);
      void stampa();
};//end-class
#endif
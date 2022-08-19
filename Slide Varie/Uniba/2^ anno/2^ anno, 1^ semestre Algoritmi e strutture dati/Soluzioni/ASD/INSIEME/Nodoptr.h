//definizione di un nodo con puntatori
#ifndef NODO_H
#define NODO_H
typedef int tipoelem;

class Nodoptr{
   private:
   	tipoelem elem;
      Nodoptr *succ, *pred;
   public:
      Nodoptr();	//costruttore
      ~Nodoptr(); //distruttore
      void setelem(tipoelem);
      void setsucc(Nodoptr*);
      void setpred(Nodoptr*);
      tipoelem getelem();
      Nodoptr* getsucc();
      Nodoptr* getpred();
};//end-class
typedef Nodoptr* posizione;
#endif



#ifndef NODOC_H
#define NODOC_H

typedef int tipoelem;

class Nodoc
{
   private:
   tipoelem valore;
   int succ;

   public:
   Nodoc();
   ~Nodoc();
   tipoelem leggivalore();
   void scrivivalore(tipoelem);
   int leggisucc();
   void scrivisucc(int);
};

#endif

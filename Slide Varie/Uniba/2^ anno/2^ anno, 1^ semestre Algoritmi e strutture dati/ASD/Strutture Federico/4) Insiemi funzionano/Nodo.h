#ifndef _NODO_H
#define _NODO_H

typedef int tipoelem;

class Nodo{

    private:
       tipoelem elemento;
       Nodo *prec, *succ;
    public:
        Nodo();
        ~Nodo();
        void setelem(tipoelem);
        void setsucc(Nodo*);
        void setprec(Nodo*);
        tipoelem getelem();
        Nodo* getsucc();
        Nodo* getprec();
};

typedef Nodo* posizione;

#endif // _NODO_H

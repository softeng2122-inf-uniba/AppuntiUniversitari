#ifndef Nodo_H
#define Nodo_H

typedef int tipoelem;

class Nodo{
    private:
        tipoelem esponente;
        tipoelem coefficiente;
        Nodo *succ,*prec;
    public:
        Nodo();
        ~Nodo();
        void setesponente(tipoelem);
        void setcoefficiente(tipoelem);
        void setsucc(Nodo*);
        void setprec(Nodo*);
        tipoelem getesponente();
        tipoelem getcoefficiente();
        Nodo* getsucc();
        Nodo* getprec();
};

typedef Nodo* polinomio;
#endif // Nodo_H

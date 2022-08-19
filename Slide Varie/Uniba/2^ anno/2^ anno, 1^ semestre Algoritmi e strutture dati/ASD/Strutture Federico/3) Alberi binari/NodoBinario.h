#ifndef _NODOBINARIO_H
#define _NODOBINARIO_H
typedef int tipoelem;

class NodoBinario {
    private:
        tipoelem elem;
        NodoBinario* sx;	//FIGLIO SINISTRO
        NodoBinario* dx;   //FIGLIO DESTRO
        NodoBinario* padre;//PADRE
    public:
        NodoBinario();
        ~NodoBinario();
        void setelem(tipoelem);
        void setsx(NodoBinario*);
        void setdx(NodoBinario*);
        void setpadre(NodoBinario*);
        tipoelem getelem();
        NodoBinario* getsx();
        NodoBinario* getdx();
        NodoBinario* getpadre();
};

typedef NodoBinario* cellap; //PUNTATORE AL NODO
#endif // _NODOBINARIO_H

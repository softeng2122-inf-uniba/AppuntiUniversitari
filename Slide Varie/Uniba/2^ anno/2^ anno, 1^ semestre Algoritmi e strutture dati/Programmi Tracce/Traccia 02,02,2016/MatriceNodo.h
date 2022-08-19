#ifndef MATRICENODO_H
#define MATRICENODO_H

typedef int tipoelem;

class Nodo{
    private:
        tipoelem r,c,v;
        Nodo *suc,*prec;
    public:
        Nodo();
        ~Nodo();
        void creanodo();
        void setriga(tipoelem);
        void setcolonna(tipoelem);
        void setvalore(tipoelem);
        void setsuc(Nodo*);
        void setprec(Nodo*);
        int getvalore();
        int getriga();
        int getcolonna();
        Nodo* getsuc();
        Nodo* getprec();
};
typedef Nodo* campo;

#endif // MATRICENODO_H

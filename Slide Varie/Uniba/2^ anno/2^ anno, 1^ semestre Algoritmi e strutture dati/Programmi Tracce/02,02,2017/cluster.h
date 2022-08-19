#ifndef CLUSTER_H
#define CLUSTER_H
#include "oggetto.h"
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef string tipoelem;

class Cluster{

    private:
        tipoelem nm;
        oggetto inizio,fine;
        Cluster *prec,*suc;
    public:
        Cluster();
        ~Cluster();
        void setnome(tipoelem);
        void setsuc(Cluster*);
        void setprec(Cluster*);
        tipoelem getnome();
        Cluster* getsuc();
        Cluster* getprec();
        bool vuoto();
        oggetto primocluster();
        oggetto finecluster();
        oggetto sucluster(oggetto);
        oggetto precluster(oggetto);
        void stampa();
        void inserimento();
        void inserisci(oggetto,tipoelem);
        bool finelista();
};

typedef Cluster* cluster;
#endif // CLUSTER_H

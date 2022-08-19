#ifndef CLUSTERING_H
#define CLUSTERING_H
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"cluster.h"
#include"oggetto.h"
using namespace std;

typedef string tipoelem;
class Clustering{
    private:
        cluster primo,ultimo;
    public:
        Clustering();
        ~Clustering();
        void crea();
        bool vuoto();
        bool fineclustering();
        cluster primocluster();
        cluster ultimocluster();
        cluster sucluster(cluster);
        cluster precluster(cluster);
        void stampa1();
        void inserimento();
        void inserisci(cluster,tipoelem);
        int nCluster();
        void stampaCluster(tipoelem);

};

#endif // CLUSTERING_H

#ifndef CLASSESTRINGA_H
#define CLASSESTRINGA_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef string tipoelem;
class stringa{
    private:
        tipoelem str;
        stringa *suc;*prec;
    public:
        stringa();
        ~stringa();
        void setstr(tipoelem n);
        void setsuc(stringa*);
        void setprec(stringa*);
        tipoelem getvalore();
        stringa* getsuc();
        stringa* getprec();
};

typedef stringa* Stringa;


#endif // CLASSESTRINGA_H

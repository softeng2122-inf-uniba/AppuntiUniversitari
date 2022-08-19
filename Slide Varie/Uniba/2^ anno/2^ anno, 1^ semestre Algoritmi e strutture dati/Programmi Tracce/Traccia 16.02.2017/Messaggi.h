#ifndef MESSAGGI_H
#define MESSAGGI_H
#include "Nodo.h"
#include<string.h>
#include <iostream>
#include<stdio.h>

using namespace std;

typedef string mess;

class Messaggio{
    private:
        mess danomeutente,dacognomeutente,messaggio,anomeutente,acognomeutente;
        Messaggio *prec,*suc;
    public:
        Messaggio();
        ~Messaggio();
        void setmessaggio(mess);
        void setsuc(Messaggio*);
        void setdanomeutente(mess);
        void setdacognomeutente(mess);
        void setanomeutente(mess);
        void setacognomeutente(mess);
        void setprec(Messaggio*);
        Messaggio* getprec();
        Messaggio* getsuc();
        mess getmessaggio();
        mess getdanomeutente();
        mess getdacognomeutente();
        mess getanomeutente();
        mess getacognomeutente();

};
typedef Messaggio* messaggio;

#endif // MESSAGGI_H

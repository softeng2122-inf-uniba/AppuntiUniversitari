#include <iostream>
#include <string.h>


using namespace std;


void caricavettore(int A[]);
int greaterthen(int x, int A[]);
bool member(int x, int A[]);
int elementopiugrande(int A[]);
int posizione(int x, int A[]);
void rimozione(int x, int A[]);
int ordinamento(int A[]);
void scambiare_ordine_elementi(int A[]);

int dimensione;
int main()
{
    int maggiore,y,pos, ordinare;
    bool appartenente;
    cout<<"Inserire diemensione vettroe"<<endl;
    cin>>dimensione;
    int A[dimensione];
    caricavettore(A);
    cout<<"Inserire il numero del quale si vuole sapere quanti elementi sono maggiori"<<endl;
    cin>>y;
    maggiore=greaterthen(y,A);
    cout<<"L'elemento maggiore e': "<<maggiore<<endl;
    cout<<"Inserire elemento da verificare l'esistenza nel vettore"<<endl;
    cin>>y;
    appartenente=member(y,A);
    if(appartenente==0)
        cout<<"L'elemento appartiene al vettore"<<endl;
    else
        cout<<"L'elemento non appartiene al vettore"<<endl;
    y=elementopiugrande(A);
    cout<<"L'elemento più grande nel vettore e': "<<y<<endl;
    pos=posizione(y,A);
    cout<<"La sua posizioe è: "<<pos<<endl;
    cout<<"Inserire elemento da eliminare dal vettore"<<endl;
    cin>>y;
    rimozione(y,A);
    ordinare=ordinamento(A);
    switch(ordinare)
    {
        case 1:
            cout<<"Il vettore è ordinato in ordine cresccente"<<endl;
            break;
        case 2:
            cout<<"Il vettore è ordinato in maniera decrescente"<<endl;
            break;
        case 3:
            cout<<"il vettore è ordinato in maniera costante"<<endl;
            break;
    }
    scambiare_ordine_elementi(A);
    return 0;
}

void scambiare_ordine_elementi(int A[])
{
    int i,j,resto,solve;
    resto=dimensione%2;
    if(resto==0)
    {
        i=0;
        j=dimensione;
        while(i<j)
        {
            solve=A[i];
            A[i]=A[j];
            A[j]=solve;
            i++;
            j--;
        }
    }
    else
    {
        i=0;
        j=dimensione;
        while(!(i==j))
        {
            solve=A[i];
            A[i]=A[j];
            A[j]=solve;
            i++;
            j--;
        }
    }
}

int ordinamento(int A[])
{
    int i=0,j,ordinato;
    while(i<dimensione)
    {
        j=i+1;
        while(j<=dimensione)
        {
            if(A[i]==A[j])
                ordinato=3;
            if(A[i]>A[j])
                ordinato=2;
            if(A[i]<A[j])
                ordinato=1;
            j++;
        }
        i++;
    }
    return(ordinato);
}

void rimozione(int x,int A[])
{
    int i=0,j,solve;
    while(i<dimensione)
    {

        if(A[i]==x)
            A[i]=0;
        j=i;
        while(j<=dimensione)
        {
            solve=A[j+1];
            A[j+1]=0;
            A[j]=solve;
            j++;
        }
    }
}

int posizione(int x, int A[])
{
    int i=0,solve;
    while(i<dimensione)
    {
        if(A[i]==x)
            solve=i;
        i++;
    }
    return(solve+1);
}

int elementopiugrande(int A[])
{
    int i=0,m;
    m=0;
    while(i<dimensione)
    {
        if(A[i]>m)
            m=A[i];
        i++;
    }
    return(m);
}

bool member(int x, int A[])
{
    int i;
    bool app;
    i=0;
    while(i<dimensione)
    {
        if(A[i]==x)
            app=1;
        else
            app=0;
        i++;
    }
    return(app);
}

int greaterthen(int x,int A[])
{
    int i=0,cont=0;
    while(i<dimensione)
    {
        if(A[i]>x)
            cont++;
        i++;
    }
    return(cont);
}

void caricavettore(int A[])
{
    int i;
    i=0;
    while(i<dimensione)
    {
        cout<<"inserire elemento"<<endl;
        cin>>A[i];
        i++;
    }
}

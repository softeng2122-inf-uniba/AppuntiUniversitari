#include <iostream>
#include <stdlib.h>

#include <string>

#define dim 33

typedef char *tipoelem;
typedef class elemento *elemPTR;
unsigned funzionehash(tipoelem);

class elemento
{
   private:
 	tipoelem chiave;
 	elemPTR succ;

	public:
 	elemento();
 	tipoelem getelemento();
 	elemPTR getsucc();
 	void setelemento(tipoelem);
 	void setsucc(elemPTR);
};

class dizionario
{
 	private:
  	elemPTR iniziodizionario[dim];

	public:
 	void creadizionario();
 	void inserisci(tipoelem);
 	void cancella(tipoelem);
   bool appartiene(tipoelem);
//	void aggiorna();
 	elemPTR recupera(int);
};

elemento::elemento()
{
	succ=NULL;
   chiave='\0';
}


void elemento::setelemento(tipoelem attrib)
{
	chiave=strdup(attrib);
}

void elemento::setsucc(elemPTR posizione)
{
	succ=posizione;
}

tipoelem elemento::getelemento()
{
	return chiave;
}

elemPTR elemento::getsucc()
{
	return succ;
}


void dizionario::creadizionario()
{
	for(int i=0;i<dim;i++)
   iniziodizionario[i]=NULL;
}


void dizionario::inserisci(tipoelem attrib)
{
	if(appartiene(attrib))
   	return;
	elemPTR temp=new class elemento;
  	unsigned valoreh;
   valoreh=funzionehash(attrib);
  	if (iniziodizionario[valoreh]==NULL)
   	iniziodizionario[valoreh]=temp;
  	else
  	{
   	temp->setsucc(iniziodizionario[valoreh]);
   	iniziodizionario[valoreh]=temp;
   }
   temp->setelemento(attrib);
}

void dizionario::cancella(tipoelem attrib)
{
	if(!appartiene(attrib))
   {
   	return;
   }

  	elemPTR p,pre;
  	unsigned valoreh,i=0;
  	valoreh=funzionehash(attrib);
  	p=pre=iniziodizionario[valoreh];
  	while(strcmp(p->getelemento(),attrib) !=0)
   {
   	p=p->getsucc();
    	i++;
   }
   if(i==0)
  	{
   	iniziodizionario[valoreh]=(p->getsucc());
   	delete p;
  	}
  	else
   {
  		while(i==0)
  		{
   		pre=pre->getsucc();
    		i--;
   	}
  		pre->setsucc(p->getsucc());
  		delete p;
	}
}

bool dizionario::appartiene(tipoelem attrib)
{
	elemPTR p;
  	unsigned valoreh;
   valoreh=funzionehash(attrib);
  	p=iniziodizionario[valoreh];
  	while (p != NULL)
  	{
   	if (strcmp(p->getelemento(),attrib)==0)
    		return true;
  		else
   		p=p->getsucc();
  	}
  	return false;
}

elemPTR dizionario::recupera(int posizione)
{
	if(posizione>=0 && posizione<dim)
 	return iniziodizionario[posizione];
}


unsigned funzionehash(tipoelem s)
{
	unsigned valoreh;
   for (valoreh = 0; *s != '\0'; s++)
   	valoreh = *s + 12 * valoreh;
  	return (valoreh % dim);
}

void stampadizionario(dizionario diz)
{
	elemPTR p;
 	for (int i=0;i<dim;i++)
  	{
   	p=diz.recupera(i);
   	while (p!=NULL)
   	{
      	cout <<p->getelemento()<<"\n";
    		p=p->getsucc();
      }
  	}
}

void inserimento(dizionario &diz)
{
	bool tf=true;
   char stringa[40];
   char risp;
 	while(tf)
 	{
   	cout <<"che elemento inserisci? ";
   	cin >> stringa;
   	diz.inserisci(stringa);
   	cout <<"vuoi inserire altri elementi? ";
   	cin >> risp;
   	if (risp=='n')
   		tf=false;
 	}
}

int main()
{
	char stringa[40];
 	dizionario diz;
 	diz.creadizionario();
 	inserimento(diz);
 	stampadizionario(diz);
 	cout <<"quale elemento vuoi cancellare? ";
   cin >> stringa;
 	diz.cancella(stringa);
  	stampadizionario(diz);
 	system("pause");
   return 0;
}

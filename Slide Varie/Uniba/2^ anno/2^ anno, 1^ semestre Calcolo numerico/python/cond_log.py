# -*- coding: utf-8 -*-
"""
Created on Wed Nov  2 10:58:37 2016

@author: felix
"""

from numpy import *
from pylab import *
def cond_log():
    """
    Mostra il mal condizionamento della funzione
    log(x) per x vicino a 1
    
    COMMENTI:
    - si lavora in semplice precisione e l'errore e' 
      valutato scegliendo come valori di riferimento
      quelli valutati in doppia precisione
    - la funzione float32 trasforma un numero (o array numerico)
      da doppia precisione in semplice precisione
    - il modulo pylab contiene le funzioni che gestiscono
      la grafica
    - loglog genera un grafico con assi in scala logaritmica
      su entrambi gli assi
    """
    c=logspace(0,8,100)
    x=1+1/c;
    xs=float32(x)
    y=log(x)
    ys=log(xs)
    err=abs(ys-y)/abs(y) # errore inerente
    loglog(x-1,err)
    title('Condizionamento del log(x)')
    xlabel('distanza di x da 1')
    ylabel('errore inerente')
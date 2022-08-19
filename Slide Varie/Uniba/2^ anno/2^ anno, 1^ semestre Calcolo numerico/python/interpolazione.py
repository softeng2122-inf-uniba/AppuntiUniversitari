# -*- coding: utf-8 -*-
"""
Created on Wed Dec 13 11:40:18 2017

@author: Docente
"""

from numpy import *
from pylab import *

def lagrange(x,y,xx):
    """
    Costruisce il polinomio interpolante di Lagrange
    definito dai nodi x e dalle ordinate y, e lo valuta
    nei punti xx
    
    Parametri di input
     x: vettore dei nodi
     y: vettore delle ordinate
    xx: vettore di punti in cui valutare il polinomio
    
    Parametri di output
     p: vettore che contiene le valutazioni del 
        polinomio interpolante nei punti definiti in xx
    """
    
    n=len(x) # numero di nodi (corrisponde a n+1 negli appunti)
    p=0
    for k in range(0,n):
        Lk=1
        for i in range(0,n):
            if i!=k:
                Lk=Lk*(xx-x[i])/(x[k]-x[i])            
        p=p+Lk*y[k]
    return p


def interpola(f,a,b,n):
    """
    Costruisce e disegna il polinomio che interpola
    una funzione f(x) in n nodi uniformemente distribuiti
    nell'intervallo [a,b]  
    """
    close()
    x=linspace(a,b,n) # vettore dei nodi
    y=f(x) # vettore delle ordinate
    xx=linspace(a,b,100)
    fxx=f(xx)
    pxx=lagrange(x,y,xx)
    
    plot(x,y,"o",label="punti da interpolare")
    plot(xx,fxx,label="f(x)")
    plot(xx,pxx,label="p(x)")
    legend()
    show()
     

def f1(x):
    y=sin(x)
    return y


def f2(x):
    y=exp(-x)*cos(4*x)
    return y
    
def runge(x):
    y=1/(1+x**2)
    return y




   
    
    
    
    
    
    
    
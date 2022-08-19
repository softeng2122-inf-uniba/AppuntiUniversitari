# -*- coding: utf-8 -*-
"""
Created on Sun Oct 16 21:58:56 2016

@author: felix
"""

def newton(f,x0,tol,it_max=50,stampa=0):
    """
    Metodo di Newton 
    per la ricerca degli zeri di una funzione
    
    Dati di input
    -------------
    f: funzione di cui ricercare uno zero 
    
    x0: punto iniziale
    
    tol: precisione richiesta
    
    it_max:  num. max di iterazioni consentite
    
    stampa:  1 se si desidera la stampa degli elementi della successione
    
    Dati di output
    --------------
    x1: approssimazione dello zero di f
    
    it: numero di iterate effettuate 
    """
    it=0
    arresto=False
    while not arresto and it<=it_max:
        it=it+1
        x1=x0-f(x0)/f(x0,1)
        arresto=abs(x0-x1)/(1+abs(x1))<tol
        if stampa: print(x1)
        x0=x1
    return x1,it

    

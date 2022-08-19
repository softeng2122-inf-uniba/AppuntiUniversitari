# -*- coding: utf-8 -*-
"""
Created on Mon Oct  2 10:32:37 2017

@author: Docente
"""

def bisezioni(f,a,b,tol,nmax):
    """
    METODO DELLE SUCCESSIVE BISEZIONI
    
    Parametri di input
    ------------------
  
    f: funzione di cui ricercare uno zero
    
    a,b: estremi dell'intervallo di lavoro
    
    tol: precisione richiesta
    
    nmax: numero max di iterate consentite
    
    Parametri di output
    -------------------
    c: approssimazione dello zero
    
    it: numero di iterazioni effettuate
    """
    fa=f(a)
    fb=f(b)
    if fa*fb>0:
        print("la funzione non cambia segno agli estremi dell'intervallo [a,b]")
        return
    it=0     
    arresto=False
    while (not arresto) and it<=nmax:
        it=it+1
        c=(a+b)/2
        fc=f(c)
        if fc==0:
            return c, it
        elif fa*fc<0:
            b=c
        else:
            a=c
            fa=fc
        arresto=(b-a)/(1+min(abs(a),abs(b)))<tol
    if not arresto:
        print("precisione non raggiunta")
    return c, it
      

# -*- coding: utf-8 -*-
"""
Created on Wed Nov  8 13:46:47 2017

@author: Docente
"""
from numpy import * 
from scipy import *

def laplace(A):
    [m,n]=shape(A)
    if n==1:
        d=A[0,0]
    else:
        d=0
        for j in range(0,n):
            A1j=delete(A,0,axis=0)
            A1j=delete(A1j,j,axis=1)
            d=d+(-1)**(j)*A[0,j]*laplace(A1j)
    return d

def triang_sup(A,b):
    """
    Algoritmo di sostituzione all'indietro
    per la risoluzione dei sistemi lineari
    
    Ax=b
    
    triangolari superiori
    """
    [m,n]=shape(A) # oppure n=len(b)
    x=zeros(shape=(n,1)) # prealloca la memoria per x
    for i in range(n-1,-1,-1):
        s=0
        for j in range(i+1,n):
            s=s+A[i,j]*x[j]
        if abs(A[i,i])<1e-15:
            print("matrice singolare")
            return nan
        else:
            x[i]=(b[i]-s)/A[i,i]
    return x
        
def fatt_lu(A):
    #versione NON OTTIMIZZATA
    [m,n]=shape(A)
    if m!=n:
        print("matrice non quadrata")
    A=copy(A)
    tol=1e-15
    L=identity(n)
    for k in range(0,n-1):
        if abs(A[k,k])<tol:
            print("minore principale nullo")
            return
        for i in range(k+1,n):
            mik=-A[i,k]/A[k,k]
            for j in range(k+1,n):
                A[i,j]=A[i,j]+mik*A[k,j]
            L[i,k]=-mik
    U=triu(A) # estrae la parte triang. sup. di A
    return L,U
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
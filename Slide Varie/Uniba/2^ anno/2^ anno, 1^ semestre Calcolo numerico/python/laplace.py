# -*- coding: utf-8 -*-
"""
Created on Mon Nov  6 14:44:37 2017

@author: felix
"""

def laplace(A):
    """
    Funzione ricorsiva che implementa la regola di Laplace 
    per il calcolo del determinante di una matrice
    Esempio:
    from numpy import *
    from scipy import *
    A=random.rand(5,5) # genera una matrice random 5x5
    laplace(A)
    linalg.det(A) # determinante calcolato mediante la funz. predefinita di numpy
    """
    [m,n]=shape(A)
    if n==1:
        d=A[0,0]
    else:
        d=0
        for j in range(0,n):
            A1j=delete(A,0,axis=0)
            A1j=delete(A1j,j,axis=1)
            d=d+(-1.)**(j)*A[0,j]*laplace(A1j)
    return d

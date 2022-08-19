import numpy as np
import numpy.linalg as la
import time

def GaussSeidel(A,b,x0):
    
    # Determina dimension del problma
    n = len(A)
    
    # Iterazione massime e tolleranza
    Kmax = 100 ; tol = 1.0e-6 ; btol = la.norm(b)*tol
    
    # Inizializzare il ciclo di calcolo
    k = 0 ; stop = False
    x1 = np.zeros(n)
    
    while not(stop) and k < Kmax:
        for i in range(n):
            S = 0 
            for j in range(0,i):
                S = S + A[i,j]*x1[j]
            for j in range(i+1,n):
                S = S + A[i,j]*x0[j]
            x1[i] = (b[i] - S)/A[i,i]
        r = b - np.dot(A,x1)
        stop = (la.norm(r)<btol) and (la.norm(x1-x0)<btol)
        x0 = x1
        k = k + 1
    
    if not(stop):
        print('Processo non converge in %d iterazioni' % Kmax)
        
    return x1, k

for n in range(100,4000,100):

    e1 = np.ones(n-1) ; e = np.ones(n)
    A = np.diag(e1,-1) - 4*np.diag(e,0) + np.diag(e1,1)
    xsol = np.ones(n)
    b = np.dot(A,xsol) 

    x0 = np.random.rand(n)
    Ripet = 2 ; inizio = time.time()
    for i in range(Ripet):
        x, k = GaussSeidel(A,b,x0)
    fine = time.time()
    tempo = (fine - inizio)/Ripet
    Errore = la.norm(x-xsol)
    print('n=%d  Iter.=%d  Errore=%e  tempo=%f' % (n,k,Errore,tempo))




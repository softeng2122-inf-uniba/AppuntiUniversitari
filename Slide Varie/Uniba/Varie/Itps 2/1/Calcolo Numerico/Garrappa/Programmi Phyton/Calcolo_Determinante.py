import numpy as np
from time import clock

def Determ(A):
    
    n = A.shape[0]
    if n == 1:
        d = A[0,0]
    else:
        d = 0
        for j in range(1,n+1):
            A1j = np.delete(np.delete(A,j-1,1),0,0)
            d = d + (-1)**(j+1)*A[0,j-1]*Determ(A1j)
    return d

#n = 5 
#A = np.random.random((n,n))
#d = Determ(A)
#dd = np.linalg.det(A)
for n in range(1,8):
    A = np.random.random((n,n))
    inizio = clock()
    d = Determ(A)
    #d = np.linalg.det(A)
    fine = clock()
    tempo = (fine - inizio)
    print('n=%d tempo=%e' % (n,tempo))


    
    
    
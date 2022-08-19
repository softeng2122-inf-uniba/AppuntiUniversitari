import numpy as np
from fractions import Fraction

def StampaMatrice(A):
    n = A.shape[0]
    for i in range(n):
        for j in range(n):
            Af = Fraction(A[i,j]).limit_denominator()
            print('%7s ' % Af ,end=' ')
        print('')


def FattLU(A):
    U = np.copy(A)
    n = U.shape[0]
    L = np.zeros((n,n))
    for j in range(n-1):
        L[j,j] = 1
        for i in range(j+1,n):
            L[i,j] = U[i,j]/U[j,j]
            U[i,j] = 0
            for k in range(j+1,n):
                U[i,k] = U[i,k] - L[i,j]*U[j,k]        
    L[n-1,n-1] = 1
    
    return L, U

A = np.array([ [1,-3,2,4], \
              [1, 6, -3, 7] , \
              [-1, 9, 4, 2], \
              [4,-4,-2,5 ]]).astype(float)
L, U = FattLU(A)
test = np.linalg.norm(np.dot(L,U)-A)
print('Test differenza ||L*U-A|| = %e' % test)
    
print('Matrice A')
StampaMatrice(A)

print('Matrice L')
StampaMatrice(L)

print('Matrice U')
StampaMatrice(U)

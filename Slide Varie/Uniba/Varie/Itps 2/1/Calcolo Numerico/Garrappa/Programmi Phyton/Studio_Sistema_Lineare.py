import numpy as np
import matplotlib.pyplot as plt

# Costruzione matrice
n = 30
#A = np.random.random((n,n))
z = np.linspace(0,1,n)
A = np.array([ [z[i]**j for j in range(n)] for i in range(n)])
c = np.linalg.cond(A)

# Costruzione del problema test
x_teor = np.ones((n,1))
b = np.dot(A,x_teor)
x = np.linalg.solve(A,b)
Errore = np.linalg.norm(x_teor-x)/np.linalg.norm(x_teor)

print('Soluz Teor.   Soluz. Calc.')
for i in range(n):
    print('  %8.6f     %8.7f' % (x_teor[i],x[i]))
print('Errore = %e' % Errore)
print('Numero condizione A = %e' % c)

n_max = 30
Errore = np.zeros(n_max)
Stima_Errore = np.zeros(n_max)
epsilon = np.finfo(np.float).eps
for n in range(1,n_max):

    # Costruzione matrice test
    #A = np.random.random((n,n))
    z = np.linspace(0,1,n)
    A = np.array([ [z[i]**j for j in range(n)] for i in range(n)])
    c = np.linalg.cond(A)

    # Costruzione del problema test
    x_teor = np.ones((n,1))
    b = np.dot(A,x_teor)
    x = np.linalg.solve(A,b)
    Errore[n] = np.linalg.norm(x_teor-x)/np.linalg.norm(x_teor)
    Stima_Errore[n] = c*epsilon
    
x_asse = np.array([i for i in range(n_max)])
plt.semilogy(x_asse,Errore,'o-b',label='Errore')
plt.semilogy(x_asse,Stima_Errore,'*-r',label='Stima K(A)*eps')
plt.xlabel('n',fontsize=14)
plt.title('Studio condizionamento matrice')
plt.legend()
plt.show()





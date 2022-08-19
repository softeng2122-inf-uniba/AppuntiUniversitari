import numpy as np
import matplotlib.pyplot as plt

# Definizione funzione da integrare
def f(x):
    y = -6*x**2 + 16*x - 4
    return y

def F(x):
    y = -2*x**3 + 8*x**2 - 4*x + 2
    return y


# Calcolo formula composta Trapezi
def TrapeziComposti(f,a,b,N):
    # Calcolo estremi sottointervallo
    z = np.linspace(a,b,N+1)
    # Calcolo formula di quadratura
    fz = f(z)
    S = 0
    for i in range(1,N):
        S = S + fz[i] 
    T = (fz[0] + 2*S + fz[N])*(b-a)/2/N
    return T

# Intervallo di integrazione
a = 1.0 ; b = 2.0 

# Calcolo valore esatto integrale
I = F(b) - F(a)

# Calcolo integrale ed errore
print('Integrale essatto    : %f' % I)
N_range = range(1,200,10)
Errore = np.zeros(len(N_range))
for i in range(len(N_range)):
    N = N_range[i]
    T = TrapeziComposti(f,a,b,N)
    Errore[i] = abs(I - T)
    print('N=%d Errore=%e' %(N,Errore[i]))

plt.figure(1)
plt.semilogy(N_range,Errore,label='Errore Trapezi') 
plt.xlabel('N')
plt.legend()
       
        
        
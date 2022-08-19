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
N = 5 
T = TrapeziComposti(f,a,b,N)
E = abs(I - T)

print('Integrale essatto    : %f' % I)
print('Formula del Trapezio : %f' % T)
print('Errore commesso      : %e' % E)

# Rappresentazione grafica
x = np.linspace(a,b,200)
y = f(x)
plt.figure(1)
plt.plot(x,y,label='f(x)',linewidth=1.2)
plt.xlabel('x')    
        
        
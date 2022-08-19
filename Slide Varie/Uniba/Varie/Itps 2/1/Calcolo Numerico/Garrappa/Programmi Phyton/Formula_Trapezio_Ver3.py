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

    # Rappresentazione grafica dei trapezi        
    for i in range(0,N):
        x = np.array([z[i],z[i],z[i+1],z[i+1],z[i]])
        y = np.array([0,fz[i],fz[i+1],0,0])
        plt.plot(x,y,'k-',linewidth=1.1)         
    return T

# Intervallo di integrazione
a = 1.0 ; b = 2.0 

# Calcolo valore esatto integrale
I = F(b) - F(a)

# Inizializzazione grafica
fig = plt.figure(1)
ax = fig.add_axes([0,0,1,1])

# Calcolo integrale ed errore
N = 3 
T = TrapeziComposti(f,a,b,N)
E = abs(I - T)

print('Integrale essatto    : %f' % I)
print('Formula del Trapezio : %f' % T)
print('Errore commesso      : %e' % E)

# Rappresentazione grafica
x = np.linspace(a-0.5,b+0.1,200)
y = f(x)
plt.plot(x,y,label='f(x)',linewidth=1.2)
plt.xlabel('x')    

stringa = 'Integrale esatto : %f' % I
plt.text(0.1,0.3,stringa,fontsize=16,transform=ax.transAxes)
stringa = 'Formula del trapezio : %f' % T
plt.text(0.1,0.2,stringa,fontsize=16,transform=ax.transAxes)
stringa = 'Errore : %e' % E
plt.text(0.1,0.1,stringa,fontsize=16,transform=ax.transAxes)

   
        
import numpy as np
import matplotlib.pyplot as plt

# Funzione da interpolare
def funz(x):
    y = np.sin(3*x) + np.cos(2*x)
    return y

# Costruzione del polinomio
def Z_Coeff(x_nodi,y_nodi):
    n = len(x_nodi)
    X = np.zeros((n,n))
    for i in range(n):
        for j in range(n):
            if i == j:
                X[i,j] = 1
            elif j > i:
                X[i,j] = x_nodi[i] - x_nodi[j]
            else:
                X[i,j] = -X[j,i]
    z = np.zeros(n)
    for i in range(n):
        z[i] = y_nodi[i]/np.prod(X[i,:])
    return z

# Calcolo del polinomio in un punto
def Calc_Lagrange(x,x_nodi,z,y_nodi):
    check_nodi = abs(x - x_nodi) < 1.0e-14
    if True in check_nodi:
        temp = np.where(check_nodi == True)
        j = temp[0][0]
        p = y_nodi[j]
    else:
        n = len(x_nodi)
        S = 0
        for j in range(n):
            S = S + z[j]/(x-x_nodi[j])
        p = np.prod(x-x_nodi)*S
    return p

# Grado del polinomio
n = 15

# Calcolo dei nodi e dei valori associati ai nodi 
a = 0 ; b = np.pi
x_nodi = np.linspace(a,b,n+1)
y_nodi = funz(x_nodi)

# Calcolo coefficienti formula baricentrica
z = Z_Coeff(x_nodi,y_nodi)

# Punti in cui calcolare il polinomio
x = np.linspace(a,b,200)

# Calcolo del polinomio di interpolazione in x
m = len(x)
p = np.zeros(m)
for i in range(m):
    p[i] = Calc_Lagrange(x[i],x_nodi,z,y_nodi)

# Grafico Polinomio di interpolazione
plt.figure(0)
plt.plot(x,p,label='p(x)')
plt.plot(x,funz(x),label='f(x)')
plt.plot(x_nodi,y_nodi,'r*')
plt.legend()
plt.show(block=False)

# Resto del polinomio di interpolazione
# Grafico Polinomio di interpolazione
plt.figure(1)
plt.plot(x,abs(p-funz(x)),label='Resto')
plt.legend()
plt.show(block=False)











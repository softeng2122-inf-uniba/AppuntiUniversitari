import numpy as np
import matplotlib.pyplot as plt

# Funzione di cui calcolare la derivata
def f(x):
    y = np.exp(x)
    return y

# Derivata della funzione (da utilizzare per il confronto)
def f_der(x):
    y = np.exp(x)
    return y

# Punto in cui calcolare la derivata
x = 1

# Sequenza dei passi h
p = np.linspace(-16,0,17)
h_vett = 10**p

# Calcolo valore esatto di riferimento per la derivata 
df = f_der(x)

# Approssimazione derivata mediante rapporto incrementale
errass = np.zeros(len(h_vett))
for i in range(len(h_vett)):
    h = h_vett[i]
    dfh = (f(x+h)-f(x))/h
    errass[i] = np.abs(df-dfh)

# Grafico dell'errore
plt.loglog(h_vett,errass,'*-g')
plt.xlabel('h')
plt.ylabel('Errore')
plt.title('Approssimazione della derivata')
plt.show()

















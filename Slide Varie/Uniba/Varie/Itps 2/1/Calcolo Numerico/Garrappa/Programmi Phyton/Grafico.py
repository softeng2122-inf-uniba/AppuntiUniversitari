import numpy as np
import matplotlib.pyplot as plt

f = plt.figure(1)
x = np.linspace(0,4*np.pi,150)
y = np.sin(x)
z = np.cos(x)
plt.plot(x,y,'k-',label='sin(x)',linewidth=1)
plt.plot(x,z,'r',label='cos(x)',linestyle='--')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Grafico di funzioni')
plt.show()
f.savefig('Figura.pdf')
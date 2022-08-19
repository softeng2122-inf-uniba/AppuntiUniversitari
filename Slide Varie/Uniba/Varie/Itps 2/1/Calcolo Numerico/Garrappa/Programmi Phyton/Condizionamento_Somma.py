# Verifica condizionamento somma

# Inserimento valori per esperimento
x = float(input('Inserire dato x : '))
y = float(input('Inserire dato y : '))
pert = float(input('Inserire perturbazione : '))

# Costruzione dati perturbati
xt = x + pert
yt = y + pert

# Calcolo delle somme
S = x + y
St = xt + yt 

# Calcolo degli errori relativi
Err_x = abs(x-xt)/abs(x)
Err_y = abs(y-yt)/abs(y)
Err_S = abs(S-St)/abs(S)

# Visualizzazione dei risultati
print('Somma dati esatti     = %15.12f' % S)
print('Somma dati perturbati = %15.12f' % St)
print('Errore su dato x : %e' % Err_x)
print('Errore su dato y : %e' % Err_y)
print('Errore su somma  : %e' % Err_S)



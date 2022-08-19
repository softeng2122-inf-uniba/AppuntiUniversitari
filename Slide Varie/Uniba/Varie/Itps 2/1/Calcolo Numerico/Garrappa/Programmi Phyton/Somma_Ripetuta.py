a = 0.1

S = 0
#while S != 1:
while abs(S-1) > 1.0e-14:
    S = S + a
    #print('S = ' + str(S))
    print('S = %25.23f' % S)
    if S > 2:
        break

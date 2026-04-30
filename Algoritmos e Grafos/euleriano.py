import numpy as np

def warshall(matriz):
    n = np.shape(matriz)[0]
    r = np.copy(matriz)

    for k in range(0,n):
        for i in range(0,n):
            for j in range(0,n):
                if(r[i][j] == 1 or (r[i][k] == 1 and r[k][j] == 1)):
                    r[i][j] = 1
                else:
                    r[i][j] = r[i][j]
    
    print(r)
    #return r


#print(warshall([[1, 0, 0, 1], [0, 0, 0, 1], [1, 0, 0, 0], [0, 1, 0, 0]]))

def caminhoEuleriano(G):
    n = np.shape(G)[0]
    total = 0
    i = 0

    while(total <= 2) and (i < n):
        grau = 0
        for j in range(0,n):
            grau+= G[i][j]
        if grau%2 != 0 :
            total = total + 1
        i = i + 1
    
    if total > 2:
        print(False)
        #return False
    else:
        print(True)
        #return True
    

print(caminhoEuleriano([[0, 2, 2, 1], [2, 0, 0, 1], [2, 0, 0, 1], [1, 1, 1, 0]]))
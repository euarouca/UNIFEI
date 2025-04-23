def criaListaAdjacencias(matriz):
    lista = dict()
    
    for i, linha in enumerate(matriz):
        ind_colunas = list()
        for j in range(len(linha)):
            if matriz[i][j] > 0:
                ind_colunas.extend([j] * matriz[i][j])
    
        lista[i] = ind_colunas
    return lista

def verificaAdjacencia(listaAdj, vi, vj):
    return vj in listaAdj[vi]

def insereAresta(listaAdj, vi, vj):
    tipo = tipoGrafo(listaAdj)

    if tipo == 0 or tipo == 20 or tipo == 30:
        listaAdj[vi].append(vj)
        listaAdj[vj].append(vi)
    else: 
        listaAdj[vi].append(vj)

    listaAdj[vi].sort()
    listaAdj[vj].sort()
    return listaAdj
        
        
def insereVertice(listaAdj):
    listaAdj[len(listaAdj)] = []
    return listaAdj

def removeAresta(listaAdj, vi, vj):
    tipo = tipoGrafo(listaAdj)

    if tipo == 0 or tipo == 20 or tipo == 30:
        listaAdj[vi].remove(vj)
        listaAdj[vj].remove(vi)
    else: 
        listaAdj[vi].remove(vj)

    print(listaAdj)

def removeVertice(listaAdj, v):
    for c in listaAdj:
        while v in listaAdj[c]:
            listaAdj[c].remove(v)
    
    del listaAdj[v]
    print(listaAdj)
    
def tipoGrafo(listaAdj):
    laco = False
    multigrafo = False
    dirigido = False
    
    for vertice in listaAdj:
        conexoes = listaAdj[vertice]
        
        if vertice in conexoes: # tem laco
            laco = True
            
        if len(set(conexoes)) < len(conexoes): # Multigrafo
            multigrafo = True
    
        for conexao in conexoes: 
            if vertice not in listaAdj[conexao]: #dirigido ??
                dirigido = True
        
    if laco: # pseudografo
        return 31 if dirigido else 30 
    if multigrafo: # multigrafo
        return 21 if dirigido else 20
    return 1 if dirigido else 0 # grafo

def calcDensidade(listaAdj):
    laco = False
    dirigido = False
    vertices = 0
    arestas = 0
    for vertice in listaAdj:
        vertices += 1
        
        if vertice in listaAdj[vertice]: # tem laco
            laco = True
            
        for conexao in listaAdj[vertice]: 
            arestas += 1
            if vertice not in listaAdj[conexao]:
                dirigido = True
    
    if laco:
        densidade = arestas / (vertices ** 2)
    elif dirigido:
        densidade = arestas / (vertices * (vertices - 1))
    else:
        densidade =  arestas / (vertices * (vertices - 1))

    return print(round(densidade, 3))

if __name__ == '__main__':
    lista = {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}
    calcDensidade(lista)
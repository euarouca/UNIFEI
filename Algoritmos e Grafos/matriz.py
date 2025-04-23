import numpy as np

def verificaAdjacencia(matriz, vi, vj):
    return bool(matriz[vi][vj])
    
def insereAresta(matriz, vi, vj):
    transposta = np.transpose(matriz)
    simetria = np.array_equal(matriz, transposta)
    
    if simetria:
        matriz[vi][vj] += 1
        matriz[vj][vi] += 1
    else:
        matriz[vi][vj] += 1
    
    return matriz
    
def insereVertice(matriz):
    for linha in matriz:
        linha.append(0)
    
    nova_linha = [0] * len(matriz[0])
    matriz.append(nova_linha)
    
    return matriz

def removeAresta(matriz, vi, vj):
    transposta = np.transpose(matriz)
    simetria = np.array_equal(matriz, transposta)
    
    if simetria:
        matriz[vi][vj] -= 1
        matriz[vj][vi] -= 1
    else:
        matriz[vi][vj] -= 1
    
    return matriz

def removeVertice(matriz, v):
    for i in range(len(matriz)):
        matriz[i][v] = -1
        matriz[v][i] = -1
        
    return print(np.array(matriz))

def tipoGrafo(matriz):
    lacos = np.any(np.diagonal(matriz) != 0)  # Verifica se tem laço
    transposta = np.transpose(matriz)
    simetria = np.array_equal(matriz, transposta)  # Verifica se é simétrica
    maior_indice = np.max(matriz)  # Maior valor da matriz para ver se tem multigrafos

    if lacos:  # Pseudografo
        if simetria:
            return 30  # Pseudografo não dirigido
        else:
            return 31  # Pseudografo dirigido
        
    else:  # Não tem laços
        if simetria:  # Grafo simples ou multigrafo
            if maior_indice > 1:
                return 20  # Multigrafo
            else:
                return 0  # Grafo simples
        else:  # Grafo direcionado
            if maior_indice > 1:
                return 21  # Multigrafo dirigido
            else:
                return 1  # Dígrafo simples
            
            
def calcDensidade(matriz):
    vertices = len(matriz)
    arestas = np.sum(matriz)
    densidade = arestas / (vertices * (vertices - 1))
    
    return densidade
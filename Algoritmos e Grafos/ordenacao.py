from busca import *

lista = {
    0: [1, 4], 
    1: [2, 4], 
    2: [5], 
    3: [0, 4], 
    4: [5], 
    5: [1]
}

def temposVertices(listaAdj, v):
    cor = {}        # cor[vertice] = 'branco' | 'cinza' | 'preto'
    tempoD = {}     # tempo de descoberta de cada vértice
    tempoT = {}     # tempo de término de cada vértice

    for vertice in listaAdj:
        cor[vertice] = 'branco'
        tempoD[vertice] = 0
        tempoT[vertice] = 0

    # 'tempo' precisa ser mutável dentro da função aninhada visitaDFS.
    # Como inteiros em Python são imutáveis, uso uma lista de 1 elemento
    # para conseguir alterar o valor de dentro da recursão.
    tempo = [0]

    def visitaDFS(u):
        cor[u] = 'cinza'           
        tempo[0] = tempo[0] + 1
        tempoD[u] = tempo[0]       # marca tempo de descoberta

        # Visita cada adjacente de u
        for adjacente in listaAdj[u]:
            if cor[adjacente] == 'branco':
                visitaDFS(adjacente)   # <-- aqui é 'adjacente', não 'u'!

        cor[u] = 'preto'           # terminou de processar u
        tempo[0] = tempo[0] + 1
        tempoT[u] = tempo[0]       # marca tempo de término

    # ---- Começa pelo vértice v passado como parâmetro ----
    if cor[v] == 'branco':
        visitaDFS(v)

    # ---- Depois, percorre os demais vértices que ficaram brancos ----
    # (caso o grafo tenha componentes desconexos a partir de v)
    for vertice in listaAdj:
        if cor[vertice] == 'branco':
            visitaDFS(vertice)

    # ---- Monta o dicionário de saída no formato 'TD/TT' ----
    resultado = {}
    for vertice in listaAdj:
        resultado[vertice] = str(tempoD[vertice]) + '/' + str(tempoT[vertice])

    return resultado




# def temposVertices(graph, start): # Khan
#     tempo = 1
#     tempos = dict()
#     chaves = list(graph.keys())   
#     sequencia = [] 
#     pilha = [start]
#     estado = {}  # 0 = não visitado, 1 = descoberto, 2 = finalizado
    
#     for vertice in graph:
#         tempos[vertice] = 0
    
#     estado[start] = 1
#     tempos[start] = [tempo]
#     tempo += 1
    
#     while pilha:
#         atual = pilha.pop()
#         if atual not in sequencia:
#             sequencia.append(atual)
#             chaves.remove(atual)
            
#         for vizinho in reversed(graph[atual]):
#             if vizinho not in sequencia:
#                 pilha.append(vizinho)
        
#         if (len(pilha) == 0) and (len(chaves) != 0):
#             pilha.append(chaves[0])
    

def classificaArestas(listaAdj, v):
    pass
    

def verificaDAG(listaAdj):
    pass

def ordenacaoTopologica(listaAdj):
    pass

if __name__ == "__main__":
    temposVertices(lista, 0)
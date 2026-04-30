lista = {0: [1, 2, 6],
         1: [0, 3, 4],
         2: [0, 6, 7],
         3: [1, 4, 5],
         4: [1, 3, 5],
         5: [3, 4],
         6: [0, 2, 7],
         7: [2, 6],
         8: []}

def bfs(graph, vertice):
    chaves = list(graph.keys())
    gray = [vertice]
    black = list()
    
    while gray:
        atual = gray.pop(0)
        for vizinho in graph[atual]:
            if vizinho not in black and vizinho not in gray:
                gray.append(vizinho)
                
        black.append(atual)
        chaves.remove(atual)
        
        if (len(gray) == 0) and (len(chaves) != 0):
                gray.append(chaves[0])

    
    return black

# def dfs_aux (sequencia, chaves, graph, start) :
#     sequencia.append(start)
#     chaves.remove(start)
#     adjacentes = graph[start]
#     for adj in adjacentes:
#         if adj not in sequencia:
#             dfs_aux(sequencia, chaves, graph, adj)

# def dfs(graph, start) :
#     sequencia = []
#     chaves = list(graph.keys())
    
#     dfs_aux(sequencia, chaves, graph, start)
    
#     while chaves: # se existir desconexo
#         dfs_aux(sequencia, chaves, graph, chaves[0]) 
        
#     return sequencia


def dfs(graph, start):
    chaves = list(graph.keys())   
    sequencia = [] 
    pilha = [start]
    
    while pilha:
        atual = pilha.pop()
        if atual not in sequencia:
            sequencia.append(atual)
            chaves.remove(atual)
            
        for vizinho in reversed(graph[atual]):
            if vizinho not in sequencia:
                pilha.append(vizinho)
        
        if (len(pilha) == 0) and (len(chaves) != 0):
            pilha.append(chaves[0])
        

    return sequencia



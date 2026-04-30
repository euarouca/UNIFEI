import numpy as np
import heapq

def dijkstra(matriz, vi, vj):
    """
    Obtém o caminho mínimo entre um vértice origem (vi) e um vértice destino (vj)
    a partir da matriz de adjacências de um grafo ponderado através do algoritmo de Dijkstra.

    Entrada:
        matriz (numpy.ndarray): matriz de adjacências. -1 representa ausência de aresta.
        vi (int): vértice origem.
        vj (int): vértice destino.

    Saída:
        list: sequência de vértices correspondente ao caminho mínimo.
        int: custo do caminho.
        Retorna ([], -1) se não houver caminho.
    """
    n_vertices = len(matriz)
    if not (0 <= vi < n_vertices and 0 <= vj < n_vertices):
        return [], -1 # Comportamento para índice inválido

    # Inicializa distâncias: infinito para todos, 0 para o vértice de origem
    distancias = [float('inf')] * n_vertices
    distancias[vi] = 0

    # Guarda o predecessor de cada vértice no caminho mínimo
    predecessores = [-1] * n_vertices # -1 indica nenhum predecessor ainda

    # Fila de prioridade para armazenar (distância, vértice)
    # Usamos heapq para obter eficientemente o vértice com a menor distância
    fila_prioridade = [(0, vi)]  # (distância, vértice)

    while fila_prioridade:
        dist_atual, u = heapq.heappop(fila_prioridade)

        # Se já encontramos um caminho menor para u, ignoramos
        # Esta verificação é importante se um vértice for adicionado múltiplas vezes à fila
        # com diferentes prioridades (o que pode acontecer se não atualizarmos na fila, apenas adicionarmos)
        if dist_atual > distancias[u]:
            continue

        # Otimização: Se alcançamos o vértice destino, podemos parar
        # Dijkstra garante que quando selecionamos o destino da fila de prioridade,
        # seu caminho mínimo foi encontrado.
        if u == vj:
            break

        # Itera sobre os vizinhos de u (todos os outros vértices, verificando a conexão pela matriz)
        for v_vizinho in range(n_vertices):
            peso_aresta = matriz[u][v_vizinho]

            # Considera apenas arestas válidas (peso != -1)
            # No Dijkstra clássico, os pesos devem ser não-negativos.
            # Se peso_aresta for 0, é uma aresta de custo zero.
            if peso_aresta != -1:
                # Relaxamento da aresta
                if distancias[u] + peso_aresta < distancias[v_vizinho]:
                    distancias[v_vizinho] = distancias[u] + peso_aresta
                    predecessores[v_vizinho] = u
                    heapq.heappush(fila_prioridade, (distancias[v_vizinho], v_vizinho))

    # Se a distância até vj ainda é infinita, não há caminho
    if distancias[vj] == float('inf'):
        return [], -1

    # Reconstrói o caminho do destino para a origem
    caminho = []
    vertice_atual = vj
    # Enquanto o vértice atual for válido e não for o predecessor indefinido (-1)
    # para o caso de vi == vj, o loop não executará se predecessores[vj] for -1,
    # o que é correto, caminho = [vj]
    while vertice_atual != -1:
        caminho.insert(0, vertice_atual) # Insere no início para obter a ordem correta
        if vertice_atual == vi: # Chegamos na origem
            break
        vertice_atual = predecessores[vertice_atual]
        # Proteção contra loop infinito se algo der muito errado na lógica de predecessores
        # (não deveria acontecer em Dijkstra correto)
        if vertice_atual in caminho:
            # print("Erro: ciclo detectado na reconstrução do caminho")
            return [], -1 # Indica um problema

    # Se o caminho não começa com vi (ex: vj não alcançável, ou vi == vj e o loop de reconstrução não adicionou vi)
    # ou se o caminho está vazio e vi != vj
    if not caminho or caminho[0] != vi:
        if vi == vj and distancias[vj] == 0: # Caso especial: origem é igual ao destino
             return [vi], 0
        return [], -1 # Nenhum caminho encontrado que comece em vi e termine em vj

    return caminho, int(distancias[vj])


def bellmanFord(matriz, vOrigem, vDestino):
    """
    Obtém o caminho mínimo entre um vértice origem (vOrigem) e um vértice destino
    (vDestino) a partir da matriz de adjacências de um grafo ponderado através do
    algoritmo de Bellman-Ford.
    -1 na matriz de adjacências é tratado como ausência de aresta.

    Entrada:
        matriz (numpy.ndarray): matriz de adjacências.
        vOrigem (int): vértice de origem.
        vDestino (int): vértice de destino.

    Saída:
        False: caso o grafo possua ciclos de custo negativo alcançáveis a partir de vOrigem.
        Caso contrário: (list: sequência de vértices do caminho mínimo, int: custo do caminho).
                      Retorna ([], -1) se não houver caminho.
    """
    n_vertices = len(matriz)

    if not (0 <= vOrigem < n_vertices and 0 <= vDestino < n_vertices):
        # print("Alerta: Vértice de origem ou destino inválido.")
        return [], -1 # Ou levantar um erro, dependendo da especificação de erro desejada

    distancias = [float('inf')] * n_vertices
    predecessores = [-1] * n_vertices  # -1 significa nenhum predecessor

    distancias[vOrigem] = 0

    # Passo 2: Relaxar arestas repetidamente (n_vertices - 1) vezes
    for _ in range(n_vertices - 1):
        houve_atualizacao_nesta_iteracao = False
        for u in range(n_vertices):
            # Se u não é alcançável, não há como relaxar arestas saindo de u
            if distancias[u] == float('inf'):
                continue
            for v in range(n_vertices):
                peso_aresta = matriz[u][v]
                if peso_aresta != -1:  # Considera -1 como ausência de aresta direta
                    if distancias[u] + peso_aresta < distancias[v]:
                        distancias[v] = distancias[u] + peso_aresta
                        predecessores[v] = u
                        houve_atualizacao_nesta_iteracao = True
        # Otimização: se nenhuma distância foi atualizada em uma iteração completa,
        # não haverá mais atualizações nas iterações subsequentes.
        if not houve_atualizacao_nesta_iteracao:
            break


    # Passo 3: Verificar ciclos de custo negativo
    # Se após n_vertices-1 iterações, ainda podemos encontrar um caminho mais curto,
    # então existe um ciclo de custo negativo alcançável a partir de vOrigem.
    for u in range(n_vertices):
        if distancias[u] == float('inf'):
            continue
        for v in range(n_vertices):
            peso_aresta = matriz[u][v]
            if peso_aresta != -1: # Ausência de aresta direta
                if distancias[u] + peso_aresta < distancias[v]:
                    # Para ser mais preciso, só retornamos False se o ciclo negativo
                    # afeta o caminho para vDestino, ou qualquer caminho a partir de vOrigem.
                    # Uma forma simples é verificar se distancias[v] pode ser reduzido.
                    # Se qualquer distância pode ser reduzida, há um ciclo negativo
                    # alcançável pela origem.
                    return False  # Ciclo de custo negativo detectado

    # Passo 4: Reconstruir o caminho se vDestino for alcançável
    if distancias[vDestino] == float('inf'):
        return [], -1  # Caminho não existe

    caminho = []
    vertice_atual = vDestino
    # Prevenir loop infinito na reconstrução do caminho se algo der muito errado (defensivo)
    # Um ciclo negativo deveria ter sido pego antes.
    # Mas, se vDestino é parte de um ciclo de custo zero, este loop pode ser longo.
    # Limitamos pelo número de vértices.
    count_path_reconstruction = 0
    while vertice_atual != -1 and count_path_reconstruction <= n_vertices :
        caminho.insert(0, vertice_atual)
        if vertice_atual == vOrigem:
            break
        vertice_atual = predecessores[vertice_atual]
        count_path_reconstruction +=1

    if not caminho or caminho[0] != vOrigem:
        # Se vDestino era alcançável (dist != inf) mas o caminho não pode ser reconstruído até vOrigem,
        # isso pode indicar um problema ou um caso de vOrigem == vDestino não tratado pelo loop.
        if vOrigem == vDestino and distancias[vDestino] == 0: # Caminho de vOrigem para vOrigem com custo 0
             return [vOrigem], 0
        # Se o ciclo de reconstrução excedeu n_vertices, pode ser um problema com ciclo não negativo.
        # No entanto, o "False" de ciclo negativo já deveria ter tratado isso.
        # Se o vertice_atual se tornou -1 antes de chegar a vOrigem, e vOrigem != vDestino
        # E distancias[vDestino] != inf, isto seria estranho.
        # Por segurança, se o caminho não começa na origem, mas o destino era alcançável.
        # Isso geralmente não deve acontecer se a lógica estiver correta e não houver ciclos negativos não detectados.
        return [], -1 # Caminho não encontrado ou erro na reconstrução

    return caminho, int(round(distancias[vDestino])) # Arredondar para int, caso float persista por alguma razão

import numpy as np

def floydWarshall(matriz):
    n_vertices = len(matriz)
    
    dist = np.full((n_vertices, n_vertices), float('inf'))

    for i in range(n_vertices):
        for j in range(n_vertices):
            if i == j:
                dist[i][j] = 0
            elif matriz[i][j] != -1:  
                dist[i][j] = matriz[i][j]

    
    for k in range(n_vertices):  
        for i in range(n_vertices):  
            for j in range(n_vertices): 
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    novo_custo_via_k = dist[i][k] + dist[k][j]
                    if novo_custo_via_k < dist[i][j]:
                        dist[i][j] = novo_custo_via_k
                        

    return dist.astype(int)
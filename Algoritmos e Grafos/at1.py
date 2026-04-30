import numpy as np

def dimensaoMatriz(matriz):
    matriz = np.array(matriz)
    dimensao = matriz.shape
    diagonal = np.diagonal(matriz)
    print(dimensao, diagonal)
    
def valorCelula(matriz, i, j):
    matriz = np.array(matriz)
    dimensao = matriz.shape
    if i > dimensao[0] or j > dimensao[1]:
        print('Erro')
        return
    
    print(f'Celula[{i}][{j}] = {matriz[i][j]}')
    
def criaDicionario(matriz):
    lista = dict()
    
    for i, linha in enumerate(matriz):
        ind_colunas = list()
        for j in range(len(linha)):
            if matriz[i][j] > 0:
                ind_colunas.extend([j] * matriz[i][j])
    
        lista[i] = ind_colunas
    return print(lista)


def contaRegressivaFor(numero):
    for i in range(numero, 0, -1):
        print(i)
    
def contaRegressivaWhile(numero):
    while numero > 0:
        print(numero)
        numero -=1
    
def contaRegressivaRecursao(numero):
    if numero == 0:
        return
    
    print(numero)
    contaRegressivaRecursao(numero-1)
    
if __name__ == '__main__':
    lista = [[0, 1, 0, 0], 
             [1, 0, 1, 1], 
             [0, 1, 0, 1], 
             [0, 1, 1, 0]]
    
    # dimensaoMatriz(lista)
    # valorCelula(lista, 2, 3)
    # criaDicionario(lista)
    # contaRegressivaFor(10)
    # contaRegressivaWhile(10)
    contaRegressivaRecursao(10)
    
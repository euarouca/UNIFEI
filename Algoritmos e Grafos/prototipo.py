import os
import numpy as np
from matriz import*
from lista import*

def carrega_arquivo(nome_dataset):
    '''
    Descrição:
        Arquivos precisam estar na pasta "datasets".
        Está sendo levado em conta que a pasta "datasets" está no mesmo diretório do script a ser executado.
    
    Parâmetros:
        - nome_dataset(str): Nome do arquivo a ser buscado.
                
        Retornos:
        - matriz(numpy.ndarray): Uma matriz com os dados lidos.
    '''
    
    caminho_pasta = os.path.join(os.getcwd(), "datasets") + f'/{nome_dataset}.txt'
    with open(caminho_pasta, 'rb') as arquivo:
        matriz = np.loadtxt(arquivo, dtype='int')
    
    return matriz

def dimensao_matriz(matriz):
    '''
    Descrição:
       Quando receber uma matriz, retorna uma tupla com seu tamanho.
    
    Parâmetros:
        - matriz(numpy.ndarray): Matriz a ser medida.
                
        Retornos:
        - tupla: Tupla com tamanho de linhas e colunas.
    '''
    return matriz.shape

def salvar_resultado(nome_dataset, linhas, colunas):
    '''
    Descrição:
       Recebe os dados gerais do dataset e salva em um arquivo txt.
       Print os dados no prompt.
    
    Parâmetros:
        - nome_dataset(str): Nome do dataset.
        - linhas(int) : Quantidade de linhas.
        - colunas(int) : Quantidade de colunas.
                
        Retornos:
        - txt: Arquivo com infos do dataset.
    '''
    print(f'Dataset: {nome_dataset}.txt')
    print(f'Quantidade de linhas: {linhas}')
    print(f'Quantidade de colunas: {colunas}')
    with open('resultados.txt', 'a') as arquivo:
        arquivo.write(f'Dataset: {nome_dataset}.txt\n')
        arquivo.write(f'Quantidade de linhas: {linhas}\n')
        arquivo.write(f'Quantidade de colunas: {colunas}\n')   


if __name__ == '__main__':
    nome_arquivo = input('Nome do dataset: ')
    matriz = carrega_arquivo(nome_arquivo)
    # qtd_linhas, qtd_colunas = dimensao_matriz(matriz)    
    # salvar_resultado(nome_arquivo, qtd_linhas, qtd_colunas)
    print(criaListaAdjacencias(matriz))
//
// Created by Vanessa on 28/08/2024.
//

#ifndef MATRIZ_MATRIZ_H
#define MATRIZ_MATRIZ_H


//Função que aloca dinamicamente uma matriz de inteiros
//Recebe a quantidade de linhas e de colunas
//Retorna a matriz alocada ou NULL
int **alocaMatriz(int linhas, int colunas);

//Preenche uma matriz a partir da opção
//Opção 1: mat[i,j] = 3i + 4j
//Opção 2: mat[i,j] = – 4i – 3j
//Opção 3: preenche a matriz com zeros
//Recebe a matriz, quantidade de linhas, colunas e a opção
void preencheMatriz(int **mat, int linhas, int colunas, int opcao);

//Função que calcula a soma de duas matrizes e retorna a matriz resultante
//Recebe as duas matrizes, quantidade de linhas e colunas
//*A soma de duas matrizes só é possível se as mesmas tiverem as mesmas dimensões
int **somaMatriz(int **matA, int **matB, int lin, int col);

//Função que imprime uma matriz
//Cada linha deve ser impressa com os valores das colunas separados por tabulação (\t)
void imprimeMatriz(int **mat, int linhas, int colunas);

//Função que desaloca uma matriz.
void desalocaMatriz(int **M);

#endif //MATRIZ_MATRIZ_H

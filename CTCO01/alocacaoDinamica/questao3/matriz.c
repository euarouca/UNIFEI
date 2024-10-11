#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>

int **alocaMatriz(int linhas, int colunas){
    int **matriz;

    matriz = (int**) malloc(linhas * sizeof(int*));
    if (!matriz){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    for (int i=0; i<linhas; i++){
        matriz[i] = (int*) malloc (colunas * sizeof(int));
        if (!matriz[i]){
            printf("Erro ao alocar memoria\n");
            return NULL;
        }
    }

    return matriz;
}

void preencheMatriz(int **mat, int linhas, int colunas, int opcao){
    if (opcao == 1){
        for (int i=0; i<linhas; i++){
            for (int j=0; j<colunas; j++){
                mat[i][j] = (3*i) + (4*j);
            }
        }
    }

    if (opcao == 2){
        for (int i=0; i<linhas; i++){
            for (int j=0; j<colunas; j++){
                mat[i][j] = -(4*i) - (3*j);
            }
        }
    }

    if (opcao == 3){
        for (int i=0; i<linhas; i++){
            for (int j=0; j<colunas; j++){
                mat[i][j] = 0;
            }
        }
    }
    return;;
}

int **somaMatriz(int **matA, int **matB, int lin, int col){
    int **matC;

    matC = (int**) malloc(lin * sizeof(int*));
    if (!matC){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    for (int i=0; i<col; i++){
        matC[i] = (int*) malloc(col * sizeof(int));
        if(!matC[i]){
            printf("Erro ao alocar memoria\n");
            return NULL;
        }
    }

    for (int i=0; i<lin; i++){
        for (int j=0; j<col; j++){
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }

    return matC;
}

void imprimeMatriz(int **mat, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void desalocaMatriz(int **M){
    free(M);
}
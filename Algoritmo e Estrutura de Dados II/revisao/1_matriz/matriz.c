#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


int** alocaMatriz(int linhas, int colunas){
    int** mat = (int**) malloc(linhas * sizeof(int*));  
    if (!mat) return 0;

    for(int i=0; i<linhas; i++){
        mat[i] = (int*) malloc(colunas * sizeof(int));
        if (!mat[i]) return 0;
    }

    return mat;
}

int preencheMatriz(int** mat, int linhas, int colunas, FILE *arq){
    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            if (fscanf(arq, "%d", &mat[i][j]) != 1)
                return 0;
    return 1;
}

int verificaElementos(int** mat, int linhas, int colunas){
    int nElementos = 0;

    for (int i=0; i<linhas; i++)
        for (int j=0; j<colunas; j++)
            if (mat[i][j] >= 15 && mat[i][j] <= 20)
                nElementos++;

    return nElementos;
}

void desalocaMatriz(int** mat, int linhas){
    for (int i=0; i<linhas; i++)
        free(mat[i]);
    free(mat);
}
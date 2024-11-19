#include <stdio.h>
#include "matriz.h"

int main() {
    int linhas, colunas;
    int opcao1, opcao2;
    int **matA;
    int **matB;
    int **matSoma;

    scanf("%d", &linhas);
    scanf("%d", &colunas);
    scanf("%d", &opcao1);
    scanf("%d", &opcao2);

    //ALOCA E PREENCHE MATRIZ A
    matA = alocaMatriz(linhas, colunas);
    if (!matA)
        return 1;
    preencheMatriz(matA, linhas, colunas, opcao1);

    //ALOCA E PREENCHE MATRIZ B
    matB = alocaMatriz(linhas, colunas);
    if (!matB)
        return 1;
    preencheMatriz(matB, linhas, colunas, opcao2);

    //CALCULA A SOMA
    matSoma = somaMatriz(matA, matB, linhas, colunas);
    if (!matSoma)
        return 1;

    //LIBERA AS MATRIZES A E B
    desalocaMatriz(matA);
    desalocaMatriz(matB);

    //IMPRIME O RESULTADO
    imprimeMatriz(matSoma, linhas, colunas);

    //LIBERA A MATRIZ RESULTANTE
    desalocaMatriz(matSoma);
}

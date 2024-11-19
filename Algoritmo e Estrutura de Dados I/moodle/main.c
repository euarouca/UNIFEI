#include <stdio.h>
#include "produto.h"

int main() {
    int qtdProdutos;
    int desconto;
    char nomeArquivo[30];

    scanf("%s", nomeArquivo);
    scanf("%d", &qtdProdutos);
    scanf("%d", &desconto);

    //DECLARAR A MATRIZ
    int mat[qtdProdutos][col];

    //CHAMAR A FUNÇÃO QUE VAI CARREGAR A MATRIZ
    carregaMatriz(mat, qtdProdutos, nomeArquivo);

    //IMPRIMIR A MATRIZ
    printf("VALORES ATUAIS\n");
    imprimeMatriz(mat, qtdProdutos);

    //ATUALIZAR O PREÇO DOS PRODUTOS
    alteraValor(mat, qtdProdutos, desconto);

    //IMPRIMIR A MATRIZ
    printf("VALORES ATUALIZADOS\n");
    imprimeMatriz(mat, qtdProdutos);

    return 0;
}
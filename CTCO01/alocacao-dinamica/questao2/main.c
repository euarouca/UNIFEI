#include <stdio.h>
#include "produtos.h"

int main() {

    char nomeArquivo[30];
    int totalProdutos;
    int valorEstoque;
    int res;
    prod *vetProd;
    prod *maisCaro;


    scanf("%s", nomeArquivo);
    scanf("%d", &totalProdutos);
    scanf("%d", &valorEstoque);

    vetProd = alocaVet(totalProdutos);
    if (!vetProd)
    {
        printf("Erro ao alocar o vetor");
        return 1;
    }

    res = preencheVet(nomeArquivo, totalProdutos, vetProd);
    if (res == 2)
    {
        printf("Não foi possivel preencher o vetor.");
        return 1;
    }

    maisCaro = maiorValor(vetProd, totalProdutos);

    imprimeProduto(maisCaro);

    res = estoque(vetProd, totalProdutos, valorEstoque);

    printf("São %d produtos com estoque maior que %d", res, valorEstoque);

    desaloca(vetProd);

    return 0;
}

#include <stdio.h>
#include "estoque.h"
#include "produtos.h"

int main() {
    char nomeArquivo[30];
    FILE *arq;
    TLitaS *pereciveis, *naoPereciveis;
    TLitaD *estoque;
    TProd *produto;
    TProdEstoque *prodEstoque;
    int cod, totalEstoque, valor;
    char nomeProduto[20];
    char buffer[256];


    scanf("%s", nomeArquivo);
    arq = fopen(nomeArquivo, "r");
    if(!arq)
    {
        printf("Nao foi possivel abrir o arquivo");
        return 1;
    }

    pereciveis = criaLista();
    naoPereciveis = criaLista();
    if(!pereciveis || !naoPereciveis)
    {
        printf("Erro ao alocar lista simplesmente encadeada");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), arq) != NULL)
    {
        sscanf(buffer, "%d %s %d", &cod, nomeProduto, &totalEstoque);
        produto = criaProd(cod, nomeProduto, totalEstoque);
        if(!produto)
        {
            printf("Erro ao alocar produto");
            return 1;
        }
        processaEntrada(pereciveis, naoPereciveis, produto);
    }

     estoque = fusao(pereciveis, naoPereciveis);
     if(!estoque)
     {
         printf("Erro ao alocar lista duplamente encadeada");
         return 1;
     }
     //DESALOCA AS LISTAS SIMPLESMENTE ENCADEADAS
     desalocaLista(pereciveis);
     desalocaLista(naoPereciveis);

     //IMPRIME O TOTAL DE PRODUTOS NA LISTA
     printf("Total de produtos: %d\n", tamanhoLista(estoque));
     //IMPRIME A LISTA EM ORDEM CRESCENTE
     imprimeLista(estoque, 1);
     //IMPRIME A LISTA EM ORDEM DECRESCENTE
     imprimeLista(estoque, 2);
     //CONSULTAR UM PRODUTO NA LISTA
     scanf("%d", &valor);
     consutaProduto(estoque, valor);
     //LIMIAR DE BAIXO ESTOQUE
     scanf("%d", &valor);
     consultaEstoque(estoque, valor);
     //TRANSFORMA A LISTA EM UMA LISTA CIRCULAR
     circular(estoque);
     //PROCURA UM PRODUTO NA LISTA
     scanf("%d", &valor);
     prodEstoque = getProduto(estoque, valor);
     //IMPRIME OS N PRÓXIMOS NÓS DA LISTA
     if(prodEstoque)
     {
         scanf("%d", &valor);
         imprimeProximos(estoque, prodEstoque, valor);
     }

     //DESALOCA LISTA CIRCULAR E DUPLAMENTE ENCADEADA
     desalocaListaDE(estoque);
     return 0;
}

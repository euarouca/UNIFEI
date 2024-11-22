#include <stdio.h>
#include "TAD_ABP.h"
// teste
int main() {
    FILE *arq;
    noABP *novoNo;
    int valor;
    char nome[20];
    char nomeArquivo[20] = "entrada.txt";

    abp *arv = criaArvore();
    if (!arv)
    {
        printf("Erro ao alocar a nova árvore\n");
        return 1;
    }

    arq= fopen(nomeArquivo, "r");
    if (!arq)
    {
        printf("Erro ao abrir o arquivo \n");
        return 1;
    }
    while(!feof(arq))
    {
        fscanf(arq, "%d %s", &valor, nome);
        novoNo = criaNo(valor, nome);
        if (!novoNo)
        {
            printf("Erro ao alocar o novo nó \n");
            return 1;
        }
        insere(arv, novoNo);
    }
    percorreEmPreOrdem(retornaRaiz(arv));

    printf("Digite um valor para buscar na árvore (-1 para encerrar): ");
    scanf("%d", &valor);
    while(valor != -1)
    {
        printf("%s\n", buscaElemento(arv, valor));
        printf("\nDigite um valor para buscar na árvore (-1 para encerrar): ");
        scanf("%d", &valor);
    }

    percorreEmOrdem(retornaRaiz(arv));

    return 0;
}
#include <stdio.h>
#include <string.h>
#include "TAD_Lista.h"


int main() {
    FILE *arq;
    int codigo;
    float valor;
    char nomeArquivo[30];
    TNo *no;

    scanf("%s", nomeArquivo);

    arq = fopen(nomeArquivo, "r");
    if (!arq)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    TLista *lista =  criaLista();
    if (!lista)
    {
        printf("Não foi possivel alocar a lista\n");
        return 1;
    }

    while(!feof(arq))
    {
        fscanf(arq, "%d %f", &codigo, &valor);
        if(ferror(arq))
        {
            printf("Não foi possivel ler do arquivo\n");
            return 1;
        }
        no = criaNo(codigo, valor);
        insereInicioLista(lista,no);
    }

    imprimeLista(lista);
    float total = somaPedidos(getLInicio(lista));
    float media = calculaMedia(lista);
    printf("\nO total de pedidos na lista é de %0.2f. O valor médio dos pedidos é %0.2f\n", total, media);

    TLista *novaLista = criaLista();
    pedidos(novaLista, getLInicio(lista));
    printf("\n");
    esvaziaLista(lista);
    desalocaLista(lista);

    imprimeLista(novaLista);
    total = somaPedidos(getLInicio(novaLista));
    media = calculaMedia(novaLista);
    printf("\nO total de pedidos validos na lista é de %0.2f. O valor médio dos pedidos é %0.2f\n", total, media);

    esvaziaLista(novaLista);
    desalocaLista(novaLista);
    return 0;
}

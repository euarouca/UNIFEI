#include <stdio.h>
#include "TAD_Lista.h"

int main() {
    char nomeArq[30];
    int cod, idade;
    char nome[10];
    FILE *arq;
    TLista *l;
    TNo *pessoa;
    int opc; //opção de inserção
    int auxCod; //cod para consulta e remoção
    int res;//retorno das funções


    scanf("%s", nomeArq);
    arq = fopen(nomeArq, "r");
    if(!arq)
    {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    l = criaLista();
    if(!l)
    {
        printf("Erro ao alocar lista");
        return 1;
    }

    //opção de inserção
    //1, a inserção deve ser no início da lista
    //2, a inserção deve ser no final da lista
    //3, a inserção deve ser ordenada pelo cod
    //4, a inserçã deve ser ordenada pelo nome
    scanf("%d", &opc);

    while (!feof(arq))
    {
        fscanf(arq, "%9s %d %d", nome, &cod, &idade);

        pessoa = criaNo(cod, nome, idade);
        if(!pessoa)
        {
            printf("Erro ao alocar pessoa ");
            desalocaLista(l);
            return 1;
        }
        //imprimeNo(pessoa);
        if (opc == 1)
            insereInicio(l, pessoa);
        else
        {
            if(opc == 2)
                insereFim(l, pessoa);
            else
            {
                if(opc == 3)
                    insereOrdenado(l, pessoa, 1);
                else
                    insereOrdenado(l, pessoa, 2);
            }

        }
    }
    imprimeLista(l);

    //CONSULTA//
    //opção de consulta
    scanf("%d", &auxCod);
    scanf("%s", nome);
    res = consultaCod(l, auxCod);
    if (res == -1)
        printf("A pessoa de codigo %d não esta na lista\n", auxCod);
    else
        printf("A pessoa de codigo %d esta na posicao %d da lista\n", auxCod, res);
    res = consultaNome(l, nome);
    if (res == -1)
        printf("%s não esta na lista\n", nome);
    else
        printf("%s está na posição %d da lista\n", nome, res);

    //REMOÇÃO//
    scanf("%d", &auxCod);
    res = removePessoa(l, auxCod);
    if (res)
        printf("Pessoa removida com sucesso\n");
    else
        printf("Pessoa nao localizada na lista\n");
    imprimeLista(l);

    //Total pessoas//
    printf("\nA lista possui %d pessoas\n", qtdPessoas(l));
    esvaziaLista(l);
    printf("\nA lista possui %d pessoas\n", qtdPessoas(l));

    desalocaLista(l);

    return 0;
}

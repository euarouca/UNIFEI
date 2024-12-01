#include <stdio.h>
#include "TAD_Heap.h"


int main() {
    char nomeArquivo[30];
    int tamHeap;
    int totalRemocoes;

    scanf("%s", nomeArquivo);
    scanf("%d", &tamHeap);
    scanf("%d", &totalRemocoes);


    heap *h = alocaHeap(tamHeap);
    criaHeap(h, nomeArquivo);
    imprimeHeap(h);

    for(int i=1; i<=totalRemocoes; i++)
        removeElemento(h);

    printf("\n");
    imprimeHeap(h);
    return 0;
}

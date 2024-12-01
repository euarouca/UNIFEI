#include <stdio.h>
#include "TAD_Heap.h"

int main(){
    char nomeArquivo[30] = "entrada.txt";
    int tamHeap = 7;

    heap *h = alocaHeap(tamHeap);
    criaHeap(h, nomeArquivo);
    imprimeHeap(h);
    removeElemento(h);
    removeElemento(h);
    printf("\n");
    imprimeHeap(h);

    return 0;
}
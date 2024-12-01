//
// Created by Vanessa on 14/11/2024.
//

#ifndef LISTA_7_TAD_HEAP_H
#define LISTA_7_TAD_HEAP_H

typedef struct vetHeap heap;

//Aloca uma heap
//A heap tem três atributos
//Tamanho (tamanho máximo da heap)
//Tail (posição em que o elemento deve ser inserido na heap)
//Vet (vetor que será a heap)
heap *alocaHeap(int tam);


//Cria uma HEAP de máximo a partir de dados que são lidos do arquivo
void criaHeap(heap *h, char nomeArquivo[30]);

//Imprime o vetor heap
//printf("%d\t", X);
void imprimeHeap(heap *h);

//Remove da Heap o elemento de maior prioridade
void removeElemento(heap *h);

#endif //LISTA_7_TAD_HEAP_H

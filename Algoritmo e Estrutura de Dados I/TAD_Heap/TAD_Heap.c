#include <stdio.h>
#include <stdlib.h>
#include "TAD_Heap.h"


/* 
Lucas Arouca Baldoni Mello Palhares - 2024009210
Rafael Santos Pinto Batista Leite - 2024004564

a) O heap máximo é como se fosse uma fila dentro de uma árvore, ela é sempre preenchida da esquerda para a direita em
ordem de prioridades de chave. A chave que tiver maior prioridade vai para o topo da fila, idependente de quantas chaves com
menor prioridade existirem. A heap é representada na memória como um vetor, o elemento com maior prioridade está no inicio
do vetor, seus filhos respectivamente sao 2*indice e 2*indice+1 (esquerda e direita.

b) Na inserção o elemento deveria ser inserido na próxima posição livre (tail) do vetor, porém, antes de realizar a inserção de fato, 
é verificado se o pai atende à propriedade heap. Caso não atenda, o pai é copiado para a posição de inserção e a posição
antiga do pai é avaliada para inserir o novo elemento aplicando a mesma regra, sucessivamente, até encontrar a posição correta.
Na remoção é retirado o elemento de maior prioridade.  A remoção é feita colocando o último elemento no lugar do primeiro. Como a 
raiz não atende mais a propriedade de heap, o nó é comparado com os filhos para ser rebaixado até seu devido lugar.
*/


struct vetHeap
{
    int size;
    int tail;
    int *vet;
};

heap *alocaHeap(int tam){
    heap *h = (heap*)malloc(sizeof(heap));
    if (!h) return NULL; // não foi possível alocar a heap

    h->size = tam + 1;
    h->tail = 1;
    h->vet = (int*)malloc(tam * sizeof(int));
    if(!h->vet) return NULL; // não foi possível alocar o vetor
    return h;
}

void criaHeap(heap *h, char nomeArquivo[]){
    FILE *arq;

    arq = fopen(nomeArquivo, "r");
    if(!arq) return;
    int valor;
    while(fscanf(arq, "%d", &valor) != EOF && h->tail < h->size){
        h->vet[h->tail] = valor;

        if(h->tail > 1){
            int indAtual = h->tail; // ultimo adicionado
            int indPai = indAtual / 2; // pai do ultimo

            while (indPai >= 1 && h->vet[indPai] < h->vet[indAtual] ){ // nao for a raiz e o filho maior que o pai
            // inverte os valores
                int temp = h->vet[indAtual]; 
                h->vet[indAtual] = h->vet[indPai];
                h->vet[indPai] = temp;
                indAtual = indPai;
                indPai = indAtual / 2;
            }
        }
        h->tail++;
    }
    fclose(arq);
}

void imprimeHeap(heap *h){
    for(int i=1; i < h->tail; i++)
        printf("%d\t", h->vet[i]);
}

void removeElemento(heap *h){
    if (h->tail <= 1)
        return; 

    h->vet[1] = h->vet[h->tail - 1];
    h->tail--;

    int indAtual = 1;
    while(indAtual < h->tail){
        int maior = indAtual;
        int fEsq = indAtual * 2;
        int fDir = indAtual * 2 + 1;

        // filho esquerda
       if (fEsq < h->tail && h->vet[fEsq] > h->vet[maior])
            maior = fEsq;
        // filho direita
        if (fDir < h->tail && h->vet[fDir] > h->vet[maior])
            maior = fDir;

        if (maior != indAtual){
            int temp = h->vet[indAtual];
            h->vet[indAtual] = h->vet[maior];
            h->vet[maior] = temp;

            indAtual = maior;
        } 
        else 
            indAtual = h->tail; 
    }
}
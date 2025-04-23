#include <stdio.h>
#include <stdlib.h>
#include "TechLoja.h"


struct pedido{
    int id_pedido;
    float valor;
    char nome[50];
};

pedido *alocaVet(int tam){
    pedido *vet = (pedido*) malloc(tam *sizeof(pedido));
    if(!vet)
        return NULL;
    return vet;
}


void carregaPedidos(pedido *vet, int tam, char nomeArquivo[30]){
    FILE *arq = fopen(nomeArquivo, "r");
    if(!arq) 
        return;

    for (int i=0; i < tam; i++) 
        fscanf(arq, "%d;%f;%s\n", &vet[i].id_pedido, &vet[i].valor, vet[i].nome);
    
    fclose(arq);
}

void imprimePedidos(pedido *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d\t%0.2f\t%s\n", vet[i].id_pedido, vet[i].valor, vet[i].nome);
    }
}

void merge(pedido *vet, int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    pedido *L = alocaVet(n1);
    pedido *R = alocaVet(n2);

    for (i = 0; i < n1; i++)
        L[i] = vet[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (L[i].id_pedido <= R[j].id_pedido) {
            vet[k] = L[i];
            i++;
        } else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(pedido *vet, int inicio, int fim, int *contador) {
    (*contador)++;
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vet, inicio, meio, contador);
        mergeSort(vet, meio + 1, fim, contador);
        merge(vet, inicio, meio, fim);
    }
}

// void quickSort(int *vet, int inicio, int fim, int *contador) {
//     (*contador)++;
//     if (inicio < fim){
//         int pivo = particiona(vet, inicio, fim);
//         quickSort(vet, inicio, pivo-1, contador);
//         quickSort(vet, pivo, fim, contador);
//     }
// }

// int particiona(int *vet, int inicio, int fim) {
//     int pivo = (vet[inicio] + vet[fim] + vet[(inicio+fim)/2]) / 3;
//     int aux;
//     while(inicio < fim){
//         while(inicio < fim && vet[inicio] <= pivo)
//             inicio++;
//         while(inicio < fim && vet[inicio] >pivo)
//             fim--;
//         aux = vet[inicio];
//         vet[inicio] = vet[fim];
//         vet[fim] = aux;
//     }
//     return inicio;
// }

void quickSort(pedido *vet, int inicio, int fim, int *contador) {
    (*contador)++;
    if (inicio < fim) {
        int pivo = particiona(vet, inicio, fim);
        quickSort(vet, inicio, pivo-1, contador);
        quickSort(vet, pivo+1, fim, contador);
    }
}
int particiona(pedido *vet, int inicio, int fim) {
    float pivo = vet[inicio].valor;
    pedido aux;
    int pos = inicio;
    for (int i = inicio + 1; i <= fim; i++) {
        if (vet[i].valor > pivo) {
            pos++;
            if (i != pos) {
                aux = vet[i];
                vet[i] = vet[pos];
                vet[pos] = aux;
            }
        }
    }
    aux = vet[inicio];
    vet[inicio] = vet[pos];
    vet[pos] = aux;

    return pos;
}
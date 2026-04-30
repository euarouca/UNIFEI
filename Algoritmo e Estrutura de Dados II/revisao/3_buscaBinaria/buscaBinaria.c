#include <stdio.h>
#include <stdlib.h>
#include "buscaBinaria.h"

int* alocaVetor(int tam){
    int* vet = (int*)malloc(tam * sizeof(int));
    if(!vet) return 0;

    return vet;
}

void preencheVetor(int *vet, int tam, FILE *arq){
    for (int i=0; i<tam; i++)
        fscanf(arq, "%d", &vet[i]); 
}

void imprimeVetor(int *vet, int tam){
    for (int i=0; i<tam; i++)
        printf("%d\n", vet[i]);
}



int buscaBinaria(int *vet, int inicio, int fim, int valor){
    if (inicio > fim) return -1; // parada

    int meio = inicio + (fim - inicio) / 2; 

    if (vet[meio] == valor) return meio; // encontrou a posição

    if (vet[meio] > valor) // valor menor que o meio 
        return buscaBinaria(vet, inicio, meio-1, valor);
    
    // valor maior que o meio
    return buscaBinaria(vet, meio+1, fim, valor);
}
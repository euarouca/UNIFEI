#include <stdio.h>
#include <stdlib.h>
#include "vetRecursao.h"

float* alocaVetor(int tam){
    float* vet = (float*) malloc(tam * sizeof(float));
    if (!vet) return 0;

    return vet;
}

void preencheVetor(float *vet, int tam, FILE *arq){
    for (int i=0; i<tam; i++)
        fscanf(arq, "%f", &vet[i]);
}

void imprimeVetor(float *vet, int tam){
    for(int i=0; i<tam; i++)
        printf("%f\n", vet[i]);
}

void inverteVetor(float *vet, int ini, int fim){
    // Caso base: se o início for maior ou igual ao fim
    if (ini >= fim)
        return;
    
    // Troca os elementos das pontas
    float temp = vet[ini];
    vet[ini] = vet[fim];
    vet[fim] = temp;
    
    inverteVetor(vet, ini + 1, fim - 1);
}


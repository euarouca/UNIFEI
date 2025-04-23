#include <stdio.h>
#include <stdlib.h>
#include "ES.h"

void imprimeVetor(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
}


int *geraVetorAleatorio(int tam, int min, int max, int semente){
    int *vet = (int *) malloc(tam * sizeof(int));
    srand(semente);
    for(int i = 0; i < tam; i++){
        vet[i] = min + rand() % (max - min + 1);
    }
    return vet;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"


int geraAleatorios(char *nomeArquivo, int qtd, int semente) {
    FILE *file = fopen(nomeArquivo, "w");
    if (file == NULL) {
        return 1;
    }
    
    srand(semente);
    for (int i = 0; i < qtd; i++) {
        int num = rand() % 1001; 
        fprintf(file, "%d\n", num);
    }
    
    fclose(file);
    return 0;
}

int* leArquivo(char *nomeArquivo, int qtd) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        return NULL;
    }
    
    int *vet = (int*)malloc(qtd * sizeof(int));
    if (vet == NULL) {
        fclose(file);
        return NULL;
    }
    
    for (int i = 0; i < qtd; i++) {
        if (fscanf(file, "%d", &vet[i]) != 1) {
            free(vet);
            fclose(file);
            return NULL;
        }
    }
    
    fclose(file);
    return vet;
}

void selecao(int *vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }
        
        int temp = vet[min_idx];
        vet[min_idx] = vet[i];
        vet[i] = temp;
    }
}

void insercao(int *vet, int tam){
    for (int i = 1; i < tam; i++) {
        int key = vet[i];
        int j = i - 1;
        
        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = key;
    }
}

void buscaBinaria(int *vet, int inicio, int fim, int valor, int *res) {
    res[1]++; // Increment call count
    
    if (inicio > fim) {
        res[0] = 0;
        return;
    }
    
    int meio = (inicio + fim) / 2;
    
    if (vet[meio] == valor) {
        res[0] = 1;
        return;
    } else if (vet[meio] < valor) {
        buscaBinaria(vet, meio + 1, fim, valor, res);
    } else {
        buscaBinaria(vet, inicio, meio - 1, valor, res);
    }
}

void imprimeVet(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "trabalho.h"
#define RUN 32

void imprimeVet(int *vet, int tam){
    if (!vet || tam == 0)
        return;

        for(int i=0; i<tam; i++) {
            printf("%d ", vet[i]);
        }
        printf("\n");        
}

int *geraAleatorios(int tam, int semente){
    int *vet = (int*) malloc(tam * sizeof(int)); 
    if(!vet) return NULL;

    srand(semente);
    for(int i = 0; i < tam ; i++)
        vet[i] = rand();
    return vet;
}

int *geraQuaseOrdenados(int tam, int porcentagem){
    int *vet = (int*) malloc(tam * sizeof(int));
    if(!vet) return NULL;

    for(int i = 0; i < tam; i++)
        vet[i] = i + 1;

    int numDesordenados = (tam * porcentagem) / 100;    
    srand(time(NULL));

    for(int i = 0; i < numDesordenados; i++){
        int pos1 = rand() % tam;
        int pos2 = rand() % tam;

        int temp = vet[pos1];
        vet[pos1] = vet[pos2];
        vet[pos2] = temp;
    }

    return vet;
}

int *geraOrdenados(int tam, int ordem){
    int *vet = (int*) malloc(tam * sizeof(int));
    if(!vet) return NULL;

    if(!ordem)
        for(int i = 0; i < tam; i++)
            vet[i] = i + 1;
    else   
        for(int i = 0; i < tam; i++)
            vet[i] = tam - i;

    return vet;
}

void selectionSort(int *vetor, int tamanho, long long int *comparacoes, long long int *trocas) {
    for (int i = 0; i < tamanho - 1; i++){
        int indice_menor = i; 
        for (int j = i + 1; j < tamanho; j++){
            (*comparacoes)++;
            if (vetor[j] < vetor[indice_menor])
                indice_menor = j;
        }
        if (indice_menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indice_menor];
            vetor[indice_menor] = temp;
            (*trocas)++;
        }
    }
    imprimeVet(vetor, tamanho);
}

void inserctionSort(int *vetor, int tamanho, long long int *comparacoes, long long int *trocas) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        (*comparacoes)++;
        while(j >= 0 && vetor[j] > chave){
            (*comparacoes)++;
            vetor[j + 1] = vetor[j];
            (*trocas)++;
            j--;
        }
        vetor[j + 1] = chave;
        if (j + 1 != i) (*trocas)++;
    }
}

void merge(int *vetor, int inicio, int meio, int fim, long long int *comparacoes, long long int *trocas){
    int tamanho1 = meio - inicio + 1;
    int tamanho2 = fim - meio;

    int *v1 = malloc(tamanho1 * sizeof(int));
    int *v2 = malloc(tamanho2 * sizeof(int));

    for (int i = 0; i < tamanho1; i++)
        v1[i] = vetor[inicio + i];
    for (int j = 0; j < tamanho2; j++)
        v2[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < tamanho1 && j < tamanho2) {
        (*comparacoes)++;
        if (v1[i] <= v2[j]) {
            if (vetor[k] != v1[i]) (*trocas)++;
            vetor[k++] = v1[i++];
        } else {
            if (vetor[k] != v2[j]) (*trocas)++;
            vetor[k++] = v2[j++];
        }
    }
    
    while (i < tamanho1) {
        if (vetor[k] != v1[i]) (*trocas)++;
        vetor[k++] = v1[i++];
    }
    
    while (j < tamanho2) {
        if (vetor[k] != v2[j]) (*trocas)++;
        vetor[k++] = v2[j++];
    }

    free(v1);
    free(v2);
}

void mergeSort(int *vetor, int inicio, int fim, long long int *comparacoes, long long int *trocas){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio, comparacoes, trocas);
        mergeSort(vetor, meio + 1, fim, comparacoes, trocas);
        merge(vetor, inicio, meio, fim, comparacoes, trocas);
    }
}

int particiona(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas) {
    int pivo = (vet[inicio] + vet[fim] + vet[(inicio + fim)/2]) / 3;
    int aux;

    while(inicio < fim){
        while(inicio < fim && vet[inicio] <= pivo){
            (*comparacoes)++;
            inicio++;
        }
        while(inicio < fim && vet[fim] > pivo){
            (*comparacoes)++;
            fim--;
        }
        if(inicio < fim){
            aux = vet[inicio];
            vet[inicio] = vet[fim];
            vet[fim] = aux;
            (*trocas)++;
        }
    }
    return inicio;
}

void quickSort(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas){
    if (inicio < fim){
        int pivo = particiona(vet, inicio, fim, comparacoes, trocas);
        quickSort(vet, inicio, pivo - 1, comparacoes, trocas);
        quickSort(vet, pivo + 1, fim, comparacoes, trocas);
    }
}

void insertionSortTim(int arr[], int left, int right, long long int *comparacoes, long long int *trocas) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        (*comparacoes)++;
        while (j >= left && arr[j] > key) {
            (*comparacoes)++;
            arr[j + 1] = arr[j];
            (*trocas)++;
            j--;
        }
        if (arr[j + 1] != key) {
            arr[j + 1] = key;
            (*trocas)++;
        }
    }
}

void mergeTim(int arr[], int l, int m, int r, long long int *comparacoes, long long int *trocas) {
    (*comparacoes)++;
    if (arr[m] <= arr[m + 1]) return;

    int len1 = m - l + 1, len2 = r - m;
    int *L = malloc(len1 * sizeof(int));
    int *R = malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++) L[i] = arr[l + i];
    for (int i = 0; i < len2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        (*comparacoes)++;
        if (L[i] <= R[j]) {
            if (arr[k] != L[i]) {
                arr[k] = L[i];
                (*trocas)++;
            }
            i++;
        } else {
            if (arr[k] != R[j]) {
                arr[k] = R[j];
                (*trocas)++;
            }
            j++;
        }
        k++;
    }

    while (i < len1) {
        if (arr[k] != L[i]) {
            arr[k] = L[i];
            (*trocas)++;
        }
        i++;
        k++;
    }

    while (j < len2) {
        if (arr[k] != R[j]) {
            arr[k] = R[j];
            (*trocas)++;
        }
        j++;
        k++;
    }

    free(L);
    free(R);
}

void timSort(int arr[], int n, long long int *comparacoes, long long int *trocas) {
    for (int i = 0; i < n; i += RUN)
        insertionSortTim(arr, i, fmin((i + RUN - 1), (n - 1)), comparacoes, trocas);

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = fmin((left + 2 * size - 1), (n - 1));
            if (mid < right)
                mergeTim(arr, left, mid, right, comparacoes, trocas);
        }
    }
}


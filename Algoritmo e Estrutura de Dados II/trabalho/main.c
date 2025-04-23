#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trabalho.h"

int main() {
    int tamanhos[] = {5, 6, 7, 8, 9};
    int n_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    FILE *arquivo = fopen("resultados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo CSV.\n");
        return 1;
    }

    // Cabeçalho do CSV
    fprintf(arquivo, "Algoritmo,Tamanho,Comparacoes,Trocas,Tempo(ms)\n");

    for (int i = 0; i < n_tamanhos; i++) {
        int tamanho = tamanhos[i];
        printf("\n==============================\n");
        printf("TAMANHO DO VETOR: %d\n", tamanho);
        printf("==============================\n");

        int *vet;
        long long int comparacoes, trocas;
        clock_t inicio, fim;
        double tempo;

        // --- SELECTION SORT ---
        vet = geraOrdenados(tamanho, 0);
        comparacoes = trocas = 0;
        inicio = clock();
        selectionSort(vet, tamanho, &comparacoes, &trocas);
        fim = clock();
        tempo = ((double)(fim - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        printf("Selection Sort -> Comparações: %lld | Trocas: %lld | Tempo: %.2f ms\n", comparacoes, trocas, tempo);
         free(vet);

        // // --- INSERTION SORT ---
        // vet = geraAleatorios(tamanho, 30);
        // comparacoes = trocas = 0;
        // inicio = clock();
        // inserctionSort(vet, tamanho, &comparacoes, &trocas);
        // fim = clock();
        // tempo = ((double)(fim - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        // imprimeVet(vet, tamanho);
        // printf("Insertion Sort -> Comparações: %lld | Trocas: %lld | Tempo: %.2f ms\n", comparacoes, trocas, tempo);
        // free(vet);
    }

    fclose(arquivo);
    printf("\nResultados salvos no arquivo 'resultados.csv'\n");

    return 0;
}

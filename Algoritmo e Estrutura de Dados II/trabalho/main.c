/*
 * Universidade Federal de Itajubá – UNIFEI
 * Curso de Ciência da Computação
 * Disciplina: Algoritmos e Estruturas de Dados II
 * Trabalho: Benchmarking de Algoritmos de Ordenação
 *
 * Autores:
 *   • 2024009210 – Lucas Arouca Baldoni Mello Palhares
 *   • 2024009453 – Rafaela Cristina de Moraes Mendes
 *   • 2024004564 – Rafael Santos Pinto Batista Leite
 *   • 2024008886 – Rodolfo Henrique Faria
 *
 * Arquivo: main.c
 * Descrição: Programa principal que gera vetores, executa testes de ordenação e armazena resultados
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <unistd.h>
 #include "trabalho.h"
 
 int main() {
     int tamanhos[] = {1000,10000,100000,125000,130000};
     int n_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]); // quantidade de tamanhos
     const char* tipos_vetor[] = {"Ordenado", "Reverso", "Aleatorio", "QuaseOrdenado"};
 
     FILE* arquivo = fopen("resultados.csv", "w");
     if (arquivo == NULL) {
         printf("Erro ao criar o arquivo CSV.\n");
         return 1;
     }
     
     //Cabeçalho Arquivo.csv
     fprintf(arquivo, "Algoritmo,Tamanho,Tipo,Comparacoes,Trocas,Tempo(ms)\n");
 
     for (int i = 0; i < n_tamanhos; i++) {
         int tamanho = tamanhos[i];
         printf("\n==============================\n");
         printf("TAMANHO DO VETOR: %d\n", tamanho);
         printf("==============================\n");
 
         for (int tipo = 0; tipo < 4; tipo++) {
             printf("\n--- Tipo de vetor: %s ---\n", tipos_vetor[tipo]);
 
             int* vet;
             if (tipo == 0)
                 vet = geraOrdenado(tamanho, 0);
             else if (tipo == 1)
                 vet = geraOrdenado(tamanho, 1);
             else if (tipo == 2)
                 vet = geraAleatorios(tamanho, 42);
             else
                 vet = geraQuaseOrdenado(tamanho, 10);  
 
             int repetir = (tipo == 2 || tipo == 3) ? 5 : 1;
 
             testarAlgoritmo("Tim Sort", timSort, vet, tamanho, tipos_vetor[tipo], arquivo, repetir);
 
             free(vet);
         }
     }
 
     fclose(arquivo);
     printf("\nResultados salvos no arquivo 'resultados.csv'\n");
 
     return 0;
 }
#include <stdio.h>
#include <stdlib.h>
#include "bolha.h"

struct tReturn{
    int *vet;
    int tam;
    int erro;
};

tReturn* alocatReturn(){
    tReturn *t = (tReturn*)malloc(sizeof(tReturn));
    if (!t)
        return NULL;

    t->vet = NULL;
    t->tam = t->erro = 0;
    return t;
}

int *getVet(tReturn *rep){
    if (!rep || !rep->vet)
        return NULL;
    return rep->vet;
}

int getTam(tReturn *rep){
    return rep->tam;
}

int getErro(tReturn *rep){
    return rep->erro;
}

void trataErro(int erro){
    if (erro == 1) {
        printf("Erro ao abrir o arquivo\n");
    } else if (erro == 2) {
        printf("Erro ao ler do arquivo\n");
    } else if (erro == 3) {
        printf("Erro ao alocar memória\n");
    }
}

tReturn* leArquivo(char nomeArquivo[]) {
    tReturn* ret = alocatReturn();
    if (ret == NULL)
        return NULL;

    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        ret->erro = 1; // Erro ao abrir o arquivo
        return ret;
    }

    int qtdElementos;
    // Lê o tamanho do vetor na primeira linha
    if (fscanf(fp, "%d", &qtdElementos) != 1) {
        ret->erro = 2; // Erro ao ler do arquivo
        fclose(fp);
        return ret;
    }

    ret->vet = (int*)malloc(sizeof(int) * qtdElementos);
    if (ret->vet == NULL) {
        ret->erro = 3; // Erro ao alocar memória
        fclose(fp);
        return ret;
    }

    ret->tam = qtdElementos;

    // Lê os elementos do vetor
    for (int i = 0; i < qtdElementos; i++) {
        if (fscanf(fp, "%d", &ret->vet[i]) != 1) {
            ret->erro = 2; // Erro ao ler do arquivo
            break; // Interrompe  se encontrar um dado inválido
        }
    }

    fclose(fp); // Fecha o arquivo para evitar vazamento de recursos
    return ret;
}

int bolha(int *vet, int tam){
    if (!vet || tam == 0)
        return 0;
    int comp = 0, temp;
    for (int i = 0; i < tam; i++) {
        for (int j = 1; j < tam; j++){
            comp++;
            if (vet[j - 1] > vet[j]){
                temp = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = temp;
            }
        }
    }
    return comp;
}


int bolhaInteligente(int *vet, int tam){ // [3, 5, 1, 2, 4]
    if (!vet || tam == 0)
    return 0;

    int comp = 0, temp, swap = 1;
    for (int i = 0; i < tam && swap; i++) {
        swap = 0;
        for (int j = 1; j < tam - i; j++) {
            comp++;
            if (vet[j - 1] > vet[j]) {
                swap = 1;
                temp = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = temp;
            }
        }
    }
    return comp;
}

void imprimeVet(int *vet, int tam){
    if (!vet || tam == 0)
        return;

    for(int i=0; i<tam; i++) 
        printf("%d\n", vet[i]); 
    
}
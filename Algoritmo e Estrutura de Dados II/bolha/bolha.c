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

tReturn* leArquivo(char nomeArquivo[]){
    tReturn* ret = alocatReturn();
    if (!ret)
        return NULL;

    FILE *fp = fopen(nomeArquivo, "r");
    if (!fp) {
        ret->erro = 1;
        return ret;
    }

    int qtdElementos;
    fscanf(fp, "%d\n", &qtdElementos);

    ret->vet = (int*)malloc(sizeof(int) * qtdElementos);
    if (!ret->vet) {
        ret->erro = 3;
        return ret;
    }

    ret->tam = qtdElementos;

    for (int i = 0; i < qtdElementos; i++) {
        if(fscanf(fp, "%d", &ret->vet[i]) != 1) {
            ret->erro = 2;
        }
    }
    return ret;
}

void imprime(int *vet, int tam){
    for(int i=0; i<tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
}


int bolha(int *vet, int tam){
    if (!vet || tam == 0)
        return 0;
    int comp = 0, temp;
    for (int i = 0; i < tam; i++) {
        for (int j = 1; j < tam; j++){
            comp++;
            imprime(vet, tam);
            if (vet[j - 1] > vet[j]){
                temp = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = temp;
            }
        }
    }
    return comp;
}


int bolhaInteligente(int *vet, int tam){
    if (!vet || tam == 0)
    return 0;

    int comp = 0, temp, swap = 1;
    for (int i = 0; i < tam && swap; i++) {
        swap = 0;
        for (int j = 1; j < tam - i; j++) {
            imprime(vet, tam);
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

        for(int i=0; i<tam; i++) {
            printf("%d ", vet[i]);
        }
        printf("\n");        
}
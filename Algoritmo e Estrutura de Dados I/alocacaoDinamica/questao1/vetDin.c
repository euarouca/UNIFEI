#include <stdio.h>
#include <stdlib.h>
#include "vetDin.h"


int *alocaVetor(int tam){
    int *vet;

    vet = (int*) malloc (tam * sizeof(int));
    if (!vet){
        return NULL;
    }

    return vet;
}

int preencheVetor(char *nomeArquivo, int tam, int *vet){
    FILE *arq;

    arq = fopen(nomeArquivo, "r");
   if (!arq) {
        return -1; // Erro ao abrir o arq
    }

    for (int i = 0; i < tam; i++) {
        if (feof(arq)){
            fclose(arq);
            return -2; // Erro na leitura
        }
        else{
            fscanf(arq, "%d", &vet[i]);
        }  
    }

    fclose(arq);
    return 1; // Preenchimento bem-sucedido
}

int econtraValor(int *vet, int tam, int valor){
    for(int i=0; i<tam; i++){
        if(valor == vet[i]){
            return i;
        }
    }

    return -1;
}

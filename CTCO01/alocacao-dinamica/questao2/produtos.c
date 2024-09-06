#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

struct produtos{
    int codigo;
    int estoque;
    float preco;
};

prod *alocaVet(int qtd){
    prod *vetProd;

    vetProd = (prod*) malloc(qtd * sizeof(prod));

    if (!vetProd){ 
        return NULL;
    }

    return vetProd;
}

int preencheVet(char *nomeArquivo, int qtd, prod *vet){
    FILE *arq;
    arq = fopen(nomeArquivo, "r");
    if (!arq)
    {
        printf("Erro ao ler o arquivo");
        return 2;
    }

    for (int i=0; i<qtd; i++){
        if(fscanf(arq, "%d;%d;%f", &vet[i].codigo, &vet[i].estoque, &vet[i].preco) != 3){
            printf("Erro ao ler os dados do arquivo\n");
            fclose(arq); // Fecha o arquivo em caso de erro
            return 2;  
        }
    }

    fclose(arq);
    return 1;
}

prod *maiorValor(prod *vet, int qtd){
    float maisCaro = -1;
    prod *end;

    for (int i=0; i<qtd; i++){
        if (vet[i].preco > maisCaro){
            maisCaro = vet[i].preco;
            end = &vet[i];
        }
    }

    return end;
}


int estoque(prod *vet, int qtd, int valor){
    int produtos=0;

    for (int i=0; i<qtd; i++)
        if (vet[i].estoque > valor)
            produtos += 1;

    return produtos;
}


void imprimeProduto(prod *P){
    printf("%d\n", P->codigo);
    printf("%d\n", P->estoque);
    printf("%.2f\n", P->preco);
}

void desaloca(prod *P){
    free(P);
}
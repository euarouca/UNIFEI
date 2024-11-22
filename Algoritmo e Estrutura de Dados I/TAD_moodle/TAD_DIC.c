#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_DIC.h"

struct abp{
    pal *raiz;
};

struct no{
    char palavra[10];
    char significado[30];
    pal *sae;
    pal *sad;
};

dic *criaDic(){
    dic *novoDic = (dic*)malloc(sizeof(dic));
    if(!novoDic)
        return NULL;

    novoDic->raiz = NULL;
    return novoDic;
}

pal *criaNo(char palavra[], char significado[]){
    pal *novaPalavra = (pal*)malloc(sizeof(pal));
    if(!palavra)
        return NULL;
    
    strcpy(novaPalavra->palavra, palavra);
    strcpy(novaPalavra->significado, significado);
    novaPalavra->sae = NULL;
    novaPalavra->sad = NULL;
    return NULL;
}

void carregaDicionario(dic *dicionario, char nomeArquivo[20]) {
    FILE *arq;
    char significado[31];
    char palavra[11];

    arq = fopen(nomeArquivo, "r");

    while (!feof(arq)){
        fscanf(arq, " %s", palavra);
        fscanf(arq, " %[^\r\n]", significado);
        pal *novaPalavra = criaNo(palavra, significado);
        if(!novaPalavra)
            return;
        inserePalavra(dicionario, novaPalavra);
    }
    fclose(arq);
}    

void inserePalavra(dic *dicionario, pal* novaPalavra){
    
}
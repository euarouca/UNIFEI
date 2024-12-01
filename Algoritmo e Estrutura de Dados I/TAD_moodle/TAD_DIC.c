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
    return novaPalavra;
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
    // Dicionário vazio
    if (!dicionario->raiz){
        dicionario->raiz = novaPalavra;
        return;
    }

    pal *aux = dicionario->raiz;
    pal *pai = NULL;

    while(aux != NULL){
        pai = aux;
        if (strcmp(aux->palavra, novaPalavra->palavra) > 0)
            aux = aux->sae;
        else
            aux = aux->sad; 
    }
    // Palavra menor
    if (strcmp(pai->palavra, novaPalavra->palavra) > 0)
        pai->sae = novaPalavra;
    // Palavra maior
    else
        pai->sad = novaPalavra;
}

void buscaPalavra(dic *dicionario, char palavra[]){
    if(!dicionario||!dicionario->raiz) return;

    pal *aux=dicionario->raiz;
    while (aux){
        if (strcmp(aux->palavra,palavra) == 0){
            printf("\n%s : %s\n", aux->palavra, aux->significado);
            return;
        }
        if (strcmp(palavra,aux->palavra) < 0)
            aux=aux->sae;
        else
            aux=aux->sad;
    }
    printf("Palavra não encontrada - Sugestões:\n");
    sugerePalavras(dicionario->raiz, palavra);
}

void sugerePalavras(pal *no, char *prefixo){
    if (!no) return;

    if (strncmp(no->palavra, prefixo, 3) == 0)
    printf("%s\n", no->palavra);

    sugerePalavras(no->sae, prefixo);
    sugerePalavras(no->sad, prefixo);
}

void percorrePreOrdem(pal *palavra){
    if (palavra == NULL) return;

    printf("%s\n", palavra->palavra);
    percorrePreOrdem(palavra->sae);
    percorrePreOrdem(palavra->sad);
}

void percorreEmOrdem(pal *palavra){
    if (palavra == NULL) return;

    percorreEmOrdem(palavra->sae);
    printf("%s\n", palavra->palavra);
    percorreEmOrdem(palavra->sad);
}

pal *getRaiz(dic *dicionario){
    return dicionario->raiz;
}

//Remove uma palavra do dicionário
//Retorna 1 se removeu e -1 se a palavra não foi encontrada
int removePalavra(dic *dicionario, char palavra[]) {
    if (!dicionario || !dicionario->raiz)
        return -1;

    pal *ant = NULL, *t = dicionario->raiz;

    while (t && strcmp(t->palavra, palavra) != 0) {
        ant = t;
        if (strcmp(t->palavra, palavra) > 0)
            t = t->sae;
        else
            t = t->sad;
    }
    if (!t)
        return -1;

    if (t->sad && t->sae) {
        pal *predec = t->sae, *predec_ant = t;

        while (predec->sad) {
            predec_ant = predec;
            predec = predec->sad;
        }

        strcpy(t->palavra, predec->palavra);
        strcpy(t->significado, predec->significado);

        if (predec_ant->sae == predec)
            predec_ant->sae = predec->sae;
        else
            predec_ant->sad = predec->sae;

        free(predec);
        return 1;
    }

    pal *c = (t->sae) ? t->sae : t->sad;

    if (!ant) {
        dicionario->raiz = c;
    } else if (ant->sae == t) {
        ant->sae = c;
    } else {
        ant->sad = c;
    }

    free(t);
    return 1;
}
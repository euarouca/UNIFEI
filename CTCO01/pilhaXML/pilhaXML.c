#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaXML.h"
#define MAX_TAG 20

struct pilhaXML{
    int numTags;
    tag *topo;
};

struct no
{   
    char data[MAX_TAG];
    tag *prox;
};

pilhaXML *criaPilha(){
    pilhaXML *pilha = (pilhaXML*)malloc(sizeof(pilhaXML));
    if (!pilha) return NULL;

    pilha->numTags = 0;
    pilha->topo = NULL;
    return pilha;
}

int empilhaTag(pilhaXML *pilha, char *nomeTag){
    tag *novaTag = (tag*)malloc(sizeof(tag));
    if (!novaTag) return 0;

    strcpy(novaTag->data, nomeTag);
    novaTag->prox = NULL;

    if (pilha->topo == NULL){
        pilha->topo = novaTag;
        pilha->numTags++;
        return 1;
    }

    novaTag->prox = pilha->topo;
    pilha->topo = novaTag;
    pilha->numTags++;
    return 1;
}

tag *desempilha(pilhaXML *pilha){
    tag *tagAux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    pilha->numTags--;
    return tagAux;
}

int validaXML(char *nomeArquivo, pilhaXML *pilha){
    FILE *arq;
    arq = fopen(nomeArquivo, "r");
    if (!arq) return 0;

    char linha[100];
    while(fgets(linha, sizeof(linha), arq)){
        char *abertura = strchr(linha, '<');
        char *fechamento = strchr(linha, '>');

        if(abertura && fechamento){
            char conteudoTag[MAX_TAG];
            int tamanho = fechamento - abertura - 1;
            strncpy(conteudoTag, abertura+1, tamanho);
            conteudoTag[tamanho] = '\0';

            if(conteudoTag[0] != '/') empilhaTag(pilha, conteudoTag);

            else{
                tag *noTopo = desempilha(pilha);
                if(!noTopo || strcmp(noTopo->data, conteudoTag+1) != 0){
                    fclose(arq);
                    return 0;
                }
                free(noTopo);
            }
        }
    }

    fclose(arq);

    if(pilha->numTags != 0) return 0;

    return 1; // tudo valido 
}

void desalocaPilha(pilhaXML *pilha){
    while(pilha->topo){
        tag *noRemovido = desempilha(pilha);
        free(noRemovido);
    }
    free(pilha);
}

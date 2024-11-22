#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ABP.h"

struct arvore{ // árvore possui uma raiz apenas
    noABP *raiz;
};

struct no{
    // Sempre vai ter uma ou mais infos do nó e duas sub-árvores
    int valor;
    char nome[20];
    noABP *sae; // sub árvore da esquerda
    noABP *sad; // sub árvore da direita
};

abp *criaArvore(){
    abp *newTree = (abp*)malloc(sizeof(abp));
    if (!newTree) return NULL;
    newTree->raiz = NULL;
    return newTree;
}

noABP *retornaRaiz(abp *arvore){
    return arvore->raiz;
}

noABP *criaNo(int valor, char nome[]){
    noABP *novoNo = (noABP*)malloc(sizeof(noABP));
    if (!novoNo) return NULL;
    novoNo->valor = valor;
    strcpy(novoNo->nome, nome);
    novoNo->sae = NULL;
    novoNo->sad = NULL;
    return novoNo;
}

void insere(abp *arvore, noABP *novoNo){
    // árvore vazia
    if (arvore->raiz == NULL){
        arvore->raiz = novoNo;
        return;
    }

    noABP *aux = arvore->raiz;
    noABP *pai = NULL;

    while (aux != NULL){
        pai = aux;
        // se for menor ele corre pra esquerda
        if (novoNo->valor < aux->valor)
            aux = aux->sae; 
        // se for maior ele corre pra direita
        else
            aux = aux->sad;
    }
    // Se o novo valor for menor que o pai ele vai pra esquerda
    if (novoNo->valor < pai->valor)
        pai->sae = novoNo;
    // Se o novo valor for maior que o pai ele vai pra direita
    else
        pai->sad = novoNo;
}

char *buscaElemento(abp *arvore, int valor){
    noABP *aux = arvore->raiz;
    while (valor != aux->valor && aux != NULL){
        if (valor < aux->valor)
            aux = aux->sae;
        else    
            aux = aux->sad;
    }
    if (valor == aux->valor)
        return aux->nome;

    // não encontrou o valor
    return "NULL";
}

void percorreEmOrdem(noABP *novoNo){
    if (novoNo == NULL) return;

    percorreEmOrdem(novoNo->sae);
    printf("%d-%s\n", novoNo->valor, novoNo->nome);
    percorreEmOrdem(novoNo->sad);
}

void percorreEmPreOrdem(noABP *novoNo){
    if(novoNo == NULL) return;

    printf("%d-%s\n", novoNo->valor, novoNo->nome);
    percorreEmPreOrdem(novoNo->sae);
    percorreEmPreOrdem(novoNo->sad);
}

int removeElemento(abp *arvore, int valor){
    if (!arvore->raiz) return -1; // árvore vazia

    noABP *aux = arvore->raiz;
    noABP *pai = NULL;
    while (aux != NULL && aux->valor != valor){
        pai = aux;
        if (valor < aux->valor)
            aux = aux->sae;
        else    
            aux = aux->sad;
    }

    if (aux == NULL) return -1; // valor não existe

    // Nó de grau 2
    if (aux->sae != NULL && aux->sad != NULL){
        //Predecessor
        noABP *pred = aux->sae;
        pai = aux;
        while (pred->sad != NULL){
            pai = pred;
            pred = pred->sad;
        }
        //cópia dos dados
        aux->valor = pred->valor;
        strcpy(aux->nome, pred->nome);
        // faz o pred do pred apontar para esquerda do pred
        pai->sad = pred->sae;
        free(pred);
        return 1;
    }

    // Nó de grau 1
    if (aux->sae || aux->sad){
        noABP *filho;
        if(aux->sae) //Nó tem filho à esquerda
            filho = aux->sae;
        else //Nó tem filho à direita
            filho = aux->sad;
        if(pai){ //Se não for raiz
            if(pai->valor > aux->valor)
                pai->sae = filho;
            else
                pai->sad = filho;
        }
        else //É raiz
            arvore->raiz = filho;     
        free(aux);
        return 1;
    }
    else{ //Grau 0
        if(pai){ //Se não for raiz
            if(pai->valor > aux->valor) 
                pai->sae = NULL;
            else
                pai->sad = NULL;
        }
        else //É raiz
            arvore->raiz = NULL;
        free(aux);
        return 1;
    }
}
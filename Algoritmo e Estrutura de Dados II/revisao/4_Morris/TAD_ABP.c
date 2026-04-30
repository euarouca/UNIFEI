#include <stdio.h>
#include <stdlib.h>
#include "TAD_ABP.h"

struct arvore{
    noABP *raiz;
};

struct no{
    int valor;
    noABP *sae;
    noABP *sad;
    noABP *pai;
};

abp *criaArvore(){
    abp* novaArvore = (abp*)malloc(sizeof(abp));
    if (!novaArvore) return NULL;
    novaArvore->raiz = NULL;
    return novaArvore;
}

noABP *retornaRaiz(abp *arvore){
    return arvore->raiz;
}

noABP *criaNo(int valor){
    noABP* novoNo = (noABP*)malloc(sizeof(noABP));
    if (!novoNo) return NULL;
    novoNo->valor = valor;
    novoNo->sae = NULL;
    novoNo->sad = NULL;
    novoNo->pai = NULL;
    return novoNo;
}

void insere(abp *arvore, noABP *novoNo){
    // árvore vazia
    if (!arvore->raiz){
        arvore->raiz = novoNo;
        return;
    }

    noABP* aux = arvore->raiz;
    noABP* pai = NULL;

    while (aux){
        pai = aux;
        // se for menor ele corre pra esquerda
        if (novoNo->valor < aux->valor)
            aux = aux->sae;
        // se for maior ele corre pra direita
        else 
            aux = aux->sad;
    }

    novoNo->pai = pai;
    // Se o valor for menor que o pai ele vai pra esquerda
    if (novoNo->valor < pai->valor)
        pai->sae = novoNo;
     // Se o valor for menor que o pai ele vai pra direita
    else   
        pai->sad = novoNo;
}



void travessiaMorris(abp *arvore){
   if (arvore == NULL || arvore->raiz == NULL) return; // Árvore vazia
    
    noABP *atual = arvore->raiz;
    noABP *pred;
    
    while (atual != NULL){ 
        if (atual->sae == NULL){ // chegou no menor número 
            printf("%d\n", atual->valor);
            atual = atual->sad;
        }
        else {
            pred = atual->sae;
            // procura o predecessor do atual
            while (pred->sad != NULL && pred->sad != atual)
                pred = pred->sad;

            if (pred->sad == NULL){
                pred->sad = atual;
                atual = atual->sae;
            }

            else{
                pred->sad = NULL;
                printf("%d\n", atual->valor);
                atual = atual->sad;
            }
        }
    }
}


noABP *predecessor(noABP *no) {
    if (no == NULL) return NULL; 
    
    if (no->sae != NULL) {
        noABP *atual = no->sae;
        while (atual->sad != NULL)
            atual = atual->sad;
        return atual;
    }

    noABP *pai = no->pai;
    while (pai != NULL && no == pai->sad) {
        no = pai;
        pai = pai->pai;
    }

    return pai;
}

// Retorna a chave de um determinado nó
int getChave(noABP *no) {
        return no->valor;
}

// Retorna um determinado nó, passando sua chave
noABP *getNo(abp *arvore, int chave) {
    if (arvore == NULL) return NULL;

    noABP *atual = arvore->raiz;
    while (atual != NULL) {
        if (chave == atual->valor) 
            return atual;
        else if (chave < atual->valor) 
            atual = atual->sae;
        else 
            atual = atual->sad;
        
    }
    return NULL; // Não encontrou
}
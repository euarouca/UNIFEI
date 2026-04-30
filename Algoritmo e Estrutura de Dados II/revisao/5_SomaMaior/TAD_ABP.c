#include <stdio.h>
#include <stdlib.h>
#include "TAD_ABP.h"

struct arvore {
    int soma;
    noABP *raiz;
};

struct no {
    int valor;
    noABP *sae;
    noABP *sad;
    noABP *pai;
};

abp *criaArvore() {
    abp* novaArvore = (abp*)malloc(sizeof(abp));
    if (!novaArvore) return NULL;
    novaArvore->soma = 0;
    novaArvore->raiz = NULL;
    return novaArvore;
}

noABP *retornaRaiz(abp *arvore) {
    return arvore->raiz;
}

noABP *criaNo(int valor) {
    noABP* novoNo = (noABP*)malloc(sizeof(noABP));
    if (!novoNo) return NULL;
    novoNo->valor = valor;
    novoNo->sae = NULL;
    novoNo->sad = NULL;
    novoNo->pai = NULL;
    return novoNo;
}

void insere(abp *arvore, noABP *novoNo) {
    // árvore vazia
    if (!arvore->raiz) {
        arvore->raiz = novoNo;
        return;
    }

    noABP* aux = arvore->raiz;
    noABP* pai = NULL;

    while (aux) {
        pai = aux;
        // se for menor ele corre pra esquerda
        if (novoNo->valor < aux->valor)
            aux = aux->sae;
        // se for maior ou igual ele corre pra direita
        else 
            aux = aux->sad;
    }

    novoNo->pai = pai;
    arvore->soma += novoNo->valor;
    
    // Conecta o novo nó ao pai correspondente
    if (novoNo->valor < pai->valor)
        pai->sae = novoNo;
    else   
        pai->sad = novoNo;
}

void travessiaMorris(abp *arvore) {
   if (arvore == NULL || arvore->raiz == NULL) return; // Árvore vazia
    
    noABP *atual = arvore->raiz;
    noABP *pred;
    
    while (atual != NULL) { 
        if (atual->sae == NULL) { // chegou no menor número 
            printf("%d\n", atual->valor);
            atual = atual->sad;
        } else {
            pred = atual->sae;
            // procura o predecessor em ordem do atual
            while (pred->sad != NULL && pred->sad != atual)
                pred = pred->sad;

            if (pred->sad == NULL) {
                pred->sad = atual; // Cria a thread
                atual = atual->sae;
            } else {
                pred->sad = NULL; // Desfaz a thread
                printf("%d\n", atual->valor);
                atual = atual->sad;
            }
        }
    }
}

noABP *predecessor(noABP *no) {
    if (no == NULL) return NULL; 
    
    // Caso 1: Tem subárvore esquerda (pega o maior valor à esquerda)
    if (no->sae != NULL) {
        noABP *atual = no->sae;
        while (atual->sad != NULL)
            atual = atual->sad;
        return atual;
    }

    // Caso 2: Não tem subárvore esquerda (sobe até vir da direita)
    noABP *pai = no->pai;
    while (pai != NULL && no == pai->sae) {
        no = pai;
        pai = pai->pai;
    }

    return pai;
}

// Retorna o nó sucessor de um elemento na árvore
noABP *sucessor(noABP *no) {
    if (no == NULL) return NULL; 
    
    // Caso 1: Tem subárvore direita (pega o menor valor à direita)
    if (no->sad != NULL) {
        noABP *atual = no->sad;
        while (atual->sae != NULL)
            atual = atual->sae;
        return atual;
    }

    // Caso 2: Não tem subárvore direita (sobe até vir da esquerda)
    noABP *pai = no->pai;
    while (pai != NULL && no == pai->sad) {
        no = pai;
        pai = pai->pai;
    }

    return pai;
}

// Retorna a chave de um determinado nó
int getChave(noABP *no) {
    if (no != NULL) return no->valor;
    return -1;
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

// Árvore de soma maior
// cada nó contém a soma de todos os nós maiores que aquele nó. [cite: 98]
void somaMaior(abp *arvore) {
    if (arvore == NULL || arvore->raiz == NULL) return;

    noABP *atual = arvore->raiz;
    noABP *suc;
    int somaAcumulada = 0; // Guarda a soma dos maiores já visitados

    // Travessia de Morris Inversa (Direita -> Raiz -> Esquerda)
    while (atual != NULL) {
        if (atual->sad == NULL) {
            int valorOriginal = atual->valor;
            atual->valor = somaAcumulada;
            somaAcumulada += valorOriginal;
            
            atual = atual->sae;
        } else {
            // Procura o sucessor (mais à esquerda da subárvore direita)
            suc = atual->sad;
            while (suc->sae != NULL && suc->sae != atual) {
                suc = suc->sae;
            }

            if (suc->sae == NULL) {
                suc->sae = atual; // Cria a thread reversa
                atual = atual->sad;
            } else {
                suc->sae = NULL; // Desfaz a thread reversa
                
                // Processa a soma
                int valorOriginal = atual->valor;
                atual->valor = somaAcumulada;
                somaAcumulada += valorOriginal;
                
                atual = atual->sae;
            }
        }
    }
}
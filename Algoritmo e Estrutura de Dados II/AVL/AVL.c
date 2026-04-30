#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

struct no{
    int chave;
    int fb;
    noAVL *fEsq;
    noAVL *fDir;
    noAVL *pai;
};

struct AVL{
    noAVL *sentinela;
};

arvAVL *alocaArvore(){
    arvAVL *novaArvore = (arvAVL*)malloc(sizeof(arvAVL));
    if(!novaArvore) return NULL;

    noAVL *novoSentinela = (noAVL*)malloc(sizeof(noAVL));
    if(!novoSentinela) return NULL;

    novoSentinela->chave = -1000;
    novoSentinela->fDir = NULL;
    novoSentinela->fEsq = NULL;
    novoSentinela->pai = NULL;

    novaArvore->sentinela = novoSentinela;

    return novaArvore;
}

noAVL *alocaNo(int codigo){
    noAVL *novoNo = (noAVL*)malloc(sizeof(noAVL));
    if(!novoNo) return NULL;

    novoNo->chave = codigo;
    novoNo->fb = 0;
    novoNo->fDir = NULL;
    novoNo->fEsq = NULL;
    novoNo->pai = NULL;

    return novoNo;
}

int carregaArvore(char *nomeArquivo, arvAVL *arv);

void insereNo(arvAVL *arv, noAVL *novoNo){
    novoAVL *aux = arv->sentinela->fDir;
    novoAVL *pai = arv->sentinela;

    // buscando posicao de insercao na arvore
    while (aux != NULL){
        pai = aux;
        if(novoNo->chave < aux->chave)
            aux = aux->fEsq;
        else
            aux = aux->fDir;
    }

    if(novoNo->chave < pai->chave)
        pai->fEsq = novoNo;
    else
        pai->fDir = novoNo;
    
    novoNo->pai = pai;

    ajustaFB(arv, novoNo);
}


void ajustaFB(arvAVL *arv, noAVL *novoNo){
    noAVL *aux = novoNo->pai;

    if(aux == arv->sentinela)
        return;

    do
    {
        aux = aux->pai;
        if(novoNo->chave < aux->chave)
            aux->fb--;
        else
            aux->fb++;
    } while ((aux != arv->sentinela->fDir) && (aux->fb != 0) && (aux->fb != -2) && (aux->fb != 2));
    
    if (aux->fb == 2 || aux->fb == -2)
        balanceamento(arv, aux);

    return;
}

//Função que corrige o balamenceamento da árvore˚
void balanceamento(arvAVL *arv, noAVL *noDesbalanceado){
    noAVL *filho;
    
    if(noDesbalanceado->fb == 2){ // rotacao a esquerda
        filho = noDesbalanceado->fDir;
        if(filho->fb == 1){ // simples
            rotacaoEsquerda(arv, noDesbalanceado);
            noDesbalanceado->fb = 0;
            filho->fb = 0;
        }else{ // dupla
            rotacaoDireita(arv, filho);
            rotacaoEsquerda(arv, noDesbalanceado);
        }
    }
}

//Função que realiza a rotação à direita no noDesbalanceado
void rotacaoDireita(arvAVL *arv, noAVL *noDesbalanceado);

//Função que realiza a rotação à esquerda no noDesbalanceado
void rotacaoEsquerda(arvAVL *arv, noAVL *noDesbalanceado);

//Percorre a árvore em pré-ordem
//printf("%d (%d) \t", &no->codigo, &no->fb);
void percorrePreOrdem(noAVL *aux);

//Retorna raiz da árvore
noAVL *retornaRaiz(arvAVL *arv);
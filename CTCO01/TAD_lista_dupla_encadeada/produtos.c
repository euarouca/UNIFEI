#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

struct listaProd{
    TProd *head;
    int size;
};

struct prod{
    int cod;
    char nome[20];
    int estoque;
    TProd *next;
};

TLitaS *criaLista(){
    TLitaS *lista = (TLitaS*)malloc(sizeof(TLitaS));
    if(!lista)
        return NULL;
    lista->head = NULL;
    lista->size = 0;
    return lista;
}

TProd *inicioLista(TLitaS *l){
    return l->head;
}

TProd *criaProd(int cod, char nome[], int estoque){
    TProd *produto = (TProd*)malloc(sizeof(TProd));
    if(!produto)
        return NULL;
    produto->cod = cod;
    produto->estoque = estoque;
    strcpy(produto->nome, nome);
    produto->next = NULL;
    return produto;
}

int getCod(TProd *prod){
    return prod->cod;
}

char *getNome(TProd *prod){
    return prod->nome;
}

int getEstoque(TProd *prod){
    return prod->estoque;
}

TProd *getProx(TProd *prod){
    return prod->next;
}

void cadastraProduto(TLitaS *l, TProd *prod){
    prod->next = l->head;
    l->head = prod;
    l->size++;
}

void processaEntrada(TLitaS *l1, TLitaS *l2, TProd *prod){
    if(prod->cod % 2 == 0){
        prod->next = l1->head;
        l1->head = prod;
        l1->size++;
    }
    else{
        prod->next = l2->head;
        l2->head = prod;
        l2->size++;
    }
}

int removeProduto(TLitaS *l, int cod){
    TProd *aux = l->head;
    TProd *liberar = NULL;

    if(aux->cod == cod){
        l->head = aux->next;
        l->size--;
        free(aux);
        return 1;
    }

    while(aux->next != NULL && aux->next->cod != cod)
        aux = aux->next;
    
    if(aux->next->cod == cod){
        liberar = aux->next;
        aux->next = aux->next->next;
        l->size--;
        free(liberar);
        return 1;
    }

    return -1;
}

void desalocaLista(TLitaS *l){
    if(l->size != 0){
        TProd *prox = l->head;
        TProd *ant = NULL;
        while(prox->next != NULL){
            ant = prox;
            prox = prox->next;
            free(ant);
        }
        l->size = 0;
    }
    free(l);
}


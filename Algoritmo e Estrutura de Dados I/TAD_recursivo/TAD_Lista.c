#include <stdio.h>
#include <stdlib.h>
#include "TAD_Lista.h"

struct lista{
    TNo *inicio;
    int tam;
};

struct no{
    int cod;
    float preco;
    TNo *prox;
};

TLista *criaLista(){
    TLista *lista = (TLista*)malloc(sizeof(TLista));
    if(!lista) return NULL;

    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

TNo *criaNo(int cod, float valor){
    TNo *novoNo = (TNo*)malloc(sizeof(TNo));
    if(!novoNo) return NULL;

    novoNo->cod = cod;
    novoNo->preco = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void insereInicioLista(TLista *lista, TNo *elemento){
    elemento->prox = lista->inicio;
    lista->inicio = elemento;
    lista->tam++;
}

void insereFinalRec(TLista *lista, TNo *noAtual, TNo *pedido){
    if(lista->inicio == NULL){
        insereInicioLista(lista, pedido);
        return;
    }

    if(noAtual->prox == NULL){
        noAtual->prox = pedido;
        pedido->prox = NULL;
        lista->tam++;
    }
    else
        insereFinalRec(lista, noAtual->prox, pedido);
}

TNo *getLInicio(TLista *lista){
    return lista->inicio;
}

void imprimeLista(TLista *lista){
    TNo *aux = lista->inicio;
    while(aux!=NULL){
        printf("%d\t", aux->cod);
        aux = aux->prox;
    }
}

void esvaziaLista(TLista *lista){
    TNo *aux = lista->inicio;
    while(aux!=NULL){
        TNo *ex = aux;
        aux = aux->prox;
        free(ex);
    }
    lista->inicio = NULL;
    lista->tam = 0;
}

void desalocaLista(TLista *lista){
    if(lista->tam != 0)
        esvaziaLista(lista);
    
    free(lista);
}

float calculaMedia(TLista *lista){
    if(lista->tam == 0)
        return 0.0;
    
    int count = 0;
    float soma = 0.0;
    TNo *aux = lista->inicio;

    while(aux!=NULL){
        count++;
        soma += aux->preco;
        aux = aux->prox;
    }
    return soma/count;
}

float somaPedidos(TNo *inicio){
    if(inicio == NULL)
        return 0.0;

    return inicio->preco + somaPedidos(inicio->prox);
}

void pedidos(TLista *novaLista, TNo *inicio){
    if(inicio != NULL){
        if(inicio->cod > 0){
            TNo *novoPedido = criaNo(inicio->cod, inicio->preco);
            insereFinalRec(novaLista, novaLista->inicio, novoPedido);
        }
        pedidos(novaLista, inicio->prox);

    }
}
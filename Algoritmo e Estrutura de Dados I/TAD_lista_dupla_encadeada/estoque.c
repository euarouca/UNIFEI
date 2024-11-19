#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

struct listaEstoque{
    TProdEstoque *head;
    TProdEstoque *tail;
    int size;
};

struct prodEstoque{
    int cod;
    char nomeProduto[20];
    int estoque;
    TProdEstoque *next;
    TProdEstoque *last;
};

TLitaD *criaListaDE(){
    TLitaD *lista = (TLitaD*)malloc(sizeof(TLitaD));
    if(!lista) 
        return NULL;
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

void cadastraProdutoEst(TLitaD *l, TProdEstoque *prod){
    TProdEstoque *aux = l->head;
    if(l->head == NULL){ // lista vazia
        l->head = prod;
        l->tail = prod;
        prod->next = NULL;
        prod->last = NULL;
        l->size++;
        return;
    }
 
    if(prod->cod < l->head->cod){ // Inserir nas cabeça
        prod->next = aux;
        prod->last = NULL;
        aux->last = prod;
        l->head = prod;
        l->size++;
        return;
    }

    while(aux->next != NULL && aux->next->cod < prod->cod)
        aux = aux->next;

    if(aux->next == NULL){ // Inserer no final
        aux->next = prod;
        prod->next = NULL;
        prod->last = aux;
        l->tail = prod;
        l->size++;
        return;
    }

    // Inserer no meio 
    prod->next = aux->next;
    prod->last = aux;
    aux->next = prod;
    prod->next->last = prod;
    l->size++;
    return;
}

void consutaProduto(TLitaD *l, int cod){
    TProdEstoque *aux = l->head;
    int pos=0;

    while (aux->next != NULL && aux->cod != cod){
        aux = aux->next;
        pos++;
    }
    
    if(aux->cod == cod){ 
        printf("%d\t%d\t%s\t%d\n", pos+1, aux->cod, aux->nomeProduto, aux->estoque);
        return; 
    }

    printf("Produto nao existe\n");
    return;
}

TProdEstoque *getProduto(TLitaD *l, int cod){
    TProdEstoque *aux = l->head;

    while (aux->next != NULL && aux->cod != cod)
        aux = aux->next;
    
    if(aux->cod == cod) 
        return aux; 

    // Não existe
    return NULL;
}

void consultaEstoque(TLitaD *l, int limiar){
    TProdEstoque *aux = l->head;
    for(int i=0; i<l->size; i++){
        if(aux->estoque < limiar)
            printf("%d\t%d\t%s\t%d\n", i+1, aux->cod, aux->nomeProduto, aux->estoque);
        aux = aux->next;
    }
}

int tamanhoLista(TLitaD *l){
    return l->size;
}

void imprimeLista(TLitaD *l, int tipo){
    if(tipo==1){
        TProdEstoque *aux = l->head;
        for(int i=0; i<l->size; i++){
            printf("%d\t%s\t%d\n",aux->cod, aux->nomeProduto, aux->estoque);
            aux = aux->next;
        }
    }
    else{
        TProdEstoque *aux = l->tail;
        for(int i=l->size-1; i>=0; i--){
            printf("%d\t%s\t%d\n",aux->cod, aux->nomeProduto, aux->estoque);
            aux = aux->last;
        }
    }
}

TLitaD *fusao(TLitaS *pereciveis, TLitaS *naoPereciveis){
    TLitaD *lista = criaListaDE();

    TProd *aux;
    TProdEstoque *novoProd;

    aux = inicioLista(pereciveis);
    while(aux != NULL){
        novoProd = (TProdEstoque*)malloc(sizeof(TProdEstoque));
        if(!novoProd)
            return NULL;
        novoProd->cod = getCod(aux);
        novoProd->estoque = getEstoque(aux);
        strcpy(novoProd->nomeProduto, getNome(aux));
        cadastraProdutoEst(lista, novoProd);
        aux = getProx(aux);
    }
    
    aux = inicioLista(naoPereciveis);
    while(aux != NULL){
        novoProd = (TProdEstoque*)malloc(sizeof(TProdEstoque));
        if(!novoProd)
            return NULL;
        novoProd->cod = getCod(aux);
        novoProd->estoque = getEstoque(aux);
        strcpy(novoProd->nomeProduto, getNome(aux));
        cadastraProdutoEst(lista, novoProd);
        aux = getProx(aux);
    }

    return lista;
}

void circular(TLitaD *lista){
    lista->head->last = lista->tail;
    lista->tail->next = lista->head;
}

void imprimeProximos(TLitaD *lista, TProdEstoque *prod, int qtdNos){
    TProdEstoque *aux = lista->head;
    int pos=1;

    while(aux->cod != prod->cod){
        pos++;
        aux = aux->next;
    }

    for(int i = 0; i < qtdNos; i++){
        aux = aux->next;
        pos++;
        printf("%d\t%d\t%s\t%d\n", pos, aux->cod, aux->nomeProduto, aux->estoque);
        if(pos == lista->size) pos = 0;
    }
    
}

void desalocaListaDE(TLitaD *l){
    if(l->size != 0){
        TProdEstoque *atual = l->head;
        TProdEstoque *ant = NULL;

        for(int i=0; i<l->size; i++){
            ant = atual;
            atual = atual->next;
            free(ant);
        }
        l->size= 0;
    }
    free(l);
}
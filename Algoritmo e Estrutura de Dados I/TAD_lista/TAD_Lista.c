#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Lista.h"

struct lista{
    int size;
    TNo *head;
    TNo *tail;
};

struct no{
    int codigo;
    char nome[10];
    int idade;
    TNo *next;
};

TLista *criaLista(){
    TLista *lista = (TLista*)malloc(sizeof(TLista));
    if(!lista)
        return NULL;
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

TNo *criaNo(int cod, char nome[], int idade){
    TNo *pessoa = (TNo*)malloc(sizeof(TNo));
    if(!pessoa)
        return NULL;
    
    pessoa->codigo = cod;
    pessoa->idade = idade;
    strcpy(pessoa->nome, nome);
    return pessoa;
}

void insereInicio(TLista *lista, TNo *pessoa){
    if(lista->size == 0){
        lista->head = pessoa;
        lista->tail = pessoa;
        lista->size++;
        return;
    }
    pessoa->next = lista->head;
    lista->head = pessoa;
    lista->size++;
}

void insereFim(TLista *lista, TNo *pessoa){
    if(lista->size == 0){
        lista->head = pessoa;
        lista->tail = pessoa;
        lista->size++;
        return;
    }
    lista->tail->next = pessoa;
    lista->tail = pessoa;
    lista->size++;
}

void insereOrdenado(TLista *lista, TNo *pessoa, int tipo){
    TNo *aux = lista->head;
    TNo *anterior = NULL;
    
    if(tipo == 1){ // Inserir pelo código
        if (lista->size == 0){ // lista vazia
            lista->head = pessoa;
            lista->tail = pessoa;
            lista->size++;
            return;
        }

        if(pessoa->codigo < aux->codigo){ // valor menor que o primeiro
            pessoa->next = aux;
            lista->head = pessoa;
            lista->size++;
            return;
        }

        while(aux->next != NULL && pessoa->codigo > aux->next->codigo)
            aux = aux->next;
        
        if(aux->next == NULL){ // Inserir final da lista
            aux->next = pessoa;
            lista->size++;
            lista->tail = pessoa;
            return;
        }

        //Insere no meio da lista
        pessoa->next = aux->next;
        aux->next = pessoa;
        lista->size++;
        return;

    }
    else{ // Tipo por nome
        if (lista->size == 0){ // lista vazia
            lista->head = pessoa;
            lista->tail = pessoa;
            lista->size++;
            return;
        }

        if(strcmp(pessoa->nome, aux->nome) < 0){ // Nome menor que o primeiro
            pessoa->next = aux;
            lista->head = pessoa;
            lista->size++;
            return;
        }
        while(aux->next != NULL && strcmp(pessoa->nome, aux->next->nome) > 0)
            aux = aux->next;
        
        if(aux->next == NULL){ // Inserir final da lista
            aux->next = pessoa;
            lista->size++;
            lista->tail = pessoa;
            return;
        }

        // Insere no meio da lista
        pessoa->next = aux->next;
        aux->next = pessoa;
        lista->size++;
        return;
    }
}

int consultaCod(TLista *lista, int cod){
    TNo *atual = lista->head;

    for(int i=0; i<lista->size; i++){
        if(atual->codigo == cod)
            return i+1;
        atual = atual->next;
    }

    return -1; // elemento não encontrado
}

int consultaNome(TLista *lista, char *nome){
    TNo *atual = lista->head;

    for(int i=0; i<lista->size; i++){
        if(strcmp(atual->nome, nome) == 0)
            return i+1;
        atual = atual->next;
    }
    return -1; // elemento não encontrado
}

int removePessoa(TLista *lista, int cod){
    TNo *anterior = NULL;
    TNo *atual = lista->head;

    if(atual->codigo == cod){ // tira nas cabeça
        lista->head = atual->next;
        lista->size--;
        free(atual);
        return 1;
    }

    while(atual->next != NULL && atual->codigo != cod){
        anterior = atual;
        atual = atual->next;
    }

    if(atual->codigo == cod){
        anterior->next = atual->next;
        lista->size--;
        if (atual->next == NULL) // verifica se é o final da lista
            lista->tail = anterior;
        free(atual);
        return 1;
    }

    return 0;
}

int qtdPessoas(TLista *lista){
    return lista->size;
}

void imprimeLista(TLista *lista){
    TNo *atual = lista->head;

    for(int i=0; i<lista->size; i++){
        printf("%d\t%s\t%d\n", atual->codigo, atual->nome, atual->idade);
        atual = atual->next;
    }
}

void esvaziaLista(TLista *lista){
    TNo *atual = lista->head;
    TNo *anterior = NULL;
    
    for(int i=0; i<lista->size; i++){
        anterior =  atual;
        atual = atual->next;
        free(anterior);
    }
    lista->size = 0;
}

void desalocaLista(TLista *lista){
    if(lista->size != 0){
        TNo *atual = lista->head;
        TNo *anterior = NULL;
    
        for(int i=0; i<lista->size; i++){
            anterior =  atual;
            atual = atual->next;
            free(anterior);
        }
        lista->size=0;
    }
    free(lista);
}

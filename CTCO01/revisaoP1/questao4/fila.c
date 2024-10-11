#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no{
    char name[50];
    int friends;
    Cliente *next;
};

struct fila{
    int size;
    Cliente *start;
    Cliente *end;
};

Fila *criaFila(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if(!fila) 
        return NULL;
    fila->size = 0;
    fila->start = NULL;
    fila->end = NULL;
    return fila;
}

int *adicionarCliente(Fila *fila, char nome[], int numPessoas){
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    if(!cliente)
        return NULL;
    
    strcpy(cliente->name, nome);
    cliente->friends = numPessoas;
    
    if(fila->size == 0){
        fila->start = cliente;
        fila->end = cliente;
        cliente->next = NULL;
    }
    else{
        fila->end->next = cliente;
        fila->end = cliente;
    }

    fila->size++;
    return 1;
}

int atendeCliente(Fila *fila){
    if(fila->start == NULL)
        return 0;
    Cliente *clienteAux = fila->start;
    fila->start = fila->start->next;
    fila->size--;
    free(clienteAux);
    return 1;
}

int tamanhoFila(Fila *fila){
    return fila->size;
}

char *clienteTopo(Fila *fila){
    if(fila->start == NULL)
        return NULL;
    
    return fila->start->name;
}

int totalClienteTopo(Fila *fila){
    if(fila->start == NULL)
        return 0;
    
    return fila->start->friends+1;
}

void desalocaFila(Fila *fila){
    Cliente *aux = fila->start;
    while(fila->start != NULL){
        fila->start = fila->start->next;
        free(aux);
    }
    free(fila);
}

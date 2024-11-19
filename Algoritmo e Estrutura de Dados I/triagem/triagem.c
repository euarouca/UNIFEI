#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "triagem.h"
#define TAM_NOME 20

struct no{
    char nome[TAM_NOME];
    int prioridade;
    TPaciente *next;
};

struct pilha{
    int size;
    TPaciente *top;
};

struct fila
{
    TPaciente *start;
    TPaciente *end;
    int size;
};


TFila *criaFila(){
    TFila *fila = (TFila*)malloc(sizeof(TFila));
    if(!fila) 
        return NULL;
    fila->start = NULL;
    fila->end = NULL;
    fila->size = 0;
    return fila;
}

TPilha *criaPilha(){
    TPilha *pilha = (TPilha*)malloc(sizeof(TPilha));
    if(!pilha) 
        return NULL;
    pilha->size = 0;
    pilha->top = NULL;
    return pilha;
}

void push(TPilha *pilha, TPaciente *paciente){
    if (!paciente)
        return;
    paciente->next = pilha->top;
    pilha->top = paciente;
    pilha->size++;
}

int pop(TPilha *pilha){
    if (!pilha->top)
        return 0;
    TPaciente *aux = pilha->top;
    pilha->top = pilha->top->next;
    pilha->size--;
    free(aux);
    return 1;
}

TPaciente *criaPaciente(char *nome, int prioridade){
    TPaciente *paciente = (TPaciente*)malloc(sizeof(TPaciente));
    if(!paciente)
        return NULL;
    strcpy(paciente->nome, nome);
    paciente->next = NULL;
    paciente->prioridade = prioridade;
    return paciente;
}

void adicionarPaciente(TPaciente *novoPaciente, TFila *fila){
    if(!fila->end){
        fila->start = novoPaciente;
        fila->end = novoPaciente;
        fila->size++;
        return;
    }
    fila->end->next = novoPaciente;
    fila->end = novoPaciente;
    fila->size++;
}

int atenderPaciente(TFila *fila, TPilha *pilha){
    if(!fila->start)
        return 0;
    TPaciente *paciente = fila->start;
    fila->start=paciente->next;
    fila->size--;
    push(pilha, paciente);
    if(fila->size==0)
        fila->end = NULL;
    return 1;
}

void GerenciaAtendimento(TFila *U_Alta, TFila *U_Media, TFila *U_Baixa, TPilha *pilha){
    if(U_Alta->size>0)
        atenderPaciente(U_Alta, pilha);
    else if(U_Media->size>0)
        atenderPaciente(U_Media, pilha);
    else
        atenderPaciente(U_Baixa,pilha);
    return;
}

void mostraUltimoAtendimento(TPilha* pilha){
    if(!pilha->top)
        return;
    printf("ULTIMO ATENDIMENTO\n");
    printf("Paciente : %s\n",pilha->top->nome);
    printf("Prioridade de Atendimento: %d\n",pilha->top->prioridade);
}

int tamanhoFila(TFila *fila){
    return fila->size;
}

int totalAtendimentos(TPilha *pilha){
    return pilha->size;
}

void reiniciaPilha(TPilha *pilha){
    while(pilha->top)
        pop(pilha);
}

int processaCarga(char *nomeArquivo, TFila *U_Alta, TFila *U_Media, TFila *U_Baixa){
    FILE *file = fopen(nomeArquivo, "r");
    if(!file)
        return 0;
    char name[TAM_NOME];
    int prioridade;
    while(fscanf(file,"%s %d",name,&prioridade)!=EOF)
    {
        TPaciente *novoPaciente = criaPaciente(name,prioridade);
        if(!novoPaciente)
            return 0;
        if(prioridade==1)
            adicionarPaciente(novoPaciente,U_Alta);
        else if(prioridade==2)
            adicionarPaciente(novoPaciente,U_Media);
        else
            adicionarPaciente(novoPaciente,U_Baixa);
    }
    fclose(file);
    return 1;
}

void desalocaPilha(TPilha *pilha){
    reiniciaPilha(pilha);
    free(pilha);
}


void desalocaFila(TFila *fila){
    while(fila->start)
    {
        TPaciente *aux = fila->start;
        fila->start=aux->next;
        free(aux);
    }
    free(fila);
}
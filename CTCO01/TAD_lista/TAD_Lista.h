//
// Created by Vanessa on 30/09/2024.
//

#ifndef LISTA_3_TAD_LISTA_H
#define LISTA_3_TAD_LISTA_H

typedef struct lista TLista;
typedef struct no TNo;

//Cria uma nova lista
TLista *criaLista();

//Cria um novo nó
TNo *criaNo(int cod, char nome[], int idade);

//Insere no início da lista
void insereInicio(TLista *lista, TNo *pessoa);

//Insere no final da lista
void insereFim(TLista *lista, TNo *pessoa);

//Insere ordenado dependendo do tipo
//Se tipo 1, a ordenação deve ser pelo cod
//Se tipo 2, a ordenação deve ser pelo nome
void insereOrdenado(TLista *lista, TNo *pessoa, int tipo);

//Consulta uma pessoa da lista pelo cod
//Retorna a posição uma pessoa na lista ou -1 se ela não existir
int consultaCod(TLista *lista, int cod);

//Consulta uma pessoa da lista pelo nome
//Retorna a posição uma pessoa na lista ou -1 se ela não existir
int consultaNome(TLista *lista, char *nome);

//Remove uma pessoa da lista pelo cod
//Retorna 1 se a pessoa foi removida
//Retorna 0 caso contrário
int removePessoa(TLista *lista, int cod);

//Retorna o total de pessoas da lista
int qtdPessoas(TLista *lista);

//Imprime os elementos da lista
void imprimeLista(TLista *lista);

//Esvazia a lista
void esvaziaLista(TLista *lista);

//Desaloca lista
//Caso haja pessoas na lista, as mesmas devem ser excluídas primeiro
void desalocaLista(TLista *lista);


#endif //LISTA_3_TAD_LISTA_H

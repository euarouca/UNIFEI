//
// Created by Vanessa on 01/10/2024.
//

#ifndef TAD_LISTA_H
#define TAD_LISTA_H

typedef struct lista TLista;
typedef struct no TNo;

//Cria uma nova lista
TLista *criaLista();

//Cria um novo nó
TNo *criaNo(int cod, float valor);

//Insere no início da lista
void insereInicioLista(TLista *lista, TNo *elemento);

//Função recursiva que insere o pedido no final da lista ao qual o no pertence
void insereFinalRec(TLista *lista, TNo *noAtual, TNo *pedido);

//Retorna o nó inicial da lista
TNo *getLInicio(TLista *lista);

//Imprime os códigos dos pedidos da lista
//printf("%d\t", aux->cod);
void imprimeLista(TLista *lista);

//Esvazia a lista
void esvaziaLista(TLista *lista);

//Desaloca lista
//Caso haja elementos na lista, as mesmas devem ser excluídas primeiro
void desalocaLista(TLista *lista);

//Média dos elementos
//Função que calcula a média dos elementos de uma lista simplesmente encadeada
float calculaMedia(TLista *lista);

float somaPedidos(TNo *inicio);

//Função recursiva que lê dados de uma lista e insere em uma nova lista os nós cujos códigos são positivos.
//A inserção acontece no final da lista e usa a função insereFinalRec.
void pedidos(TLista *novaLista, TNo *inicio);

#endif //TAD_LISTA_H

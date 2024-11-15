//
// Created by Vanessa on 02/10/2024.
//

#ifndef PRODUTOS_ESTOQUE_H
#define PRODUTOS_ESTOQUE_H

#include "produtos.h"

//LISTA DUPLAMENTE ENCADEADA
typedef struct listaEstoque TLitaD;
typedef struct prodEstoque TProdEstoque;

//Cria uma lista simplesmente encadeada não ordenada
TLitaD *criaListaDE();

//Insere um produto na lista duplamente encadeada ordenada pelo código do produto
void cadastraProdutoEst(TLitaD *l, TProdEstoque *prod);

//Consulta um produto no estoque
//Imprime sua posição na lista, o código, o nome, quantidade no estoque
//printf("%d\t%d\t%s\t%d\n",...)
// Caso ele não exista na lista: printf("Produto nao existe\n")
void consutaProduto(TLitaD *l, int cod);

//Retorna um produto do estoque
// Caso ele não exista na lista, retorna NULL
TProdEstoque *getProduto(TLitaD *l, int cod);

//Consulta produtos que estejam com estoque baixo
//Imprime sua posição na lista, o código, o nome, quantidade no estoque
//printf("%d\t%d\t%s\t%d\n",...)
//Função recebe o valor limiar. Ou seja, abaixo desse valor, é considerado baixo estoque
void consultaEstoque(TLitaD *l, int limiar);

//Retorna o tamanho da lista duplamente encadeada
int tamanhoLista(TLitaD *l);

//Imprime a lista pelo código do produto
//Se tipo 1: ordem crescente
//Se tipo 2: ordem decrescente
//printf("%d\t%s\t%d\n"...)
void imprimeLista(TLitaD *l, int tipo);

//Fusão das lista
//Recebe duas listas simplesmente encadeadas e cria a lista duplamente encadeada ordenada
//As listas simplesmente encadeadas não estão ordenadas
//DICA: Remova da simplesmente encadeada para inserir na duplamente encadeada
TLitaD *fusao(TLitaS *pereciveis, TLitaS *naoPereciveis);

//Transformar a lista em uma lista circular
//A mesma será utilizada APENAS para pecorrimento
void circular(TLitaD *lista);

//Imprime os valores dos n nós depois do nó recebido em uma lista circular
void imprimeProximos(TLitaD *lista, TProdEstoque *prod, int qtdNos);

//Desaloca lista duplamente encadeada e circular
//Caso haja produtos na lista, desalocar também
void desalocaListaDE(TLitaD *l);


#endif //PRODUTOS_ESTOQUE_H

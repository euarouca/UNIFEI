//
// Created by Vanessa on 02/10/2024.
//

#ifndef PRODUTOS_PRODUTOS_H
#define PRODUTOS_PRODUTOS_H

//LISTA SIMPLESMENTE ENCADEADA
typedef struct listaProd TLitaS;
typedef struct prod TProd;

//Cria uma lista simplesmente encadeada não ordenada
TLitaS *criaLista();

//Retorna o início da lista
TProd *inicioLista(TLitaS *l);

//Cria um novo produto
//Produto é composto por um código e um nome e a quantidade em estoque
TProd *criaProd(int cod, char nome[], int estoque);

//Retorna o código do produto
int getCod(TProd *prod);

//Retorna o nome do produto
char* getNome(TProd *prod);

//Retorna o estoque do produto
int getEstoque(TProd *prod);

//Retorna o prox do prod
TProd * getProx(TProd *prod);

//Insere um produto no início da lista
void cadastraProduto(TLitaS *l, TProd *prod);

//Direciona o produto para a lista correta
//cod par = produto perecível
//cod ímpar = produto não perecível
void processaEntrada(TLitaS *l1, TLitaS *l2, TProd *prod);

//Remove um produto da lista
//Retorna 1 se removeu ou -1 se não removeu
int removeProduto(TLitaS *l, int cod);

//Desaloca lista
//Caso haja produtos na lista, desalocar também
void desalocaLista(TLitaS *l);

#endif //PRODUTOS_PRODUTOS_H

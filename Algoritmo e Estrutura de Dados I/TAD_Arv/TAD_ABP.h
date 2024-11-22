//
// Created by Vanessa on 08/11/2024.
//

#ifndef INC_6_ARVORE_TAD_ABP_H
#define INC_6_ARVORE_TAD_ABP_H

typedef struct arvore abp;

typedef struct no noABP;

//Cria uma nova árvore com raiz nula
abp *criaArvore();

//Retorna a raiz da árvore
noABP *retornaRaiz(abp *arvore);

//Cria um novo nó
noABP *criaNo(int valor, char nome[20]);

//Insere um novo nó na árvore
void insere(abp *arvore, noABP *novoNo);

//Busca um elemento na árvore - retorna a primeira vez que encontrá-lo na árvore
//Retorna o nome caso encontre a chave
//Retorna a string "NULL" se não existir
char* buscaElemento(abp *arvore, int valor);

//Imprime a árvore em ordem
//printf("%d-%s\n, no->chave, no->nome)
void percorreEmOrdem(noABP *novoNo);

//Imprime a árvore em pré ordem
//printf("%d-%s\n, no->chave, no->nome)
void percorreEmPreOrdem(noABP *novoNo);

//remove um elemento da árvore
//retorna 1 se encontrou
//retorna -1 se não encontrou
int removeElemento(abp *arvore, int valor);


#endif //INC_6_ARVORE_TAD_ABP_H

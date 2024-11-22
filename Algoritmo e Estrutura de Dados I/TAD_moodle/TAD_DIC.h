//
// Created by Vanessa on 13/11/2024.
//

#ifndef ARVORE_DIC_TAD_DIC_H
#define ARVORE_DIC_TAD_DIC_H

typedef struct abp dic;
typedef struct no pal;

dic *criaDic();

pal *criaNo(char palavra[10], char significado[30]);

//lê uma lista de palavras de um arquivo e a insere no dicionário
void carregaDicionario(dic *dicionario, char nomeArquivo[20]);

//Insere uma palavra no dicionário
void inserePalavra(dic *dicionario, pal *novaPalavra);

//Busca a palavra no dicionário e imprime na tela o significado
//Se não encontrar a palavra, chama a função que busca por palavras com o
//mesmo prefixo (4 caracteres) para sugerir outras palavras
void buscaPalavra(dic *dicionario, char palavra[11]);

//busca por palavras que tem o mesmo prefixo da palavra solicitada
//Retorna um vetor com essas palavras
void sugerePalavras(pal *no, char *prefixo);

//Mostra palavras do dicionário em pré-ordem
void percorrePreOrdem(pal *palavra);

//Mostra palavras do dicionário em ordem alfabética
void percorreEmOrdem(pal *palavra);

//Retorna a raiz da árvore
pal *getRaiz(dic *dicionario);

//Remove uma palavra do dicionário
//Retorna 1 se removeu e -1 se a palavra não foi encontrada
int removePalavra(dic *dicionario, char palavra[11]);

#endif //ARVORE_DIC_TAD_DIC_H

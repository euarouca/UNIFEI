//
// Created by Vanessa on 09/09/2024.
//

#ifndef PROJETO1_PILHAXML_H
#define PROJETO1_PILHAXML_H

typedef struct pilhaXML pilhaXML;
typedef struct no tag;//o no guarda a tag de, no máximo, 20 caracteres

//Cria a TAD Pilha que armazena também a quantidade de tags armazenadas
pilhaXML *criaPilha();

//Empilha uma tag
//Retorna 1 se foi possível empilhar
//Retorna 0 caso não tenha sido possível alocar novo nó tag
int empilhaTag(pilhaXML *pilha, char *nomeTag);

//Desempilha uma tag e retorna o nó tag desempilhado
tag *desempilha(pilhaXML *pilha);

//Valida o documento XML
//Recebe o nome do arquivo e a pilha
//Essa função deve ler linha a linha do arquivo.
//Caso a linha seja uma tag de abertura, empilha
//Caso seja uma tag de fechamento, desempilha e compara se o nome da tag lida é igual a do topo da pilha
//Se as tags forem iguais, continua
//Se forem diferentes, retorna 0
//Caso chegue ao final do arquivo sem erros, retorna 1
int validaXML(char *nomeArquivo, pilhaXML *pilha);

//Esvazia e Desaloca a pilha
void desalocaPilha(pilhaXML *pilha);

#endif //PROJETO1_PILHAXML_H

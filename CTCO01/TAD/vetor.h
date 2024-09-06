#ifndef MODULO_VETOR_H
#define MODULO_VETOR_H

// Define o tipo de dado que é a estrutura
typedef struct vetor vet;

// Função cria - Aloca e retorna vetor de tamanho tam
vet *cria(int tam);

//Função libera - Libera a memória do vetor
void libera(int *vetTad);

// Função acessa - Retorna o valor do elemento [i]
int acessa(vet *vetTad, int i);

// Função atribui - Atribui valor ao elemento [i]
void atribui(vet vetTad);

// Função tamanho - Retorna a quantidade de elementos do vetor

// Função redimensionar – Redimensiona o tamanho do vetor

// Função preencheAleatoriamente – Preenche o vetor aleatoriamente

// Função imprime – Imprime o vetor com tamanho tam/
#endif
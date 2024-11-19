//
// Created by Vanessa on 27/08/2024.
//

#ifndef VETDINAMICO_VETDIN_H
#define VETDINAMICO_VETDIN_H

//Função que aloca um vetor dinamicamente
//Recebe o tamanho do vetor e retorna um ponteiro para esse vetor
//Retorna NULL caso o vetor não possa ser alocado
int *alocaVetor(int tam);

//Função que preenche um vetor a partir de um arquivo
//Recebe o nome do arquivo, o tamanho e o vetor
//Retorna 1 se o preenchimento ocorreu com sucesso
//Retorna -1 caso não seja possível abrir o arquivo
//Retorna -2 caso haja erro na leitura do arquivo
int preencheVetor(char *nomeArquivo, int tam, int *vet);

//Função que verifica se um determinado valor existe no vetor
//Recebe o vetor, o tamanho e o valor a ser encontrado
//Retorna -1 caso o elemento não exista
//Retorna a posição do valor no vetor, caso o elemento exista
//Retorne a primeira posição encontrada
int econtraValor(int *vet, int tam, int valor);

#endif //VETDINAMICO_VETDIN_H

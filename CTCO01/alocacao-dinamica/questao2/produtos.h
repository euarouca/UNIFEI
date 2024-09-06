//
// Created by Vanessa on 27/08/2024.
//

#ifndef PRODUTOS_PRODUTOS_H
#define PRODUTOS_PRODUTOS_H

typedef struct produtos prod;

//Função que aloca um vetor de produtos dinamicamente
//Recebe a quantidade de produtos
//Retorna o vetor alocado ou NULL caso não consiga alocar
prod *alocaVet(int qtd);

//Função que preenche o vetor de pessoas
//Recebe o nome do arquivo onde, cada linha tem o registro de um produto com os campos separados por vírgula
//Recebe a quantidade de produtos
//Recebe o vetor alocado
//Retorna 1 se conseguir preencher o vetor
//Retorna 2 caso não consiga
int preencheVet(char *nomeArquivo, int qtd, prod *vet);

//Função que retorna o produto mais caro
//Recebe o vetor preenchido e a quantidade de produtos
//Retorna o produto mais caro
prod *maiorValor(prod *vet, int qtd);

//Função que retorna a quantidade de produtos com mais de n itens no estoque
//Recebe o vetor preenchido e a quantidade de produtos
//Recebe o valor para verificar o estoque
//Retorna quantos produtos têm mais que a quantidade informada no estoque
int estoque(prod *vet, int qtd, int valor);

//Função que imprime os dados de um produto
//A impressão deve ser cada campo em uma linha
//O preço deve ter 2 casas decimais
void imprimeProduto(prod *P);

void desaloca(prod *P);

#endif //PRODUTOS_PRODUTOS_H

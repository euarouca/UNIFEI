#ifndef FILARESTAURANTE_H
#define FILARESTAURANTE_H

typedef struct fila Fila;
typedef struct no Cliente;

// Cria uma fila
// Retorna NULL se der errado
// Retorna a fila 
Fila *criaFila();

// Cria um cliente para fila
// Retorna 1 se ele foi inserido
// Retorna 0 se caso o contrário
int *adicionarCliente(Fila *fila, char nome[], int numPessoas);

// Atende o cliente
// Retorna 1 se ele foi atendido com sucesso
// Retorna 0 se caso contrário
int atendeCliente(Fila *fila);

// Retorna o tamanho da fila
int tamanhoFila(Fila *fila);

// Retorna o cliente que está no inicio
// Se a fila estiver vazia retorna NULL
char *clienteTopo(Fila *fila);

// Retorna o total de clientes da fila
// Se estiver vazia retorna 0
int totalClienteTopo(Fila *fila);

// Deslaoca fila
void desalocaFila(Fila *fila);

#endif
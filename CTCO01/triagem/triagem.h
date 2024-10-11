//
// Created by Vanessa on 16/09/2024.
//

#ifndef QUESTAO_2_TRIAGEM_TRIAGEM_H
#define QUESTAO_2_TRIAGEM_TRIAGEM_H

typedef struct pilha TPilha; //armazena a quantidade de atendimentos
typedef struct fila TFila; //armazena o tamanho da fila
typedef struct no TPaciente; //armazena o nome e prioridade do paciente

//Cria e retorna uma fila
TFila *criaFila();

//Cria e retorna a pilha de histórico de atendimento
TPilha *criaPilha();

//Insere um paciente da pilha
void push(TPilha *pilha, TPaciente *paciente);

//Remove um paciente da pilha
int pop(TPilha *pilha);

//Aloca um novo nó TPaciente, inicializa e o retorna
TPaciente *criaPaciente(char *nome, int prioridade);

//Insere um paciente na sua fila de prioridade adequada
void adicionarPaciente(TPaciente *novoPaciente, TFila *fila);

//Remove o paciente da fila e o insere na pilha
int atenderPaciente(TFila *fila, TPilha *pilha);

//Verifica qual fila será atendida seguindo as regras estabelecidas
//Chama a função de atender paciente
void GerenciaAtendimento(TFila *U_Alta, TFila *U_Media, TFila *U_Baixa, TPilha *pilha);

//Exibe na tela os dados do último paciente atendido
//printf("ULTIMO ATENDIMENTO\n");
//printf("Paciente : %s\n", ?);
//printf("Prioridade de Atendimento: %d\n", ?);
void mostraUltimoAtendimento(TPilha* pilha);

//Retorna o tamanho da fila
int tamanhoFila(TFila *fila);

//Retorna o total de atendimentos até o momento
int totalAtendimentos(TPilha *pilha);

//Esvazia a pilha de atendimento
//Chama a função pop
void reiniciaPilha(TPilha *pilha);

//Abre o arquivo
//Para cada linha do arquivo, chama a função criaPaciente
//Verifica a priopridade do paciente e chama a função adicionarPaciente
//Retorna 1 se o paciente foi inserido na sua fila de prioridade
//Retorna 0 caso contrário
int processaCarga(char *nomeArquivo, TFila *U_Alta, TFila *U_Media, TFila *U_Baixa);

//Esvazia e desaloca pilha
void desalocaPilha(TPilha *pilha);

//Esvazia e desaloca fila
void desalocaFila(TFila *fila);



#endif //QUESTAO_2_TRIAGEM_TRIAGEM_H

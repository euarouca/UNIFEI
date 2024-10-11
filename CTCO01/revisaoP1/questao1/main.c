//*********QUESTÃO 1*************///////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

int main() {
    Funcionario f1;

    // Inicialização dos dados de f1
	// Inicialize o nome com João da Silva, a idade com 25 e o salário com 3000.
	strcpy(f1.nome, "Joao da Silva");
    f1.idade = 25;
    f1.salario = 3000.0;

    Funcionario *f2 = (Funcionario*) malloc(sizeof(Funcionario));
    if (f2 == NULL) {
        printf("Memória não alocada.\n");
        return 1;
    }
	
    // Inicialização dos dados de f2
	// Inicialize o nome com Maria Oliveira, a idade com 40 e o salário com 5000.
	strcpy(f2->nome, "Maria Oliveira");
    f2->idade = 40;
    f2->salario = 5000.0;
	
	Funcionario *f3 = &f1;
	// Inicialização dos dados de f3
    // Inicialize o nome com Ana Beatriz, a idade com 28 e o salário com 1000.
    strcpy(f3->nome, "Ana Beatriz");
    f3->idade = 28;
    f3->salario = 1000.0;
	
    // Impressão dos dados de f1 - complete o comando printf (?)
    printf("Funcionario f1:\n");
    printf("Nome: %s\n", f1.nome);
    printf("Idade: %d\n", f1.idade);
    printf("Salario: %.2f\n", f1.salario);

    // Impressão dos dados de f2 - complete o comando printf (?)
    printf("\nFuncionario f2:\n");
    printf("Nome: %s\n", f2->nome);
    printf("Idade: %d\n", f2->idade);
    printf("Salario: %.2f\n", f2->salario);
	
	// Impressão dos dados de f3 - complete o comando printf (?)
    printf("\nFuncionario f3:\n");
	printf("Nome: %s\n", f3->nome);
    printf("Idade: %d\n", f3->idade);
    printf("Salario: %.2f\n", f3->salario);

    // Liberação da memória alocada
    free(f2);

    return 0;
}

#include <stdio.h>
#define qtd 50

typedef struct tPessoa{
    int cod;
    char sexo;
    float altura;
    int idade;
    char olhos;
}tPessoa;

void preencheVet(tPessoa vet[]);
void imprimeVet(tPessoa vet[]);
void geraRelatorios(tPessoa vet[]);

int main() {
    //DECLARAÇÃO DE VARIÁVEIS
    tPessoa vet[qtd];
    preencheVet(vet);
    imprimeVet(vet);
    geraRelatorios(vet);
    return 0;
}

void preencheVet(tPessoa vet[])
{
    //DECLARAÇÃO DE VARIÁVEIS
    FILE *arq;

    arq = fopen("C:/Users/lucas/OneDrive/Documentos/UNIFEI/CTCO01/revisao/arquivos/dados2.txt", "r");
    if (!arq)
    {
        printf("Erro ao ler o arquivo");
        return;
    }

    for (int i = 0; i < qtd; i++)
    {
        fscanf(arq, "%d %c %f %d %c", &vet[i].cod, &vet[i].sexo, &vet[i].altura, &vet[i].idade, &vet[i].olhos);
        if(ferror(arq))
        {
            printf("Erro ao ler do arquivo");
            return;
        }
    }
    fclose(arq);
}

void imprimeVet(tPessoa vet[])
{
    for (int i = 0; i < qtd; i++)
    {
          printf("%d %c %0.2f %d %c \n", vet[i].cod, vet[i].sexo, vet[i].altura, vet[i].idade, vet[i].olhos);
    }
    return;
}

void geraRelatorios(tPessoa vet[])
{
    //DECLARACAO DE VARIAVEIS
    int R1 = 0; //total de pessoas com olhos castanhos e altura superior a 1,6m
    float R1_Idade = 0;
    int maiorIdade = -1; //maior idade
    int R2 = 0; // sexo feminino entre 20 e 45 anos ou olhos verdes e altura inferior a 1,7
    float percentualHomens = 0;

    for (int i =0; i<qtd; i++)
    {
        if (vet[i].olhos == 'C' && vet[i].altura > 1.6)
        {
            R1++;
            R1_Idade += vet[i].idade;
        }

        if (vet[i].sexo == 'F')
        {
            if ((vet[i].idade >=20 && vet[i].idade <=45) || (vet[i].olhos == 'V' && vet[i].altura < 1.7))
                R2++;
        }
        else
            percentualHomens++;

        if (vet[i].idade > maiorIdade)
            maiorIdade = vet[i].idade;
    }
    printf("Média de idade das pessoas com olhos castanhos e altura superior a 1,60m: %0.2f \n", R1_Idade/R1);
    printf("Maior idade entre os habitantes: %d \n", maiorIdade);
    printf("Quantidade de indivíduos do sexo feminino com idade entre 20 e 45 anos (inclusive) ou que tenham olhos verdes e altura inferior a 1,70m: %d \n", R2);
    printf("Percentual de homens: %0.2f \n", (percentualHomens*100)/qtd);
}

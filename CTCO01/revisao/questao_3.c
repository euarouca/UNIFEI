#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qtd 20

int carregaVet(float *vet);
void imprimeVet(float *vet);
void tamSequencia(float *vet);

int main() {
    float vet[qtd];
    carregaVet(vet);
    if (carregaVet(vet) == 1)
    {
        imprimeVet(vet);
        tamSequencia(vet);
    }
    return 0;
}

int carregaVet(float *vet)
{
    FILE *arq;
    int i = 0;

    arq = fopen("C:/Users/lucas/OneDrive/Documentos/UNIFEI/CTCO01/revisao/arquivos/dados3.txt", "r");
    if (!arq)
    {
        printf("Erro ao ler o arquivo \n");
        return -1;
    }

    while (fscanf(arq, "%f,", &vet[i]) == 1 && i < qtd) {
        i++;
    }

    if (i < 20)
    {
        printf("Sequencia menor que a solicitada\n");
        return -1;
    }
    return 1;
}

void imprimeVet(float *vet)
{
    for (int i = 0; i < qtd; i++)
        printf("%0.2f \n", vet[i]);
    return;
}

void tamSequencia(float *vet)
{
    float valor;
    int contador;
    int k = 0;
    float aux[qtd];
    int posAux = -1;

    for (int i = 0; i < qtd; i++)
    {
        k = 0;
        valor = vet[i];
        //conferir se o valor já foi lido alguma vez
        for (int j = 0; j <= posAux && k == 0; j++)
        {
            if (valor == aux[j])
            {
                j = posAux;
                k = 1; //quer dizer que o valor já foi lido
            }
        }
        if (k == 0)
        {
            posAux++;
            aux[posAux] = valor;
            contador = 0;
            //verificar quantas vezes o valor aparece no vetor
            for (int x = 0; x < qtd; x++)
            {
                if (vet[x] == valor)
                    contador++;
            }
            printf("%0.2f ocorre %d vezes \n", valor, contador);
        }
    }
}
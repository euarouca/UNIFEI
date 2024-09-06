#include <stdio.h>
#include "vetDin.h"

int main() {
    char nomeArquivo[30];
    int tam;
    int valor;
    int *vet;
    int res;

    scanf("%s", nomeArquivo);
    scanf("%d", &tam);
    scanf("%d", &valor);

    vet = alocaVetor(tam);
    if (!vet)
    {
        printf("Erro ao alocar o vetor.");
        return 1;
    }
    res = preencheVetor(nomeArquivo, tam, vet);
    if (res == -1)
    {
        printf("Erro ao alocar o vetor.");
        return 1;
    }
    if (res == -2)
    {
        printf("Erro ao ler do vetor.");
        return 1;
    }

    res = econtraValor(vet, tam, valor);
    if (res == -1)
        printf("O elemento não existe no vetor.");
    else
        printf("O elemento ocorre na posicao %d do vetor." ,res);

    return 0;
}

#include <stdio.h>

int maiorRecursivo(int vet[], int n){
    if (n==1) 
        return vet[0];

    int maior = maiorRecursivo(vet, n-1);

    if(vet[n-1] > maior)
        return vet[n-1];

    else
        return maior; 
}

int main() {
    int vetor[] = {3, 5, 7, 2, 8, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("O maior elemento e: %d\n", maiorRecursivo(vetor, tamanho));

    return 0;
}
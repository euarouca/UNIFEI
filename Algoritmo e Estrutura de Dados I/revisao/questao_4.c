#include <stdio.h>

void mm(int vet[], int tam, int *min, int *max);

int main() {
    int vet[10] = {2, 6, 7, 8, 11, 3, 9, 4, 5, 10};
    int tam = 10;
    int min, max;
    mm(vet, tam, &min, &max);
    printf("O menor valor no vetor e %d. E o maior valor e %d.\n", min, max);
    return 0;
}


void mm(int *vet, int tam, int *min, int *max)
{
    *min = vet[0];
    *max = vet[0];

    for (int i = 1; i < tam; i++)
    {
        if (vet[i] < *min)
           *min = vet[i];
        if (vet[i] > *max)
           *max = vet[i];
    }
}
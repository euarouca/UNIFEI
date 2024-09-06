#include <stdio.h>
#include "vetor.h"

int main()
{
    int tam, res;
    vet *vetTad;

    printf("tam do vetor: ");
    scanf("%d",&tam);

    vetTad = cria(tam);
    if(vetTad==NULL)
    {
        printf("Erro");
        return 1;
    }

    preenchealeat(vetTad);

    res= acessa(vetTad, 2);
    printf("\n%d",res);

    libera(vetTad);

    return 0;
}

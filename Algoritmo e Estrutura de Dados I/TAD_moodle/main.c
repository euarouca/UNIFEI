#include <stdio.h>
#include "TAD_DIC.h"
#include <string.h>

int main() {
    char nomeArquivo[20];
    char palavra[11];
    dic *D = criaDic();
    scanf("%s", nomeArquivo);
    scanf("%s", palavra);
    carregaDicionario(D, nomeArquivo);
    printf("Percorrimento em pré-ordem\n");
    percorrePreOrdem(getRaiz(D));
    buscaPalavra(D, palavra);
    scanf("%s", palavra);
    removePalavra(D, palavra);
    printf("\nPercorrimento em Ordem Alfabética\n");
    percorreEmOrdem(getRaiz(D));
    return 0;
}







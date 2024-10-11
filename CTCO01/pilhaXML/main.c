#include <stdio.h>
#include "pilhaXML.h"

int main() {
    char nomeArquivo[20];
    pilhaXML *pilha = criaPilha();
    if(!pilha)
        return 0;
    scanf("%s", nomeArquivo);
    int res = validaXML(nomeArquivo, pilha);
    if (res == 1)
        printf("XML bem formado");
    else
        printf("XML mal formado");
    desalocaPilha(pilha);
    return 0;
}

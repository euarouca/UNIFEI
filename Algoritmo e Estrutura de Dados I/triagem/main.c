#include <stdio.h>
#include "triagem.h"

int main() {
    char nomeArquivo[20];
    int opc;
    TFila *urgencia = criaFila();
    TFila *media = criaFila();
    TFila *baixa = criaFila();
    if (!urgencia || !media || !baixa)
    {
        printf("Não foi possível inicializar as filas de prioridade");
        desalocaFila(urgencia);
        desalocaFila(media);
        desalocaFila(baixa);
        return 0;
    }

    TPilha *historico = criaPilha();
    if (!historico)
    {
        printf("Não foi possível inicializar o histórico");
        desalocaFila(urgencia);
        desalocaFila(media);
        desalocaFila(baixa);
        return 0;
    }

    scanf("%s", nomeArquivo);

    int res = processaCarga(nomeArquivo, urgencia, media, baixa);
    if (!res)
    {
        printf("Erro ao processar os clientes");
        desalocaPilha(historico);
        desalocaFila(urgencia);
        desalocaFila(media);
        desalocaFila(baixa);
        return 0;
    }

    //opc = 1 -> Gerencia Atendimento
    //opc = 2 -> Mostra Último Atendimento
    //opc = 3 -> sair do loop
    scanf("%d", &opc);
    while(opc != 3)
    {
        if(opc == 1)
            GerenciaAtendimento(urgencia, media, baixa, historico);
        if(opc == 2)
            mostraUltimoAtendimento(historico);
        scanf("%d", &opc);
    }

    printf("Tamanho da fila de urgencia alta: %d\n", tamanhoFila(urgencia));
    printf("Tamanho da fila de urgencia media: %d\n", tamanhoFila(media));
    printf("Tamanho da fila de urgencia baixa: %d\n", tamanhoFila(baixa));
    printf("Total de atendimentos: %d\n", totalAtendimentos(historico));

    reiniciaPilha(historico);

    printf("Total de atendimentos: %d\n", totalAtendimentos(historico));

    desalocaPilha(historico);
    desalocaFila(urgencia);
    desalocaFila(media);
    desalocaFila(baixa);
}

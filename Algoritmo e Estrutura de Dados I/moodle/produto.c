#include "produto.h"
#include <stdio.h>

void carregaMatriz(int mat[][col], int linhas, char *nomeArquivo) {
  FILE *arquivo;
  arquivo = fopen(nomeArquivo, "r");

  if (arquivo) {
    for (int i = 0; i < linhas; i++) {
      if (fscanf(arquivo, "%d %d %d", &mat[i][0], &mat[i][1], &mat[i][2]) !=3){
        printf("Erro ao ler a linha %d do arquivo.\n", i);
        break;
      }
    }
    fclose(arquivo); // Fechar o arquivo após a leitura
  } else {
    printf("Erro ao abrir o arquivo.\n");
  }
}

void imprimeMatriz(int mat[][col], int linhas){
  for (int i = 0; i < linhas; i++) {
    printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
  }
}

void alteraValor(int mat[][col], int linhas, int desconto){
  for (int i = 0; i < linhas; i++) {
    if (mat[i][2] > 50)
      mat[i][1] -= desconto;
  }
}
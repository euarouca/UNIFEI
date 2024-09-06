#include <stdio.h>
#define col 3

void carregaMatriz(int mat[][col], int linhas);
void imprimeMatriz(int mat[][col], int linhas);
void alteraValor(int mat[][col], int linhas);
void atualizaArquivo(int mat[][col], int linhas);

int main() {
    int qtdProdutos;
    printf("Digite a quantidade de produtos: ");
    scanf("%d", &qtdProdutos);

    //DECLARAR A MATRIZ
    int mat[qtdProdutos][col];

    //CHAMAR A FUNÇÃO QUE VAI CARREGAR A MATRIZ
    carregaMatriz(mat, qtdProdutos);

    //IMPRIMIR A MATRIZ
    imprimeMatriz(mat, qtdProdutos);

    //ATUALIZAR O PREÇO DOS PRODUTOS
    alteraValor(mat, qtdProdutos);

    //IMPRIMIR A MATRIZ
    imprimeMatriz(mat, qtdProdutos);

    //ATUALIZAR O ARQUIVO
    atualizaArquivo(mat, qtdProdutos);

    return 0;
}

void carregaMatriz(int mat[][col], int linhas)
{
    FILE *arq;

    //ABRIR O ARQUIVO
    arq = fopen("C:/Users/lucas/OneDrive/Documentos/UNIFEI/CTCO01/revisao/arquivos/dados5.txt", "r");
    if (!arq)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    //LER DO ARQUIVO E CARREGAR NA MATRIZ
    for (int l = 0; l < linhas; l++)
    {
        fscanf(arq, "%d %d %d", &mat[l][0], &mat[l][1], &mat[l][2]);
        if (ferror(arq))
        {
            printf("Erro ao ler do arquivo.\n");
            return;
        }
    }
    fclose(arq);
}

void imprimeMatriz(int mat[][col], int linhas)
{
    for (int l=0; l < linhas; l++)
        printf("%d %d %d \n", mat[l][0], mat[l][1], mat[l][2]);
}

void alteraValor(int mat[][col], int linhas)
{
    int desconto;
    printf("Digite o valor do desconto: ");
    scanf("%d", &desconto);

    for(int i =0; i < linhas; i++)
    {
        if (mat[i][2] > 50)
            mat[i][1] = mat[i][1] - desconto;
    }
}

void atualizaArquivo(int mat[][col], int linhas)
{
    FILE *arq;
    //ABRIR O ARQUIVO
    arq = fopen("saida.txt", "w");
    if (!arq)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    //LER DA MATRIZ E ATUALIZAR O VETOR
    for (int l = 0; l < linhas; l++)
    {
        fprintf(arq, "%d %d %d\n", mat[l][0], mat[l][1], mat[l][2]);
        if (ferror(arq))
        {
            printf("Erro ao ler do arquivo.\n");
            return;
        }
    }
    fclose(arq);

}
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXN 100
#define MAXM 3
#define MAXCOEFS (MAXM + 1)

double g(int j, double x) {
    return pow(x, j - 1);
}

int main() {
    int n, m, num_coefs, i, j, k;
    double fx[MAXN], x[MAXN];
    double matriz[MAXCOEFS][MAXCOEFS + 1];
    double coef[MAXCOEFS];
    double pivo, soma;

    printf("Digite o numero de pontos n: ");
    scanf("%d", &n);

    printf("Digite o grau do polinomio m: ");
    scanf("%d", &m);

    if (n > MAXN || m > MAXM || n <= 0 || m < 0) {
        printf("Erro: n deve ser <= %d e m deve ser <= %d.\n", MAXN, MAXM);
        return 1;
    }

    num_coefs = m + 1;

    printf("Digite os %d pontos no formato x f(x):\n", n);
    for (i = 0; i < n; i++) {
        printf("Ponto %d: ", i + 1);
        scanf("%lf %lf", &x[i], &fx[i]);
    }

    memset(matriz, 0, sizeof(matriz));

    for (i = 0; i < num_coefs; i++) {
        for (j = 0; j < num_coefs; j++) {
            soma = 0;
            for (k = 0; k < n; k++) {
                soma += g(i + 1, x[k]) * g(j + 1, x[k]);
            }
            matriz[i][j] = soma;
        }

        soma = 0;
        for (k = 0; k < n; k++) {
            soma += fx[k] * g(i + 1, x[k]);
        }
        matriz[i][num_coefs] = soma;
    }

    printf("\nMatriz extendida inicial:\n");
    for(i = 0; i < num_coefs; i++) {
        for(j = 0; j <= num_coefs; j++) {
            printf("%10.4f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nEtapas da Eliminacao:\n");
    for (k = 0; k < num_coefs - 1; k++) {
        for (i = k + 1; i < num_coefs; i++) {
            pivo = matriz[i][k] / matriz[k][k];

            printf("L%d = L%d - L%d * (%f)\n", i+1, i+1, k+1, pivo);

            for (j = k; j <= num_coefs; j++) {
                matriz[i][j] -= pivo * matriz[k][j];
            }
        }
    }

    printf("\nMatriz triangularizada:\n");
    for(i = 0; i < num_coefs; i++) {
        for(j = 0; j <= num_coefs; j++) {
            printf("%10.4f ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = num_coefs - 1; i >= 0; i--) {
        soma = 0;
        for (j = i + 1; j < num_coefs; j++) {
            soma += matriz[i][j] * coef[j];
        }
        coef[i] = (matriz[i][num_coefs] - soma) / matriz[i][i];
    }

    printf("\n--- Resultados ---\n");
    printf("Coeficientes encontrados (a_1 a a_%d):\n", num_coefs);
    for(i = 0; i < num_coefs; i++){
        printf("a_%d = %lf\n", i + 1, coef[i]);
    }

    printf("\nEquacao ajustada: h(x) = ");
    for (i = 0; i < num_coefs; i++) {
        printf("(%lf)", coef[i]);
        if (i > 0) {
            printf("*x^%d", i);
        }
        if (i < num_coefs - 1) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
#include "least_squares.h" // Nosso módulo de MMQ
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_points, degree;
    double* x = NULL;
    double* y = NULL;
    double* coeffs = NULL;

    printf("Metodo dos Minimos Quadrados - Ajuste Polinomial\n");
    
    printf("Digite a quantidade de pontos (n <= 100): ");
    scanf("%d", &n_points);

    printf("Digite o grau do polinomio (m <= 3): ");
    scanf("%d", &degree);

    if (n_points <= 0 || degree < 0) {
        fprintf(stderr, "Erro: Numero de pontos e grau devem ser positivos.\n");
        return 1;
    }
    
    if (n_points > 100 || degree > 3) {
        fprintf(stderr, "Erro: Entrada viola as restricoes (n<=100, m<=3).\n");
        return 1;
    }

    // Alocar memória para os vetores de pontos
    x = (double*)malloc(n_points * sizeof(double));
    y = (double*)malloc(n_points * sizeof(double));

    if (x == NULL || y == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria para os pontos.\n");
        free(x);
        free(y);
        return 1;
    }

    // Leitura dos pontos (x, f(x))
    printf("\nDigite os %d pares de pontos (x y):\n", n_points);
    for (int i = 0; i < n_points; ++i) {
        printf("Ponto %d: ", i + 1);
        if (scanf("%lf %lf", &x[i], &y[i]) != 2) {
            fprintf(stderr, "Erro na leitura do ponto.\n");
            free(x);
            free(y);
            return 1;
        }
    }

    // Calcular os coeficientes
    coeffs = polynomialFit(n_points, x, y, degree);

    // Liberar os vetores de pontos (não são mais necessários)
    free(x);
    free(y);
    x = NULL;
    y = NULL;

    // Verificar se o cálculo falhou
    if (coeffs == NULL) {
        fprintf(stderr, "Nao foi possivel calcular os coeficientes.\n");
        return 1;
    }

    // Imprimir resultados
    printf("\n--- Resultados ---\n");
    printf("Coeficientes do polinomio [c0, c1, ..., cm]:\n");
    for (int i = 0; i <= degree; ++i) {
        printf("c%d = % .8f\n", i, coeffs[i]);
    }

    // Formatar e imprimir a string do polinômio
    char poly_buffer[1024]; // Buffer para a string
    getPolynomialString(coeffs, degree, poly_buffer, sizeof(poly_buffer));
    
    printf("\nPolinomio ajustado:\n");
    printf("%s\n", poly_buffer);

    // Liberar memória dos coeficientes
    free(coeffs);
    coeffs = NULL;

    return 0;
}
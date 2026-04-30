#include <stdio.h>
#include <math.h>

// Definição da função original
double f(double x) {
    return (x + 1.0) / (x * x + 1.0);
}

// h(x) = a1 + a2*x + a3*x^2
double h2(double x, double a1, double a2, double a3) {
    return a1 + a2 * x + a3 * x * x;
}

void gaussElimination(double A[3][3], double b[3], double sol[3]) {
    double tempA[3][3];
    double tempb[3];
    int i, j, k;

    // Copia para matrizes para não destruir as originais
    for (i = 0; i < 3; i++) {
        tempb[i] = b[i];
        for (j = 0; j < 3; j++) {
            tempA[i][j] = A[i][j];
        }
    }

    //triangularização
    for (k = 0; k < 2; k++) { // Pivô A[k][k]
        for (i = k + 1; i < 3; i++) {
            double factor = tempA[i][k] / tempA[k][k];
            tempb[i] = tempb[i] - factor * tempb[k];
            for (j = k; j < 3; j++) {
                tempA[i][j] = tempA[i][j] - factor * tempA[k][j];
            }
        }
    }

    // retro-substituição
    for (i = 2; i >= 0; i--) {
        double sum = 0;
        for (j = i + 1; j < 3; j++) {
            sum += tempA[i][j] * sol[j];
        }
        sol[i] = (tempb[i] - sum) / tempA[i][i];
    }
}


int main() {
    printf("--- Questao 1 ---\n\n");
    // Valores calculados analiticamente na resolução
    double A[3][3] = {
        {3.0, -1.5, 3.0},
        {-1.5, 3.0, -3.75},
        {3.0, -3.75, 6.6}
    };

    // Vetor b
    double b1 = (0.5 * log(2.0) + M_PI / 4.0) - (0.5 * log(5.0) - atan(2.0));
    double b2 = (1.0 + 0.5 * log(2.0) - M_PI / 4.0) - (-2.0 + 0.5 * log(5.0) + atan(2.0));
    double b3 = 1.5 - b1;
    
    double b[3] = {b1, b2, b3};
    
    double a[3]; // a[0] = a1, a[1] = a2, a[2] = a3

    gaussElimination(A, b, a);

    printf("a) Coeficientes do polinomio h2(x) = a1 + a2*x + a3*x^2:\n");
    printf("a1 (g1(x)=1) = %f\n", a[0]);
    printf("a2 (g2(x)=x) = %f\n", a[1]);
    printf("a3 (g3(x)=x^2) = %f\n", a[2]);
    printf("h2(x) = %f + %f*x + %f*x^2\n\n", a[0], a[1], a[2]);

    printf("b) Comparacao de f(x) e h2(x):\n");
    printf("|  x  |   f(x)   |  h2(x)   |  Erro    |\n");
    printf("|-----|----------|----------|----------|\n");

    double valoresDeX[] = {-2.0, -1.0, 0.0, 1.0};
    int n = 4;
    for (int i = 0; i < n; i++) {
        double x = valoresDeX[i];
        double fx = f(x);
        double h2x = h2(x, a[0], a[1], a[2]);
        double erro = fabs(fx - h2x);
        printf("| %3.1f | %8.4f | %8.4f | %8.4f |\n", x, fx, h2x, erro);
    }
    printf("\n");

    return 0;
}
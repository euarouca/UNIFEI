#include <stdio.h>
#include <math.h>

int main() {
    printf("--- Questao 2 ---\n\n");

    double t_k[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double F_k[] = {10.0, 15.0, 23.0, 33.0, 45.0, 58.0, 69.0};
    int m = 7; // Número de pontos

    double z_k[m];
    printf("1. Linearizacao dos dados (z = ln(100/F - 1)):\n");
    printf("|  t  | F(t) |      y     |     z_k    |\n");
    printf("|-----|------|------------|------------|\n");
    for (int i = 0; i < m; i++) {
        double y_k = (100.0 / F_k[i]) - 1.0;
        z_k[i] = log(y_k); 
        printf("| %3.1f | %4.1f | %10.4f | %10.4f |\n", t_k[i], F_k[i], y_k, z_k[i]);
    }
    printf("\n");
    
    double alpha11 = 0, alpha12 = 0, alpha22 = 0;
    double b1 = 0, b2 = 0;

    for (int i = 0; i < m; i++) {
        double g1 = 1.0;
        double g2 = t_k[i];
        
        alpha11 += g1 * g1;
        alpha12 += g1 * g2;
        alpha22 += g2 * g2;
        
        b1 += z_k[i] * g1;
        b2 += z_k[i] * g2;
    }

    printf("2. Sistema Linear (alpha * a = b):\n");
    printf("| %8.4f  %8.4f | | a1 | = | %8.4f |\n", alpha11, alpha12, b1);
    printf("| %8.4f  %8.4f | | a2 | = | %8.4f |\n\n", alpha12, alpha22, b2);

    double detA = (alpha11 * alpha22) - (alpha12 * alpha12);
    double a1 = ((b1 * alpha22) - (b2 * alpha12)) / detA;
    double a2 = ((alpha11 * b2) - (alpha12 * b1)) / detA;

    printf("3. Solucao do sistema (a1, a2):\n");
    printf("a1 = %f\n", a1);
    printf("a2 = %f\n\n", a2);

    double alpha_final = exp(a1);
    double beta_final = -a2;

    printf("4. Determinacao dos parametros alpha e beta:\n");
    printf("alpha = exp(a1) = %f\n", alpha_final);
    printf("beta = -a2      = %f\n\n", beta_final);
    
    printf("Funcao aproximada:\n");
    printf("g(t) = 100 / (1 + %f * e^(%f * t))\n", alpha_final, -beta_final);

    return 0;
}
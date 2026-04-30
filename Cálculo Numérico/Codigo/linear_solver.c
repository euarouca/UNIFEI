#include "linear_solver.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h> // Para stderr

double* solveLinearSystem(double** A, double* B, int n) {
    // --- Fase de Eliminação (com Pivotação Parcial) ---
    for (int k = 0; k < n - 1; ++k) {
        // Encontrar o pivô (maior valor absoluto na coluna k)
        int max_row = k;
        double max_val = fabs(A[k][k]);
        for (int i = k + 1; i < n; ++i) {
            if (fabs(A[i][k]) > max_val) {
                max_val = fabs(A[i][k]);
                max_row = i;
            }
        }

        // Se o pivô for muito próximo de zero, a matriz é singular
        if (max_val < 1e-10) {
            fprintf(stderr, "Erro: Matriz singular ou mal condicionada.\n");
            return NULL;
        }

        // Trocar linhas (se necessário)
        if (max_row != k) {
            // Troca linha na matriz A
            double* temp_row = A[k];
            A[k] = A[max_row];
            A[max_row] = temp_row;

            // Troca elemento no vetor B
            double temp_b = B[k];
            B[k] = B[max_row];
            B[max_row] = temp_b;
        }

        // Eliminação
        for (int i = k + 1; i < n; ++i) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
            B[i] -= factor * B[k];
        }
    }

    // --- Fase de Substituição Reversa ---
    double* x = (double*)malloc(n * sizeof(double));
    if (x == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria para o vetor solucao.\n");
        return NULL;
    }

    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        
        if (fabs(A[i][i]) < 1e-10) {
            fprintf(stderr, "Erro: Divisao por zero na substituicao reversa.\n");
            free(x);
            return NULL;
        }
        x[i] = (B[i] - sum) / A[i][i];
    }

    return x;
}
#ifndef LEAST_SQUARES_H
#define LEAST_SQUARES_H

/**
 * @brief Calcula os coeficientes de um polinômio de ajuste usando o 
 * Método dos Mínimos Quadrados.
 * @param n_points O número de pontos de dados (n).
 * @param x O vetor de coordenadas x dos pontos (tamanho n_points).
 * @param y O vetor de coordenadas y (f(x)) dos pontos (tamanho n_points).
 * @param degree O grau do polinômio a ser ajustado (m).
 * @return Um ponteiro para um vetor de coeficientes [c0, c1, ..., cm] 
 * alocado dinamicamente (tamanho degree + 1), ou NULL em caso de erro.
 * @note O CHAMADOR é responsável por liberar a memória do vetor de 
 * coeficientes retornado usando free().
 */
double* polynomialFit(int n_points, const double* x, const double* y, int degree);

/**
 * @brief Gera uma string formatada do polinômio para exibição.
 * @param coeffs Vetor de coeficientes [c0, c1, ..., cm].
 * @param degree O grau do polinômio (m).
 * @param buffer O buffer de caracteres onde a string será escrita.
 * @param buffer_size O tamanho total do buffer.
 */
void getPolynomialString(const double* coeffs, int degree, char* buffer, int buffer_size);

#endif // LEAST_SQUARES_H
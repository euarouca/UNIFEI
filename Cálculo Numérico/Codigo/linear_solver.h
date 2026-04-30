#ifndef LINEAR_SOLVER_H
#define LINEAR_SOLVER_H

/**
 * @brief Resolve um sistema de equações lineares Ax = B (N x N) usando 
 * Eliminação Gaussiana com Pivotação Parcial.
 * @param A Matriz N x N. Esta matriz SERÁ MODIFICADA (destruída) durante o processo.
 * @param B Vetor N x 1. Este vetor SERÁ MODIFICADO (destruído) durante o processo.
 * @param n A dimensão do sistema (N).
 * @return Um ponteiro para um vetor de solução 'x' alocado dinamicamente (tamanho N), 
 * ou NULL se a matriz for singular ou se a alocação de memória falhar.
 * @note O CHAMADOR é responsável por liberar a memória do vetor 'x' retornado 
 * usando free().
 */
double* solveLinearSystem(double** A, double* B, int n);

#endif // LINEAR_SOLVER_H
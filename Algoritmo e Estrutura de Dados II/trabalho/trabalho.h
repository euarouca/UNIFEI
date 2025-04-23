#ifndef TRABALHOALG2_H
#define TRABALHOALG2_H


// funções geradoras de vetores aleatórios/ordenados
int *geraAleatorios(int tam, int semente);
int *geraQuaseOrdenados(int tam, int porcentagem);
int *geraOrdenados(int tam, int ordem);

// algoritmos de ordenação
// seleção
void selectionSort(int *vetor, int tamanho, long long int *comparacoes, long long int *trocas);

// inserção
void inserctionSort(int *vetor, int tamanho, long long int *comparacoes, long long int *trocas);

// mergeSort
void mergeSort(int *vetor, int inicio, int fim, long long int *comparacoes, long long int *trocas);
void merge(int *vetor, int inicio, int meio, int fim, long long int *comparacoes, long long int *trocas);

// quickSort
void quickSort(int *vetor, int inicio, int fim, long long int *comparacoes, long long int *trocas);
int particiona(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas);

// timSort
void timSort(int *vetor, int tamanho, long long int *comparacoes, long long int *trocas);
void timInsertionSort(int *vetor, int esq, int dir, long long int *comparacoes, long long int *trocas); 
void mergeTim(int *vetor, int esq, int meio, int dir, long long int *comparacoes, long long int *trocas); 

#endif //TRABALHOALG2_H
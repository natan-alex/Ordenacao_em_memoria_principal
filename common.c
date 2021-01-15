#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * newArray(int size) {
	return (int *) malloc(sizeof(int) * size);
}

void mostrarItens(int * array, int tam) {
    printf("[");
    for (int i = 0; i < tam; i++)
        printf(" %d", array[i]);
    printf(" ]\n");
}

// printar elementos do array de início a fim,
// incluindo o fim
void mostrarRange(int * array, int inicio, int fim) {
    printf("[");
    for (int i = inicio; i <= fim; i++)
        printf(" %d", array[i]);
    printf(" ]\n");
}

void swap(int * array, int p1, int p2) {
	int aux = array[p1];
	array[p1] = array[p2];
	array[p2] = aux;
}

// obter maior elemento de um array
int getMaior(int * array, int tam) {
	int maior = array[0];
	for (int i = 1; i < tam; i++)
		if (maior < array[i])
			maior = array[i];
	return maior;
}

int * gerarArrayAleatorio(int tam) {
	int * array = (int *) malloc(sizeof(int) * tam);
	srand(time(NULL));
	for (int i = 0; i < tam; i++) 
		array[i] = rand() % tam;
	return array;
}

void printaTempoOrdenacao(clock_t inicio, clock_t fim) {
	printf("Tempo para ordenar o array: %lfms.\n", (fim - inicio) / ((double) CLOCKS_PER_SEC / 1000));
}

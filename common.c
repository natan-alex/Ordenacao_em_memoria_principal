#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// retorna um array de inteiros de tamanho size
int * newIntArray(int size) {
	return (int *) malloc(sizeof(int) * size);
}

void mostrarItens(int array[], int tam) {
    printf("[");
    for (int i = 0; i < tam; i++)
        printf(" %d", array[i]);
    printf(" ]\n");
}

// printar elementos do array de início a fim,
// incluindo o fim
void mostrarRange(int array[], int inicio, int fim) {
    printf("[");
    for (int i = inicio; i <= fim; i++)
        printf(" %d", array[i]);
    printf(" ]\n");
}

// trocar dois elementos de um array de inteiros
void swap(int array[], int p1, int p2) {
	int aux = array[p1];
	array[p1] = array[p2];
	array[p2] = aux;
}

// obter maior elemento de um array
int getMaior(int array[], int tam) {
	int maior = array[0];
	for (int i = 1; i < tam; i++)
		if (maior < array[i])
			maior = array[i];
	return maior;
}

int * gerarArrayAleatorio(int tam) {
	srand(time(NULL));
	int * array = (int *) malloc(sizeof(int) * tam);
	for (int i = 0; i < tam; i++) 
		array[i] = rand() % (2 * tam);
	return array;
}

void printaTempoOrdenacao(clock_t comeco, clock_t fim) {
	double tempoSeg = (fim - comeco) / (double) CLOCKS_PER_SEC;
	if (tempoSeg < 1) {
		tempoSeg *= 1000;
		printf("Tempo para ordenar o array: %lf ms.\n", tempoSeg);
	} else {
		printf("Tempo para ordenar o array: %lf s.\n", tempoSeg);
	}
}

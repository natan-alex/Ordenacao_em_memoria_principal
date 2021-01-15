#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "common.h"
// algoritmos
#include "countingsort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selectionsort.h"
#include "shellsort.h"

int main(int argc, char ** argv) {
	int tam, opcao, * array;
	clock_t comeco, fim;

	do {
		printf("\n");
		printf("Tamanho do array a ser ordenado: ");
		scanf("%d", &tam);
		array = gerarArrayAleatorio(tam);
		printf("Array gerado: \n");
		mostrarItens(array, tam);
		printf("\t\tMENU\t\t\n");
		printf("  [1] - Countingsort\n");
		printf("  [2] - Heapsort\n");
		printf("  [3] - Insertionsort\n");
		printf("  [4] - Mergesort\n");
		printf("  [5] - Quicksort\n");
		printf("  [6] - Selectionsort\n");
		printf("  [7] - Shellsort\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		scanf("%d", &opcao);
		comeco = clock();
		switch(opcao) {
			case 1:
				countingsort(array, tam);
				break;
			case 2:
				heapsort(array, tam);
				break;
			case 3:
				insertionsort(array, tam);
				break;
			case 4:
				mergesort(array, 0, tam-1);
				break;
			case 5:
				quicksort(array, 0, tam-1);
				break;
			case 6:
				selectionsort(array, tam);
				break;
			case 7:
				shellsort(array, tam);
				break;
			case 0:
				printf("Finalizado.\n");
				break;
			default:
				printf("Opcao invalida.\n");
				break;
		}
		if (opcao != 0) {
			fim = clock();
			printf("Array ordenado: \n");
			mostrarItens(array, tam);
			printaTempoOrdenacao(comeco, fim);
		}
		free(array);
	} while (opcao != 0);
}

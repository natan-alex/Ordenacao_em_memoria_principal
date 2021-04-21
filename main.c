#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "common.h"
// algoritmos
#include "countingsort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "insertion_with_bsearch.h"
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
		printf("Array gerado aleatoriamente: \n");
		mostrarItens(array, tam);
		printf("\t\tMENU\t\t\n");
		printf(" Escolha dentre um dos algoritmos abaixo para ordenar o array: \n");
		printf("  [0] - sair\n");
		printf("  [1] - Countingsort\n");
		printf("  [2] - Heapsort\n");
		printf("  [3] - Insertionsort\n");
		printf("  [4] - Insertionsort com pesquisa binaria\n");
		printf("  [5] - Mergesort\n");
		printf("  [6] - Quicksort\n");
		printf("  [7] - Selectionsort\n");
		printf("  [8] - Shellsort\n");
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
                insertion_sort_with_bsearch(array, tam);
                break;
			case 5:
				mergesort(array, 0, tam-1);
				break;
			case 6:
				quicksort(array, 0, tam-1);
				break;
			case 7:
				selectionsort(array, tam);
				break;
			case 8:
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

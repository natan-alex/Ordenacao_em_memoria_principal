#include "selectionsort.h"
#include "common.h"

void selectionsort(int * array, int tam) {
	for (int i = 0; i < tam-1; i++) {
		int menor = i;
		for (int j = i+1; j < tam; j++) {
			if (array[menor] > array[j]) 
				menor = j;
		}	
		swap(array, menor, i);
	}
}

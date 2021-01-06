#include "shellsort.h"

void insercaoShell(int * array, int tam, int cor, int h) {
	for (int i = cor + h; i < tam; i += h) {	
		int tmp = array[i];
		int j = i - h;
		while ((j >= 0) && (array[j] > tmp)) {
			array[j + h] = array[j];
			j -= h;
		}
		array[j + h] = tmp;
	}
}

void shellsort(int * array, int tam) {
	int h = 1;
	// encontrar valor maximo de h
	// utilizando a sequencia de knuth
	while (h <= tam) 
		h = (h * 3) + 1;
	// segmentacao de fato em subarrays
	// com elementos distantes um do outro
	// em valor h
	while (h > 1) {
		h /= 3;
		for (int cor = 0; cor < h; cor++)
			insercaoShell(array, tam, cor, h);
	}
}

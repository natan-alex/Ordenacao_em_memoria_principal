#include "insertionsort.h"

void insertionsort(int * array, int tam) {
	for (int i = 1; i < tam; i++) {
		int tmp = array[i];
		int j = i-1;
		while ((j>=0) && (array[j] > tmp)) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = tmp;
	}
}

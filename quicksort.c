#include "quicksort.h"
#include "common.h"

void quicksort(int * array, int esq, int dir) {
    int pivo = array[(esq+dir)/2];
    int i = esq, j = dir;

    while (i <= j) {
        while (array[i] < pivo)
            i++;
        while (array[j] > pivo)
            j--;
        if (i <= j) {
            swap(array, i, j);
            j--;
            i++;
        }
    }

    if (esq < j)
        quicksort(array, esq, j);
    if (dir > i)
        quicksort(array, i, dir);
}

#include "mergesort.h"

void intercalar(int * array, int esq, int meio, int dir) {
    // array para intercalação
    int tmp[dir - esq + 1];

    int i = esq, j = meio+1;
    int controle = 0; // inserções no array tmp

    // início intercalação
    while (i <= meio && j <= dir) {
        tmp[controle++] = (array[i] < array[j]) ? array[i++] : array[j++];
    }

    // restantes
    while (i <= meio)
        tmp[controle++] = array[i++];

    while (j <= dir)
        tmp[controle++] = array[j++];

    // copiar para o array original
    i = esq;
    for (int k = 0; k < controle; k++)
        array[i++] = tmp[k];
}

void mergesort(int * array, int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergesort(array, esq, meio);
        mergesort(array, meio+1, dir);
        intercalar(array, esq, meio, dir);
    }
}

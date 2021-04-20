#include <stdio.h>
#include <stdlib.h>

void show_array(int array[], size_t size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void binary_search_insertion(int array[], int item, size_t start, size_t end) {
    int left = start;
    int right = end;
    int middle = (right - left) / 2;
    printf("\n");
    printf("item: %d\n", item);
    printf("left: %d, array[left]: %d\n", left, array[left]);
    printf("middle: %d, array[middle]: %d\n", middle, array[middle]);
    printf("right: %d, array[right]: %d\n", right, array[right]);
    show_array(array, 12);
}

void insertion_sort_with_bsearch(int array[], size_t size) {
    int j = 0, tmp = 0;
    int position = 0;
    for (int i = 1; i < size; i++) {
        /* j = i - 1; */
        /* tmp = array[i]; */
        /* while (j >= 0 && array[j] > tmp) { */
        /*     array[j + 1] = array[j]; */
        /*     j--; */
        /* } */
        /* array[j + 1] = tmp; */
        binary_search_insertion(array, array[i], 0, i);
    }
}

int main(int argc, char ** argv) {
    printf("\n\tinicio\n");
    int array[] = {5,12,3,7,9,2,6,10,15,13,4,8};
    int tam = sizeof(array)/sizeof(array[0]);
    show_array(array, tam);
    insertion_sort_with_bsearch(array, tam);
    show_array(array, tam);
    return EXIT_SUCCESS;
}

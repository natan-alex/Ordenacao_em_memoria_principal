#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_array(int array[], size_t size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int binary_search_insertion(int array[], int item, int left, int right) {
    int middle = 0, item_middle = 0;

    while (right >= left) {
        middle = (right + left) / 2;
        item_middle = array[middle];
        /* printf("\nleft: %d, middle %d, right %d\n", left, middle, right); */

        if (item_middle > item) {
            right = middle - 1;
        } else if (item_middle < item) {
            left = middle + 1;
        } else {
            return middle;
        }
    }

    if (item > item_middle) {
        return middle + 1;
    } else {
        return middle;
    }
}

void insertion_sort_with_bsearch(int array[], size_t size) {
    int j = 0, position = 0, tmp = 0;

    for (int i = 1; i < size; i++) {
        j = i - 1;
        tmp = array[i];
        position = binary_search_insertion(array, tmp, 0, i);

        /* printf("\nposition: %d\n", position); */
        /* printf("tmp: %d\n", tmp); */

        while (j >= position) {
            /* printf("j: %d\n", j); */
            array[j + 1] = array[j];
            j--;
        }

        array[position] = tmp;
        /* show_array(array, size); */
    }
}

int * generate_random_array(size_t size) {
    srand(time(NULL));
    int * array = (int *) malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (2 * size);
    }

    return array;
}

int main(int argc, char ** argv) {
    printf("\n\tinicio\n");
    /* int array[] = {5,12,3,7,9,2,6,10,15,13,4,8,11,20,22,18,16,19,25,21}; */
    int tam = 100;
    int * array = generate_random_array(tam);

    show_array(array, tam);

    insertion_sort_with_bsearch(array, tam);

    show_array(array, tam);

    free(array);

    return EXIT_SUCCESS;
}

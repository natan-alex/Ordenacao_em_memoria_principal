#include <stdio.h>
#include <stdlib.h>
#include "insertion_with_bsearch.h"

size_t binary_search_insertion(int array[], int item, int left, int right) {
    int middle = 0, item_middle = 0;

    while (right >= left) {
        middle = (right + left) / 2;
        item_middle = array[middle];

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

        // every item that is in a position that is bigger than
        // the position of the insertion is pushed forward
        while (j >= position) {
            array[j + 1] = array[j];
            j--;
        }

        array[position] = tmp;
    }
}

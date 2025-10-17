#include <stdio.h>

#include "array.h"

int64_t int64_array_get(int64_array array, int64_t index) {
    if (index  >= 0 && index < array.length) {
        return array.items[index];
    }

    return 0;
}

void print_array_memaddr(int64_t *array, size_t arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("Memory address of array[%d]: %p\n", i, &array[i]);
    }

    printf("\n");
}

void print_int64_array_memaddr(int64_array array) {
    for (int i = 0; i < array.length; i++) {
        int64_t currentItem = int64_array_get(array, i);
        printf("Memory address of array[%d]: %p\n", i, &currentItem);
    }

    printf("\n");
}

void print_array_values(int64_t *array, size_t arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("Value of array[%d]: %ld\n", i, *(array + i));
    }

    printf("\n");
}

void print_int64_array_values(int64_array array) {
    for (int i = 0; i < array.length; i++) {
        int64_t currentItem = int64_array_get(array, i);
        printf("Value of array[%d]: %ld\n", i, currentItem);
    }

    printf("\n");
}

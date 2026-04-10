#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int64_t int64_array_get(int64_array array, size_t index) {
    if (index < array.length) {
        return array.items[index];
    }

    return 0;
}

int64_array create_int64_array(size_t size) {
    int64_array arr;

    arr.items = malloc(size * sizeof(int64_t));
    arr.length = size;

    return arr;
}

void print_array_memaddr(int64_t *array, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        printf("Memory address of array[%lu]: %p\n", i, &array[i]);
    }

    printf("\n");
}

void print_int64_array_memaddr(int64_array array) {
    for (size_t i = 0; i < array.length; i++) {
        int64_t currentItem = int64_array_get(array, i);
        printf("Memory address of array[%lu]: %p\n", i, &currentItem);
    }

    printf("\n");
}

void print_array_values(int64_t *array, size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        printf("Value of array[%lu]: %ld\n", i, *(array + i));
    }

    printf("\n");
}

void print_int64_array_values(int64_array array) {
    for (size_t i = 0; i < array.length; i++) {
        int64_t currentItem = int64_array_get(array, i);
        printf("Value of array[%lu]: %ld\n", i, currentItem);
    }

    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

#include "array.h"

#define SIZE_OF_DS 2
#define SIZE_OF_ARRAY_01 4
#define SIZE_OF_ARRAY_02 2

int main() {
    // Allocate memory
    // int64_t *array01 = malloc(SIZE_OF_ARRAY_01 * sizeof(int64_t));
    // int64_t *array02 = malloc(SIZE_OF_ARRAY_02 * sizeof(int64_t));
    int64_array array01 = { malloc(SIZE_OF_ARRAY_01 * sizeof(int64_t)), SIZE_OF_ARRAY_01 };
    int64_array array02 = { malloc(SIZE_OF_ARRAY_02 * sizeof(int64_t)), SIZE_OF_ARRAY_02 };

    // Write to memory
    *array01.items = 25;
    array01.items[1] = 50;
    array01.items[2] = 75;
    array01.items[3] = 100;

    *array02.items = 10;
    array02.items[1] = 20;

    printf("Array01:\n\n");
    // print_array_memaddr(array01.items, SIZE_OF_ARRAY_01);
    // print_array_values(array01.items, SIZE_OF_ARRAY_01);
    print_int64_array_memaddr(array01);
    print_int64_array_values(array01);

    printf("Array02:\n\n");
    // print_array_memaddr(array02.items, SIZE_OF_ARRAY_02);
    // print_array_values(array02.items, SIZE_OF_ARRAY_02);
    print_int64_array_memaddr(array02);
    print_int64_array_values(array02);
    
    // Deallocate memory
    free(array01.items);
    array01.items = NULL;
    free(array02.items);
    array02.items = NULL;

	return 0;	
}

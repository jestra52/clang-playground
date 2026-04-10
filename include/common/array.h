#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    int32_t* items;
    size_t length;
} int32_array;

typedef struct {
    int64_t* items;
    size_t length;
} int64_array;

int64_t int64_array_get(int64_array array, size_t index);
int64_array create_int64_array(size_t size);
void print_array_memaddr(int64_t *array, size_t arraySize);
void print_int64_array_memaddr(int64_array array);
void print_array_values(int64_t *array, size_t arraySize);
void print_int64_array_values(int64_array array);

#endif

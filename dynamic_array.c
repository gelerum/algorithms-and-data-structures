#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int *data;
} DynamicArray;

DynamicArray init_dynamic_array() {
    DynamicArray array;
    array.size = 0;
    array.data = malloc(2 * sizeof(int));
    array.capacity = 2;
    return array;
}

void push_back_dynamic_array(DynamicArray *array, int elemenet) {
    if (array->size == array->capacity) {
        array->data = realloc(array->data, 2 * array->capacity * sizeof(int));
        array->capacity = 2 * array->capacity;
    }
    array->data[array->size] = elemenet;
    array->size++;
}

int pop_front_dynamic_array(DynamicArray *array) {
    if (array->size == 0) {
        exit(EXIT_FAILURE);
    }

    int popped = array->data[array->size - 1];
    for (int i = 0; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    array->size--;

    return popped;
}

void free_dynamic_array(DynamicArray *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void print_dynamic_array(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%i", array->data[i]);
        if (i < array->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    DynamicArray array = init_dynamic_array();

    print_dynamic_array(&array); // output:
    push_back_dynamic_array(&array, 2);
    print_dynamic_array(&array); // output: 2
    push_back_dynamic_array(&array, 5);
    print_dynamic_array(&array); // output: 2 5
    pop_front_dynamic_array(&array);
    print_dynamic_array(&array); // output: 2 5 77

    free_dynamic_array(&array);

    return 0;
}
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

int parent(int i) { return (i - 1) / 2; }
int left_child(int i) { return 2 * i + 1; }
int right_child(int i) { return 2 * i + 2; }

void sift_up_min(DynamicArray *heap, int i) {
    if (i == 1) {
        return;
    }
    if (heap->data[i] < heap->data[parent(i)]) {
        int tmp = heap->data[i];
        heap->data[i] = heap->data[parent(i)];
        heap->data[parent(i)] = tmp;
        sift_up_min(heap, parent(i));
    }
}

void sift_down_min(DynamicArray *heap, int i) {
    int min_index = i;
    int left = left_child(i);
    int right = right_child(i);

    if (left < heap->size && heap->data[left] < heap->data[min_index]) {
        min_index = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[min_index]) {
        min_index = right;
    }

    if (min_index != i) {
        int tmp = heap->data[i];
        heap->data[i] = heap->data[min_index];
        heap->data[min_index] = tmp;
        sift_down_min(heap, min_index);
    }
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

    int popped = array->data[0];
    for (int i = 0; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;

    return popped;
}

int remove_min(DynamicArray *heap) {
    int popped = pop_front_dynamic_array(heap);
    sift_down_min(heap, 0);
    return popped;
}

void free_dynamic_array(DynamicArray *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void insert_min(DynamicArray *heap, int element) {
    push_back_dynamic_array(heap, element);
    sift_up_min(heap, heap->size - 1);
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
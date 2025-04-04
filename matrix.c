#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix init_matrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

void print_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d", matrix.data[i][j]);
            if (j < matrix.cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
    matrix.data = NULL;
    matrix.rows = 0;
    matrix.cols = 0;
}

Matrix copy_matrix(Matrix original) {
    Matrix copy = init_matrix(original.rows, original.cols);

    for (int i = 0; i < original.rows; i++) {
        for (int j = 0; j < original.cols; j++) {
            copy.data[i][j] = original.data[i][j];
        }
    }

    return copy;
}
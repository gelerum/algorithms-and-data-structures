#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix init_matrix(int rows, int cols);
void print_matrix(Matrix matrix);
void free_matrix(Matrix matrix);
Matrix copy_matrix(Matrix original);

#endif
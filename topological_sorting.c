#include "matrix.h"
#include <stdbool.h>

int *kahns_algorithm(Matrix adjacency_matrix) {
    int *ordered_vertices = (int *)malloc(adjacency_matrix.rows * sizeof(int));
    int t = 0;
    int *in_degree = (int *)calloc(adjacency_matrix.rows, sizeof(int));

    for (int i = 0; i < adjacency_matrix.rows; i++) {
        for (int j = 0; j < adjacency_matrix.cols; j++) {
            if (adjacency_matrix.data[i][j]) {
                in_degree[j]++;
            }
        }
    }

    bool found;
    while (t < adjacency_matrix.rows) {
        found = false;
        for (int i = 0; i < adjacency_matrix.rows; i++) {
            if (in_degree[i] == 0) {
                ordered_vertices[t++] = i;
                in_degree[i] = -1;
                found = true;

                for (int j = 0; j < adjacency_matrix.cols; j++) {
                    if (adjacency_matrix.data[i][j]) {
                        in_degree[j]--;
                    }
                }
                break;
            }
        }
        if (!found) {
            free(ordered_vertices);
            free(in_degree);
            return NULL;
        }
    }

    free(in_degree);
    return ordered_vertices;
}
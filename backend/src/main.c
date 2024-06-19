#include <stdio.h>
#include <stdlib.h>
#include "logistic-regression.h"
#include "matrix-op.h"
#define EPOCHS 10000

void print_matrix(double* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main(){
    int n_rows = 4;
    int n_cols = 3;

    double X[] = {1.0, 2.0, 3.0, 1.0, 3.0, 3.0, 1.0, 4.0, 3.0, 1.0, 5.0, 3.0};
    double y[] = {0, 0, 1, 1};
    double initial_params[] = {0.0, 0.0, 0.0};

    // Normalizando X para valores entre 0 e 1
    for(int i = 0; i < n_rows * n_cols; i++) {
        X[i] /= 5.0;
    }

    double *params = fit(X, y, initial_params, n_cols, n_rows, 10);

    return 0;
}

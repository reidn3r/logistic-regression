#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/logistic-regression.h"
#include "../include/matrix-op.h"

double* sigmoid(double *z, int size){
    double* out = malloc(size * sizeof(double));
    for(int i = 0; i < size; i++){
        out[i] = 1.0 / (1.0 + exp(-z[i]));
    }
    return out;
}

double* gradient(double *X, double *y, double *y_hat, int n_rows, int n_cols){
    double *array_diff = subtract(y, y_hat, n_rows);
    double *out = multiply_mat(X, array_diff, n_rows, n_cols);
    for(int i = 0; i < n_cols; i++){
        out[i] /= -n_rows;
    }
    free(array_diff);
    return out;
}

double logloss(double *y, double *y_hat, int size){
    double sum = 0.0;
    for(int i = 0; i < size; i++){
        sum += y[i] * log(y_hat[i]) + ((1 - y[i]) * log(1 - y_hat[i]));
    }
    return -sum / size;
}

double* update_params(double* current_params, double* gradient, int size){
    for(int i = 0; i < size; i++){
        current_params[i] -= LR * gradient[i];
    }
    return current_params;
}

double* fit(double* X, double* y, double* params, int n_cols, int n_rows, int epochs){
    for(int i = 0; i < epochs; i++){
        double *z = multiply_mat(X, params, n_rows, n_cols);
        double *y_hat = sigmoid(z, n_rows);
        double *computed_gradient = gradient(X, y, y_hat, n_rows, n_cols);
        double* updated_params = update_params(params, computed_gradient, n_cols);
        params = updated_params;

        free(z);
        free(y_hat);
        free(computed_gradient);
    }
    return params;
}

double* predict(double *X, double* params, int n_rows, int n_cols){
    double* z = multiply_mat(X, params, n_rows, n_cols);
    double* y_hat = sigmoid(z, n_rows);
    free(z);
    return y_hat;
}

void hello(){
    printf("Hello, world");
}

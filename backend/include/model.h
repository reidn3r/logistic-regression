#ifndef MODEL_H
#define MODEL_H

double* sigmoid(double *z, int size);

double* gradient(double *X, double *y, double *y_hat, int n_rows, int n_cols);

double logloss(double *y, double *y_hat, int size);

int early_stopper(double* best_loss, double current_loss, double min_delta, int patience, int* current_iteration, double* best_params);

double* fit(double* X, double* y, double*params, int n_cols, int n_rows, int epochs);

double* update_params(double* current_params, double* gradient, int size);

double* predict(double *X, double* params, int n_rows, int n_cols);

void hello();

#endif
#include <stdio.h>
#include <stdlib.h>
#include "logistic-regression.h"
#include "product.h"

int main(){
    double X[] = {3, 4, 5, 6};
    double y[] = {1, 2};
    // double X[] = {1, 2, 3, 4};
    // double y[] = {5, 6};


    double* mm = multiply_matrix_1Darray(X, y, 2, 2);

    for (int i = 0; i < 2; i++) {
        printf("%f ", mm[i]);
    }

    free(mm);
    return 0;
}
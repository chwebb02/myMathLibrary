#ifndef MATRIX_ARITHMETIC
#define MATRIX_ARITHMETIC

#include "matrixDef.h"
#include "matrix.h"

#include <stdlib.h>

// Checks error conditions for matrix operations
Matrix *checkConditions(Matrix *A, Matrix *B) {
    if (A->dimc != B->dimc)
        return NULL;
    
    for (int i = 0; i < A->dimc; i++) {
        if (A->dimensions[i] != B->dimensions[i])
            return NULL;
    }

    Matrix *output = newMatrix(A->dimc, A->dimensions);
    if (output == NULL)
        return NULL;
    
    return output;
}

Matrix *M_add(Matrix *A, Matrix *B) {
    Matrix *output = checkConditions(A, B);
    if (output == NULL)
        return NULL;

    for (int i = 0; i <= A->max; i++) {
        output->matrix[i] = A->matrix[i] + B->matrix[i];
    }

    return output;
}

Matrix *M_subtract(Matrix *A, Matrix *B) {
    Matrix *output = checkConditions(A, B);
        if (output == NULL)
            return NULL;
        
    for (int i = 0; i <= A->max; i++) {
        output->matrix[i] = A->matrix[i] - B->matrix[i];
    }

    return output;
}

#endif
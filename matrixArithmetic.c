#ifndef MATRIX_ARITHMETIC
#define MATRIX_ARITHMETIC

#include "matrix.h"
#include "matrixDef.h"

#include <stdlib.h>

Matrix *M_add(Matrix *A, Matrix *B) {
    if (A->dimc != B->dimc)
        return NULL;
    
    for (int i = 0; i < A->dimc; i++) {
        if (A->dimensions[i] != B->dimensions[i])
            return NULL;
    }

    Matrix *output = newMatrix(A->dimc, A->dimensions);
    if (output == NULL)
        return NULL;

    for (int i = 1; i <= A->max; i++) {
        output->matrix[i] = A->matrix[i] + B->matrix[i];
    }

    return output;
}

#endif
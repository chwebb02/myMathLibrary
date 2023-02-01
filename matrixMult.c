#ifndef MATRIX_MULT
#define MATRIX_MULT

#include "matrix.h"
#include "matrixDef.h"

#include <stdlib.h>

// Matrix multiplication in n-dimensions
Matrix *M_mult_ndim(Matrix *A, Matrix *B) {
    return NULL;
}

// Matrix multiplication in 2 or less dimensions
Matrix *M_mult(Matrix *A, Matrix *B) {
    if (A == NULL || B == NULL)
        return NULL;
    
    if (A->dimc > 2 || B->dimc > 2)
        return M_mult_ndim(A, B);
    
    // Check that the number of columns in A are equal to the number of rows in B
    if (A->dimensions[1] != B->dimensions[0])
        return NULL;
    
    Matrix *output = newMatrix(2, (unsigned int []){A->dimensions[0], B->dimensions[1]});
    if (output == NULL)
        return NULL;

    // Iterate over each element of the output matrix
    for (int outputRow = 1; outputRow <= output->dimensions[0]; outputRow++) {
        for (int outputColumn = 1; outputColumn <= output->dimensions[1]; outputColumn++) {
            int element = 0;
            
            for (int cursor = 1; cursor <= A->dimensions[1]; cursor++) {
                element += M_getElement(A, (unsigned int []) {outputRow, cursor}) * \
                           M_getElement(B, (unsigned int []) {cursor, outputColumn});
            }

            M_setElement(output, (unsigned int []){outputRow, outputColumn}, element);
        }
    }

    return output;
}

#endif
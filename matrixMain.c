#ifndef MATRIX_MAIN
#define MATRIX_MAIN

#include "matrix.h"
#include "matrixDef.h"

#include <stdlib.h>

/*
    Translates from:
        1 6 7 9 2       5 7 8 9 2
        1 5 2 3 1       9 8 7 6 3
        2 5 3 2 1       9 2 3 2 6
        5 8 0 9 2       9 0 1 0 3
    [2][2][1] = 5      [4][3][2] = 1
    To:
        1 1 2 5 6 5 5 8 7 2 3 0 9 3 2 9 2 1 1 2 5 9 9 9 7 8 2 0 8 7 3 1 9 6 2 0 2 3 6 3
    [6] = 5         [31] = 1

    i.e. [2][2][1] (4 x 5 x 2) = [6] (1 dimensional)
         [4][3][1] (4 x 5 x 2) = [31] (1 dimensional)

*/
inline
unsigned long translate(Matrix *input, unsigned int *location) {
    if (input == NULL)
        return ULONG_MAX;
    
    if (location == NULL)
        return input->max + 1;
    
    unsigned long output = location[0] - 1;

    // Apply offset for dimensions > 1
    for (int i = 1; i < input->dimc; i++) {
        unsigned long offset = 1;

        for (int j = i; j > 0; j--) {
            offset *= input->dimensions[j - 1];
        }

        output += offset * (location[i] - 1);
    }

    return output;
}

Matrix *newMatrix(unsigned int dimc, unsigned int *dimensions) {
    Matrix *output = malloc (sizeof(Matrix));
    if (output == NULL)
        return NULL;
    
    // Allocate the size array of the Matrix
    output->dimensions = malloc (dimc * sizeof(unsigned int));
    if (output->dimensions == NULL) {
        free(output);
        return NULL;
    }
    
    // Assign the dimensions and max to the matrix struct
    output->dimc = dimc;
    output->max = 1;
    for (int i = 0; i < dimc; i++) {
        output->dimensions[i] = dimensions[i];
        output->max *= dimensions[i];
    }

    output->matrix = malloc (output->max * sizeof(int));
    if (output->matrix == NULL) {
        free(output->dimensions);
        free(output);
        return NULL;
    }
    output->max -= 1;

    return output;
}

int M_setElement(Matrix *mat, unsigned int *location, int value) {
    if (mat == NULL)
        return 1;
    
    unsigned long loc = translate(mat, location);
    if (loc > mat->max)
        return 2;
    
    mat->matrix[loc] = value;
    return 0;
}

int M_getElement(Matrix *mat, unsigned int *location) {
    if (mat == NULL)
        return 0;
    
    unsigned long loc = translate(mat, location);
    if (loc > mat->max)
        return 0;
    
    return mat->matrix[loc];
}

int M_getDimensionCount(Matrix *mat) {
    if (mat == NULL)
        return -1;
    
    return mat->dimc;
}

int M_getDimension(Matrix *mat, unsigned int dimension) {
    if (mat == NULL)
        return -1;
    
    return mat->dimensions[dimension - 1];
}

int M_assignMatrix2D(Matrix *input, int **array) {
    if (input == NULL || array == NULL)
        return 1;

    for (int row = 1; row <= input->dimensions[0]; row++) {
        for (int column = 1; column <= input->dimensions[1]; column++) {
            M_setElement(input, (unsigned int []){row, column}, array[row - 1][column - 1]);
        }
    }

    return 0;
}

#endif
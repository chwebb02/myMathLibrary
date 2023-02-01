#ifndef MATRIX_DEF
#define MATRIX_DEF 1

#include "matrix.h"

struct matrixStruct {
    int *matrix;                // The arrray that stores the matrix
    unsigned int *dimensions;   // Size of each dimension of the array
    unsigned int *dimOffsets;   // Offsets for unidimensional representation conversions
    unsigned int dimc;          // Number of dimensions of the array
    unsigned long max;          // Index of the last element for the single-dimensional representation
};

// Returns the integer for the location of an
// element in the matrix given its representation
// in multi-dimensional notation
unsigned long translate(Matrix *, unsigned int *);

#endif

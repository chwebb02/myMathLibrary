#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrixStruct Matrix;

// Create a new Matrix
// Takes number of dimensions and size of each dimension as input
// Returns a pointer to the Matrix if successful, NULL if unsuccessful
Matrix *newMatrix(unsigned int dimensionCount, unsigned int *dimensions);

// Getters and setters for matrix elements on an existing matrix
int M_setElement(Matrix *matrix, unsigned int *location, int value);    // Returns 0 if successful, or 1 if error
int M_getElement(Matrix *matrix, unsigned int *location);               // Returns element if successful, or 0 if error

// Getters for matrix dimensions
// Returns the value if successful, or -1 if unsuccessful
int M_getDimensionCount(Matrix *matrix);
int M_getDimension(Matrix *matrix, unsigned int dimension);

// Translates a two-dimensional array into a two dimensional matrix
// Takes an existing matrix as input, array must be equal to size of the matrix
// Returns 0 if successful, or nonzero to indicate an error
int M_assignMatrix2D(Matrix *matrix, int **array);

// Add and Subtract
// Returns the resultant matrix if successful, or NULL if an error
Matrix *M_add(Matrix *A, Matrix *B);
Matrix *M_subtract(Matrix *A, Matrix *B);

Matrix *M_transpose(Matrix *m_in);

// Multiply two matrices and return the resultant matrix
Matrix *M_mult(Matrix *A, Matrix *B);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

int main() {
    Matrix *A = newMatrix(2, (unsigned int []) {5, 5}), \
           *B = newMatrix(2, (unsigned int []) {5, 5});
    if (A == NULL || B == NULL) {
        printf("Allocation error!\n");
        return 1;
    }

    int **arrayA = malloc(5 * sizeof(int *)), \
        **arrayB = malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; i++) {
        arrayA[i] = malloc (5 * sizeof(int));
        arrayB[i] = malloc (5 * sizeof(int));

        for (int n = 0; n < 5; n++) {
            arrayA[i][n] = rand() % 10;
            arrayB[i][n] = rand() % 10;
        }
    }

    M_assignMatrix2D(A, arrayA);
    M_assignMatrix2D(B, arrayB);

    printf("assignMatrix2D test:\nA:\n");
    for (int row = 1; row <= M_getDimension(A, 1); row++) {
        for (int column = 2; column <= M_getDimension(A, 2); column++) {
            printf("%d ", M_getElement(A, (unsigned int []) {row, column}));
        } 
        printf("\n");
    }

    printf("\nB:\n");
    for (int row = 1; row <= M_getDimension(B, 1); row++) {
        for (int column = 2; column <= M_getDimension(B, 2); column++) {
            printf("%d ", M_getElement(B, (unsigned int []) {row, column}));
        } 
        printf("\n");
    }

    Matrix *C = M_add(A, B);

    printf("\n\nM_add test:\n");
    for (int row = 1; row <= M_getDimension(C, 1); row++) {
        for (int column = 2; column <= M_getDimension(C, 2); column++) {
            printf("%d ", M_getElement(C, (unsigned int []) {row, column}));
        } 
        printf("\n");
    }


    return 0;
}
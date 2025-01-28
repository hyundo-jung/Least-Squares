#include <stdio.h>
#include <stdlib.h>

#include "matrixoperation.c"

int main(void)
{
    int A_rows, A_cols;

    printf("Dimension of Matrix A: ");

    scanf("%d %d", &A_rows, &A_cols);

    printf("Verifying the dimension of Matrix A: %d X %d \n\n", A_rows, A_cols); 

    int* matrixA = malloc(sizeof(int) * A_rows * A_cols);

    int i, j, value;

    for (i = 0; i < A_rows; i++)
    {
        printf("Entry for Row %d: \n", i+1);
        for (j = 0; j < A_cols; j++)
        {
            printf("Element %d: ", i*A_cols + j + 1);
            scanf("%d", &matrixA[i*A_cols + j]);
        }
        printf("\n");
    }

    printf("Matrix A: \n");
    printMatrix(matrixA, A_rows, A_cols);

    int* matrixA_transpose = copyMatrix(matrixA, A_rows, A_cols);
    int At_rows = A_rows, At_cols = A_cols;

    matrixA_transpose = transpose(matrixA_transpose, At_rows, At_cols);
    At_rows = A_cols, At_cols = A_rows;

    printf("Matrix A transposed: \n");
    printMatrix(matrixA_transpose, At_rows, At_cols);

    int* bCol = malloc(sizeof(int) * A_rows);

    printf("Entry for b column: \n");
    for (i = 0; i < A_rows; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &bCol[i]);
    }
    printf("\n");
    
    int * test = addZeroColum(matrixA, A_rows, A_cols, bCol);

    printf("Combined Matrix: \n");
    printMatrix(test, A_rows, A_cols + 1);

    int* resultMatrix = multiplication(matrixA, A_rows, A_cols, matrixA_transpose, At_rows, At_cols);

    printf("After multiplication method: \n");
    printMatrix(resultMatrix, A_rows, At_cols);

    free(matrixA);
    free(bCol);
    free(matrixA_transpose);
    free(resultMatrix);
    return 0;
}

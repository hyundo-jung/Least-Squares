#include <stdio.h>
#include <stdlib.h>

void printMatrix(int* matrix, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", matrix[i*col + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int* copyMatrix(int *matrix, int row, int col)
{
    int* two_d_array;
    int i, j;
    two_d_array = malloc(sizeof(int) * row * col);

    if (two_d_array == NULL)
    {
        printf("ERROR: malloc failed! \n");
        exit(1);
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            // one of two method to dynamically allocate 2D array
            two_d_array[i*col + j] = matrix[i*col + j];
        }
    }
    return two_d_array;
} 

int* transpose(int* matrix, int rows, int cols)
{
    int* transposeMatrix = malloc(sizeof(int) * cols * rows);
    int i, j, temp;


    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            transposeMatrix[i + rows*j] = matrix[i*cols + j];
        }
    }

    return transposeMatrix;
}

int* multiplication(int *matrix1, int rows1, int cols1, int *matrix2, int rows2, int cols2)
{
    int* resultMatrix;
    int i, j, k, value, idx = 0;
    resultMatrix = malloc(sizeof(int) * rows1 * cols2);

    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            value = 0;
            for (k = 0; k < rows2; k++)
            {
                value += matrix1[i*cols1 + k] * matrix2[j + k*cols2];
            }
            resultMatrix[i*cols2 + j] = value;
        }
    }

    return resultMatrix;
}

int* addZeroColum(int *matrix, int row, int col, int* endCol)
{
    int* newMatrix;
    int i, j, n = 0;

    newMatrix = malloc(sizeof(int) * row * (col + 1));

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col + 1; j++)
        {
            if (j == col)
            {
                newMatrix[i*(col + 1) + j] = endCol[n];
                n++;
            }
            else
            {
                newMatrix[i*(col + 1) + j] = matrix[i*col + j];
            }
        }
    }

    return newMatrix;
}

void inverse(int *matrix, int rows, int cols);

void exchange(int *matrix, int row1, int row2, int col)
{
    int arr[col];
    int i, j;

    for (i = 0; i < col; i++)
    {
        arr[i] = matrix[(row1 - 1)*col + i];
        matrix[(row1-1)*col + i] = matrix[(row2 - 1)*col + i];
    }

    for (i = 0; i < col; i++)
    {
        matrix[(row2 - 1)*col + i] = arr[i];
    }

    return;
}

void mult(int *matrix, double d, int row, int col)
{
    int i;

    for (i = 0; i < col; i++)
    {
        matrix[(row-1)*col + i] *= d;
    }

    return;
}

void add(int *matrix, double d, int row1, int row2, int col)
{
    int i;

    for (i = 0; i < col; i++)
    {
        matrix[(row1 - 1)*col + i] += d * matrix[(row2 - 1)*col + i];
    }

    return;
}

// int* rref(int *matrix, int row, int col)
// {

// }

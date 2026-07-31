#include <stdio.h>

#define MAX 10

// Function Prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols);

int main()
{
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX], transpose[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("\n====================================\n");
    printf("      MATRIX OPERATIONS PROGRAM\n");
    printf("====================================\n");

    printf("\nEnter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("\nEnter elements of Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("\nEnter elements of Matrix B:\n");
    inputMatrix(B, r2, c2);

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Display Matrices\n");
        printf("2. Matrix Addition\n");
        printf("3. Matrix Multiplication\n");
        printf("4. Transpose of Matrix A\n");
        printf("5. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nMatrix A:\n");
                displayMatrix(A, r1, c1);

                printf("\nMatrix B:\n");
                displayMatrix(B, r2, c2);
                break;

            case 2:
                if(r1 == r2 && c1 == c2)
                {
                    addMatrices(A, B, result, r1, c1);

                    printf("\nAddition Result:\n");
                    displayMatrix(result, r1, c1);
                }
                else
                {
                    printf("\nAddition is not possible.");
                    printf("\nMatrices must have same dimensions.\n");
                }
                break;

            case 3:
                if(c1 == r2)
                {
                    multiplyMatrices(A, B, result, r1, c1, c2);

                    printf("\nMultiplication Result:\n");
                    displayMatrix(result, r1, c2);
                }
                else
                {
                    printf("\nMultiplication is not possible.");
                    printf("\nColumns of Matrix A must equal Rows of Matrix B.\n");
                }
                break;

            case 4:
                transposeMatrix(A, transpose, r1, c1);

                printf("\nTranspose of Matrix A:\n");
                displayMatrix(transpose, c1, r1);
                break;

            case 5:
                printf("\nThank you for using the program.\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}

// Function to Input Matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to Display Matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for Matrix Addition
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for Matrix Multiplication
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2)
{
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for Matrix Transpose
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}
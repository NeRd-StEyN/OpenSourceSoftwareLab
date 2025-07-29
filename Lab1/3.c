#include <stdio.h>

#define MAX 10  // Maximum matrix size

void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Matrix is:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = matrix[i][j];  // Transposing the matrix
        }
    }
}

int main() {
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int row, col;

    // Read the number of rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    // Input matrix elements
    inputMatrix(matrix, row, col);

    // Print original matrix
    printf("Original Matrix:\n");
    printMatrix(matrix, row, col);

    // Get transpose of the matrix
    transposeMatrix(matrix, transpose, row, col);

    // Print transposed matrix
    printf("Transpose Matrix:\n");
    printMatrix(transpose, col, row);  // Transposed matrix has swapped dimensions

    return 0;
}

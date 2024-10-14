/*
Noah Haskins
3094077
Lab 5
10/13/2024
*/

#include <stdio.h>   // Include the standard input-output library
#include <stdbool.h> // Include the boolean library for future extensions if needed

#define SIZE 5  // Define the size of matrices, making it easy to modify in the future

// Function Prototypes
void addMatrices(int result[SIZE][SIZE], int m1[SIZE][SIZE], int m2[SIZE][SIZE]);  // Adds two matrices
void multiplyMatrices(int result[SIZE][SIZE], int m1[SIZE][SIZE], int m2[SIZE][SIZE]);  // Multiplies two matrices
void transposeMatrix(int result[SIZE][SIZE], int matrix[SIZE][SIZE]);  // Computes the transpose of a matrix
void printMatrix(int matrix[SIZE][SIZE]);  // Prints the matrix in a readable format

int main() {
    // Define two 5x5 sample matrices for testing
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // Initialize matrices to store results of operations
    int sum[SIZE][SIZE];      // Matrix to store the sum of m1 and m2
    int product[SIZE][SIZE];  // Matrix to store the product of m1 and m2
    int transpose[SIZE][SIZE]; // Matrix to store the transpose of m1

    // Perform and display matrix addition
    printf("Matrix 1:\n");
    printMatrix(m1);  // Print the first matrix
    printf("Matrix 2:\n");
    printMatrix(m2);  // Print the second matrix

    addMatrices(sum, m1, m2);  // Compute the sum of m1 and m2
    printf("Sum of matrices:\n");
    printMatrix(sum);  // Print the result of the addition

    // Perform and display matrix multiplication
    multiplyMatrices(product, m1, m2);  // Compute the product of m1 and m2
    printf("Product of matrices:\n");
    printMatrix(product);  // Print the result of the multiplication

    // Perform and display transpose of the first matrix
    transposeMatrix(transpose, m1);  // Compute the transpose of m1
    printf("Transpose of Matrix 1:\n");
    printMatrix(transpose);  // Print the transpose

    return 0;  // End of the program
}

// Function to add two matrices
void addMatrices(int result[SIZE][SIZE], int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    // Iterate over each element of the matrices
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Add corresponding elements from m1 and m2
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int result[SIZE][SIZE], int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    // Initialize the result matrix to zero to avoid garbage values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < SIZE; i++) {  // Loop through rows of m1
        for (int j = 0; j < SIZE; j++) {  // Loop through columns of m2
            for (int k = 0; k < SIZE; k++) {  // Loop through elements in the row/column pair
                result[i][j] += m1[i][k] * m2[k][j];  // Accumulate the product
            }
        }
    }
}

// Function to compute the transpose of a matrix
void transposeMatrix(int result[SIZE][SIZE], int matrix[SIZE][SIZE]) {
    // Swap rows and columns
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];  // Assign the element at (i, j) to (j, i)
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    // Iterate over the rows of the matrix
    for (int i = 0; i < SIZE; i++) {
        // Iterate over the columns of the matrix
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);  // Print each element with some padding for alignment
        }
        printf("\n");  // Move to the next line after each row
    }
    printf("\n");  // Add a blank line for better readability
}

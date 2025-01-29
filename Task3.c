#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));  // Allocate memory for rows
    if (matrix == NULL) {
        printf("Memory allocation failed for rows\n");
        return 1;                                           // memory allocation fails
    }

    for (int i = 0; i < rows; i++) {                    // Allocate memory for columns in each row
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for columns in row %d\n", i);
            return 1;                               //  memory allocation fails
        }
    }

    int value = 1;                                 // Initialize the matrix with sequential numbers starting from 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }

    printf("\nThe matrix is:\n");                   // Print the 3x3 matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

                            
    for (int i = 0; i < rows; i++) {                       // Step 5: Free the allocated memory
        free(matrix[i]);                                    // Free each row
    }
    free(matrix);                                       // Free the main array holding row pointers

    printf("\nMemory has been freed.\n");

    return 0;
}

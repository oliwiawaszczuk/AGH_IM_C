#include <stdio.h>
#include<stdlib.h>

int main2() {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int** matrix = malloc(rows * sizeof(int*));

    for (int i=0; i<rows; i++)
        matrix[i] = malloc(cols*sizeof(int));

    int counter = 1;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j] = counter;
            counter++;
        }
    }

    // Macierz wyświetlana normalnie
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }

    printf("\n");
    // Transponowanie macierzy
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++)
            printf("%d ",matrix[j][i]);
        printf("\n");
    }

    for (int i=0; i<rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
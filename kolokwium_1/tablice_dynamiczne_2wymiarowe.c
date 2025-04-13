#include <stdio.h>
#include<stdlib.h>

int main1() {
    int row, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &cols);

    int** matrix = malloc(row * sizeof(int*));

    for (int i=0; i<row; i++)
        matrix[i] = malloc(cols*sizeof(int));

    int counter = 1;
    for (int i=0; i<row; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j] = counter;
            counter++;
        }
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<row; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
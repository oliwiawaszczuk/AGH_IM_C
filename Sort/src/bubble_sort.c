#include <stdio.h>

#include "sort.h"

void bubble_sort(int *array, int size) {


    printf("\n");

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    printf("Tablica pp posortowaniem : ");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);

        }
    }

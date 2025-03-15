#include <stdio.h>
#include "sort.h"

int main() {
    int n,temp,wybor;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d: ", &temp);
        arr[i] = temp;
    }
    printf("1-Babelkowe \n 2-Quicksort \n 3-Insertionsort \n 4-Mergesort \n Wybierz sposob sortowania \n");
    scanf("%d", &wybor);
    switch (wybor) {
        case 1: bubble_sort(arr,n);
        break;
        case 2: quick_sort(arr,n);
        break;
        case 3: insertion_sort(arr,n);
        break;
        case 4:
            merge_sort(arr,n);
            break;
        default:
            printf("Wrong wybor \n");
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main3() {
    srand(time(NULL));
    int v1 = rand() % 100;         // [0 - 99]
    int v2 = rand() % 100 + 1;     // [1 - 100]
    int v3 = rand() % 30 + 1985;   // [1985 - 2014]

    return 0;
}

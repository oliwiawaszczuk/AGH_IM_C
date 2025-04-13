#include <stdio.h>

int main4() {
    FILE *file = fopen("test.txt", "w");
    fprintf(file, "Wprowadzamy jakiś tekst\nA tutaj kolejny");
    fclose(file);

    FILE *file2 = fopen("test.txt", "r");
    char myString[100];

    while(fgets(myString, 100, file2)) {
        printf("%s", myString);
    }
    fclose(file2);

    return 0;
}

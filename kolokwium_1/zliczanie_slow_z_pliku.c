#include <stdio.h>

// TREŚĆ: Policz ile jest słów "Ala" w historyjka.txt
int main() {
    FILE *file = fopen("/Users/praoliwia/Desktop/Code/c/AGH/kolokwium_1/historyjka.txt", "r");

    char lf[] = "Ala";
    int counter_slow = 0;
    char str[100];
    while (fgets(str, 100, file)) {
        int temp = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == lf[temp]) {
                printf("%c %c %d\n", str[i], lf[temp], temp);
                temp++;
            } else {
                temp = 0;
            }

            if (temp == sizeof(lf)/sizeof(char)-1) {
                counter_slow++;
                temp = 0;
            }
        }
    }

    printf("Tyle naliczono słów '%s' : %d\n", lf, counter_slow);

    fclose(file);
    return 0;
}

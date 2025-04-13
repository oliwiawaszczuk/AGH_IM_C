#include <stdio.h>

struct Pacjent {
    char imie[30];
    int wiek;
};

int main() {
    struct Pacjent pacjent1 = {"Adam", 22};
    struct Pacjent pacjent2 = {"Agata", 11};

    struct Pacjent pacjenci[] = {pacjent1, pacjent2};
    int liczba_pacjentow = sizeof(pacjenci)/sizeof(struct Pacjent);

    int sum_wiek = 0;
    for (int i = 0; i < liczba_pacjentow; i++) {
        printf("%d: %s %d\n", i+1, pacjenci[i].imie, pacjenci[i].wiek);
        sum_wiek += pacjenci[i].wiek;
    }

    float srednia_wiek = (float)sum_wiek / (float)liczba_pacjentow;
    printf("Średnia wieku u pacjentów: %.2f", srednia_wiek);

    return 0;
}

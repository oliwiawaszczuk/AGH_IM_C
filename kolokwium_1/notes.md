### 0. Mega ważne
1. printf
```c
int items = 50;
float cost_per_item = 9.99;
float total_cost = items * cost_per_item;
char currency = '$';

printf("Total cost = %.2f %c\n", total_cost, currency); //Total cost = 499.50 $
```

| Format | Typ    | Przykład |
| ------ | ------ | -------- |
| %d     | int    | 44       |
| %f     | float  | 5.440100 |
| %.2f   | float  | 5.44     |
| %c     | char   | 'R'      |
| %s     | string | "pra"    |
```c
// tworzenie stringa
// jakieś biblioteki?
// pointers
```

### 1. Tworzenie tablicy dynamicznej 2-wymiarowej
```c
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

// Macierz wyświetlana normalnie
for (int i=0; i<row; i++) {  
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

for (int i=0; i<row; i++)  
    free(matrix[i]);  
free(matrix);
```
> Co nam daje wynik:
```txt
Enter number of rows and columns: 3 3
1 2 3 
4 5 6 
7 8 9 
```

### 2. Losowość
```c
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
int main() {  
    srand(time(NULL));  
    int v1 = rand() % 100;         // [0 - 99]  
    int v2 = rand() % 100 + 1;     // [1 - 100]  
    int v3 = rand() % 30 + 1985;   // [1985 - 2014]  
  
    return 0;  
}
```

### 3. Pliki
```c
#include <stdio.h>  
  
int main() {  
    FILE *file = fopen("test.txt", "w");  
    fprintf(file, "Wprowadzamy jakiś tekst\nA tutaj kolejny");  
    fclose(file);  
  
    FILE *file2 = fopen("test.txt", "r");  
    char myString[100];  
  
    while(fgets(myString, 100, file2))
        printf("%s", myString);  
    
    fclose(file2);  
  
    return 0;  
}
```


---
#### ZADANIA
1. Policz ile jest słów "Ala" w historyjka.txt
> historyjka.txt
```txt
Ala ma kota. Kot ma na imię Filemon.  
Filemon to bardzo sprytny kot, który lubi mleko i spać na parapecie.  
Ala często głaszcze kota i mówi: "Filemon, jesteś najlepszym kotem!"  
  
Pewnego dnia Filemon zniknął. Ala była smutna.  
Na szczęście kot wrócił po dwóch dniach. Ufff!  
  
Od tego czasu Ala i Filemon są nierozłączni.
```
> Cały kod:
```c
#include <stdio.h>  
  
int main() {  
    FILE *file = fopen("historyjka.txt", "r");  
  
    char lf[] = "Ala";  
    int counter_slow = 0;  
    char str[100];  
    while (fgets(str, 100, file)) {  
        int temp = 0;  
        for (int i = 0; str[i] != '\0'; i++) {  
            if (str[i] == lf[temp])
                temp++;  
            else 
                temp = 0;  
            
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
```
> Wynik:
```txt
Tyle naliczono słów 'Ala' : 4
```

---

2. Stwórz listę pacjentów oraz oblicz ich średni wiek
> Przykładowe rozwiązanie
```c
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
```
> Wynik:
```txt
1: Adam 22
2: Agata 11
Średnia wieku u pacjentów: 16.50
```
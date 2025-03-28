#include <stdio.h>

int main(int argc, char *argv[]) {
    const char *file_name = argv[1];
    const char *output_file_name = argv[2];
    const char key = argv[3][0];

    FILE *file = fopen(file_name, "r");
    FILE *output_file = fopen(output_file_name, "w");

    if (file == NULL || output_file == NULL) {
        printf("Błąd otwierania pliku wejściowego: No such file or directory\n");
        return 1;
    }

    printf("Szyfrowanie / deszyfrowanie pliku: %s -> %s z kluczem '%c'\n", file_name, output_file_name, key);

    int chr;
    while ((chr = fgetc(file)) != EOF) {
        char encrypted_char = chr ^ key;
        fputc(encrypted_char, output_file);
        printf("%c -> %c\n", chr, encrypted_char);
    }

    printf("Operacja zakończona. Wynik zapisano w pliku: %s\n", output_file_name);

    fclose(file);
    fclose(output_file);
    return 0;
}
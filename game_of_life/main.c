#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARDSIZE_H 10
#define BOARDSIZE_W 50

// v1 = rand() % 100;         // [0 - 99]
// v2 = rand() % 100 + 1;     // [1 - 100]
// v3 = rand() % 30 + 1985;   // [1985 - 2014]
// usleep(500000);

// O – oznacza komórkę żywą
// . – oznacza komórkę martwą

void print_board(char board[BOARDSIZE_H][BOARDSIZE_W]) {
    for (int i = 0; i < BOARDSIZE_H; i++) {
        for (int j = 0; j < BOARDSIZE_W; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

int get_number_of_neighbours(char board[BOARDSIZE_H][BOARDSIZE_W], int x_point, int y_point) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int new_x_point = x_point + j;
            int new_y_point = y_point + i;

            if (new_x_point >= 0 && new_x_point < BOARDSIZE_W && new_y_point >= 0 && new_y_point < BOARDSIZE_H)
                if (board[new_y_point][new_x_point] == 'O')
                    count++;
        }
    }

    return count;
}

void check_board(char board[BOARDSIZE_H][BOARDSIZE_W]) {
    char new_board[BOARDSIZE_H][BOARDSIZE_W];

    for (int i = 0; i < BOARDSIZE_H; i++)
        for (int j = 0; j < BOARDSIZE_W; j++)
            new_board[i][j] = board[i][j];

    for (int i = 0; i < BOARDSIZE_H; i++) {
        for (int j = 0; j < BOARDSIZE_W; j++) {
            int neighbours = get_number_of_neighbours(new_board, j, i);

            if (board[i][j] == 'O') {
                if (neighbours != 2 && neighbours != 3)
                    new_board[i][j] = '.';
            } else {
                if (neighbours == 3)
                    new_board[i][j] = 'O';
            }
        }
    }

    for (int i = 0; i < BOARDSIZE_H; i++)
        for (int j = 0; j < BOARDSIZE_W; j++)
            board[i][j] = new_board[i][j];
}

int main(void) {
    srand(1234);
    int start_cell_count, how_many_years;
    char board[BOARDSIZE_H][BOARDSIZE_W];

    for (int i = 0; i < BOARDSIZE_H; i++)
        for (int j = 0; j < BOARDSIZE_W; j++)
            board[i][j] = '.';

    printf("Podaj liczbę początkowych żywych komórek: ");
    scanf("%d", &start_cell_count);

    printf("Podaj liczbę lat (iteracji): ");
    scanf("%d", &how_many_years);

    int x, y;
    while (start_cell_count > 0) {
        x = rand() % BOARDSIZE_H;
        y = rand() % BOARDSIZE_W;
        if (board[x][y] == '.') {
            board[x][y] = 'O';
            start_cell_count--;
        }
    }

    for (int i = 0; i <= how_many_years; i++) {
        if (i > 0)
            check_board(board);

        printf("Rok %d:\n", i);
        print_board(board);
        usleep(500000);
    }

    return 0;
}
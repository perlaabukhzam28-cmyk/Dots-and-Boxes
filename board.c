#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void init_game(Game *g) {
    int row, col;
    for (row = 0; row <= ROWS; row++)
        for (col = 0; col < COLS; col++)
            g->hlines[row][col] = 0;
    for (row = 0; row < ROWS; row++)
        for (col = 0; col <= COLS; col++)
            g->vlines[row][col] = 0;
    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            g->owner[row][col] = ' ';
    g->score[0] = 0;
    g->score[1] = 0;
    g->current = 0;
    g->boxes_claimed = 0;
}

void print_board(const Game *g) {
    int r, c;
    printf("\n  ");
    for (c = 0; c <= COLS; c++)
        printf("%d ", c);
    printf("\n");
    for (r = 0; r <= ROWS; r++) {
        printf("%d ", r);
        for (c = 0; c <= COLS; c++) {
            printf(".");
            if (c < COLS)
                printf("%c", g->hlines[r][c] ? '-' : ' ');
        }
        printf("\n");
        if (r < ROWS) {
            printf("  ");
            for (c = 0; c <= COLS; c++) {
                printf("%c", g->vlines[r][c] ? '|' : ' ');
                if (c < COLS)
                    printf("%c", g->owner[r][c]);
            }
            printf("\n");
        }
    }
    printf("Player A score: %d\n", g->score[0]);
    printf("Player B score: %d\n", g->score[1]);
}

int read_move(int *r1, int *c1, int *r2, int *c2) {
    char line[100];
    if (fgets(line, sizeof line, stdin) == NULL)
        return -1;
    if (sscanf(line, "%d %d %d %d", r1, c1, r2, c2) != 4)
        return 0;
    return 1;
}

int validate_move(const Game *g, int r1, int c1, int r2, int c2) {
    int dr, dc;
    if (r1 < 0 || r1 > ROWS || r2 < 0 || r2 > ROWS ||
        c1 < 0 || c1 > COLS || c2 < 0 || c2 > COLS)
        return 1;                                  /* checks if out of range */
    dr = abs(r1 - r2);
    dc = abs(c1 - c2);
    if ((dr != 1 || dc != 0) && (dr != 0 || dc != 1))
        return 2;                                  /* checks if diagonal */
    if (dr == 0) {
        if (g->hlines[r1][c1 < c2 ? c1 : c2])
            return 3;                              /* checks if already drawn */
    } else {
        if (g->vlines[r1 < r2 ? r1 : r2][c1])
            return 3;
    }
    return 0;
}

void apply_move(Game *g, int r1, int c1, int r2, int c2) {
    if (r1 == r2)
        g->hlines[r1][c1 < c2 ? c1 : c2] = 1;
    else
        g->vlines[r1 < r2 ? r1 : r2][c1] = 1;
}

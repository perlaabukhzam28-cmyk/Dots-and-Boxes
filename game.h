#ifndef GAME_H
#define GAME_H

#define ROWS 4   /* rows of boxes */
#define COLS 5   /* columns of boxes */

typedef struct {
    int  hlines[ROWS + 1][COLS];   /* horizontal line from dot (r,c) to (r,c+1) */
    int  vlines[ROWS][COLS + 1];   /* vertical line from dot (r,c) to (r+1,c) */
    char owner[ROWS][COLS];        /* ' ', 'A' or 'B' */
    int  score[2];                 /* [0] = A, [1] = B */
    int  current;                  /* 0 = A, 1 = B */
    int  boxes_claimed;
} Game;

/* board.c (you) */
void init_game(Game *g);
void print_board(const Game *g);
int  read_move(int *r1, int *c1, int *r2, int *c2);   /* 1 ok, 0 bad format, -1 end of input */
int  validate_move(const Game *g, int r1, int c1, int r2, int c2); /* 0 ok, else error code */
void apply_move(Game *g, int r1, int c1, int r2, int c2);

/* game.c (partner) */
int  check_boxes(Game *g, int r1, int c1, int r2, int c2); /* boxes completed by this line */
int  is_game_over(const Game *g);
void declare_winner(const Game *g);

#endif

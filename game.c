#include <stdio.h>
  #include "game.h"

  static int box_complete(const Game *g, int r, int c) {
      return g->hlines[r][c] && g->hlines[r + 1][c] &&
             g->vlines[r][c] && g->vlines[r][c + 1];
  }

  static int whatsinthebox(Game *g, int r, int c) {
      if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
          return 0;
      if (g->owner[r][c] != ' ')
          return 0;
      if (!box_complete(g, r, c))
          return 0;
      g->owner[r][c] = (g->current == 0) ? 'A' : 'B';
      g->score[g->current]++;
      g->boxes_claimed++;
      return 1;
  }

  int check_boxes(Game *g, int r1, int c1, int r2, int c2) {
      int n = 0;
      if (r1 == r2) {                       /* horizontal line: boxes above and below */
          int c = (c1 < c2) ? c1 : c2;
          n += whatsinthebox(g, r1 - 1, c);
          n += whatsinthebox(g, r1, c);
      } else {                              /* vertical line: boxes left and right */
          int r = (r1 < r2) ? r1 : r2;
          n += whatsinthebox(g, r, c1 - 1);
          n += whatsinthebox(g, r, c1);
      }
      return n;
  }

  int is_game_over(const Game *g) {
      return g->boxes_claimed == ROWS * COLS;
  }

  void declare_winner(const Game *g) {
      printf("\nFinal score - Player A: %d, Player B: %d\n", g->score[0], g->score[1]);
      if (g->score[0] > g->score[1])
          printf("Player A wins!\n");
      else if (g->score[1] > g->score[0])
          printf("Player B wins!\n");
      else
          printf("It's a tie!\n");
  }

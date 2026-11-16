#include <stdio.h>
#include "game.h"

int main(void){
Game g;
int r1, c1, r2, c2, rc, err,boxes;
init_game(&g);
while(!(is_game_over(&g))){
print_board(&g);
printf("Player %c's turn. Enter the row and column of the first dot and second dot e.g(0 0 0 1): ", g.current ==0  ? 'A':'B');
rc = read_move(&r1, &c1, &r2, &c2);
if(rc <0){
printf("\n Input ended. Exiting. \n");
return 1;}
if (rc ==0){
printf("Invalid input.Enter four numbers. \n");
continue;
}
err = validate_move(&g, r1, c1, r2, c2);
if(err ==1){
printf("Dots must be inside the grid(rows 0-%d, columns0-%d).\n", ROWS, COLS);
continue;
}
if(err ==2){
printf("Dots cant't be diagonal.\n");
continue;
}
if(err == 3){
printf("This line is already drawn\n");
continue; 
} 

/* passed all checks, move is validated */
apply_move(&g, r1, c1, r2, c2);
boxes = check_boxes(&g, r1, c1, r2, c2);
        if (boxes == 0)
            g.current = 1 - g.current;
}
print_board(&g);
declare_winner(&g);
return 0;
}

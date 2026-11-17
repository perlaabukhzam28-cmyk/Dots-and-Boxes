# Dots and Boxes

A two-player console Dots and Boxes game in C (4 x 5 boxes). Players A and B take turns drawing lines between neighbouring dots. Completing a box claims it and shows the player's initial inside it. The player with the most boxes wins.

## Team

- Perla: board.c, Makefile, and game.h
- Prescila: game.c, main.c, and Alpine

## Build and run

```
make
./dotsboxes
```

## How to play

Enter four numbers: the row and column of the first dot, then of the second dot. Example: `0 0 0 1`

## Rules

- Lines must be horizontal or vertical between neighbouring dots.
- Completing a box gives that player another turn.
- The game ends when all 20 boxes are claimed.

## Alpine Linux

The game runs in an Alpine Linux VM and starts automatically at boot, with no login.

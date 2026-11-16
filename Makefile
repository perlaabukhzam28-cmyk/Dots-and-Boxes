CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = main.o board.o game.o

dotsboxes: $(OBJS)
	$(CC) $(CFLAGS) -o dotsboxes $(OBJS)

%.o: %.c game.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o dotsboxes

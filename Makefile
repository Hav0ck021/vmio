CC = gcc
CFLAGS = -I ./include/ -g -O0 --std=c2x -Wall

SRC = main.c \
      src/core.c \
      src/stack.c \
	  src/registers.c

OBJ = $(SRC:.c=.o)

.INTERMEDIATE: $(OBJ)

debug: $(OBJ)
	$(CC) $(OBJ) -o debug

clean:
	rm -f $(OBJ) debug
CC = gcc
CFLAGS = -I ./src/ -g -O0 --std=c2x -Wall

SRC = main.c \
      src/core/core.c \
      src/stack/stack.c \
	  src/registers/registers.c

OBJ = $(SRC:.c=.o)

.INTERMEDIATE: $(OBJ)

debug: $(OBJ)
	$(CC) $(OBJ) -o debug

clean:
	rm -f $(OBJ) debug
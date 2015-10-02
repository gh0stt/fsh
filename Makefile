CC = gcc
CFLAGS = -Wall -std=c11
LIBFLAGS = -lreadline -lcurses

all: ./src/fsh.c \
     ./src/lib/fsh/fsh_builtins.c \
     ./src/lib/fsh/fsh_prompt.c \
     ./src/lib/fsh/builtins/fsh_exit.c
	$(CC) $(CFLAGS) $+ -o fsh $(LIBFLAGS) -I ./src/lib/ -g
clean:
	rm -vf fsh *.o */*.o ./src/lib/*.o

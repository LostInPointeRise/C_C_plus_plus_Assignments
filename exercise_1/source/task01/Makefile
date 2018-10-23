CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = printsizes.o


all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o printsizes
 
printsizes.o: printsizes.c
	$(CC) $(CFLAGS) -c printsizes.c

clean:
	rm printsizes.o printsizes

